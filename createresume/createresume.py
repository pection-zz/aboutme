# Text Variables
import matplotlib.pyplot as plt
from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox
import matplotlib.image as mpimg
import cv2
Header = '"This resume was generated entirely in Python. For full sourcecode, view my portfolio."'
Name = 'Naphat Nithisopa'
Title = 'Robotic & Automation Engineering '
Title_2 = 'Programming system integration'
Contact = 'Bangkok,TH\n+66-93-494-6545\npection.naphat@gmail.com\ndev.to/pection\ngithub.com/pection'
ProjectsHeader = 'PROJECTS/PUBLICATIONS'
ProjectOneTitle = '• Lens Quality Checking using Machine Learning'
ProjectOneDesc = '- Published by Bachelor of Engineering Program in Robotics Engineeing\n- This research project is about checking the quality of the lens with \nmachine learning methods\n- The result of experiments show that the lens quality checking \nusing machine learning can be achieved a performance testing with 99 %\n- This method can be applied to \ncheck the quality of lens in manufacturing automation in the future\nKeywords : checking the quality of the lens / polarization / image processing \n/ machine learning'
plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.sans-serif'] = 'STIXGeneral'
fig, ax = plt.subplots(figsize=(8.5, 11))

ax.axvline(x=.5, ymin=0, ymax=1, color='#007ACC', alpha=0.0, linewidth=50)
plt.axvline(x=.99, color='#000000', alpha=0.5, linewidth=300)
plt.axhline(y=.88, xmin=0, xmax=1, color='#ffffff', linewidth=3)

ax.set_facecolor('white')

plt.axis('off')
plt.annotate(Header, (.02,.98), weight='regular', fontsize=8, alpha=.75)
plt.annotate(Name, (.02,.94), weight='bold', fontsize=20)
plt.annotate(Title, (.02,.91), weight='regular', fontsize=14)
plt.annotate(Title_2, (.02,.89), weight='regular', fontsize=14)
plt.annotate(Contact, (.7,.906), weight='regular', fontsize=8, color='#ffffff')
plt.annotate(ProjectsHeader, (.02,.83), weight='bold', fontsize=14, color='#393b44')
plt.annotate(ProjectOneTitle, (.02,.812), weight='bold', fontsize=10)
plt.annotate(ProjectOneDesc, (.04,.664), weight='regular', fontsize=9)

qr_code = cv2.imread('myqr.png')
imagebox = OffsetImage(qr_code, zoom=0.5)
ab = AnnotationBbox(imagebox, (0.84, 0.12))
ax.add_artist(ab)
plt.savefig('resumefrompython.png', dpi=300, bbox_inches='tight')
