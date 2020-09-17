# -*- coding: utf-8 -*-

from PyQt4 import QtCore, QtGui

from Realtime_T_First import DETAIL
from Realtime_T_Subjectselect import MAINWINDOW
from Quiz import QUIZ
from Realtime_T_Class import Classprofile
from Realtime_T_Student import STUDENT
from Realtime_T_Question import QUESTIONSTUDENT
import time

from add import ADD
from Q import Q
import sys

class start_teacher(QtGui.QMainWindow,MAINWINDOW,DETAIL,QUIZ,Classprofile,STUDENT, QUESTIONSTUDENT,ADD,Q):

        chk = False
        datdy = "2016-22-11"
        timy = "00:00:00"

        def __init__(self, parent=None):
            super(start_teacher,self).__init__(parent)
            self.a=0    #fra...
            self.q=0    #question...
            self.mainwindow = MAINWINDOW()
            self.detail = DETAIL()
            self.quiz = QUIZ()
            self.questionstudent= QUESTIONSTUDENT()
            self.classprofile = Classprofile()
            self.student = STUDENT()
            self.open_mainwindow()
            self.addpage = ADD()
            self.question = Q()


        def open_mainwindow(self):
            self.mainwindow.setupUi(self)
            QtCore.QObject.connect(self.mainwindow.FRA141, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(141))
            QtCore.QObject.connect(self.mainwindow.FRA142, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(142))
            QtCore.QObject.connect(self.mainwindow.FRA162, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(162))
            QtCore.QObject.connect(self.mainwindow.FRA221, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(221))
            QtCore.QObject.connect(self.mainwindow.FRA241, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(241))
            QtCore.QObject.connect(self.mainwindow.FRA351, QtCore.SIGNAL("clicked()"), lambda : self.ifsubject(351))
            time.sleep(2)

        def ifsubject(self,id):
            self.a = id
            self.open_detail()

        def open_detail(self):
            self.detail.setupUi(self,self.a)
            QtCore.QObject.connect(self.detail.CLASSPROFILE, QtCore.SIGNAL("clicked()"),self.open_classprofile)
            QtCore.QObject.connect(self.detail.STUDENTPROFILE, QtCore.SIGNAL("clicked()"), self.open_student)
            QtCore.QObject.connect(self.detail.SHOWQUESTION, QtCore.SIGNAL("clicked()"), self.open_questionstudent)
            QtCore.QObject.connect(self.detail.back1, QtCore.SIGNAL("clicked()"), self.open_mainwindow)


        def open_quiz(self):
            self.quiz.setupUi(self)

            QtCore.QObject.connect(self.quiz.question1, QtCore.SIGNAL("clicked()"), self.ifq1)
            QtCore.QObject.connect(self.quiz.question2, QtCore.SIGNAL("clicked()"), self.ifq2)
            QtCore.QObject.connect(self.quiz.question3, QtCore.SIGNAL("clicked()"), self.ifq3)
            QtCore.QObject.connect(self.quiz.questoin4, QtCore.SIGNAL("clicked()"), self.ifq4)
            QtCore.QObject.connect(self.quiz.back, QtCore.SIGNAL("clicked()"), self.open_detail)
            QtCore.QObject.connect(self.quiz.add, QtCore.SIGNAL("clicked()"), self.open_addpage)

        def newf(self):

            lis = self.classprofile.func()
            self.datdy = lis[0]
            self.timy = lis[1]

        def write_txtfile(self,lisy):
            text_file = open("RealtimeDownload"+'.txt', "w")
            text_file.write(lisy.encode("utf-8"))
            text_file.close()

        def open_classprofile(self):
            if self.chk:
                date,tim,queslist = self.classprofile.setupUi(self,self.a,self.datdy,self.timy)
            else:
                date,tim,queslist = self.classprofile.setupUi(self,self.a,"2016-11-22","00:00:00")
                self.chk = True
            self.datdy = date
            self.timy = tim

            QtCore.QObject.connect(self.classprofile.ok, QtCore.SIGNAL("clicked()"),self.newf)
            QtCore.QObject.connect(self.classprofile.pri, QtCore.SIGNAL("clicked()"),lambda: self.write_txtfile(queslist))
            QtCore.QObject.connect(self.classprofile.ok, QtCore.SIGNAL("clicked()"),self.open_classprofile)
            QtCore.QObject.connect(self.classprofile.back, QtCore.SIGNAL("clicked()"), self.open_detail)

        def open_student(self):
            self.student.setupUi(self)
            QtCore.QObject.connect(self.student.send, QtCore.SIGNAL("clicked()"), self.open_student)
            QtCore.QObject.connect(self.student.back, QtCore.SIGNAL("clicked()"), self.open_detail)

        def open_questionstudent(self):
            self.questionstudent.setupUi(self,self.a)

            QtCore.QObject.connect(self.questionstudent.back, QtCore.SIGNAL("clicked()"), self.open_detail)


        def open_addpage(self):
            self.addpage.setupUi(self)

            QtCore.QObject.connect(self.addpage.send, QtCore.SIGNAL("clicked()"), self.open_addpage)
            QtCore.QObject.connect(self.addpage.back, QtCore.SIGNAL("clicked()"), self.open_detail)

        def ifq1(self):
            self.q=1
            self.open_question()

        def ifq2(self):
            self.q=2
            self.open_question()

        def ifq3(self):
            self.q=3
            self.open_question()

        def ifq4(self):
            self.q=4
            self.open_question()


        def open_question(self):
            self.question.setupUi(self)
            QtCore.QObject.connect(self.question.back, QtCore.SIGNAL("clicked()"), self.open_quiz)



if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    main = start_teacher()
    main.show()
    sys.exit(app.exec_())


