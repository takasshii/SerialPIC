from gtts import gTTS


def text_to_speech(textList):
    i = 0
    for text in textList:
        i+=1
        tts = gTTS(text, lang='ja')
        tts.save('audio/%s.mp3' % i)
