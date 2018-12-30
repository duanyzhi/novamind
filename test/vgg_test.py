import tensorflow as tf
from novamind.framework.vgg import vgg16
from novamind.ops.imagenet_classes import class_names
import numpy as np
import cv2

if __name__ == '__main__':
    sess = tf.Session()
    imgs = tf.placeholder(tf.float32, [None, 224, 224, 3])
    vgg = vgg16(imgs, 'data/npz/vgg16_weights.npz', sess)

    img1 = cv2.imread('/media/dyz/Data/kaggle/test1/1.jpg')
    img1 = cv2.resize(img1, (224, 224))

    prob = sess.run(vgg.probs, feed_dict={vgg.imgs: [img1]})[0]
    preds = (np.argsort(prob)[::-1])[0:5]
    for p in preds:
        print(class_names[p], prob[p])
