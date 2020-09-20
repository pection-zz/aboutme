#! /usr/bin/env python
import cv2
import numpy as np
import pandas as pd

import argparse
import glob
import os
from random import shuffle

IMAGE_SIZE = 50

DATA_SET_NAME = "PHFull1Font"
FILENAME = "{}-imagesize-{}"
FILENAME = FILENAME.format(	DATA_SET_NAME,
							IMAGE_SIZE)

def createProjectionHistogram(image):
	v = np.sum(image, axis=0) / (image.shape[1])
	h = np.sum(image, axis=1) / (image.shape[0])
	features = np.hstack((v,h)).astype(np.float64)
	# features = features / np.linalg.norm(features)
	features = features / 255
	return features

if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-i", "--imagepath", required=True,
					help="path to folder which contain images.")
	ap.add_argument("-s", "--save", action='store_true',
					help="To save dataset",default="C:\Code_python\image_another\ImageFullVer")
	args = vars(ap.parse_args())

	print os.path.abspath(args["imagepath"])
	filesList = glob.glob(os.path.abspath(args["imagepath"])+"/*.*")
	print filesList
	datas = []
	labels = []
	index = []

	for name in filesList:
		assert name.split("_")[0].isdigit() == False
		label = int(name.split("/")[-1].split("\\")[-1].split("_")[0])
		image = cv2.imread(name,0)
		assert image is not None

		cells = [np.hsplit(row,50) for row in np.vsplit(image,10)]
		# print cells
		for i,rows in enumerate(cells):
			for j,img in enumerate(rows):
				img = cv2.resize(img, (IMAGE_SIZE,IMAGE_SIZE))
				feature = createProjectionHistogram(img)
				feature = np.hstack((feature,np.array([label],feature.dtype)))
				index.append(name.split("/")[-1].split("\\")[-1].split(".")[0]+"png"+str(i)+"C"+str(j))
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

		header = ["proHist"+str(i) for i in range(len(datas[0])-1)]
		header.append("Class")
		# header = " ".join(header)
		df = pd.DataFrame(	data = datas,
							index = index,
							columns = header)
		df.to_csv(	FILENAME + ".csv",
					sep = "\t",
					encoding = "utf-8")
		# np.savetxt(FILENAME+".csv", datas, header = header, comments = "")