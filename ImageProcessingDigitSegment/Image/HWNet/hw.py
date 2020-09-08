import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('ori.png', 0)
mask = cv2.imread('mask.png', 0)

fft = np.fft.fft2(img)
fftshift = np.fft.fftshift(fft)
ifftshift = np.fft.ifftshift(fftshift)

filtering = mask.astype(float) 
filtering = filtering *ifftshift / 255.0
shiftt = np.fft.ifft2(filtering)

spectrum = 20 * np.log(np.abs(fftshift))
spectrum_shift = np.abs(shiftt)

spec_gus = cv2.GaussianBlur(spectrum_shift, (1, 1), 0)
hb_ = cv2.addWeighted(spectrum_shift, 4, spec_gus, -3, 0)
hb_ = np.clip(hb_, 0, 255).astype(np.uint8)
final_img = np.clip(spec_gus, 0, 255).astype(np.uint8)

cv2.imshow("ORI",img)
cv2.imshow("AFTER",final_img)
cv2.waitKey(0)
