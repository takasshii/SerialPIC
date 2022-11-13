import serial_send_pc_to_arduino as sp
import speech_to_text_api as st

result = st.speech_to_text_api()
sp.serial_send_pc_to_arduino(result)