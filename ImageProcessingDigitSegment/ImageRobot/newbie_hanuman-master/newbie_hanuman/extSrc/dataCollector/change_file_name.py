#!/usr/bin/env python
import cv2
import numpy as np

import glob
import os
import sys
import argparse
from shutil import copyfile,move

def findLatestImage(path):
	fileList = glob.glob(os.path.abspath(path)+"/*.*")
	if len(fileList) == 0:
		return "1_0.png"
	fileList = sorted(fileList, key = lambda x: int(x.split(".")[-2].split("_")[-1]))
	return fileList[-1]

if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-i", "--inputpath", required=True,
					help="path to folder for save image.")
	ap.add_argument("-o", "--outputpath", required=True,
					help="Camera ID")
	ap.add_argument("-l", "--label", required=True, type=int,
					help="Time interval.")
	args = vars(ap.parse_args())

	inputPath = args["inputpath"]
	outputpath = args["outputpath"]
	label = args["label"]

	print "Read input image from "+os.path.abspath(args["inputpath"])+"/*.*"
	inputFileList = glob.glob(os.path.abspath(args["inputpath"])+"/*.*")

	latestLabelNumber = int(findLatestImage(args["outputpath"]).split(".")[-2].split("_")[-1]) + 1

	for file_name in inputFileList:
		move(file_name, outputpath+"/"+str(label)+"_"+str(latestLabelNumber)+"."+file_name.split(".")[-1])
		latestLabelNumber += 1

	print "Done"