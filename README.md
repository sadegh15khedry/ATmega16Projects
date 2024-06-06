# ATmega16 Projects

This repository contains various projects developed for the ATmega16 microcontroller.

## Contents

1. [Introduction](#introduction)
2. [Projects](#projects)
3. [Requirements](#requirements)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The ATmega16 is a low-power CMOS 8-bit microcontroller based on the AVR enhanced RISC (Reduced Instruction Set Computer) architecture. These projects are designed to demonstrate the capabilities of the ATmega16 and provide examples for beginners to learn from.

## Project List

1. **LM35**: this project is connecting LM35 sensonr to the microcontroller and displaying the resual on a seven segment.
2. **Timer Frequency Measurement**: Measures frequency using Timer 0 overflow interrupt and displays it on an LCD.
3. **PWM Adjustment with External Interrupts**: Adjusts PWM output using external interrupts and displays the OCR0 value on an LCD.
4. **RTC using Library**: read the current time from a DS1307 Real-Time Clock (RTC) and display it on a 16x2 alphanumeric LCD. The time is continuously updated and displayed in the format "HH : MM : SS".
5. **RTC without Library**: read the current time from a DS1307 Real-Time Clock (RTC) and display it on a 16x2 alphanumeric LCD. The time is continuously updated and displayed in the format "HH : MM : SS" without using a Library.  
6. **Number Counter with seven segment**: The code is designed to interface an ATmega16 microcontroller with a 4x4 keypad and a set of 7-segment displays. It reads key presses from the keypad and displays the corresponding numbers on the 7-segment displays.
7. **SPI**: slave.c sets up the ATmega16 as an SPI slave device that receives data and outputs it to Port D. master.c sets up the ATmega16 as an SPI master device that continuously sends the byte 0x00 every 500 milliseconds.
8. **Ultrasonic**: sets up a basic application that measures distance using an ultrasonic sensor, displaying the result on an alphanumeric LCD.
9. **USART**:  Program 1 reads input from Port A and sends it over USART, while Program 2 reads characters from USART and controls the output on Port A.
10. **motor**: This program sets up external interrupts INT0 and INT1 to adjust the value of OCR0, which controls the PWM output on Timer/Counter 0 and It continuously updates an LCD display with the current value of OCR0.
    
## Requirements

To compile and run these projects, you'll need the following:

- AVR development environment (e.g., AVR-GCC, AVR Studio)
- AVR programmer (e.g., USBasp, AVRISP)
- ATmega16 microcontroller
- Other necessary components as specified in each project's README

## Usage

To use these projects, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the desired project directory.
3. Connect the necessary components as described.
4. Power up your microcontroller and observe the project's behavior.

## Contributing

Contributions to this repository are welcome! If you have a project or improvement you'd like to add, feel free to fork this repository, make your changes, and submit a pull request.

Please ensure that your contributions adhere to the coding standards and guidelines provided in the repository.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
