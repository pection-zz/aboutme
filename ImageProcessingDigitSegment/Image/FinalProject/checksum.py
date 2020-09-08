def Value(x,y):
    h_x = int(x) & 0xff00 >>8
    l_x = int(x) / 256
    h_y = int(y) & 0xff00 >>8
    l_y = int(y) / 256
    xaxis=hex(int(x))
    yaxis=hex(int(y)).split('x')[-1]
    checksum = 1+1+5+int(x)+int(y)
    checksum %=256
    checksum = 255-checksum
    print (xaxis)
    pack =[255,255,1,1,5,int(l_x),int(h_x),int(l_y),int(h_y),checksum]
    print (pack)
    for i in range(0,len(pack)):
        pack[i]=hex(pack[i])
        # pack[i].split('x')[-1]
    return pack

mikeX = input("X >>")
mikeY = input("Y >>")

Hello = Value(mikeX,mikeY)
print(Hello)
