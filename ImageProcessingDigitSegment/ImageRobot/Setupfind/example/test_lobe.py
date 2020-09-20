#!/usr/bin/env python
from brain.visionModule import VisionModule, KinematicModule
from newbie_hanuman.msg import msgForBlissFace

import rospy
from sensor_msgs.msg import CompressedImage

import numpy as np
import cv2
import dlib

import os
import sys

import time

print sys.path

PATH = sys.path[0]

def getJsPosFromName(Js, name):
	indexJs = Js.name.index(name)
	return Js.position[indexJs]

class A(VisionModule):
	# def __init__(self):
	# 	super(A,self).__init__()
	# 	self.objectsMsgType = msgForBlissFace
	# 	self.__face_cascade = cv2.CascadeClassifier("/home/visittor/haarcascade_frontalface_default.xml")
	# 	self.__detector = dlib.get_frontal_face_detector()

	# def __transform(self, rect):
	# 	x = rect.left()
	# 	y = rect.top()
	# 	w = rect.right() - x
	# 	h = rect.bottom() - y
	# 	return x,y,w,h
	
	# def ImageProcessingFunction(self,img, header):
	# 	e1 = cv2.getTickCount()
	# 	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	# 	maxA = 0
	# 	biggestFace = [0,0,0,0]
	# 	faces = self.__face_cascade.detectMultiScale(gray, 1.1, 5)
	# 	for (x,y,w,h) in faces:
	# 		if w*h > maxA:
	# 			biggestFace = [x,y,w,h]

	# 	msg = msgForBlissFace()
	# 	msg.x = biggestFace[0]
	# 	msg.y = biggestFace[1]
	# 	msg.w = biggestFace[2]
	# 	msg.h = biggestFace[3]
	# 	# msg.header.stamp = rospy.Time.now()
	# 	msg.header = header
	# 	e2 = cv2.getTickCount()
	# 	t = 1/((e2 - e1)/cv2.getTickFrequency())
	# 	print t
	# 	return msg


	# def visualizeFunction(self, img, msg):
	# 	x = msg.x
	# 	y = msg.y
	# 	w = msg.w
	# 	h = msg.h
	# 	cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)

	pass

