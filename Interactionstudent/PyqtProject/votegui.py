# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'vote.ui'
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
a="kwai"
b="kwaieiei"
c="kwaimak"
d="Kwaimakamk"
class Ui_MainWindowVote(object):
    Question1_text=a
    Question2_text=b
    Question3_text=c
    Question4_text=d
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.textEdit = QtGui.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(30, 70, 581, 61))
        self.textEdit.setHtml(self.Question1_text)
        self.textEdit.setObjectName(_fromUtf8("textEdit"))
        self.textEdit_2 = QtGui.QTextEdit(self.centralwidget)
        self.textEdit_2.setGeometry(QtCore.QRect(30, 180, 581, 61))
        self.textEdit_2.setObjectName(_fromUtf8("textEdit_2"))
        self.textEdit_2.setHtml(self.Question2_text)
        self.textEdit_3 = QtGui.QTextEdit(self.centralwidget)
        self.textEdit_3.setGeometry(QtCore.QRect(30, 310, 581, 61))
        self.textEdit_3.setObjectName(_fromUtf8("textEdit_3"))
        self.textEdit_3.setHtml(self.Question3_text)

        self.textEdit_4 = QtGui.QTextEdit(self.centralwidget)
        self.textEdit_4.setGeometry(QtCore.QRect(30, 420, 581, 61))
        self.textEdit_4.setObjectName(_fromUtf8("textEdit_4"))
        self.textEdit_4.setHtml(self.Question4_text)

        self.Vote1 = QtGui.QPushButton(self.centralwidget)
        self.Vote1.setGeometry(QtCore.QRect(650, 90, 93, 28))
        self.Vote1.setObjectName(_fromUtf8("Vote1"))
        self.Vote2 = QtGui.QPushButton(self.centralwidget)
        self.Vote2.setGeometry(QtCore.QRect(660, 190, 93, 28))
        self.Vote2.setObjectName(_fromUtf8("Vote2"))
        self.Vote3 = QtGui.QPushButton(self.centralwidget)
        self.Vote3.setGeometry(QtCore.QRect(660, 330, 93, 28))
        self.Vote3.setObjectName(_fromUtf8("Vote3"))
        self.Vote4 = QtGui.QPushButton(self.centralwidget)
        self.Vote4.setGeometry(QtCore.QRect(670, 440, 93, 28))
        self.Vote4.setObjectName(_fromUtf8("Vote4"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.Vote1.setText(_translate("MainWindow", "Vote", None))
        self.Vote2.setText(_translate("MainWindow", "Vote", None))
        self.Vote3.setText(_translate("MainWindow", "Vote", None))
        self.Vote4.setText(_translate("MainWindow", "Vote", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindowVote()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

