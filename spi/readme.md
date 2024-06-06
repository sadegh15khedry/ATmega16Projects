# ATmega16 SPI Communication

This project demonstrates how to implement SPI (Serial Peripheral Interface) communication between two ATmega16 microcontrollers, one acting as the master and the other as the slave.

## Contents

1. [Introduction](#introduction)
2. [Components](#components)
3. [Circuit Diagram](#circuit-diagram)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

SPI (Serial Peripheral Interface) is a synchronous serial communication protocol commonly used for short-distance communication between microcontrollers, sensors, and other peripheral devices. This project illustrates how to configure and use SPI communication between two ATmega16 microcontrollers, where one serves as the master and the other as the slave.

## Components

To build this project, you'll need the following components:

- Two ATmega16 microcontrollers
- Breadboards (two)
- Jumper wires

## Circuit Diagram

The circuit diagram for connecting the two ATmega16 microcontrollers for SPI communication is as follows:
```
Master ATmega16                     Slave ATmega16
+------------+                     +------------+
|            |                     |            |
|   +-----+  |      MOSI (PB5) ----|----- MOSI  |
|   |     |  |      MISO (PB6) ----|----- MISO  |
|   |     |  |      SCK  (PB7) ----|----- SCK   |
|   |     |  |      SS   (PB4) ----|----- SS    |
|   +-----+  |      GND            |    GND     |
|            |      VCC            |    VCC     |
+------------+                     +------------+
```
## Usage

To use this project:

1. Connect the Master ATmega16 to the Slave ATmega16 according to the circuit diagram provided.
2. Compile the code for both microcontrollers using an AVR-GCC compiler.
3. Upload the compiled code to each ATmega16 microcontroller using an AVR programmer.
4. Power up both microcontrollers.
5. The master microcontroller will communicate with the slave microcontroller using the SPI protocol.

## Contributing

Contributions to this project are welcome! If you have any improvements or additional features you'd like to add, feel free to fork this repository, make your changes, and submit a pull request.

Please ensure that your contributions adhere to the coding standards and guidelines provided in the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](../LICENSE) file for details.
