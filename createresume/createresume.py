# Text Variables
import matplotlib.pyplot as plt
from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox
import matplotlib.image as mpimg

Header = '"This resume was generated entirely in Python. For full sourcecode, view my portfolio."'
Name = 'Naphat Nithisopa'
Title = 'Robotic & Automation Engineering '
Title_2 = 'Programming system integration'
Contact = 'Bangkok,TH\n+66-93-494-6545\npection.naphat@gmail.com\ndev.to/pection\ngithub.com/pection'

plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.sans-serif'] = 'STIXGeneral'
fig, ax = plt.subplots(figsize=(8.5, 11))
# Decorative Lines
ax.axvline(x=.5, ymin=0, ymax=1, color='#007ACC', alpha=0.0, linewidth=50)
plt.axvline(x=.99, color='#000000', alpha=0.5, linewidth=300)
plt.axhline(y=.88, xmin=0, xmax=1, color='#ffffff', linewidth=3)
# set background color
ax.set_facecolor('white')
# remove axes
plt.axis('off')
plt.annotate(Header, (.02,.98), weight='regular', fontsize=8, alpha=.75)
plt.annotate(Name, (.02,.94), weight='bold', fontsize=20)
plt.annotate(Title, (.02,.91), weight='regular', fontsize=14)
plt.annotate(Title_2, (.02,.89), weight='regular', fontsize=14)
plt.annotate(Contact, (.7,.906), weight='regular', fontsize=8, color='#ffffff')

arr_code = mpimg.imread('myqr.png')
imagebox = OffsetImage(arr_code, zoom=0.5)
ab = AnnotationBbox(imagebox, (0.84, 0.12))
ax.add_artist(ab)
plt.savefig('resumefrompython.png', dpi=300, bbox_inches='tight')
