#include <Arduino.h>
#include <BleKeyboard.h>
#include <BLEDevice.h>   // Native BLE
#include <BLESecurity.h> // Native BLE Security

BleKeyboard bleKeyboard("Selfie Stick", "Espressif", 100);

const int buttonPin = 0; // BOOT button on ESP32-S3-DevKitC-1
int lastButtonState = HIGH;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Starting Native Bluetooth Keyboard...");

  // Start the keyboard BEFORE setting security
  bleKeyboard.begin();

  // Configure BLE Security
  BLESecurity *pSecurity = new BLESecurity();

  // 1. Force a secure bond
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_BOND);

  // 2. The Magic Line: "I have no screen and no buttons to type a PIN"
  pSecurity->setCapability(ESP_IO_CAP_NONE);

  // 3. Set standard encryption protocols
  pSecurity->setInitEncryptionKey(ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK);
  // --------------------------------
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    int currentButtonState = digitalRead(buttonPin);

    // Check if the BOOT button was just pressed
    if (currentButtonState == LOW && lastButtonState == HIGH)
    {
      Serial.println("BOOT button pressed! Triggering shutter...");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      delay(200);
    }

    lastButtonState = currentButtonState;
  }
  delay(10);
}