# MD0587 测试代码说明


> **运行说明：** Arduino 示例只执行 USB 串口与蓝牙模块 UART 的双向透传，上电初始化后不额外打印启动提示。串口监视器只显示蓝牙端实际发送的数据；在串口监视器中输入的内容仍会转发至蓝牙端。

| 目录 | 适用环境 | 依赖 |
|---|---|---|
| `arduino_esp32/` | 经典 ESP32 DevKit、Arduino 框架 | 无第三方库；使用 Arduino-ESP32 自带 `HardwareSerial` |
| `micropython_esp32/` | 经典 ESP32 DevKit、MicroPython | 无第三方库；使用固件自带 `machine.UART` |

两个示例均使用 **GPIO16 作为 ESP32 RX**、**GPIO17 作为 ESP32 TX**，并以 **9600 baud 作为首次测试值**。HC-06 兼容板可能因固件和批次不同而采用其他串口参数；无响应或乱码时，应先检查交叉接线与共地，再修改代码中的 `HC06_BAUD` 逐一验证常见速率，而不是直接执行未知 AT 指令。

MicroPython 版本依据本批次实测，使用 `rx=RX_PIN`、`tx=TX_PIN` 直接向 `machine.UART` 传入 GPIO 编号。请勿改回 `rx=Pin(RX_PIN)`、`tx=Pin(TX_PIN)`；该包装写法会在本次测试所用 ESP32 MicroPython 固件中触发 UART 初始化错误。
