import cv2
import numpy as np

def binarize_image(image):
	cv2.adaptiveThreshold(image,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,9,20,image)
	# cv2.threshold(image,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU, image)

def morphology(image):
	kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(3,3))
	cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel, image)