# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Questionformstuden.ui'
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

class Ui_QuestionFormStudent_2(object):
    def setupUi(self, QuestionFormStudent_2):
        QuestionFormStudent_2.setObjectName(_fromUtf8("QuestionFormStudent_2"))
        QuestionFormStudent_2.resize(331, 501)
        self.centralwidget = QtGui.QWidget(QuestionFormStudent_2)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(30, 30, 261, 391))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.QuestionFormStudent = QtGui.QTextBrowser(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.QuestionFormStudent.sizePolicy().hasHeightForWidth())
        self.QuestionFormStudent.setSizePolicy(sizePolicy)
        self.QuestionFormStudent.setObjectName(_fromUtf8("QuestionFormStudent"))
        self.verticalLayout.addWidget(self.QuestionFormStudent)
        QuestionFormStudent_2.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(QuestionFormStudent_2)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 331, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        QuestionFormStudent_2.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(QuestionFormStudent_2)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        QuestionFormStudent_2.setStatusBar(self.statusbar)

        self.retranslateUi(QuestionFormStudent_2)
        QtCore.QMetaObject.connectSlotsByName(QuestionFormStudent_2)

    def retranslateUi(self, QuestionFormStudent_2):
        QuestionFormStudent_2.setWindowTitle(_translate("QuestionFormStudent_2", "MainWindow", None))
        self.QuestionFormStudent.setHtml(_translate("QuestionFormStudent_2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'MS Shell Dlg 2\'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; text-decoration: underline;\">คำถาม</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; text-decoration: underline;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", None))



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    QuestionFormStudent_2 = QtGui.QMainWindow()
    ui = Ui_QuestionFormStudent_2()
    ui.setupUi(QuestionFormStudent_2)
    QuestionFormStudent_2.show()
    sys.exit(app.exec_())

