import cv2
import numpy as np
from matplotlib import pyplot as plt
k = 5
img = cv2.imread("Humanimg.jpg")
img = cv2.cvtColor(img,cv2.COLOR_RGB2BGR)
kernel = np.array((
	[0, 1, 0],
	[1, -4, 1],
	[0, 1, 0]), dtype="int")
dst = cv2.filter2D(img,-1,kernel)
mask = cv2.subtract(img,dst)
img_unsharp_highboots = cv2.add(img,k*mask)
plt.subplot(121),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(img_unsharp_highboots),plt.title('After Unsharp and Highboots')
plt.xticks([]), plt.yticks([])
plt.show()
