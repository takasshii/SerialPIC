import function.text_to_speech as tt

# 音声ファイルの設定を行う
def init():
    textList = ["こんにちは", "こんにちは", "こんにちは", "こんにちは", "こんにちは"]
    tt.text_to_speech(textList)

def main():
  init()

main()
