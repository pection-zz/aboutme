import pytesseract
import argparse
import numpy as np
import pyautogui
import imutils
import cv2
import pyautogui, sys
pyautogui.FAILSAFE = True
# pyautogui.size()
# try:
#     while True:
#         x, y = pyautogui.position()
#         positionStr = 'X: ' + str(x).rjust(5) + ' Y: ' + str(y).rjust(5)
#         print(positionStr, end='')
#         print('\b' * len(positionStr), end='', flush=True)
# except KeyboardInterrupt:
#     print('\n') 

pyautogui.size()
image = pyautogui.screenshot()
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# check to see if we should apply thresholding to preprocess the
# image
if args["preprocess"] == "thresh":
	gray = cv2.threshold(gray, 0, 255,
		cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
# make a check to see if median blurring should be done to remove
# noise
elif args["preprocess"] == "blur":
	gray = cv2.medianBlur(gray, 3)
# write the grayscale image to disk as a temporary file so we can
# apply OCR to it
filename = "{}.png".format(os.getpid())
cv2.imwrite(filename, gray)
image2 = imutils.resize(image, width=800)

cv2.imwrite("OcrMain.png", image)
cv2.imwrite("OcrCrop", image2)


# pytesseract.pytesseract.tesseract_cmd =  '/usr/local/Cellar/tesseract/4.1.1/bin/tesseract'

# image = cv2.imread("")
# ori = image.copy()
# custom_config = r'-l tha --psm 6'
# txt = pytesseract.image_to_string(ori, config=custom_config)

# # image=cv2.imread(filename)
# # text = pytesseract.image_to_string(image,lang='eng+tha')
# # text2 = pytesseract.image_to_string(image,lang='tha')
# # print(pytesseract.image_to_string(img, config=custom_config))

# print (txt)
# print (text2)
