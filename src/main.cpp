#include <MQUnifiedsensor.h>
#define MQ5_ANALOG_PIN 34  // Chân ADC đọc tín hiệu analog
#define MQ5_DIGITAL_PIN 27 // Chân digital cảnh báo mức cao

void setup() {
    Serial.begin(115200);
    pinMode(MQ5_DIGITAL_PIN, INPUT);
}

void loop() {
    int gasValue = analogRead(MQ5_ANALOG_PIN);  // Đọc giá trị từ MQ-5
    int gasDigital = digitalRead(MQ5_DIGITAL_PIN); // Đọc mức cảnh báo từ D0

    Serial.print("Gas Level (Analog): ");
    Serial.println(gasValue);

    if (gasDigital == HIGH) {
        Serial.println("Cảnh báo! Nồng độ khí gas cao!");
    } else {
        Serial.println("An toàn, không có khí gas rò rỉ.");
    }

    delay(1000);
}
