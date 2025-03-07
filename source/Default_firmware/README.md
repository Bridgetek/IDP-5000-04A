# Overview

The "Default_firmware" folder includes reusable source code for applications, along with a sample application demonstrating a screensaver for reference purpose. 

# Folder introduction
```
📂 Default_firmware
    ├───eve_hal                        | Hardware abstraction layer for interfacing the FT903 platform with EVE FT813 control support
    ├───example_binary                 | A pre-compiled binary of this default firmware for reference
    ├───lib                            | Third party libraries
    │   ├──fatfs                       | fatfs library for SD card support
    │   ├──tinyprintf                  | tinyprintf library
    │   ├──usbdbg                      | Library for supporting the printing of USB debug information
    ├───.cproject                      | FT903 project file
    ├───.project                       | FT903 project file
    ├───Bridgetek_Logo_197x69_ARGB4.c  | Bridgetek logo image data used in the sample application
    ├───app.c                          | Sample application featuring FT903 and FT813 initialization, calibration, and screensaver functionality
    ├───app.h                          | Header file for sample application
```

# System diagram
Below diagram describe how this folder used in the program:
                     
                -------------------------------------------
                |             Main application            |
                -------------------------------------------
                     |                   |
                     |                   ▼
                     |        -----------------------
                     |        |          Lib        |
                     |        -----------------------
                     |                   |
                     ▼                   ▼
                -------------------------------------------
                |                  eve_hal                |
                -------------------------------------------
                                      |
                                      |
                                      ▼
                -------------------------------------------
                |             EVE ICs (FT81x)             |
                -------------------------------------------
                                      |
                                      |
                                      ▼   
                -------------------------------------------
                |               LCD, touch                | 
                -------------------------------------------

# Usage
IDP903-50A is using EVE FT813 with FT903 host platform. Users are expected to be familiar with the FT81X programming guide and data sheet for EVE FT813 chip.

This folder does not include the toolchain for FT903. For information on downloading, installing, and using the toolchain, please visit https://brtchip.com/ft9xx-toolchain/. This folder used toolchain setup can be found at https://brtchip.com/wp-content/uploads/Support/SoftwareExample/FT9xx/FT9xx_Toolchain_Setup_2.8.0_rc2.exe

## Hardware requirement
* IDP903-50A development board
* FTDI UMFTPD2A Module

![IDP903-50A](https://github.com/user-attachments/assets/273e4a8a-80c0-4a12-9349-46b8b19587d5)

## Build instruction
1. Install FT903 toolchain and download this folder

![image](https://github.com/user-attachments/assets/c2f67d4d-29cd-4d9d-9dbf-185caacc3c07)

![image](https://github.com/user-attachments/assets/d0be7597-fcd7-4cfe-bb1f-fb93280d5c22)

2. Launch 'Eclipse for FT9xx', and setup workspace

3. Import IDP903-50A project

![image](https://github.com/user-attachments/assets/ed8766c1-4efd-440e-b507-c4edfc1a0e24)

![image](https://github.com/user-attachments/assets/68a45ff8-fefa-42bb-9c14-83e824533ba8)

![image](https://github.com/user-attachments/assets/49b8b4c0-a2c8-47bd-8b05-5f41c31f783d)

4. Setup building enviroment

![image](https://github.com/user-attachments/assets/7d1e7618-0dd4-47dd-9fbb-ebf6f82eb9ef)

![image](https://github.com/user-attachments/assets/b12c211c-8948-4d21-8c28-f5c389bb2374)

> If 'USB_DEBUG' is defined, the print information will be sent via USB; otherwise, it will be sent via UART0.

5. Build the project

![image](https://github.com/user-attachments/assets/cba8a047-26d3-42cb-b031-4afd3980c5ed)

6. The binary file will be in [YOURPATH]\IDP903-50A\source\Default_firmware\FT90x_Debug\IDP903_50A.bin

7. Program the above binary onto the IDP903-50A development board (ensure the debug module is connected to the one-wire debug port as specified in the 'Hardware Requirements' section).

![image](https://github.com/user-attachments/assets/b71c12f4-a79f-47f3-a6fb-926f0665ccdb)

> The FT9XX programming utility will be installed along with the toolchain.

![image](https://github.com/user-attachments/assets/4a5c2fcf-4449-4ff5-bc9e-a2173af7b319)

![image](https://github.com/user-attachments/assets/2d5c7647-a6aa-45a6-b223-92b56682a110)

![image](https://github.com/user-attachments/assets/f8bf7657-44ae-4372-b6f1-485f758f840d)

8. Board will reboot and show the application

![image](https://github.com/user-attachments/assets/af46c4ca-abdd-446b-91af-8da6c396d2e5)


 

                                   【END】
