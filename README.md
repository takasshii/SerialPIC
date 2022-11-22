# パスタ作ったお前ボタン

### 機能
タクトスイッチを押すことで、PCからさまざまな音声が流すことができます。
1番のボタンを押すと、「パスタ作ったお前」という音声が流れるため、ゲームもすることができます。

### デモ

https://user-images.githubusercontent.com/83356340/203395842-081992a6-6c37-4ed2-b0ee-3e9fd1784600.MOV

パスタ作ったお前ボタンのデモ↓


<blockquote class="twitter-tweet"><p lang="ja" dir="ltr">「パスタ作ったお前」ボタン作った <a href="https://t.co/08ejNOptQf">pic.twitter.com/08ejNOptQf</a></p>&mdash; たかっしー（開発垢） (@takashiho_2) <a href="https://twitter.com/takashiho_2/status/1594675807254740992?ref_src=twsrc%5Etfw">November 21, 2022</a></blockquote>

### 背景
PICの授業で使用するために作成しました。
PCからPICにシリアル通信でデータを送りたかったのですが、シリアルケーブルが手元になかったため、
ArduinoUnoを経由させてシリアル通信を可能にするために作成しました。

### 使い方
1. PIC16F1709のRA4ピンをArduinoのRXpinに差し、ArudinoとPCを接続します。
2. PIC、Arudinoそれぞれにコードを書き込むことでPICからAruduinoへのシリアル通信、ArudinoからPCへの送信が行われます。
3. PCにてmain.pyを実行し、Aruduinoから送られてきたコードを受信できるようにします。
4. PICに接続されているタクトスイッチを押すことで、押されたタクトスイッチに応じてさまざまな音声が再生されます。

パスタ作ったお前ボタンとして使う場合は、入っている音声ファイルを再生し、その音声に合わせて「パスタ作ったお前」の流れるボタンを押してください。

### 構成
![pic](https://user-images.githubusercontent.com/83356340/203396525-74632d28-2046-4e6d-82b5-f6493f61bdfd.png)



### 再生する音声ファイルについて
再生される音声ファイルは、機械音声です。

make_audio.pyのtextListを変更し、実行することで、さまざまなフレーズを喋らせることができます。

また、audioフォルダにあるaudioファイルを変更させることで再生する音声を変更することができます。

## 今後のアップデート予定
なし
