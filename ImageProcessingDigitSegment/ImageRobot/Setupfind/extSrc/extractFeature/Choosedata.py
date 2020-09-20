import cv2
import numpy as np
import pandas as pd

#range(0,729) is hog10 729 features
#range(0,144) is hog20 144 features
#range(0,100) is projectionhistrogram 100 features

def ReadDataset(datasetName,feature):
    filedData = []
    ClassLabel= ['Class']
    if feature == 'hog10':
        for i in range(0,729):
            filedData.append('hog10_'+str(i))
    if feature == 'hog20':
        for i in range(0,144):
            filedData.append('hog20_'+str(i))
    if feature == 'ph':
        for i in range(0,100):
            filedData.append('proHist'+str(i))
    if feature == 'all':
        for i in range(0,729): 
            filedData.append('hog10_'+str(i))
        for i in range(0,144):
            filedData.append('hog20_'+str(i))          
        for i in range(0,100):
            filedData.append('proHist'+str(i))
    #AppendNameData 
    
    Features_panda= pd.read_csv(datasetName,usecols=filedData) 
    Classlabels_panda= pd.read_csv(datasetName,usecols=ClassLabel) 
    Featureslist = Features_panda.values.tolist()
    Classlabeslist = Classlabels_panda.values.tolist()
    Data_include = [Featureslist[1], Classlabeslist[1]]
    #can test data with     
    #Data_include = [Featureslist[1], Classlabeslist[1]]
    #and change range like (0,2)
    #[[0.023529411764705882, 0.9686274509803922], [0.0]]
    #   ^                   ^ 
    #   ph0   index2        ph1 index2          class label index2


    return Features_panda,Classlabels_panda,Data_include



if __name__ == "__main__":
    ReadData,ClassData,DATA_ALL = ReadDataset('TestData_1.csv','ph')
    print(DATA_ALL)
    