import numpy as np 

def readNumpyDataset(fileName):
	npFile = np.load(fileName)
	
	print npFile.files
	print "X Data"
	print npFile['X']
	print "y Data"
	print npFile['y']

	return npFile['X'], npFile['y']

if __name__ == "__main__":

	X,y = readNumpyDataset("test.npz")