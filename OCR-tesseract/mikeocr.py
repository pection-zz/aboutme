try:
    from PIL import Image
except ImportError:
    import Image
import pytesseract

def ocr_core(filename):
    """
    This function will handle the core OCR processing of images.
    """
    text = pytesseract.image_to_string(Image.open(filename),lang='tha')  # We'll use Pillow's Image class to open the image and pytesseract to detect the string in the image
    return text
pytesseract.pytesseract.tesseract_cmd =  '/usr/local/Cellar/tesseract/4.1.1/bin/tesseract'

print(ocr_core('address.png'))