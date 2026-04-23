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
```
### Detailed Module Descriptions

#### 🛠 MCAL (Microcontroller Abstraction Layer)
* **DIO (Digital I/O):** The foundational driver for pin control. It implements direct register access to `DDRx`, `PORTx`, and `PINx` registers. Features include atomic bit-setting, direction configuration, and logic-level reading with high-efficiency macros.
* **ADC (Analog-to-Digital Converter):** A 10-bit conversion driver. It manages the `ADMUX` and `ADCSRA` registers to handle channel selection, voltage reference (AVCC/Internal), and prescaler configuration to ensure accurate sensor readings at a stable frequency.
* **TWI (I2C):** A custom implementation of the Two-Wire Interface. It manages the hardware state machine via `TWCR` and `TWDR` registers, supporting Start/Stop conditions, Master Transmitter mode, and SLA+W (Slave Address + Write) protocols.
* **UART:** Enables full-duplex serial communication. It calculates the `UBRR0` value based on $F_{CPU}$ to set the baud rate and utilizes the `UDR0` data register for transmitting strings and system logs to external monitors.

#### 🏗 HAL (Hardware Abstraction Layer)
* **LCD I2C Driver:** An abstraction that interfaces with the **PCF8574** I2C expander. It translates 8-bit commands into 4-bit nibbles required by the HD44780 LCD controller, managing the Enable (E) and Register Select (RS) pulses over the I2C bus.
* **MQ-135 Sensor Module:** Handles the mathematical conversion of raw ADC data into gas concentration levels. It implements the sensor's load resistance calibration and uses logarithmic curve fitting to estimate PPM (Parts Per Million).

#### 📱 APP (Application Layer)
* **Gas Detection Logic:** The top-level firmware that orchestrates the system behavior. It implements a non-blocking super-loop that:
    1. Periodically triggers ADC conversions.
    2. Updates the LCD with real-time concentration data.
    3. Evaluates safety thresholds to trigger the **Buzzer Alarm** and **Serial Alerts** if air quality degrades.

