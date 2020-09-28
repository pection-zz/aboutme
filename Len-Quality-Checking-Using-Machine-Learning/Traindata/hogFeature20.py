import cv2
import numpy as np
import pandas as pd

import argparse
import glob
import os
from random import shuffle

IMAGE_SIZE = 50
BLOCKSIZE = 20
BLOCKSTRIBE = BLOCKSIZE/2
CELLSIZE = BLOCKSIZE
NBINS = 9
DERIVAPERTURE = 1
WINSIGMA = -1.
HISTOGRAMNORMTYPE = 0
L2HYSTHRESHOLD = 0.2
GAMMACORRECTION = 1
NLEVELS = 64
SINEDGRADIENTS = True

DATA_SET_NAME = "HOGFull1Font"
FILENAME = "{}-imagesize-{}-block-{}-cell-{}-bin-{}-sined-{}"
FILENAME = FILENAME.format(	DATA_SET_NAME,
							IMAGE_SIZE,
							BLOCKSIZE,
							CELLSIZE,
							NBINS,
							SINEDGRADIENTS)


# def createHOGDescription():
winSize = 			(IMAGE_SIZE,	IMAGE_SIZE)
blockSize = 		(BLOCKSIZE, 	BLOCKSIZE)
blockStride = 		(BLOCKSTRIBE, 	BLOCKSTRIBE)
cellSize = 			(CELLSIZE,		CELLSIZE)
nbins = 			NBINS
derivAperture = 	DERIVAPERTURE
winSigma = 			WINSIGMA
histogramNormType = HISTOGRAMNORMTYPE
L2HysThreshold = 	L2HYSTHRESHOLD
gammaCorrection = 	GAMMACORRECTION
nlevels = 			NLEVELS
signedGradients = 	SINEDGRADIENTS
	 
	# hog = cv2.HOGDescriptor(winSize,blockSize,blockStride,cellSize,nbins,derivAperture,winSigma,histogramNormType,L2HysThreshold,gammaCorrection,nlevels, signedGradients)

	# return hog


if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-i", "--imagepath", required=True,
					help="path to folder which contain images.")
	ap.add_argument("-s", "--save", action='store_true',
					help="To save dataset")
	args = vars(ap.parse_args())

	print os.path.abspath(args["imagepath"])
	filesList = glob.glob(os.path.abspath(args["imagepath"])+"/*.*")
	print filesList
	datas = []
	labels = []
	index = []
	hog = cv2.HOGDescriptor(winSize,blockSize,blockStride,cellSize,nbins,derivAperture,winSigma,histogramNormType,L2HYSTHRESHOLD,gammaCorrection,nlevels)

	for name in filesList:
		assert name.split("/")[-1].split("\\")[-1].split("_")[0].isdigit() == True
		label = int(name.split("/")[-1].split("\\")[-1].split("_")[0])
		label2 = int(name.split("/")[-1].split("\\")[-1].split("_")[-1].split(".")[0])
		image = cv2.imread(name,0)
		assert image is not None

		cells = [np.hsplit(row,50) for row in np.vsplit(image,10)]
		# print cells
		for i,rows in enumerate(cells):
			for j,img in enumerate(rows):
				img = cv2.resize(img, (IMAGE_SIZE,IMAGE_SIZE))
				feature = hog.compute(img).reshape(-1)
				feature = np.hstack((feature,np.array([label],feature.dtype)))
				index.append(name.split("/")[-1].split("\\")[-1].split(".")[0]+"png"+str(i)+"C"+str(j))
				datas.append(feature)

	datas = np.array(datas)
	print datas[:,-1]
	X = datas[:,:-1]
	y = datas[:,-1]
	print y

	if args["save"]:
		a = "-nimage-{}".format(len(datas))
		FILENAME += a
		np.savez(FILENAME+".npz", X=X, y=y)
		col = "hog"+str(BLOCKSIZE)+"_"
		header = [col+str(i) for i in range(len(datas[0])-1)]
		header.append("Class")
		print len(header)
		# header = " ".join(header)
		df = pd.DataFrame(	data = datas,
							index = index,
							columns = header)
		df.to_csv(	FILENAME+".csv",
					sep = "\t",
					encoding= "utf-8")
		# np.savetxt(FILENAME+".csv", datas, header = header, comments="")