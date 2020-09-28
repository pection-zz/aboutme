import matplotlib.pyplot as plt

from skimage.feature import hog
from skimage import data, exposure
import cv2

# image = cv2.imread("./NI/LENS/SEMI/SingleVision/Base1/SEMI_SV_B1_GD_01_1.jpg")
image = cv2.imread("./NI/LENS/SEMI/SingleVision/Base1/BadCircle_1.jpg")
# image = cv2.imread("./NI/LENS/SEMI/SingleVision/Base1/Good_1.jpg")

# image = cv2.imread("./TestPictures/BadCircle_1.jpg")
fd, hog_image = hog(image, orientations=8, pixels_per_cell=(16,16),
                    cells_per_block=(1, 1),multichannel=True, visualize=True)

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(8, 4), sharex=True, sharey=True)

ax1.axis('off')
ax1.imshow(image, cmap=plt.cm.gray)
ax1.set_title('Input image')

# Rescale histogram for better display
hog_image_rescaled = exposure.rescale_intensity(hog_image, in_range=(0, 10))

ax2.axis('off')
ax2.imshow(hog_image_rescaled, cmap=plt.cm.gray)
ax2.set_title('HOG')
plt.show()
# print("HELLO")