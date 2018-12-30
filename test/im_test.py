import cv2
from novamind.ops.im_ops import draw_box


im = cv2.imread('/media/dyz/Data/kaggle/test1/1.jpg')

o = draw_box(im, [10, 10, 200, 200])

cv2.imshow("out", o)
cv2.waitKey()
