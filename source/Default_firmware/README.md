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
**IDP-5000-04A** is using EVE FT813 with FT903 host platform. Users are expected to be familiar with the FT81X programming guide and data sheet for EVE FT813 chip.

This folder does not include the toolchain for FT903. For information on downloading, installing, and using the toolchain, please visit https://brtchip.com/ft9xx-toolchain/. This folder used toolchain setup can be found at https://brtchip.com/wp-content/uploads/Support/SoftwareExample/FT9xx/FT9xx_Toolchain_Setup_2.8.0_rc2.exe

## Hardware requirement
* IDP-5000-04A development board
* FTDI UMFTPD2A Module

![IDP-5000-04A](https://github.com/user-attachments/assets/fb14b1fb-cb21-4b1b-8938-ac1140a9e54a)

## Build instruction
1. Install FT903 toolchain and download this folder

![image](https://github.com/user-attachments/assets/c2f67d4d-29cd-4d9d-9dbf-185caacc3c07)

![image](https://github.com/user-attachments/assets/d0be7597-fcd7-4cfe-bb1f-fb93280d5c22)

2. Launch 'Eclipse for FT9xx', and setup workspace

3. Import IDP-5000-04A project

![image](https://github.com/user-attachments/assets/ed8766c1-4efd-440e-b507-c4edfc1a0e24)

![image](https://github.com/user-attachments/assets/68a45ff8-fefa-42bb-9c14-83e824533ba8)

![image](https://github.com/user-attachments/assets/2fe1a565-033f-4ee2-a1b3-a1ac710def26)

4. Setup building enviroment

![image](https://github.com/user-attachments/assets/e6b81521-42c5-4797-9588-ba4e3e839c94)

![image](https://github.com/user-attachments/assets/b12c211c-8948-4d21-8c28-f5c389bb2374)

> If 'USB_DEBUG' is defined, the print information will be sent via USB; otherwise, it will be sent via UART0.

5. Build the project

![image](https://github.com/user-attachments/assets/3b7f7135-65eb-4077-8129-035ae7a60346)

6. The binary file will be in [YOURPATH]\IDP-5000-04A\source\Default_firmware\FT90x_Debug\IDP-5000-04A.bin

7. Program the above binary onto the IDP-5000-04A development board (ensure the debug module is connected to the one-wire debug port as specified in the 'Hardware Requirements' section).

![image](https://github.com/user-attachments/assets/b71c12f4-a79f-47f3-a6fb-926f0665ccdb)

> The FT9XX programming utility will be installed along with the toolchain.

![image](https://github.com/user-attachments/assets/4a5c2fcf-4449-4ff5-bc9e-a2173af7b319)

![image](https://github.com/user-attachments/assets/8e9ac60b-8c63-4030-8c65-1462f8990027)

![image](https://github.com/user-attachments/assets/f8bf7657-44ae-4372-b6f1-485f758f840d)

8. Board will reboot and show the application

![image](https://github.com/user-attachments/assets/af46c4ca-abdd-446b-91af-8da6c396d2e5)


 

                                   【END】
