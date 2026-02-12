# AVR-Bare-Metal-Gas-Detection-System

---

## 1- Overview :

this project designs and implements an AVR based embedded system using custom-built, Baremetal (register-level) C driver to interface the MQ-135 gas sensor and manage additional peripherals.

Since the MQ-135 lacks an official driver, the library was developed from scratch, built on the Arduino Uno, the system reads real-time gas levels and displays them on the LCD. It also activates a buzzer for gas detection alerts and uses UART for external monitoring.

The system measures gas concentration in PPM and alerts the user when harmful gases such as CO or alcohol are detected.

---

## 2- Hardware/Software representation:

### The hardware components used in the system are:

- MQ-135 gas detector for detecting harmful gases.
- ATmega328p microcontroller on the Arduino uno.
- 16x2 I2C LCD to display the measurement.
- buzzer for alert signals.

### The software part includes the enviroment that we will be building our firmware which is:

Atmel Studio development environment (IDE) developed by Microchip for programming and debugging AVR and ARM microcontrollers. It provides a user-friendly interface for writing code in C/C++, compiling, simulating, and uploading firmware to microcontrollers like the ATmega328P.

---

## 3- Project implemetation:

### 1- driver architecture structure:

```text
avr-gas-detection-driver/
│
├── MCAL/
│   ├── DIO/
│   │   ├── DIO.c
│   │   ├── DIO_reg.h
│   │   ├── DIO_types.h
│   │   └── DIO.h
│   ├── UART/
│   │   ├── UART.c
│   │   ├── UART.h
│   │   └── UART_reg.h
│   ├── TWI/
│   │   ├── TWI.c
│   │   ├── TWI.h 
│   │   └── TWI_reg.h
│   ├── ADC/
│   │   ├── ADC.c
│   │   ├── ADC_reg.h
│   │   ├── ADC_types.h
│   │   ├── ADC.h
│   │   └── ADC_config.h
│   ├── DELAY/
│   │   ├── delay_function.c
│   │   └── delay_function_reg.h
│   ├── Bit manipulation/macros/
│   │   ├── bit_Math.h
│   │   └── common_macros.h
├── HAL/
│   ├── LCD I2C/
│   │   ├── LCD_I2C.c
│   │   └── LCD_I2C.h
│   ├── ADC /
│   │   ├── ADC_LAB.c
│   │   └── ADC_LAB.h
│   ├── UART /
│   │   ├── UART_APP.c
│   │   └── UART_APP.h
├── APP/
│   ├── GAS application/
│   │   ├── GAS_APP.c
│   │   └── GAS_APP.h

```
2- explanaition of each part of the driver:
   DIO:
    The Digital I/O (DIO) module serves as the foundation for interacting with the ATmega328P’s general-purpose I/O pins.Register-Level Implementation The DIO library is divided into three layers:
    Register Definitions (dio-reg.h):
    Macros that define for the I/O registers using memory-mapped addresses that we get from the atmega328p datasheet used with symbolic names, such as DDRA-Reg, PORTA-Reg, and PINA-Reg for Port A.
    Type Definitions (dio-types.h): 
    Contains enums for ports, pin numbers, directions, and logic levels to ensure type safety and code clarity.
    Function Prototypes (dio.h): 
    Provides function declarations for all operations (set direction/value for ports and pins, get pin value).
    Implementation (dio.c): 
    The core source file where all functionalities are defined based on direct bit manipulation of the microcontroller’s registers:
    DIO_SetPortDirection( DIO_PORTX, INPUT/OUTPUT):This function sets the direction of the entire port as either input or output.
    DIO_SetPortValue(DIO_PORTX, HIGH/LOW):this function sets the whole port to HIGH or LOW.
    DIO_SetPinDirection(DIO_PORTX, PinX, INPUT/OUTPUT): This function sets the direction a specific pin of a given port as either input or output.
    DIO-SetPinValue(DIO-PORTX, PinX, HIGH/LOW): This function sets a specific pin of a given port to HIGH or LOW.
    DIO_GetPinValue(DIO_PORTX, PinX):this function Reads (input) and returns the current logic level (HIGH or LOW) of the specific pin in the specified port.

   ADC:
   The ADC module enables the ATmega328P microcontroller to convert analog voltage inputs into corresponding 10-bit digital values. This allows interfacing with analog sensors and signals. 
   Register-Implementation The ADC library is organized into structured these 5 layers:
   Register Definitions(adc-reg.h): 
   Contains direct memory-mapped definitions for ADC-related registers like ADMUX-Reg, ADCSRA-Reg, ADCL-Reg, and ADCH-Reg, which we get from the datasheet.
   Type Definitions (adc-types.h): 
   Includes masks and macros for setting reference voltage (REFS1:0), prescalers, adjustment (left/right), modes (auto trigger or single conversion),and channel selection. These symbolic constants improve           readability and reduce errors.
   Configuration (adc-config.h):
   it centralizes the specific selections such as voltage reference source (AVCC, AREF, or 1.1V), ADC operation mode (auto-triggered or single conversion), result alignment (left or right), and prescaler            settings to set ADC clock.
   Function Prototypes (adc.h): 
   Declares the core functions which abstract the low-level operations such as initializing, triggering, and retrieving conversion results.
   Implementation (adc.c): 
   Implements all functions using bit level manipulation:
   ADC-Initialize():this function configures the ADC by setting the reference voltage, mode, adjustment, trigger source, and enables the ADC peripheral.
   ADC-StartConversion(channel): this function selects an input channel and starts the conversion.
   ADC-GetResult() waits for the conversion to complete and returns the result.

   LCD-I2C:
   The LCD I2C driver enables the ATmega328P microcontroller to interface with LCD 16×2 display using the I2C communication protocol. This significantly reduces the number of GPIO pins required while maintaining    full control over the LCD for displaying text and system information.
   The LCD I2C library is organized into the following structured layers:
   MCAL Dependency (TWI Driver):
   Function Prototypes (TWI.h): 
   Declares the core functions which abstract the low-level operations such as initializing, reading, and stopping the I2C communication.
   Implementation (TWI.c): 
   Implements all functions using bit level manipulation:
   I2C_init():this function initialize the I2C by setting the clock using a prescaler.
   I2C_start():this function is made to start the communication by setting the start registers.
   I2C_stop():this function is made to stop the communication.
   I2C_write(data): this function is made to send data by byte.
   I2C_readAck():this read and enable  the acknowlagement from the I2C.
   
   Configuration (LCD_I2C_CONF.h): 
   Centralizes configuration parameters such as the I2C slave address of the LCD module and display-specific settings, allowing easy portability and reuse.
   Function Prototypes (LCD_I2C.h):
   Declares high-level LCD interface functions that abstract low-level I2C transactions, such as initialization, command transmission, data writing, cursor positioning, and backlight control.
   Implementation (LCD_I2C.c):
   Implements all LCD functions using bit-level manipulation and I2C communication:
   LCD_init(): Initializes the I2C peripheral and configures the LCD in 4-bit mode, setting display parameters such as number of lines, cursor behavior, entry mode, and display state.
   LCD_command(cmd):Sends control commands to the LCD, handling timing requirements for critical instructions like clear and home.
   LCD_data(data):Sends character data to be displayed on the LCD.
   LCD_setCursor(row, col): Sets the cursor position based on the specified row and column.
   LCD_print(str) / LCD_printPgm(str): Displays strings stored in RAM or program memory (Flash), supporting memory-efficient text output.
   LCD_backlight(state): Controls the LCD backlight through the I2C expander.

   UART:
   The UART (Universal Asynchronous Receiver-Transmitter) module enables the ATmega328P microcontroller to perform serial communication with external devices such as PCs, sensors, or other microcontrollers.    
   The UART library is organized into structured layers:
   Register Definitions (uart_reg.h): 
   Defines direct memory-mapped registers for the UART subsystem which we get from the ATmega328p datasheet, including UCSR0A-Reg, UCSR0B-Reg, UCSR0C-Reg, UBRR0H-Reg, UBRR0L-Reg, and UDR0-Reg.
   Function Prototypes (uart.h): 
   Declares high-level APIs for UART initialization and data transfer.
   Implementation (uart.c): Contains the function definitions using direct bit manipulation:
   UART-initialize(): Sets the baud rate registers UBRR0H and UBRR0L based on F-CPU, enables the receiver and transmitter through UCSR0B, and configures 8-bit data format via UCSR0C.
   UART-Send-Char(): Waits until the transmit buffer is empty (checks UDRE0 bit in UCSR0A) before loading the data register UDR0 with the character to send.
   UART-Send-String(): Iteratively sends characters of a null-terminated string using UART-Send-Char().

   Gas Detection driver:
   The embedded system library is architected in modular layers to promote reusability, clarity, and separation of concerns. It combines four core drivers DIO, ADC, I2C LCD and UART which together support the       functionality of the Gas Detection Application (GasApp).
   The Digital I/O (DIO) module acts as the foundational layer, providing abstraction for configuring and manipulating the microcontroller’s digital pins. All modules that require digital pin interaction            including control signals for peripherals rely on this layer.
   The Analog-to-Digital Converter (ADC) module is responsible for interfacing with analog gas sensors by converting analog voltage levels to digital values. It operates independently of pin direction settings      and provides the numerical gas level data required for threshold evaluation in the application layer.
   The LCD module uses the DIO interface to send control signals and data to a character LCD, enabling real-time display of system status or alerts such as gas concentration levels or warnings.
   In the GasApp, these modules are tightly integrated:The ADC continuously reads analog input from the gas sensor. The application logic processes this data to determine air quality. Based on the analysis, the     LCD is updated using I2C communication protocol to show appropriate messages to the user.

2- Circuit architecture structure:

The following block diagram illustrates the system’s overall architecture:
The system is built around the ATmega328P microcontroller. It interfaces with the MQ-135 gas sensor, which outputs an analog voltage connected to analog pin A1 (ADC channel 1). The system also includes a 16x2 LCD display connected via I2C on pins A4 (SDA) and A5 (SCL), a buzzer connected to digital pin PD7 for audible alerts, and optionally a UART-connected serial monitor using TX (D1) and RX (D0).





4- General conclusion:
 In conclusion, this project not only delivered a fully functional AVR-based gas detection system capable of real-time monitoring and alerting but also enriched the developer’s understanding of embedded hardware and low-level software design. The experience underlines the importance of custom software libraries in achieving fine grained control and performance optimization in embedded applications

  




















   
  
