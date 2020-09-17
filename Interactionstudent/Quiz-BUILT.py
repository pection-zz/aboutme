# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Quiz.ui'
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

class QUIZ(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(288, 548)
        MainWindow.setStyleSheet(_fromUtf8("\n"
"border-color: rgb(85, 255, 0);"))
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(30, 100, 231, 361))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.question1 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.question1.sizePolicy().hasHeightForWidth())
        self.question1.setSizePolicy(sizePolicy)
        self.question1.setObjectName(_fromUtf8("question1"))
        self.verticalLayout.addWidget(self.question1)
        self.question2 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.question2.sizePolicy().hasHeightForWidth())
        self.question2.setSizePolicy(sizePolicy)
        self.question2.setObjectName(_fromUtf8("question2"))
        self.verticalLayout.addWidget(self.question2)
        self.question3 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.question3.sizePolicy().hasHeightForWidth())
        self.question3.setSizePolicy(sizePolicy)
        self.question3.setObjectName(_fromUtf8("question3"))
        self.verticalLayout.addWidget(self.question3)
        self.questoin4 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.questoin4.sizePolicy().hasHeightForWidth())
        self.questoin4.setSizePolicy(sizePolicy)
        self.questoin4.setObjectName(_fromUtf8("questoin4"))
        self.verticalLayout.addWidget(self.questoin4)
        self.pictureQuiz = QtGui.QPushButton(self.centralwidget)
        self.pictureQuiz.setGeometry(QtCore.QRect(50, 20, 191, 71))
        self.pictureQuiz.setStyleSheet(_fromUtf8("#pictureQuiz {\n"
"background-color: transparent;\n"
"border-image: url(C:/Users/Bayguilt/PycharmProjects/FRA241/mainproject/a.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#pictureQuiz:pressed\n"
"{\n"
"border-image: url(C:/Users/Bayguilt/PycharmProjects/FRA241/mainproject/a.png);\n"
"}"))
        self.pictureQuiz.setText(_fromUtf8(""))
        self.pictureQuiz.setObjectName(_fromUtf8("pictureQuiz"))
        self.back = QtGui.QPushButton(self.centralwidget)
        self.back.setGeometry(QtCore.QRect(40, 470, 75, 31))
        self.back.setObjectName(_fromUtf8("back"))

        self.add = QtGui.QPushButton(self.centralwidget)
        self.add.setGeometry(QtCore.QRect(180, 470, 75, 31))
        self.add.setObjectName(_fromUtf8("add"))

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 288, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.question1.setText(_translate("MainWindow", "Question 1", None))
        self.question2.setText(_translate("MainWindow", "Question 2", None))
        self.question3.setText(_translate("MainWindow", "Question 3", None))
        self.questoin4.setText(_translate("MainWindow", "Question 4", None))
        self.back.setText(_translate("MainWindow", "BACK", None))
        self.add.setText(_translate("MainWindow", "ADD", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = QUIZ()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

