import MySQLdb

class Databaze_2:

    def allQuestion(self,class_code,date,zeroorone):
        mydb = MySQLdb.connect(host='10.61.3.223', port=3306, user='2016FRA241G5', passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5',use_unicode=True, charset='utf8')
        cur = mydb.cursor()

        call = "SELECT `Question`,`Student ID`,`Time` FROM `Question Table` WHERE `Class ID` = " + str(class_code)

        cur.execute(call)
        data = cur.fetchall()
        mydb.close()
        stre = ""
        newdata = []
        check = False
        for e in data:
            if (str(date) == str(e[2])[0:10]) :
                if zeroorone:

                    if int(str(e[2])[11:13]) > 13:
                        check = True
                else:

                    if int(str(e[2])[11:13]) < 13:
                        check = True
            if check:
                newdata.append((e[0],e[1]))
        for elem in newdata:
            stre += elem[0]+ " from "+str(elem[1]) + "\n"
        return stre

    def Oneshot(self,t="",sid="",time=15.00):
        mydb = MySQLdb.connect(host='10.61.3.223',port=3306,user='2016FRA241G5',passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5')
        cur = mydb.cursor()
        ns1=0#overall status 1
        ns0=0#overall status 0
        pers=0#% (ns1*100)/(ns1+ns2)
        data1 = ()#data return
        data2 = ()#data return test

        if True:
            if True:
                call = "SELECT * FROM `Click Table` WHERE (TIME>='"+str(t)+" "+str(time-0.05).replace(".",":")+":00"+"' AND TIME<='"+str(t)+" "+ str(time).replace(".",":")+":00"+"') AND `Class ID`='"+str(sid)+"' AND `Status` = 1"#call status 1 order


                cur.execute(call)#call status 1
                data = cur.fetchall() # Sometype of file to tuple
                ns1 = (len(data))  # number status1

                data1 = data1 + data #add data
                call = call.replace('`Status` = 1','`Status` = 0')#call status 0 order
                cur.execute(call)#call status 0
                data = cur.fetchall()  # Sometype of file to tuple
                ns0 = (len(data))  # number status0

                data1 = data1 + data # add data
                #print data1

                if True:
                #if (ns0!=0)|(ns1!=0):
                    if (ns0 + ns1) != 0:
                        pers = int((ns1 * 100) // (ns0 + ns1))
                    else:
                        pers = 50
                    datasent = (ns1, ns0, pers)
                    data2 = data2 + datasent  # number status1,number status2,persentage,time1,time2
                #print call + "calltest2" test
        mydb.close()
        if data2==():
            return None
        else:
            return data2

    def callClick(self,t="",sid="",hr=16):#exampleinput callClick("2016-11-8","241")

        mydb = MySQLdb.connect(host='10.61.3.223',port=3306,user='2016FRA241G5',passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5')
        cur = mydb.cursor()
        ns1=0#overall status 1
        ns0=0#overall status 0
        pers=0#% (ns1*100)/(ns1+ns2)
        data1 = ()#data return
        data2 = ()#data return test
        timesort = []
        if hr == 0:
            hr = 2
        elif hr == 22:
            hr = 21
        for i in range((hr-1), (hr+2)):#create time(text) for sort (every 1 min for 24 hour)
            for n in range(0, 60, 1):
                if i < 10:
                    if n >= 10:
                        re = "0" + (str)(i) + "." + (str)(n)
                    else:
                        re = "0" + (str)(i) + "." + "0" + (str)(n)
                if i >= 10:
                    if n >= 10:
                        re = (str)(i) + "." + (str)(n)
                    else:
                        re = (str)(i) + "." + "0" + (str)(n)
                timesort.append(re)

        for i in range(0, (len(timesort)-1)):#call every 1 min
            print int(i*100.0/len(timesort)) , "Percent"
            '''if i == ((len)(timesort)-1):
                call = "SELECT * FROM `Click Table` WHERE (TIME>='"+str(t)+" 23:55:00' AND TIME<='"+str(t)+"23:59:59') AND `Class ID`='241001' AND `Status` = 1"#call status 1 order
                call = call.replace('2016-11-9', t)
                call = call.replace('241001', sid)
                call = call.replace('0:0:0',"23:55:00")
                call = call.replace('0:5:0',"23:59:59")
                cur.execute(call)#call status 1
                data = cur.fetchall() # Sometype of file to tuple
                data1 = data1 + data #add data
                call = call.replace('`Status` = 1','`Status` = 0')#call status 0 order
                cur.execute(call)#call status 0
                data = cur.fetchall()  # Sometype of file to tuple

                data1 = data1 + data  # add data
                #print call + "calltest1" test
            else:'''
            if True:

                call = "SELECT * FROM `Click Table` WHERE (TIME>='"+str(t)+" "+str(timesort[i]).replace(".",":")+":00"+"' AND TIME<='"+str(t)+" "+ str(timesort[i+1]).replace(".",":")+":00"+"') AND `Class ID`='"+str(sid)+"' AND `Status` = 1"#call status 1 order
                #print call

                cur.execute(call)#call status 1
                data = cur.fetchall() # Sometype of file to tuple
                ns1 = (len(data))  # number status1

                data1 = data1 + data #add data
                call = call.replace('`Status` = 1','`Status` = 0')#call status 0 order
                cur.execute(call)#call status 0
                data = cur.fetchall()  # Sometype of file to tuple
                ns0 = (len(data))  # number status0

                data1 = data1 + data # add data
                #print data1

                if True:
                #if (ns0!=0)|(ns1!=0):
                    if (ns0 + ns1) != 0:
                        pers = int((ns1 * 100) // (ns0 + ns1))
                    else:
                        pers = 50
                    datasent = ( (ns1, ns0, pers, timesort[i]),)
                    data2 = data2 + datasent  # number status1,number status2,persentage,time1,time2
                #print call + "calltest2" test
        mydb.close()
        if data2==():
            return None
        else:
            return data2

    def allQuestion_vote(self,sid = 241,date = None):
        mydb = MySQLdb.connect(host='10.61.3.223', port=3306, user='2016FRA241G5', passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5', charset='utf8')
        cur = mydb.cursor()
        call = "SELECT `Question`,`Vote`,`Question ID` FROM `Question Table` WHERE (`Class ID` =" + str(sid)+")and (TIME>='"+str(date)+" 00:00:00' AND TIME<='"+str(date)+" 23:59:59') and (`Seen` = 0) ORDER BY `Vote` "

        cur.execute(call)
        data = cur.fetchall()
        mydb.close()
        self.ques_table = Databaze(server='10.61.3.223',username='2016FRA241G5',password='SzTGde9E9AxVaNXA',database='2016FRA241G5',use_unicode=True,charset='utf8')
        for i in range(0,len(data)):
            self.ques_table.CHANGE(table='Question Table',where=["Question ID",data[i][2]],column=["Seen"],to=[1])

        return data

    def callSProfile(self,Sid=0):# somethinglike "58340500075"
        mydb = MySQLdb.connect(host='10.61.3.223', user='2016FRA241G5', passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5',use_unicode=True,charset='utf8')
        Sid=str(Sid)
        cur = mydb.cursor()
        call = "SELECT `Status` FROM `Click Table` WHERE `Student ID`='58340500075'"
        call=call.replace("58340500075",Sid)
        cur.execute(call)

        data = cur.fetchall()
        lendata = len(data)

        call = "SELECT `Question` FROM `Question Table` WHERE `Student ID`='58340500075'"
        call=call.replace("58340500075", Sid)
        cur.execute(call)

        data0 = cur.fetchall()
        lendata0 = len(data0)

        returnthing = (int(Sid),lendata,lendata0,data0)#id,clicklenght,questionlenght,question

        mydb.close()
        return returnthing

class Databaze:

    #attribute.
    database = 0 #store database object.
    cur = 0 #store database cursor object.

    #initailise database from server which has username and password.
    def __init__(self,server='localhost',username='root',password='',database='zumodatabase',use_unicode=False,charset='utf8'):
        self.database = MySQLdb.connect(server, username , password ,database,use_unicode=use_unicode,charset=charset) #initailise database.
        self.cur = self.database.cursor() #initialise cursor.

    #select the (differant) select from table where column in IS tuple and print them (reverse) according to column order.
    def SELECT(self,select='*',table='*',column='',IS=(''),different = False,order='',reverse=False):
        SQL = "SELECT " #SQL store SQL command.
        if different: # check if you want to select the difference.
            SQL += "DISTINCT "
        SQL += "`"+select+"` "
        SQL += "FROM `"+table+ "` "
        if column != '': #check if you have condition.
            if type(IS) is tuple: # for multiple.
                isis = str(IS)
            else: #for only one.
                isis = "("+str(IS)+")"
            SQL += " WHERE `" + column + "` IN "+isis+" "
        if order != '': #check if you want to sort the information.
            SQL += "ORDER BY `"+order+"` "
            if reverse: #sort them reverse.
                SQL += "DESC "
            else: #sort them normally.
                SQL += "ASC "
        SQL = SQL[:-1]+";"
        self.cur.execute(SQL) #find by SQL language.
        return self.cur.fetchall() #list of the item you want.

    #count the (different) column which pass the condition from table.
    def COUNT(self,table='*',count='',column='',IS=(''),different=False):
        SQL = "SELECT COUNT(" #SQL store SQL command.
        if different: # check if you want to select the difference.
            SQL += " DISTINCT "
        SQL += count+") "
        SQL += "FROM `"+table+ "` "
        if column != '': #check if you have condition.
            if type(IS) is tuple: # for multiple.
                isis = str(IS)
            else: #for only one.
                isis = "("+str(IS)+")"
            SQL += " WHERE `" + column + "` IN "+isis+" "
        SQL = SQL[:-1]+";"
        self.cur.execute(SQL) #find by SQL language.
        return self.cur.fetchall()  #list of the item you want.

    # insert value i to column i in table.
    def ADD(self,table=None,column=[],value=[]):
        if (table is None) or (len(column) != len(value)): #checking error.
            if table is None: #printing error.
                print "error: insert to what?"
            elif len(column) != len(value):
                print "error: length of column and value isn't match"
        else:
            SQL = "INSERT "+"INTO `" +table + "`(`" #create SQL syntax.
            for element in column: #append each element in the column list to SQL syntax.
                SQL += str(element) + "` , `"
            SQL = SQL[:-3] + ") "
            SQL += "VALUES " + "("
            for element in value:
                if type(element) == int: #if element inside value list is integer then append it as interger.
                    SQL += str(element) + " , "
                else: #if element inside value list isn't integer then append it as string.
                    SQL += "'" +str(element) + "' , "
            SQL = SQL[:-2] + ");"
            self.cur.execute(SQL) #insert by SQL language.
            self.database.commit()  #commit change in sarver.

    #use your own SQL language
    def SQL(self,code):
        self.cur.execute(code) #code by SQL language.
        return self.cur.fetchall()  #list of the item you want.

    #change each element in fom list to each element in to list of table, and set condition where[0] = where[1].
    def CHANGE(self,table=None,column=[],to=[],where=[]):
        if (table==None): #printing error.
            print "error: insert to what?"
        elif (len(column) != len(to)): #printing error.
            print "error: length of fom and to isn't match"
        else: #no error.
            SQL = "UPDATE `"+table+"` SET " #set SQL syntax for changing.
            for i in range(0,len(column)): #loop through fom and to
                if type(to[i]) == int: #if element inside to list is integer then append it as interger.
                    SQL += "`"+str(column[i])+"`="+str(to[i])+" , "
                else: #if element inside to list isn't integer then append it as string.
                    SQL += "`"+str(column[i])+"`='"+str(to[i])+"' , "
            SQL = SQL [:-2]
            if where is not None: #check if condition exist.
                if type(where[1]) == int: #if where[1] is integer then append it as interger.
                    SQL += 'WHERE `'+str(where[0])+"`=" + str(where[1])+" "
                else: #if where[1] isn't integer then append it as string.
                    SQL += 'WHERE `'+str(where[0])+"`='" + str(where[1])+"' "
            self.cur.execute(SQL) #insert by SQL language.
            self.database.commit()  #commit change in sarver.


    #select the maximum value from column of table.
    def SELECT_MAX(self,table=None,column=''):
        if (table == None): #printing error.
            print "error: insert to what?"
        elif (column == None): #printing error.
            print "error: no column name ''"
        else:
            SQL = "SELECT MAX(`"+column+"`) FROM `"+table+"` "
            self.cur.execute(SQL) #insert by SQL language.
            return self.cur.fetchall()  #list of the item you want.

    #close database when you don't want to use it anymore.
    def Close(self):
        self.database.close()

    def monthToNum(self,shortMonth):

        return{'Jan' : 1,'Feb' : 2,'Mar' : 3,'Apr' : 4,'May' : 5,'Jun' : 6, 'Jul' : 7,'Aug' : 8,'Sep' : 9, 'Oct' : 10,'Nov' : 11,'Dec' : 12}[shortMonth]

'''#for testing.
a = []
db = Databaze(database = 'zumodatabase')
#a = db.SELECT(select='Stars',table='comment',column='IDuser',IS=(1,3),different=True,order='CommentID',reverse=True)
#a = db.COUNT(table='comment',count='IDcomment',column='Stars',IS=(3,4,5),different=True)
#a = db.CHANGE(table='comment',fom=['Stars','Comment'],to=[1,'hello'],where=['CommentID',3])
a = db.SELECT_MAX(table='comment',column='CommentID')
#a = db.INSERT(table='comment',column=['CommentID','IDuser','IDcomment','Comment','Stars','Date'],value=[7,2,1,"love it",5,'2016-10-24 11:34:00'])
for e in a:
    print e
db.Close()'''