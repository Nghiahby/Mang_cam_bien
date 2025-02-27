#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(); // Khởi tạo I2C (mặc định SDA: GPIO21, SCL: GPIO22)
    
    if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("BH1750 OK!");
    } else {
        Serial.println("BH1750 Error!");
    }
}

void loop() {
    float lux = lightMeter.readLightLevel();
    Serial.print("Ánh sáng: ");
    Serial.print(lux);
    Serial.println(" lx");

    delay(1000);
}
