import tensorflow as tf
from novamind.ops.tf_ops import *
from novamind.ops.np_ops import *
from novamind.framework import framework
import numpy as np
import cv2

lr = 0.0001
batch_size = 32
def _decay():
    """L2 weight decay loss."""
    costs = []
    for var in tf.trainable_variables():
        costs.append(tf.nn.l2_loss(var))
        # tf.summary.histogram(var.op.name, var)
    return tf.multiply(0.0001, tf.add_n(costs))

def train_loss(prediction, labels, optimizer_name="Mom"):
    # demo1
    # prediction = tf.nn.softmax(prediction)
    # cross_entropy = -tf.reduce_sum(labels * tf.log(prediction))        # 求和
    # demo2
    cross_entropy = tf.nn.softmax_cross_entropy_with_logits(logits=prediction, labels=labels)  # label:one hot label
    cross_entropy_loss = tf.reduce_sum(cross_entropy)/batch_size
    weight_decay_loss = _decay()
    loss = cross_entropy_loss + weight_decay_loss

    trainable_variables = tf.trainable_variables()
    grads = tf.gradients(loss, trainable_variables)

    if optimizer_name == "Mom":  # Momentum
        optimizer = tf.train.MomentumOptimizer(lr, 0.9)
    elif optimizer_name == 'RMSProp':
        optimizer = tf.train.RMSPropOptimizer(0.001, 0.9)
    elif optimizer_name == 'ADAM':
        optimizer = tf.train.AdamOptimizer(1e-4)
    else:        # SGD
        optimizer = tf.train.GradientDescentOptimizer(0.001)

    # 生成一个变量用于保存全局训练步骤( global training step )的数值,并使用 minimize() 函数更新系统中的三角权重( triangle weights )、增加全局步骤的操作
    # global_step定义存储训练次数，从1开始自己随着训练次数增加而增加。因此这个变量不需要训练的
    global_step = tf.Variable(0, name='global_step', trainable=False)
    # train_step = optimizer.minimize(loss, global_step=global_step)

    apply_op = optimizer.apply_gradients(
        zip(grads, trainable_variables),
        global_step=global_step, name='train_step')

    train_ops = [apply_op] + tf.get_collection("UPDATE_OPS_COLLECTION") # 一定要运行bn的ops
    train_step = tf.group(*train_ops)
    # ----------------------------------------------------------------------------
    correct_prediction = tf.equal(tf.argmax(prediction, 1), tf.argmax(labels, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

    top_5 = tf.nn.in_top_k(predictions=prediction, targets=tf.cast(tf.argmax(labels, 1), tf.int32), k=5)   # predictions: one hot

    top_5 = tf.reduce_max(tf.cast(top_5, tf.float16))
    return train_step, accuracy, top_5, loss

cnn = framework.resnetcifar(layers_depth=20, depth_filter=2)


class net():
    def __init__(self):
        self.cls = 100
        self.x_placeholder = [None, 32, 32, 3]
        self.x = tf.placeholder(tf.float32, self.x_placeholder)
        self.y_placeholder = [None, self.cls]
        self.y = tf.placeholder(tf.int32, self.y_placeholder)
        self.is_training = tf.placeholder(tf.bool)

    def nets(self):
        global_pool = cnn(self.x, self.is_training)
        print(global_pool)
        self.show = global_pool

        weight_fc = create_variables('fc_weight', [64*2, self.cls], 0.0001)
        biases_fc = create_variables('fc_biases', [self.cls], 0.0001, initializer=tf.zeros_initializer())
        fc = tf.add(tf.matmul(global_pool, weight_fc), biases_fc)   # fc的biases必需

        mean, variance = tf.nn.moments(fc, [0, 1])
        fc = tf.nn.batch_normalization(fc, mean, variance, 0, 1, 10-5)

        train_step, accuracy, top_5, loss = train_loss(fc, self.y)

        saver = tf.train.Saver()

        # 下面设置GPU分配方式可以有效避免出现Resource exhausted: OOM when allocating tensor with...等内存不足的情况
        config = tf.ConfigProto(allow_soft_placement=True)
        gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.7)  # 最多占用GPU 70%资源
        #  开始不会给tensorflow全部gpu资源 而是按需增加
        config.gpu_options.allow_growth = True
        sess = tf.Session(config=config)
        # sess.run(tf.global_variables_initializer())
        saver.restore(sess, 'data/cifar100_ckpt/cifar100_90000.ckpt')
        data = framework.cifar(batch_size, 'cifar100', '/media/dyz/Data/cifar100/')

        # test
        im = cv2.imread('/media/dyz/Data/kaggle/test1/2.jpg')
        im = cv2.resize(im, (32, 32))
        im = Batch_Normalization(im)
        im = im[np.newaxis, ...]

        fc_ = sess.run([fc],
                feed_dict={self.x: im, self.is_training:False})

        print(fc_)
        print(np.argmax(fc_))


        '''
        for kk in range(1, 100000):
            img_batch, label_batch = data(data_name="train")
            # print(img_batch[0, ...])
            # print(label_batch)
            # if kk < 201:
            #     lr = 0.0001
            # elif 200 < kk < 15000:
            #     lr = 0.001
            # else:
            #     lr = 0.0001
            _, acc, loss_, show = sess.run([train_step, accuracy, loss, self.show],
                        feed_dict={self.x: img_batch, self.y: label_batch, self.is_training:True})
            # print("show", show)
            if kk % 500 == 0:
                print("Train loss", loss_, "Acc:", acc)
                img_batch, label_batch = data(data_name="test")
                acc = sess.run(accuracy,
                feed_dict={self.x: img_batch, self.y: label_batch, self.is_training:False})
                print("count", kk, "acc:", acc)
                if kk % 10000 == 0:
                    saver.save(sess, "data/cifar100_ckpt/cifar100_" + str(kk) +".ckpt")
        '''

t = net()
t.nets()
# ------------------------------------------------------------------------------
