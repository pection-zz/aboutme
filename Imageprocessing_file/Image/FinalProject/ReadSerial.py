import serial
import time


class SerialPIC(object):
	"""docstring for RecieveParkinson"""
	def __init__(self, port = 'COM5' ,brate = 115200):
		self.serial = serial.Serial(port,brate,timeout = 3)
		self.serial.flush()
		# self.serial.dtr = False
		# self.serial.rst = False
		self.serial.setDTR(False)
		self.serial.setRTS(False)
		self.Package = []


	def SEND(self,package = []):
		self.serial.write(package)

	def recieveRawPackage(self):
		DATA = []
		flagNotRecieve = 0
		if flagNotRecieve == 0:
			self.activateParkinson(self.activatePackage)
		while self.serial.inWaiting() :
			if flagNotRecieve == 0:
				flagNotRecieve = 1
			DATA.append(ord(self.serial.read()))
			# print self.serial.inWaiting()
		if flagNotRecieve:
			flagNotRecieve = 0
			return DATA

	def closePort(self):
		self.serial.close()
