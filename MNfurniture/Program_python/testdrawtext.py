from PIL import Image
from PIL import ImageFont, ImageDraw
image=Image.new("RGB",[320,320])
draw = ImageDraw.Draw(image)
a=u"ひらがな - Hiragana, 히라가나ฟฟหก"
font=ImageFont.truetype("/Library/Fonts/Arial Unicode.ttf",14)
draw.text((50, 50), a, font=font)
image.save("a.png")
