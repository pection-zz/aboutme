# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'StudentProfile.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_student(object):
    def setupUi(self, student):
        student.setObjectName(_fromUtf8("student"))
        student.resize(316, 489)
        self.centralwidget = QtGui.QWidget(student)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(20, 40, 151, 41))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(20, 90, 281, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.label_3 = QtGui.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(20, 140, 211, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_3.setFont(font)
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.label_4 = QtGui.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(20, 190, 211, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_4.setFont(font)
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.label_5 = QtGui.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(20, 240, 211, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_5.setFont(font)
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.label_6 = QtGui.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(20, 290, 211, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_6.setFont(font)
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.label_7 = QtGui.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(20, 350, 111, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_7.setFont(font)
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.lineEdit = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(20, 390, 251, 20))
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        self.back = QtGui.QPushButton(self.centralwidget)
        self.back.setGeometry(QtCore.QRect(200, 420, 75, 23))
        self.back.setObjectName(_fromUtf8("back"))
        self.back_2 = QtGui.QPushButton(self.centralwidget)
        self.back_2.setGeometry(QtCore.QRect(20, 420, 75, 23))
        self.back_2.setObjectName(_fromUtf8("back_2"))
        self.lineEdit_2 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(240, 300, 61, 20))
        self.lineEdit_2.setObjectName(_fromUtf8("lineEdit_2"))
        self.lineEdit_3 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(240, 250, 61, 20))
        self.lineEdit_3.setObjectName(_fromUtf8("lineEdit_3"))
        self.lineEdit_4 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_4.setGeometry(QtCore.QRect(240, 200, 61, 20))
        self.lineEdit_4.setObjectName(_fromUtf8("lineEdit_4"))
        self.lineEdit_5 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_5.setGeometry(QtCore.QRect(240, 150, 61, 20))
        self.lineEdit_5.setObjectName(_fromUtf8("lineEdit_5"))
        student.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(student)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 316, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        student.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(student)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        student.setStatusBar(self.statusbar)

        self.retranslateUi(student)
        QtCore.QMetaObject.connectSlotsByName(student)

    def retranslateUi(self, student):
        student.setWindowTitle(_translate("student", "MainWindow", None))
        self.label.setText(_translate("student", "Student Profile", None))
        self.label_2.setText(_translate("student", "รหัสนักศึกษา : ", None))
        self.label_3.setText(_translate("student", "จำนวน Mini Quiz ที่ตอบ        :  ", None))
        self.label_4.setText(_translate("student", "จำนวนข้อปรนัยที่ตอบ            :  ", None))
        self.label_5.setText(_translate("student", "จำนวนข้ออัตนัยที่ตอบ           :", None))
        self.label_6.setText(_translate("student", "จำนวนคำถามที่ถามอาจารย์    : ", None))
        self.label_7.setText(_translate("student", "Student Code", None))
        self.lineEdit.setText(_translate("student", "58340500001", None))
        self.back.setText(_translate("student", "Send", None))
        self.back_2.setText(_translate("student", "BACK", None))

if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    student = QtGui.QMainWindow()
    ui = Ui_student()
    ui.setupUi(student)
    student.show()
    sys.exit(app.exec_())

