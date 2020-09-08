__author__ = 'SaintWingZ'
import serial

ser = serial.Serial('com80')
ser._baudrate = 9600
ser.write("hello")