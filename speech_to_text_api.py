import speech_recognition as sr

def speech_to_text_api():
    # apiキーの呼び出し
    with open("/Users/takashi/programing/api-key/forward-citron-368505-056b2be6bf19.json") as f:
        credentials = f.read()

    # マイクから音声を認識する
    r = sr.Recognizer()
    with sr.Microphone(sample_rate=16_000) as source:
        print("なにか話してください")
        audio = r.listen(source)
        print("音声を取得しました")

    # マイクから得られた音声をもとにapi通信を行なって結果を返す
    recognized_text = r.recognize_google_cloud(
        audio, credentials, language="en-US"
    )
    return recognized_text.strip()