class B(KinematicModule):
	def __init__(self):
		super(B, self).__init__()
		intrinMat = np.identity(3)
		intrinMat[0,0] = 300
		intrinMat[1,1] = 300
		intrinMat[0,2] = 320
		intrinMat[1,2] = 240

		
		path = "/".join(PATH.split("/")[:]+["output_matrix.npz"])
		intrinMat = np.load(path)["camera_matrix"]
		# intrinMat[0,0] /= 10
		# intrinMat[1,1] /= 10
		print intrinMat
		self.set_IntrinsicCameraMatrix(intrinMat)

		tranVec = np.array([0,0,0],float)
		rotVec = np.array([0,0,0],float)
		Hplane1 = self.create_transformationMatrix(tranVec, rotVec, 'zyz')

		self.add_plane(	"plane1", Hplane1, 
						(np.inf,np.inf), (np.inf,np.inf), (np.inf,np.inf))

		tranVec = np.array([0,5,5],float)
		rotVec = np.array([-np.pi/2,np.pi/2,np.pi/2],float)
		Hplane2 = self.create_transformationMatrix(tranVec, rotVec, 'zyz')

		self.add_plane(	"plane2", Hplane2, 
						(np.inf,np.inf), (np.inf,np.inf), (np.inf,np.inf))

		tranVec = np.array([0,-5,5],float)
		rotVec = np.array([-np.pi/2,-np.pi/2,np.pi/2],float)
		Hplane3 = self.create_transformationMatrix(tranVec, rotVec, 'zyz')

		self.add_plane(	"plane3", Hplane3, 
						(np.inf,np.inf), (np.inf,np.inf), (np.inf,np.inf))

		points = [	[0,50,0],
					[0,-50,0],
					[100,50,0],
					[100,-50,0],
					[200,50,0],
					[200,-50,0],
					[300,50,0],
					[300,-50,0],
					[400,50,0],
					[400,-50,0],
					[500,50,0],
					[500,-50,0],
					[600,50,0],
					[600,-50,0]
					]
		points = np.array(points, float) / 10.0
		points[:,0] /= 6
		self.points = points.copy()

		tranCam = np.array([0.0,0,0],float)
		rotCam = np.array([0,2*np.pi/4,-np.pi/2],float)
		HCamera = self.create_transformationMatrix(tranCam, rotCam, 'zyz')

		self.point2D1 = self.calculate2DCoor(points, "plane1", HCamera=HCamera)
		self.point2D1 = np.array(self.point2D1)

		self.point2D2 = self.calculate2DCoor(points, "plane2", HCamera=HCamera)
		self.point2D2 = np.array(self.point2D2)

		self.point2D3 = self.calculate2DCoor(points, "plane3", HCamera=HCamera)
		self.point2D3 = np.array(self.point2D3)

		self.HCamera = HCamera

		self.image = None

	def kinematicCalculation(self, objMsg, joint):
		npArray = np.fromstring(objMsg.data, dtype=np.uint8).copy()
		self.image = cv2.imdecode(npArray, 1)

		panAng = getJsPosFromName(joint, "pan")
		tiltAng = -getJsPosFromName(joint, "tilt")

		tranCam = np.array([0,0,8.75],float)
		rotCam = np.array([panAng,tiltAng,0],float)
		HPanTilt = self.create_transformationMatrix(tranCam, rotCam, 'zyz')

		H = np.matmul(HPanTilt, self.HCamera)

		self.point2D1 = self.calculate2DCoor(self.points, "plane1", HCamera=H)
		self.point2D1 = np.array(self.point2D1)

		self.point2D2 = self.calculate2DCoor(self.points, "plane2", HCamera=H)
		self.point2D2 = np.array(self.point2D2)

		self.point2D3 = self.calculate2DCoor(self.points, "plane3", HCamera=H)
		self.point2D3 = np.array(self.point2D3)

		point3D1 = self.calculate3DCoor(self.point2D1, HCamera=self.HCamera)

		# np.clip(self.point2D1[:,:], -((2**31)-1), (2**31)-1, out=self.point2D1[:,:])
		np.clip(self.point2D1[:,:], -0, 800, out=self.point2D1[:,:])
		# np.clip(self.point2D1[:,1], -((2**31)-1), (2**31)-1, out=self.point2D1[:,1])

		np.clip(self.point2D2[:,:], -0, 800, out=self.point2D2[:,:])
		# np.clip(self.point2D2[:,1], -((2**31)-1), (2**31)-1, out=self.point2D2[:,1])

		np.clip(self.point2D3[:,:], -0, 800, out=self.point2D3[:,:])
		# np.clip(self.point2D3[:,1], -((2**31)-1), (2**31)-1, out=self.point2D3[:,1])

		# print point3D1
		for i in range(len(self.point2D1)):
			cv2.line(self.image, tuple(self.point2D1[i].astype(int)), tuple(self.point2D1[(i+1)%len(self.point2D1)].astype(np.int32)), (0,0,255), 4)

		for i in range(len(self.point2D2)):
			cv2.line(self.image, tuple(self.point2D2[i].astype(int)), tuple(self.point2D2[(i+1)%len(self.point2D2)].astype(np.int32)), (0,255,0), 4)

		for i in range(len(self.point2D3)):
			cv2.line(self.image, tuple(self.point2D3[i].astype(int)), tuple(self.point2D3[(i+1)%len(self.point2D3)].astype(np.int32)), (255,0,0), 4)

		return self.posDictMsgType()

	def loop(self):
		if self.image is not None:
			cv2.imshow("image",self.image)
			cv2.waitKey(1)

vision_module = A()
kinematic_module = B()
