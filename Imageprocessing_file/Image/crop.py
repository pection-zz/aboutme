import cv2
import numpy as np
import time

img1 = cv2.imread('C:\Code_python\Image\Picture\back.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\white.jpg')
crop_img1 = img2[0:100, 0:100]
crop_img2 = img1[0:100, 0:100]

show = cv2.bitwise_and(img1,img1)
 # Crop from x, y, w, h -> 100, 200, 300, 400
# NOTE: its img[y: y + h, x: x + w] and *not* img[x: x + w, y: y + h]
cv2.imshow("cropped", show)
cv2.waitKey(0)