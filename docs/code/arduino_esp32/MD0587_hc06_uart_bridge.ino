/*
 * MD0587 - HC-06 兼容蓝牙串口模块透传测试
 * 平台：经典 ESP32 DevKit（Arduino 框架）
 * 第三方库：不需要
 *
 * 接线：
 *   HC-06 TXD -> ESP32 GPIO16（RX）
 *   HC-06 RXD <- ESP32 GPIO17（TX）
 *   GND        -> ESP32 GND
 *   VCC        -> 按模块底板丝印/供应批次要求供电
 */

#include <Arduino.h>

HardwareSerial HC06(2);

constexpr int HC06_RX_PIN = 16;
constexpr int HC06_TX_PIN = 17;
// 9600 仅作为首次测试值。若无输出或乱码，请按文档修改并逐一验证常见速率。
constexpr uint32_t HC06_BAUD = 9600;
constexpr uint32_t USB_BAUD = 115200;

void setup() {
  Serial.begin(USB_BAUD);
  delay(300);
  HC06.begin(HC06_BAUD, SERIAL_8N1, HC06_RX_PIN, HC06_TX_PIN);

}

void loop() {
  while (Serial.available() > 0) {
    HC06.write(Serial.read());
  }

  while (HC06.available() > 0) {
    Serial.write(HC06.read());
  }

  delay(1);
}
