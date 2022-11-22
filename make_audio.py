import function.text_to_speech as tt

# 音声ファイルの設定を行う
def init():
    textList = ["こんにちは", "わーい", "つかれた", "やっほー", "割り込み"]
    tt.text_to_speech(textList)

def main():
  init()

main()
