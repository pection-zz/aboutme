from PyQt4 import QtCore, QtGui
from Final import Ui_Form
import time
import sys
from votegui import Ui_MainWindowVote
from questiongui import Ui_MainWindowQuestion
a=0
class HumanoidMainWindow(QtGui.QMainWindow,Ui_Form):


    def __init__(self, parent=None):
        super(HumanoidMainWindow, self).__init__(parent)
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.Action()

    def Action(self):
        QtCore.QObject.connect(self.ui.kaojai, QtCore.SIGNAL("clicked()"), self.GetdataTrue)
        QtCore.QObject.connect(self.ui.maikaojai,QtCore.SIGNAL("clicked()"), self.GetdataFalse)
        QtCore.QObject.connect(self.ui.vote, QtCore.SIGNAL("clicked()"), self.VoteTrue)
        QtCore.QObject.connect(self.ui.question, QtCore.SIGNAL("clicked()"), self.Question)

    def GetdataFalse(self):
        print "Get data Maikaojai"

    def GetdataTrue(self):
        print "Get data kaojai"

    def VoteTrue(self):
        WindowVote.show()


    def Question(self):
        Windowquestion.show()

class Votewindow(QtGui.QMainWindow,Ui_MainWindowVote):
    def __init__(self, parent=None):
        super(Votewindow, self).__init__(parent)
        self.ui = Ui_MainWindowVote()
        self.ui.setupUi(self)
        self.ActionVote()
    def ActionVote(self):
        QtCore.QObject.connect(self.ui.Vote1, QtCore.SIGNAL("clicked()"), self.GetVoteQuestion1)
        QtCore.QObject.connect(self.ui.Vote2, QtCore.SIGNAL("clicked()"), self.GetVoteQuestion2)
        QtCore.QObject.connect(self.ui.Vote3, QtCore.SIGNAL("clicked()"), self.GetVoteQuestion3)
        QtCore.QObject.connect(self.ui.Vote4, QtCore.SIGNAL("clicked()"), self.GetVoteQuestion4)

    def GetVoteQuestion1(self):
        print "DATA QUESTION1 +1"


    def GetVoteQuestion2(self):
        print "DATA QUESTION2 +1"


    def GetVoteQuestion3(self):
        print "DATA QUESTION3 +1"


    def GetVoteQuestion4(self):
        print "DATA QUESTION4 +1"


class Questionwindow(QtGui.QMainWindow,Ui_MainWindowQuestion):
    def __init__(self, parent=None):
        super(Questionwindow, self).__init__(parent)
        self.ui = Ui_MainWindowQuestion()
        self.ui.setupUi(self)
        self.ActionQuestion()
    def ActionQuestion(self):
        QtCore.QObject.connect(self.ui.Sendbutton, QtCore.SIGNAL("clicked()"), self.Send)
    def Send(self):
        print "send Question"




if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    MainWindow = HumanoidMainWindow()
    WindowVote = Votewindow()
    Windowquestion = Questionwindow()

    MainWindow.show()
    sys.exit(app.exec_())