#! /usr/bin/env python
from hogFeature import createHOGDescription
from hogFeature import FILENAME as hogFilename
from hogFeature import IMAGE_SIZE as hogImSize
from projectionHistogram import createProjectionHistogram
from projectionHistogram import FILENAME as phFilename
from projectionHistogram import IMAGE_SIZE as phImSize

import cv2
import numpy as np 
import argparse
import os
import glob

if __name__ == "__main__":
	assert hogImSize == phImSize
	DATASET_NAME = "HOGandPH"
	FILENAME = "{}-"+"-".join(hogFilename.split("-")[1:])
	FILENAME = FILENAME.format(DATASET_NAME)
	print FILENAME
	IMAGE_SIZE = phImSize

	ap = argparse.ArgumentParser()
	ap.add_argument("-i", "--imagepath", required=True,
					help="path to folder which contain images.")
	ap.add_argument("-s", "--save", action='store_true',
					help="To save dataset")
	args = vars(ap.parse_args())

	print os.path.abspath(args["imagepath"])
	filesList = glob.glob(os.path.abspath(args["imagepath"])+"/*.*")
	# print filesList
	datas = []
	labels = []

	hog = createHOGDescription()
	count = 0
	for name in filesList:
		assert name.split("_")[0].isdigit() == False
		label = int(name.split("/")[-1].split("\\")[-1].split("_")[0])
		image = cv2.imread(name,0)
		assert image is not None

		cells = [np.hsplit(row,50) for row in np.vsplit(image,10)]
		# print cells
		for rows in cells:
			for img in rows:
				img = cv2.resize(img, (IMAGE_SIZE,IMAGE_SIZE))
				hogFeat = hog.compute(img).reshape(-1)
				nHog = hogFeat.shape[0]
				phFeat = createProjectionHistogram(img)
				nPh = phFeat.shape[0]
				feature = np.hstack((phFeat,hogFeat))
				feature = np.hstack((feature,np.array([label],feature.dtype)))
				# print feature.shape
				count += 1
				print count
				datas.append(feature)

	# shuffle(datas)
	datas = np.array(datas)
	print datas[:,-1]
	X = datas[:,:-1]
	y = datas[:,-1]
	print 'y',y
	print datas.shape
	if args["save"]:
		a = "-nimage-{}".format(len(datas))
		FILENAME += a
		np.savez(FILENAME+".npz", X=X, y=y)

		headerPH = ["proHist"+str(i) for i in range(nPh)]
		headerHOG = ["Hog"+str(i) for i in range(nHog)]
		header = headerPH + headerHOG
		header.append("class")
		header = " ".join(header)
		np.savetxt(FILENAME+".csv", datas, header = header, comments = "")