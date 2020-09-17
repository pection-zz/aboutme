# Text Variables
import matplotlib.pyplot as plt
from matplotlib.offsetbox import TextArea, DrawingArea, OffsetImage, AnnotationBbox
import matplotlib.image as mpimage
import cv2
Header = '"This resume was generated entirely in Python. For full sourcecode, view my portfolio."'
Name = 'Naphat Nithisopa'
Title = 'Robotic & Automation Engineering '
Title_2 = 'Programming system integration'
Contact = 'Bangkok,TH\n+66-93-494-6545\npection.naphat@gmail.com\ndev.to/pection\ngithub.com/pection\nwww.linkedin.com/in/naphat-nithisopa'
ProjectsHeader = 'PROJECTS/PUBLICATIONS'
ProjectOneTitle = '• Lens Quality Checking using Machine Learning (First place)'
ProjectOneDesc = '- Published by Bachelor of Engineering Program in Robotics Engineering\n- This research project is about checking the quality of the lens with \nmachine learning methods\n- The result of experiments show that the lens quality checking \nusing machine learning can be achieved a performance testing with 99 %\n- This method can be applied to \ncheck the quality of lens in manufacturing automation in the future\nKeywords : checking the quality of the lens / polarization / image processing \n/ machine learning'
ProjectTwoTitle= '• Humanoid Leaguge & 3rd Internation Award'
ProjectTwoDesc= '- 3rd place Robocup Asia-Pacific RCAP 2017 in Humanoid Leaguges(Kid Size)\n -Learning in Humanoid-lab to 4 years \n -Self-Learning Skills'
ProjectThreeTitle= '• XY-Plotter'
ProjectThreeDesc= '- XY Plotter Project for control XY plotter with forward kinematic pid control \nand combine a Image Processing Draw Picture in 24FJ48GA002 controller'

ProjectFourTitle= '• ImageProcessingDigitSegment & Robotic Controller'
ProjectFourDesc= '- Use machine learning to predict Digit with other font in realtime after that \ncontrol a camera for predict position x-y-z axis to move'
ProjectFiveTitle= '• Lane detection with Rasberrypi for AMAS2017'
ProjectFiveDesc= '- use matlab to lane detection in AMAS2017 and use matlab to control \nlow-level for drive a car and combine a imageprocessing in matlab'    
ProjectSixTitle = '• SimulateRobotpickingGripper & find 2D convolution in hand'
ProjectSixDesc= '- Use simulate program for see Robot to picking a Gripper \n -Find joint with Imageprocessing from Thermal Camera'    
Portfolio = 'Portfolio: github.com/pection/aboutme'
EduHeader = 'EDUCATION & AWARD'
EduOneTitle = 'King Mongkut’s University of Technology Thonburi\nBachelor of Engineering Program in Robotics Engineeing'
EduOneTime = '2015-2019 GPAX: 2.85 :Active Recruitment Scholarship 50%'
SkillsHeader = 'Skills'
SkillsDesc = '- Python\n- Image processing\n- Machine Learning\n Pandas\n- JavaScipt\n- C,C++\n- mbed OS\n- NumPy\n- PID Controll\n- Command Line\n- Git and Version Control\n- ROS\n- APIs\n- GUI\n - Electronic\n- Mechanical'
ExtrasDesc = 'Learned popular controller \n,programing languages \n,Image processing \n,machine learning \nand Humanoid Robot'
WorkHeader = 'EXPERIENCE'
WorkOneTitle = 'Kanazawa University/ Robotic researcher'
WorkOneDesc = '- Make program to predict Hand joint from ThermalCamera with Imageprocessing \nand build How to use this program with Doctoral degree in Robotic lab'
WorkOneTime = '5/2019-8/2019'
WorkTwoTitle = 'Thai Optical Group/ Robotic Engineering'
WorkTwoTime = '8/2019-12/2019'
WorkTwoDesc = '- Using the UI- 3240LE-NIR camera to capture and analyze an image with \nimage processing and machine learning techniques to decide on lens quality in\n the computer. \n - The result of experiments show that the lens quality checking \nusing machine learning can be achieved a performance testing with 99 %'
CodeTitle = 'View My Full-Portfolio\n  Scan this QR CODE'

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
plt.annotate(ProjectTwoTitle, (.02,.65), weight='bold', fontsize=10)
plt.annotate(ProjectTwoDesc, (.04,.60), weight='regular', fontsize=9)
plt.annotate(ProjectThreeTitle, (.02,.58), weight='bold', fontsize=10)
plt.annotate(ProjectThreeDesc, (.04,.55), weight='regular', fontsize=9)
plt.annotate(ProjectFourTitle, (.02,.53), weight='bold', fontsize=10)
plt.annotate(ProjectFourDesc, (.04,.50), weight='regular', fontsize=9)
plt.annotate(ProjectFiveTitle, (.02,.48), weight='bold', fontsize=10)
plt.annotate(ProjectFiveDesc, (.04,.45), weight='regular', fontsize=9)
plt.annotate(ProjectSixTitle, (.02,.43), weight='bold', fontsize=10)
plt.annotate(ProjectSixDesc, (.04,.40), weight='regular', fontsize=9)
plt.annotate(Portfolio, (.02,.38), weight='bold', fontsize=12)
plt.annotate(WorkHeader, (.02,.35), weight='bold', fontsize=10, color='#393b44')
plt.annotate(WorkOneTitle, (.02,.33), weight='bold', fontsize=10)
plt.annotate(WorkOneTime, (.02,.31), weight='regular', fontsize=9, alpha=.6)
plt.annotate(WorkOneDesc, (.04,.28), weight='regular', fontsize=9)
plt.annotate(WorkTwoTitle, (.02,.25), weight='bold', fontsize=10)
plt.annotate(WorkTwoTime, (.02,.23), weight='regular', fontsize=9, alpha=.6)
plt.annotate(WorkTwoDesc, (.04,.15), weight='regular', fontsize=9)
plt.annotate(EduHeader, (.02,.095), weight='bold', fontsize=10, color='#393b44')
plt.annotate(EduOneTitle, (.02,.055), weight='bold', fontsize=10)
plt.annotate(EduOneTime, (.02,.035), weight='regular', fontsize=9, alpha=.6)
plt.annotate(SkillsHeader, (.7,.7), weight='bold', fontsize=10, color='#ffffff')
plt.annotate(SkillsDesc, (.7,.43), weight='regular', fontsize=10, color='#ffffff')
# plt.annotate(ExtrasTitle, (.7,.43), weight='bold', fontsize=10, color='#ffffff')
plt.annotate(ExtrasDesc, (.7,.345), weight='regular', fontsize=10, color='#ffffff')
plt.annotate(CodeTitle, (.73,.25), weight='bold', fontsize=10, color='#ffffff')

qr_code = mpimage.imread('myqr.png')
imagebox = OffsetImage(qr_code, zoom=0.5)
imageqrab = AnnotationBbox(imagebox, (0.84, 0.12))
ax.add_artist(imageqrab)

profilepic =mpimage.imread('profile.png')
profilebox = OffsetImage(profilepic, zoom=0.18)
profileab = AnnotationBbox(profilebox,(0.84, 0.8))
ax.add_artist(profileab)
plt.savefig('resumefrompython_pdf.pdf', dpi=300, bbox_inches='tight')
plt.savefig('resumefrompython_png.png', dpi=300, bbox_inches='tight')
