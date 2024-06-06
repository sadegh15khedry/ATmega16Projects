# ATmega16 Real-Time Clock (RTC) Project

This project demonstrates how to implement a real-time clock (RTC) using the DS1307 RTC module and ATmega16 microcontroller.

## Contents

1. [Introduction](#introduction)
2. [Components](#components)
3. [Circuit Diagram](#circuit-diagram)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The DS1307 is a low-power serial real-time clock (RTC) with a built-in 32.768 kHz crystal oscillator and an I2C interface. This project uses the DS1307 RTC module to keep track of time and displays it on an LCD connected to the ATmega16 microcontroller.

## Components

To build this project, you'll need the following components:

- ATmega16 microcontroller
- DS1307 RTC module
- 16x2 LCD display
- 10kΩ potentiometer (for adjusting LCD contrast)
- 4.7kΩ resistor (pull-up resistor for I2C communication)
- Breadboard
- Jumper wires

## Circuit Diagram

The circuit diagram for connecting the DS1307 RTC module to the ATmega16 microcontroller and LCD display is as follows:

```

          +5V
           |
       +---+---+
       |       |
       |  DS1307  +-----+
       |       |         |
       +---+---+         |
           |             |
+----------+----------+ |
|   ATmega16           | |
|                      | |
|   SCL (PC0) --------| |
|   SDA (PC1) --------| |--- I2C
|                      | |
|                      | |
|                      | |
|                      | |
|   PORTA0  -----------| |--> RS
|   PORTA1  -----------| |--> RW
|   PORTA2  -----------| |--> EN
|                      | |
|   D4      -----------| |
|   D5      -----------| |
|   D6      -----------| |
|   D7      -----------| |
|                      | |
+----------------------+ |
                          |
                        GND
```

## Usage

To use this project:

1. Connect the components according to the circuit diagram provided.
2. Compile the code using an AVR-GCC compiler.
3. Upload the compiled code to your ATmega16 microcontroller using an AVR programmer.
4. Power up your microcontroller.
5. The LCD will display the current time obtained from the DS1307 RTC module.

## Contributing

Contributions to this project are welcome! If you have any improvements or additional features you'd like to add, feel free to fork this repository, make your changes, and submit a pull request.

Please ensure that your contributions adhere to the coding standards and guidelines provided in the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](../LICENSE) file for details.
