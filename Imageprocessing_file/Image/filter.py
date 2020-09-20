import cv2
from matplotlib import pyplot as plt

img = cv2.imread('ori_med.png')

median = cv2.medianBlur(img,5)

plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(median),plt.title('MedianBlur')
plt.xticks([]), plt.yticks([])
plt.show()