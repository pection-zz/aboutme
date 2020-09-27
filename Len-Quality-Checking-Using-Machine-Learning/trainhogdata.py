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
winSize = 			(363,485)
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
img = cv2.imread("./NI/LENS/SEMI/SingleVision/Base1/BadCircle_1.jpg")
print img.shape[0]
print img.shape[1]
img = cv2.resize(img, (50,50))
hog = cv2.HOGDescriptor(winSize,blockSize,blockStride,cellSize,nbins,derivAperture,winSigma,histogramNormType,L2HYSTHRESHOLD,gammaCorrection,nlevels)
feature = hog.compute(img).reshape(-1)

print feature