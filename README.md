# Password Entry System with LCD Display - Arduino

This project implements a password entry system using Arduino, where users enter a 4-digit password via a keypad, and the entered password is displayed on an LCD. If the password matches the preset code, access is granted; otherwise, access is denied.

## Overview

This password entry system uses the following components:
- **Arduino Board**: Runs the code to control the system.
- **LCD Display**: Shows the entered digits and status messages.
- **Keypad**: Allows users to input their password.

### Default Password

The default password for this system is set to **1234**. You can change this code in the Arduino code if needed.

## Features

- **Password Verification**: Checks if the entered password matches the preset code.
- **LCD Display**: Displays feedback, showing "Access Granted" or "Access Denied" based on the input.
- **Clear and Reset Functionality**: Allows users to clear the input if a mistake is made.

## How to Use

1. **Clone the Repository**: Clone this repository to your local machine or download the ZIP file.
   ```bash
   git clone https://github.com/DanielFHeT/Password-Entry-System-with-LCD-Display-Arduino.git
Upload the Code: Open the code in the Arduino IDE, connect your Arduino board, and upload the code.

Enter Password: Use the keypad to enter the 4-digit code (default is 1234).

If the password is correct, the LCD will display "Access Granted."
If the password is incorrect, the LCD will display "Access Denied."
Components
Arduino Board
LCD Display (16x2)
Keypad (4x4)
Customization
To change the default password, open the Arduino code file and modify the line where the password is set to 1234. For example:

cpp
Copy code
const String password = "1234";
Change "1234" to your desired 4-digit code.

License
This project is open-source and available under the MIT License.

Contact
For questions or suggestions, feel free to open an issue or contact DanielFHeT.
