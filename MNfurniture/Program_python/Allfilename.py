import os

path ="/Users/pection/Documents/mn_furniture/AddwatermarkProgram/CG1"
#we shall store all the file names in this list

for root, dirs, files in os.walk(path):
    for file in files:
        if(file.endswith(".jpg")):
            print(os.path.join(root,file))