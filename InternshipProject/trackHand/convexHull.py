#
#import cv2
#import numpy as np
#
#img = cv2.imread('./power_left/12.jpg')
##ret, thresh = cv2.threshold(img, 127, 255,0)
#contours,hierarchy = cv2.findContours(img,cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
#cnt = contours[0]
#
#hull = cv2.convexHull(cnt,returnPoints = False)
#defects = cv2.convexityDefects(cnt,hull)
#
#for i in range(defects.shape[0]):
#    s,e,f,d = defects[i,0]
#    start = tuple(cnt[s][0])
#    end = tuple(cnt[e][0])
#    far = tuple(cnt[f][0])
#    cv2.line(img,start,end,[0,255,0],2)
#    cv2.circle(img,far,5,[0,0,255],-1)
#
#cv2.imshow('img',img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

import cv2

def edge_detect(file_name, tresh_min, tresh_max):
    image = cv2.imread(file_name)
    contours, hierarchy = cv2.findContours(image, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cv2.drawContours(image, contours, -1, (0,255,0), 3)
    cv2.imwrite('cnt_'+file_name, image)

if __name__ == '__main__':
    edge_detect('./power_left/12.jpg',128, 255)
