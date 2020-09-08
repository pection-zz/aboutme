import cv2
import numpy as np
from matplotlib import pyplot as plt
img = cv2.imread("plan.jpg")
img = cv2.cvtColor(img,cv2.COLOR_RGB2BGR)
kernel = np.ones((5,5),np.float32)/25
dst = cv2.filter2D(img,-1,kernel)
mask2 = cv2.subtract(img,dst)
img_unsharp_highboots = cv2.add(img,1*mask2)
plt.subplot(121),plt.imshow(img),plt.title('imag')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(img_unsharp_highboots),plt.title('Unshparp')
plt.xticks([]), plt.yticks([])
plt.show()
