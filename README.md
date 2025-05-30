# PlatformIO Starter for IoT Project

A modular and extensible PlatformIO project template, this project use ESP32 and Arduino framework as example, but you can easily modify to your choosen board and framework (ESP-IDF, ZephyrOS, etc.). This starter includes common IoT components such as WiFi, Cellular, MQTT, RS485, I2C/SPI, ADC/DAC, Crypto, OTA, Utilities like FIFO, Serial Print, and support for dev/prod configuration via `config.json`.

## 🚀 Features

- ✅ Modular library structure (`lib/`)
- ✅ Configurable via `config.json`
- ✅ Auto-generated `config.h` from `config.json`
- ✅ Supports development and production builds
- ✅ Library handlers for:
  - FIFO
  - Serial Print

## 🛠️ Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yansyaf/platformio-starter.git
cd platformio-starter
```

### 2. Configure Your Build

Copy the example config and edit it:

```bash
cp config.json.example config.json
```

Then modify `config.json` to suit your environment (e.g., enable/disable modules, change MQTT server, WiFi credentials, etc.).

### 3. Build and Upload

Use PlatformIO to build and upload:

```bash
# For development build
pio run -e dev

# For production build
pio run -e prod
```

To upload firmware over OTA (ensure the device is on the same network):

```bash
pio run -e dev -t upload
```

## 📂 Project Structure

```
├── include/                # Auto-generated config.h
├── lib/                    # Modular handlers
├── scripts/                # Custom build scripts (hook installers, config parser)
├── src/                    # Source code (main.cpp, logic)
├── config.json.example     # Example config file
├── platformio.ini          # PlatformIO configuration
```

## ✅ TODO

- Library handlers for:
  - WiFi
  - Cellular
  - MQTT
  - RS485
  - I2C
  - SPI
  - EEPROM
  - ADC
  - DAC
  - Crypto (SHA256, AES, HMAC via mbedtls)
  - OTA (Over The Air update)
- Integrated OTA firmware update
- Add automatic firmware versioning
- Add unit test and CI/CD support

## 📌 Notes

- Libraries are conditionally compiled using `#define USE_XYZ` flags from `config.h`.
- `config.h` is generated automatically from `config.json` during build.
- Git hooks and build customization are handled in `scripts/`.

## 📄 License

MIT

---

Feel free to fork and customize!
