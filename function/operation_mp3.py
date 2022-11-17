from playsound import playsound
import os


def operation_mp3(bit):
  path = ("/Users/takashi/programing/exp_pic/audio/%s.mp3" % bit)
  if (os.path.exists(path)):
    playsound("audio/%s.mp3" %bit)

