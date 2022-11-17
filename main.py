import function.classify_serial as cs
import function.speech_to_text_api as st
import function.operation_mp3 as om
import asyncio
import serial


async def play_audio(bit):
    om.operation_mp3(bit)


# パソコンからarduinoへシリアル通信を行う関数
async def serial_send_pc_to_arduino():
    ser = serial.Serial('/dev/cu.usbmodem14101', 9600, timeout=None)
    while (1):
        resultText = ser.readline()
        temp = resultText.strip().decode('UTF-8')
        print(temp)
        await play_audio(temp)
    ser.close()

async def main():
    await serial_send_pc_to_arduino()

asyncio.run(main())
