# AVR Bare-Metal Gas Detection System

## 1. Overview
This project implements an embedded gas monitoring system for the **ATmega328P** (Arduino Uno) using **Bare-Metal C**. By bypassing high-level libraries and interacting directly with microcontroller registers, the system achieves maximum efficiency and a minimal memory footprint.

The system interfaces with an **MQ-135 sensor** to detect harmful gases like CO and Alcohol, providing real-time feedback via an **I2C LCD** and a **UART** serial interface. A hardware buzzer is integrated to provide immediate audible alerts when gas concentrations exceed safety thresholds.

---

## 2. Hardware & Software Representation

### Hardware Components
| Component | Function | Connection |
| :--- | :--- | :--- |
| **ATmega328P** | Main MCU | Core |
| **MQ-135** | Gas Detection (Analog) | ADC Channel 1 (A1) |
| **16x2 LCD** | Visual Display | I2C (SDA/SCL) |
| **Buzzer** | Audible Alert | Digital Pin PD7 |
| **FTDI/USB** | Serial Monitoring | UART (RX/TX) |

### Development Environment
* **IDE:** Microchip Studio (formerly Atmel Studio)
* **Toolchain:** AVR-GCC
* **Programming:** AVRDUDE (via Arduino Uno Bootloader)

---

## 3. Project Implementation

### Driver Architecture Structure
The firmware follows a modular layered approach (MCAL -> HAL -> APP) to ensure code reusability and portability.

```text
avr-gas-detection-driver/
├── MCAL/ (Microcontroller Abstraction Layer)
│   ├── DIO/            # Digital I/O Register-level Control
│   ├── ADC/            # 10-bit Analog to Digital Conversion
│   ├── TWI/            # I2C (Two-Wire Interface) Communication
│   ├── UART/           # Asynchronous Serial Communication
│   ├── DELAY/          # Hardware-accurate Timing Functions
│   └── Macros/         # Bit-math and Common Macros
├── HAL/ (Hardware Abstraction Layer)
│   ├── LCD_I2C/        # I2C-based LCD Driver (PCF8574)
│   ├── ADC_LAB/        # Sensor-specific Processing
│   └── UART_APP/       # High-level Serial Messaging
└── APP/ (Application Layer)
    └── GAS_APP/        # Main Logic and Threshold Detection
