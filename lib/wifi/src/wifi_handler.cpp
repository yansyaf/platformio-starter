#include "wifi_handler.h"

#ifdef USE_ARDUINO
#include <WiFi.h>
#include <config.h>  // for WIFI_SSID and WIFI_PASSWORD

void wifi_connect() {
    Serial.print("\nConnecting to WiFi: ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}
#endif