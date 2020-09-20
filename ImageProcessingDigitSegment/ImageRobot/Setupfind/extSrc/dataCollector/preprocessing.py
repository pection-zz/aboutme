#! /usr/bin/env python
from binarize import binarize_image
import argparse
import glob
import os
import cv2
import numpy as np

def preprocessing(image):
	image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
	binarize_image(image)
	return image

if __name__ == '__main__':
	ap = argparse.ArgumentParser()
	ap.add_argument("-i","--input", required=True,
					help="Path to input image folder.")
	ap.add_argument("-o","--output", required=True,
					help="Path for output image.")
	args = vars(ap.parse_args())

	print "Image path:"
	print os.path.abspath(args["input"])
	fileList = glob.glob(os.path.abspath(args["input"])+"/*.*")
	outputPath = args["output"]
	print fileList

	for name in fileList:
		image = cv2.imread(name)
		assert image is not None

		image = preprocessing(image)
		fileName = name.split("/")[-1]
		print fileName
		cv2.imwrite(outputPath+"/"+fileName, image)