#ifndef MQTT_H
#define MQTT_H

#ifdef USE_ARDUINO

#include <Arduino.h>
#include <functional>

void mqtt_setup();
void mqtt_send();
void mqtt_receive_loop();
void mqtt_set_message_callback(std::function<void(const String&)> cb);

#endif

#endif