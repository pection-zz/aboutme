import cv2
import numpy as np
import pandas as pd

IMAGE_SIZE = 50
BLOCKSIZE = 10
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


def createHOGDescription():
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
	 
	hog = cv2.HOGDescriptor(winSize,blockSize,blockStride,cellSize,nbins,derivAperture,winSigma,histogramNormType,L2HysThreshold,gammaCorrection,nlevels, signedGradients)

	return hog

if __name__ == "__main__":

	img = cv2.imread("1_1.png", 0)
	img = cv2.resize(img, (IMAGE_SIZE,IMAGE_SIZE))
	hog = createHOGDescription()
	feature = hog.compute(img).reshape(1,-1)
	print feature, feature.shape

	if 1==1:
		col = "hog"+str(BLOCKSIZE)+"_"
		header = [col+str(i) for i in range(len(feature[0]))]
		print len(header)
		index = ["1"]
		# header = " ".join(header)
		df = pd.DataFrame(	data = feature,
							index = index,
							columns = header,)
		df.to_csv(	FILENAME+".csv",
					sep = "\t",
					encoding= "utf-8")