import time
import serial

# パソコンからarduinoへシリアル通信を行う関数
def serial_send_pc_to_arduino(resultText):
    with serial.Serial('/dev/cu.usbmodem14101') as ser:
        time.sleep(5.0)
        ser.write(resultText.encode())
        print(resultText)
        time.sleep(1.0)
