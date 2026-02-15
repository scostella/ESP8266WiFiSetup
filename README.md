# ESP8266WiFiSetup

ESP8266 sketch that acts as a **Wi‑Fi to Serial TCP bridge** for **JMRI C/MRI**
communications.  
This sketch allows JMRI to communicate with an Arduino Mega C/MRI node over
Wi‑Fi instead of a direct serial or RS‑485 connection.

The ESP8266 listens for an incoming TCP connection on port 9006 from JMRI and transparently
forwards data between the network socket and the Mega’s Serial3 interface.

---

## Overview

This sketch:

- Runs on an **ESP8266**
- Connects to a Wi‑Fi network using credentials stored in `arduino_secrets.h` (Example file provided)
- Opens a **TCP server (default port 9006)** for JMRI
- Forwards all TCP data ↔ Serial data transparently
- Provides a **JMRI connection status output pin** to the Arduino Mega
- Designed to pair with an **Arduino Mega running a C/MRI sketch**

This creates a simple and reliable **Wi‑Fi C/MRI link** between JMRI and the
layout hardware.

---

## Limited Liability and Disclaimer

This project is provided as an **open‑source hardware design** and is offered **as‑is**, without warranty of any kind.

By using this design, documentation, or any assembled hardware provided by the author, you agree to the following:

- You assume **all responsibility** for proper electrical design, wiring, installation, and use
- The author makes **no guarantees** regarding suitability for any specific application
- The author shall not be held liable for:
  - Damage to equipment
  - Electrical failures
  - Personal injury
  - Property damage
  - Losses resulting from improper use, installation, or modification

Use of this project or any associated hardware constitutes acceptance of these terms.

---

## Reference Projects

This project integrates with the Arduino CMRI ecosystem. The following projects provide related hardware, firmware, and configuration support:

- **Arduino Mega CMRI WiFi**  
  Arduino sketch for Mega 2560 to operate as CMRI Node with an ESP8266-ESP01 providing WiFi connectivity.
  https://github.com/scostella/Arduino_Mega_CMRI_WiFi

- **ESP8266 WiFi Setup Utility**  
  ESP sketch to program the ESP8266-ESP01 to work with the Arduino Mega 2560 and connection configuration for your WiFi network.
  https://github.com/scostella/ESP8266WiFiSetup

- **Arduino Mega CMRI WiFi Shield**  
  KiCad design for a shield for the Arduino Mega 2560 facilitating easy integration with the ESP8266-ESP01 and the CMRI modules listed below.
  https://github.com/scostella/Arduino_Mega_CMRI_WiFi_Shield

- **Arduino Accessory Controller**  
  KiCad design for a board to control accessories up to 1 amp.
  https://github.com/scostella/Arduino-Accessory-Controller

- **Arduino IR Sensor Module - 8 Port**  
  KiCad design for a board to use TCRT5000 IR module to sense object presence which can also be used in the Arduino Mega CMRI WiFi module to group sensors to create virtual block detection.
  https://github.com/scostella/Arduino_IR_Sensor_Module_-_8_Port

- **Arduino Tortoise Controller with Feedback - 8 Port**  
  KiCad design for a board to control Circuitron Tortoise Slow Motion Switch machines and provide feedback on switch position either controlled internally by the voltage applied to the tortoise or an external signal.
  https://github.com/scostella/Arduino_Tortoise_Controller_with_Feedback_-_8_Port

- **Arduino Light Controller**  
  KiCad design for a board to control low amperage lighting and other loads (<10ma) using the Arduino's 5V source.
  https://github.com/scostella/Arduino-Light-Controller

These projects may be used together to form a complete CMRI‑controlled lighting and I/O system.

---

## Repository Contents

```text
/
├── Arduino Tortoise Controller with Feedback - 8 Port.kicad_pcb        # KiCad PCB Layout
├── Arduino Tortoise Controller with Feedback - 8 Port.kicad_prl        # KiCad Project Settings
├── Arduino Tortoise Controller with Feedback - 8 Port.kicad_pro        # KiCad Project
├── Arduino Tortoise Controller with Feedback - 8 Port.kicad_sch        # KiCad Schematics
├── PowerLED.kicad_sch                                                  # KiCad Power and LED module
├── Tortoise-1.kicad_sch                                                # KiCad Tortoise control module
├── Arduino Tortoise Controller with Feedback - 8 Port.jpg              # Board Rendering
└── README.md                                                           # This file
