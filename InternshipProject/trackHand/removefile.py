import glob, os
test = './ImageReal/*'
r = glob.glob(test)
print (r)
for i in r:
    os.remove(i)
