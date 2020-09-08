import cv2
import numpy as np
import argparse

import glob
import os

# python segmentDigit.py -i ../data/binary/ -o .

def segmentDigit(img):
	w = img.shape[1]
	h = img.shape[0]
	img = img[h/10:(9*h)/10, w/10:(9*w)/10]
	w = img.shape[1]
	h = img.shape[0]
	cen_x = w/2
	cen_y = h/2
	kernel = np.ones((5,5),np.uint8)
	img = 255 - img
	dilation = cv2.dilate(img,kernel,iterations = 2)
	# print dilation.dtype
	cv2.imshow("d", dilation)
	cv2.waitKey(1)

	_,contours,_ = cv2.findContours(dilation, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	upperB = 0.65*w*h
	lowerB = 0.02*float(w*h)
	minArea = upperB
	minDist = np.sqrt(w*w + h*h)

	digit = None
	found = False
	for cnt in contours:
		M = cv2.moments(cnt)
		A = cv2.contourArea(cnt)
		if A > upperB or A < lowerB:
			# print A<lowerB
			# print "What"
			continue
		if M['m00'] != 0:
			cx = int(M['m10']/M['m00'])
			cy = int(M['m01']/M['m00'])
			dist = np.sqrt( (cen_x-cx)**2 + (cen_y-cy)**2 )
			if minArea > A and dist < 0.2*minDist:
				# minDist = dist
				minArea = A
				digit = cnt
				found = True
		else:
			print("Fuck")
	if found:
		x,y,w,h = cv2.boundingRect(digit)
		out = img[y:y+h, x:x+w]
		out = 255 - out
		return out
	return

if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-i","--input", required=True,
					help="Path to input image folder.")
	ap.add_argument("-o","--output", required=True,
					help="Path for output image.")
	args = vars(ap.parse_args())

	fileList = glob.glob(os.path.abspath(args["input"])+"/*.*")
	outputPath = args["output"]

	for name in fileList:
		image = cv2.imread(name,0)
		assert image is not None
		blank = np.zeros(image.shape, dtype = image.dtype)
		cells = [np.hsplit(row,50) for row in np.vsplit(image,10)]

		for i,row in enumerate(cells):
			for j,img in enumerate(row):
				out = segmentDigit(img)
				if out is not None:
					out = cv2.resize(out, (100,100))
					blank[i*100:i*100+image.shape[0]/10, j*100:j*100+image.shape[1]/50] = out
		cv2.imshow("out", blank)
		cv2.waitKey(1)
		saveName = name.split("/")[-1].split("\\")[-1]
		print "Save image at \""+outputPath+"/"+saveName+".png"+"\""
		cv2.imwrite(outputPath+"/"+saveName+".png", blank)
	cv2.destroyAllWindows()