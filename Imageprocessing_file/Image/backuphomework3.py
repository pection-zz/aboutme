import matplotlib.pyplot as plt
import numpy as np
from scipy import ndimage
import cv2
def plot(data, title):
    plot.i += 1
    plt.subplot(2,2,plot.i)
    plt.imshow(data)
    plt.gray()
    plt.title(title)
plot.i = 0
im = cv2.imread("gofestoneyear.jpg")
data = np.array(im, dtype=float)
plot(data, 'Original')
kernel = np.array([[-1, -1, -1],
                   [-1,  8, -1],
                   [-1, -1, -1]])/25
highpass_3x3 = cv2.filter2D(data,-1,kernel)
plot(highpass_3x3, 'Simple 3x3 Highpass')
kernel = np.array([[-1, -1, -1, -1, -1],
                   [-1,  1,  2,  1, -1],
                   [-1,  2,  4,  2, -1],
                   [-1,  1,  2,  1, -1],
                   [-1, -1, -1, -1, -1]])/25
highpass_5x5 = cv2.filter2D(data,-1,kernel)
plot(highpass_5x5, 'Simple 5x5 Highpass')
lowpass = ndimage.gaussian_filter(data, 3)
gauss_highpass = data - lowpass
plot(gauss_highpass, r'Gaussian Highpass, $\sigma = 3 pixels$')

plt.show()