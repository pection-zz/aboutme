from ReadSerial import SerialPIC
import time 
Mike =SerialPIC(port = 'COM13',brate = 115200)
time.sleep(0.01)
# while(1) :
#     Mike.Package=input('>>')
#     # Mike.Package= ['<','1','>']
#     Pack = []
#     if Mike.Package == 'exit':
#         break
#     for i in Mike.Package:
#         Pack.append(ord(i))

#     print (Pack)

Pack =[255,255,1,1,5,0,50,0,50,148]
Setzero=[255,255,1,3,1,250]
Mike.SEND(Pack)
print("FINISH")
# Mike.SEND(Setzero)

