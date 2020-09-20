import cv2
from matplotlib import pyplot as plt
def nothing(x):
    pass
img = cv2.imread("img3.jpg")
img_blur = cv2.blur(img, (7,7))
img_canny = cv2.Canny(img_blur, 0, 0)
# cv2.imshow('image2', img)
# cv2.imshow('canny_edge', img_canny)
# cv2.createTrackbar('threshold1','canny_edge',0,500,nothing)
# cv2.createTrackbar('threshold2','canny_edge',0,500,nothing)
# while(1):
#     cv2.imshow('image', img)
#     cv2.imshow('canny_edge', img_canny)
     
#     threshold1 = cv2.getTrackbarPos('threshold1', 'canny_edge')
#     threshold2 = cv2.getTrackbarPos('threshold2', 'canny_edge')
 
#     img_canny = cv2.Canny(img_blur,threshold1,threshold2)
     
k = cv2.waitKey(37)
    # if k == 27:
    #     break