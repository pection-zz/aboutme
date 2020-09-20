import numpy as np
import cv2
# Create a black image
img1 = cv2.imread('C:\Code_python\Image\Picture\pikachu.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\tiger.jpg')
# Draw a diagonal blue line with thickness of 5 px
cv2.line(img,(0,0),(511,511),(255,0,0),5)
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'OpenCV',(10,500), font, 4,(255,255,255),2,cv2.LINE_AA)
cv2.namedWindow('image', cv2.WINDOW_AUTOSIZE)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()