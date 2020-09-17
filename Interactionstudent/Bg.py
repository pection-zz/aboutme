from PyQt4 import QtCore, QtGui
from lower import Ui_MainWindow
import time
import serial
import sys
import serial.tools.list_ports

class application_Mainwindow(QtGui.QMainWindow,Ui_MainWindow):

    def __init__(self, parent=None):
        super(application_Mainwindow, self).__init__(parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    MainWindow = application_Mainwindow()


    MainWindow.show()
    sys.exit(app.exec_())


