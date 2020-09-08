import cv2
import numpy as np
from matplotlib import pyplot as plt
def nothing(x):
    pass
cv2.namedWindow('Colorbars')
hh='Max'
hl='Min'
cv2.createTrackbar("Max", "Colorbars",0,255,nothing)
cv2.createTrackbar("Min", "Colorbars",0,255,nothing)
img = cv2.imread('./power_left/12.jpg')
kernel = np.ones((5,5),np.float32)/25
dst = cv2.filter2D(img,-1,kernel)
while(1):
    hul=cv2.getTrackbarPos("Max", "Colorbars")
    huh=cv2.getTrackbarPos("Min", "Colorbars")
    edges = cv2.Canny(dst,hul,huh,apertureSize = 3)
    cv2.imshow("Colorbars",edges)
    k = cv2.waitKey(1) & 0xFF
    if k == ord('a'):
        break
cv2.destroyAllWindows()
