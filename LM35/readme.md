# ATmega16 LM35 Temperature Sensor Project

This project demonstrates how to interface the LM35 temperature sensor with the ATmega16 microcontroller to measure ambient temperature.

## Contents

1. [Introduction](#introduction)
2. [Components](#components)
3. [Circuit Diagram](#circuit-diagram)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The LM35 is a precision integrated-circuit temperature sensor whose output voltage is linearly proportional to the Celsius (centigrade) temperature. This project uses the LM35 sensor to measure the ambient temperature and display it on an LCD connected to the ATmega16 microcontroller.

## Components

To build this project, you'll need the following components:

- ATmega16 microcontroller
- LM35 temperature sensor
- 16x2 LCD display
- 10kΩ potentiometer (for adjusting LCD contrast)
- Breadboard
- Jumper wires

## Circuit Diagram

The circuit diagram for connecting the LM35 temperature sensor to the ATmega16 microcontroller and LCD display is as follows:

```
       +5V
        |
       LM35
        |
        |-----> ADC (Analog Input)
        |
       GND

  ATmega16                  16x2 LCD
  +-----------+           +-------------+
  |           |           |             |
  |   PORTA0  |--------->|    RS       |
  |           |           |             |
  |   PORTA1  |--------->|    RW       |
  |           |           |             |
  |   PORTA2  |--------->|    EN       |
  |           |           |             |
  |           |           |   D4        |
  |           |           |   D5        |
  |           |           |   D6        |
  |           |           |   D7        |
  |           |           |             |
  |           |           +-------------+
  +-----------+
```

## Usage

To use this project:

1. Connect the components according to the circuit diagram provided.
2. Compile the code using an AVR-GCC compiler.
3. Upload the compiled code to your ATmega16 microcontroller using an AVR programmer.
4. Power up your microcontroller.
5. The LCD will display the current ambient temperature measured by the LM35 sensor.

## Contributing

Contributions to this project are welcome! If you have any improvements or additional features you'd like to add, feel free to fork this repository, make your changes, and submit a pull request.

Please ensure that your contributions adhere to the coding standards and guidelines provided in the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](../LICENSE) file for details.
