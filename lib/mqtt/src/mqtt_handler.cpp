
#ifdef USE_ARDUINO
#include <WiFi.h>
#include <PubSubClient.h>
#include <config.h>

// MQTT Broker settings from config.h
WiFiClient espClient;
PubSubClient client(espClient);

// Callback for received MQTT messages
std::function<void(const String&)> message_callback = nullptr;
void mqtt_set_message_callback(std::function<void(const String&)> cb) {
    message_callback = cb;
}

void callback(char* topic, byte* payload, unsigned int length) {
    String message;
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }

    Serial.print("Message received: ");
    Serial.println(message);

    if (message_callback) {
        message_callback(message);
    }
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Connecting to MQTT broker\n....\n");
        if (client.connect("ESP32Client", MQTT_USER, MQTT_PASS)) {
            Serial.println("MQTT connected");
            client.subscribe(MQTT_TOPIC_COMMAND);
            Serial.print("MQTT subscibed: ");
            Serial.println(MQTT_TOPIC_COMMAND);
        } else {
            Serial.print("MQTT connection failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 2 seconds");
            delay(2000);
        }
    }
}

void mqtt_init() {
    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);
}

void mqtt_send() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    client.publish(MQTT_TOPIC_DATA, MQTT_TEST_MESSAGE);
}

void mqtt_receive_loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}

#elif USE_ZEPHYR
#endif