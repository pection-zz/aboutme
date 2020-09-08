import cv2
import numpy as np
from matplotlib import pyplot as plt
img = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg',0)
# img2 = cv2.equalizeHist(img)
hist,bins = np.histogram(img.flatten(),256,[0,256])
cdf = hist.cumsum()
cdf_normalized = cdf * hist.max()/ cdf.max()
cdf_m = np.ma.masked_equal(cdf,0)
cdf_m = (cdf_m - cdf_m.min())*255/(cdf_m.max()-cdf_m.min())
cdf = np.ma.filled(cdf_m,0).astype('uint8')
img2 = cdf[img]    
cv2.namedWindow('before')
cv2.imshow('before',img)
cv2.namedWindow('after')
cv2.imshow('after',img2)
cv2.waitKey(0)
cv2.destroyAllWindows()