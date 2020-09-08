#! /usr/bin/env python
import numpy as np 
import glob
import os
import argparse
from random import shuffle

if __name__ == "__main__":
	ap = argparse.ArgumentParser()
	ap.add_argument("-i", "--input", required=True,
					help="path to dataset.")
	ap.add_argument("-s", "--save", action='store_true',
					help="To save dataset")
	ap.add_argument("-p","--percent", type = float, help="Percent of split.")
	args = vars(ap.parse_args())

	print os.path.abspath(args["input"])
	inputPath = os.path.abspath(args["input"])
	filename = inputPath.split("/")[-1]
	print filename
	filename = filename.split(".")[0]
	dataSet = np.load(inputPath)
	X = dataSet['X']
	y = dataSet['y']
	assert y.shape[0] == X.shape[0]

	lenData = y.shape[0]

	datas = np.hstack((X,y.reshape(-1,1)))
	print datas[:,-1]
	print y
	shuffle(datas)
	print datas[:,-1]

	nDatasplit = int(lenData*float(args["percent"])/100.0)

	count = 0
	for i in range(0,lenData-nDatasplit+1,nDatasplit):
		start = i
		end = min(i+nDatasplit, lenData-1)
		d = datas[i:i+nDatasplit]
		
		if args["save"]:
			nfeat = d.shape[1]-1
			header = ["F"+str(i) for i in range(nfeat+1)]
			# header.append("class")
			header = " ".join(header)
			np.savez(filename+"-"+str(count)+".npz", X = d[:,:-1], y=d[:,-1])
			np.savetxt(filename+"-"+str(count)+".csv", d,header=header,comments="")
		count += 1
		print count
