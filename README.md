# SerialPICToArduinoToPC

### 機能
タクトスイッチを押すことで、PCからさまざまな音声が流すことができます。

### 背景
PICの授業で使用するために作成しました。
PCからPICにシリアル通信でデータを送りたかったのですが、シリアルケーブルが手元になかったため、
ArduinoUnoを経由させてシリアル通信を可能にするために作成しました。

### 使い方
1. PIC16F1709のRA4ピンをArduinoのRXpinに差し、ArudinoとPCを接続します。
2. PIC、Arudinoそれぞれにコードを書き込むことでPICからAruduinoへのシリアル通信、ArudinoからPCへの送信が行われます。
3. PCにてmain.pyを実行し、Aruduinoから送られてきたコードを受信できるようにします。
4. PICに接続されているタクトスイッチを押すことで、押されたタクトスイッチに応じてさまざまな音声が再生されます。

### 再生する音声ファイルについて
再生される音声ファイルは、機械音声です。

make_audio.pyのtextListを変更し、実行することで、さまざまなフレーズを喋らせることができます。

また、audioフォルダにあるaudioファイルを変更させることで再生する音声を変更することができます。

## 今後のアップデート予定
現在は、PIC側でポーリング処理を行うことで文字列の送信を行なっていますが、よりリアルタイム性を高めるため、割り込み処理を実装する予定です。

PIC側のファイルはIDEの関係で追加できていませんが、11月中には追加してgithub上で閲覧できるようにします。
