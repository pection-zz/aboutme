from PIL import Image

img = Image.open('data/img6.png')
img = img.resize((320,320), Image.ANTIALIAS)
img.save('data/img6_4.png')
