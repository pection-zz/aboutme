# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mikeeiei.ui'
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

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(954, 600)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.formLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.formLayoutWidget.setGeometry(QtCore.QRect(80, 240, 160, 141))
        self.formLayoutWidget.setObjectName(_fromUtf8("formLayoutWidget"))
        self.formLayout = QtGui.QFormLayout(self.formLayoutWidget)
        self.formLayout.setObjectName(_fromUtf8("formLayout"))
        self.kaojai = QtGui.QPushButton(self.formLayoutWidget)
        self.kaojai.setStyleSheet(_fromUtf8("int main(int argc, char *argv[])\n"
"\n"
"#upLeft {\n"
"background-color: transparent;\n"
"border-image: url(:/images/frame.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"{\n"
"border-image: url(:mike2.jpg);\n"
"}"))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(_fromUtf8(":/mike/mike.jpg")), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.kaojai.setIcon(icon)
        self.kaojai.setObjectName(_fromUtf8("kaojai"))
        self.formLayout.setWidget(0, QtGui.QFormLayout.LabelRole, self.kaojai)
        self.maikaojai = QtGui.QPushButton(self.formLayoutWidget)
        self.maikaojai.setObjectName(_fromUtf8("maikaojai"))
        self.formLayout.setWidget(1, QtGui.QFormLayout.LabelRole, self.maikaojai)
        self.vote = QtGui.QPushButton(self.formLayoutWidget)
        self.vote.setObjectName(_fromUtf8("vote"))
        self.formLayout.setWidget(2, QtGui.QFormLayout.LabelRole, self.vote)
        self.question = QtGui.QPushButton(self.formLayoutWidget)
        self.question.setObjectName(_fromUtf8("question"))
        self.formLayout.setWidget(3, QtGui.QFormLayout.LabelRole, self.question)
        self.frame = QtGui.QFrame(self.centralwidget)
        self.frame.setGeometry(QtCore.QRect(0, 0, 331, 161))
        self.frame.setFrameShape(QtGui.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtGui.QFrame.Raised)
        self.frame.setObjectName(_fromUtf8("frame"))
        self.tabWidget = QtGui.QTabWidget(self.frame)
        self.tabWidget.setGeometry(QtCore.QRect(100, 110, 135, 80))
        self.tabWidget.setObjectName(_fromUtf8("tabWidget"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.tabWidget.addTab(self.tab, _fromUtf8(""))
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName(_fromUtf8("tab_2"))
        self.tabWidget.addTab(self.tab_2, _fromUtf8(""))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(60, 100, 831, 271))
        self.label.setText(_fromUtf8(""))
        self.label.setPixmap(QtGui.QPixmap(_fromUtf8("")))
        self.label.setObjectName(_fromUtf8("label"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.toolBar = QtGui.QToolBar(MainWindow)
        self.toolBar.setObjectName(_fromUtf8("toolBar"))
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.toolBar)
        self.actionSend = QtGui.QAction(MainWindow)
        self.actionSend.setIcon(icon)
        self.actionSend.setObjectName(_fromUtf8("actionSend"))
        self.toolBar.addAction(self.actionSend)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.kaojai.setText(_translate("MainWindow", "PushButton", None))
        self.maikaojai.setText(_translate("MainWindow", "PushButton", None))
        self.vote.setText(_translate("MainWindow", "PushButton", None))
        self.question.setText(_translate("MainWindow", "d", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("MainWindow", "Tab 1", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("MainWindow", "Tab 2", None))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar", None))
        self.actionSend.setText(_translate("MainWindow", "send", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

