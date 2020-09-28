def EdgeDetection(img):
	img = cv2.fastNlMeansDenoising(img,None,3,7,21)
	_,img = cv2.threshold(img,30,255,cv2.THRESH_TOZERO)
	denoise_img = img
	laplacian = cv2.Laplacian(img,cv2.CV_64F)
	sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=5)  # x
	sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=3)  # y
	canny = cv2.Canny(img,100,200)
	contour_image, contours, hierarchy = cv2.findContours(img, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	return {"denoise":denoise_img,"laplacian":laplacian,"canny":canny,"sobely":sobely,"sobelx":sobelx,"contour":contour_image}

# GrayScale Image Convertor
# https://extr3metech.wordpress.com 