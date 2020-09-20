from __future__ import division

import cv2
import numpy as np

from random import shuffle

if __name__ == "__main__":
	img = cv2.imread("digits.png")

	isSave = False

	assert img is not None

	cells = [np.hsplit(row,100) for row in np.vsplit(img,50)]
	
	data = []

	for i in range(len(cells)):
		for j in range(len(cells[i])):
			img = cells[i][j]
			cv2.imwrite("seperated_digits/"+str(i//5)+"_"+str((i*100+j)%500)+".png",img)
			img = img.flatten()
			img = np.hstack((img,np.array([i//5]))).astype(np.float64)
			data.append(img)
	shuffle(data)
	data = np.array(data)

	X = data[:,:-1]
	y = data[:,-1]
	print X.shape
	if isSave:
		np.savez("test", X=X, y=y)