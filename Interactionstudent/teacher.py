import sys
from PyQt4 import QtGui, QtCore


class Window(QtGui.QMainWindow):
    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(1120, 50, 220, 620)
        self.setWindowTitle("RT APPICATION!")
        self.setWindowIcon(QtGui.QIcon('ccc.jpg'))

        self.styleChoice = QtGui.QLabel("FRA241", self)
        self.styleChoice.setGeometry(90, 10, 180, 20)

        self.pushButtonWindow = QtGui.QPushButton(self)
        self.pushButtonWindow.setText("FLIE")
        self.pushButtonWindow.setGeometry(20, 130, 180, 50)


        self.pushButtonWindow = QtGui.QPushButton(self)
        self.pushButtonWindow.setText("MINI QUIZ")
        self.pushButtonWindow.setGeometry(20, 230, 180, 50)

        self.pushButtonWindow = QtGui.QPushButton(self)
        self.pushButtonWindow.setText("STUDENT PROFLIE")
        self.pushButtonWindow.setGeometry(20, 330, 180, 50)

        self.pushButtonWindow = QtGui.QPushButton(self)
        self.pushButtonWindow.setText("DATABASE")
        self.pushButtonWindow.setGeometry(20, 430, 180, 50)

        self.pushButtonWindow = QtGui.QPushButton(self)
        self.pushButtonWindow.setText("QUESTION")
        self.pushButtonWindow.setGeometry(20, 530, 180, 50)








app = QtGui.QApplication(sys.argv)
GUI = Window()
GUI.show()
sys.exit(app.exec_())

