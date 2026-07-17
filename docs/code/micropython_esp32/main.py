"""
MD0587 - HC-06 兼容蓝牙串口模块收发测试
平台：经典 ESP32 DevKit + MicroPython
第三方库：不需要

接线：
  HC-06 TXD -> ESP32 GPIO16（RX）
  HC-06 RXD <- ESP32 GPIO17（TX）
  GND        -> ESP32 GND
  VCC        -> 按模块底板丝印/供应批次要求供电
"""

from machine import UART
import time

RX_PIN = 16
TX_PIN = 17
# 9600 仅作为首次测试值；如无输出或乱码，请按文档调整。
HC06_BAUD = 9600

bluetooth_uart = UART(
    2,
    baudrate=HC06_BAUD,
    bits=8,
    parity=None,
    stop=1,
    rx=RX_PIN,
    tx=TX_PIN,
)

counter = 0
print("HC-06 UART test started at", HC06_BAUD, "baud")
print("Incoming Bluetooth data will be printed in the MicroPython console.")

while True:
    message = "ESP32 HC-06 test {}\r\n".format(counter)
    bluetooth_uart.write(message)

    time.sleep_ms(200)
    if bluetooth_uart.any():
        received = bluetooth_uart.read()
        print("RX:", received)

    counter += 1
    time.sleep_ms(800)
