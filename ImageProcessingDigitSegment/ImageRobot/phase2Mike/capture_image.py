#!/usr/bin/env python
import cv2
import numpy as np

import time
import os
import argparse

from transform import *
from binarize import binarize_image, morphology
from findRectangle import findRectangle

def recieve_and_save_image(id_, path, timeInterval=0.5):
	cap = cv2.VideoCapture(id_)

	startTime = time.time()
	numPic = 0

	imageList = []

	try:
		while True:
			ret,img = cap.read()

			if ret:
				dst = capture(img)
				if time.time() - startTime > timeInterval:
					if dst is not None:
						dst = cv2.resize(dst, (100,100))
						# print "Save image at \""+path+"/"+str(time.time())+".png"+"\"."
						# cv2.imwrite(path+"/"+str(time.time())+".png", dst)
						numPic += 1
						print numPic
						imageList.append(dst.copy())
						if numPic == 500:
							img = stackImage(imageList)
							print "Save image at \""+path+"/"+str(time.time())+".png"+"\"."
							cv2.imwrite(path+"/"+str(time.time())+".png", img)
							yield None
				yield img
			else:
				yield None
	finally:
		cap.release()

def stackImage(imageList):
	row = 10
	collumn = 50
	imwidth = 100
	imheigth = 100
	assert len(imageList) == row*collumn
	blank = np.zeros((row*imheigth, collumn*imwidth), dtype =np.uint8)
	n = 0
	for i in range(row):
		for j in range(collumn):
			blank[i*imheigth:(i+1)*imheigth,j*imwidth:(j+1)*imwidth] = imageList[n]
			n += 1
	return blank

def capture(org):
	img = cv2.cvtColor(org, cv2.COLOR_BGR2GRAY)
	rects = findRectangle(img)

	maxArea = 0
	larg = None
	for rect in rects:
		A = calArea(rect)
		if A>maxArea:
			maxArea = A
			larg = rect

	if larg is not None:

		larg = order_points(larg)

		for i in range(4):
			cv2.line(org, tuple(larg[i]), tuple(larg[(i+1)%4]), 255,3)

		dst = four_point_transform(img, larg)
		# binarize_image(dst)
		cv2.imshow("img", dst)
		return dst

def calArea(points):
	rect = order_points(points)
	(tl, tr, br, bl) = rect

	# compute the width of the new image, which will be the
	# maximum distance between bottom-right and bottom-left
	# x-coordiates or the top-right and top-left x-coordinates
	widthA = np.sqrt(((br[0] - bl[0]) ** 2) + ((br[1] - bl[1]) ** 2))
	widthB = np.sqrt(((tr[0] - tl[0]) ** 2) + ((tr[1] - tl[1]) ** 2))
	maxWidth = max(int(widthA), int(widthB))

	# compute the height of the new image, which will be the
	# maximum distance between the top-right and bottom-right
	# y-coordinates or the top-left and bottom-left y-coordinates
	heightA = np.sqrt(((tr[0] - br[0]) ** 2) + ((tr[1] - br[1]) ** 2))
	heightB = np.sqrt(((tl[0] - bl[0]) ** 2) + ((tl[1] - bl[1]) ** 2))
	maxHeight = max(int(heightA), int(heightB))
	return maxHeight * maxWidth

if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-s", "--savepath", required=True,
					help="path to folder for save image.")
	ap.add_argument("-c", "--camera", required=True, type=int,
					help="Camera ID")
	ap.add_argument("-t", "--timeinterval", required=False, default=0.5,
					help="Time interval.")
	ap.add_argument("-n", "--noCapture", action='store_false')
	args = vars(ap.parse_args())
	print args["noCapture"]
	reciever = recieve_and_save_image(args["camera"], os.path.abspath(args["savepath"]), args["timeinterval"])

	while True:
		org = next(reciever)
		if org is None:
			break

		cv2.imshow("img",org)

		if cv2.waitKey(1) == 27:
			break
	reciever.close()
	cv2.destroyAllWindows()

