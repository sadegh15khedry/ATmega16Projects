# ATmega16 Motor Control Project

This project demonstrates how to control a DC motor using pulse-width modulation (PWM) with the ATmega16 microcontroller.

## Contents

1. [Introduction](#introduction)
2. [Components](#components)
3. [Circuit Diagram](#circuit-diagram)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The ATmega16 microcontroller is used to generate PWM signals to control the speed of a DC motor. PWM is a technique used to generate analog signals using digital means. In this project, PWM is used to vary the average voltage applied to the motor, thereby controlling its speed.

## Components

To build this project, you'll need the following components:

- ATmega16 microcontroller
- DC motor
- L293D motor driver IC
- External power supply (for the motor)
- Breadboard
- Jumper wires

## Circuit Diagram

The circuit diagram for connecting the DC motor to the ATmega16 microcontroller using the L293D motor driver IC is as follows:
```
         +5V                 +5V
          |                   |
    +-----+-----+       +-----+-----+
    |           |       |           |
    |           |       |           |
    |  ATmega16 +-------+  L293D    +---------+
    |           |       |           |         |
    |           |       |           |         |
    +-----+-----+       +-----+-----+         |
          |                   |               |
+---------+---------+---------+               |
|   PORTB1 (OC1A)   |   PORTB2 (OC1B)        |
|                   |                         |
|                   |    Enable Pin (1,2EN)  |
|                   +-------------------------+
|                   |                         |
|                   |    Input 1 (1A)         |
|                   |                         |
|                   +-------------------------+
|                   |                         |
|                   |    Input 2 (2A)         |
|                   |                         |
|                   +-------------------------+
|                                             |
|                 +----+                      |
|                 |    |                      |
|                 |    |                      |
|                 | DC |                      |
|                 | Motor                     |
|                 |    |                      |
|                 |    |                      |
|                 +----+                      |
|                                             |
+---------------------------------------------+
```

## Usage

To use this project:

1. Connect the components according to the circuit diagram provided.
2. Compile the code using an AVR-GCC compiler.
3. Upload the compiled code to your ATmega16 microcontroller using an AVR programmer.
4. Power up your microcontroller.
5. The PWM signals generated by the microcontroller will control the speed of the DC motor connected through the L293D motor driver IC.

## Contributing

Contributions to this project are welcome! If you have any improvements or additional features you'd like to add, feel free to fork this repository, make your changes, and submit a pull request.

Please ensure that your contributions adhere to the coding standards and guidelines provided in the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](../LICENSE) file for details.