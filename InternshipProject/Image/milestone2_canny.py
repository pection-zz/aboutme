import cv2
from matplotlib import pyplot as plt
def nothing(x):
    pass
img = cv2.imread("triangle.jpg", 0)
img_blur = cv2.blur(img, (7,7))
img_canny = cv2.Canny(img_blur, 0, 0)
cv2.imshow('Original_img', img)
cv2.imshow('Blur_img', img_blur)
cv2.imshow('Canny_img', img_canny)
cv2.createTrackbar('threshold1','Canny_img',0,500,nothing)
cv2.createTrackbar('threshold2','Canny_img',0,500,nothing)
while(1):
    cv2.imshow('Original_img', img)
    cv2.imshow('Blur_img', img_blur)

    threshold1 = cv2.getTrackbarPos('threshold1', 'Canny_img')
    threshold2 = cv2.getTrackbarPos('threshold2', 'Canny_img')
 
    img_canny = cv2.Canny(img_blur,threshold1,threshold2)
    cv2.imshow('Canny_img', img_canny) 
    k = cv2.waitKey(30)
    if k == 27:
        break