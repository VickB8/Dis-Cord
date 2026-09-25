# Dis-Cord
Custom 6-key macro pad powered by a XIAO RP2040 with a 0.91 inch OLED display. Includes Fusion 360, Chrome, KiCad, Valorant, YouTube, and Arduino IDE shortcuts, plus a rotary encoder for volume control and an OLED display. Pressing the encoder switches to a Discord layer with controls for mute, deafen, screen sharing, and other Discord shortcuts.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/Final%20Look.png?raw=true)

# Inspiration

I wanted to make a custom macro pad that I could actually use while working on my computer. Instead of making all of the keys do the same type of shortcut. I wanted each key to have a different purpose depending on what i am doing.

I also wanted the hack pad to have more functionality than just six buttons, so I added a rotary encoder for volume control and an OLED display to show the current mode and volume.

The main ideas was to have one layer for my normal computer shortcuts and another layer specifically for discord.

# Design Concept

I wanted the hackpad to be more than just a small PCB with switches on it, so I designed the physical setup around how I would actually use it at my desk.

I made an under-desk stand that holds the hackpad at an angle, making the keys easy to reach while keeping the OLED visible. The stand is designed to attach underneath the desk so the hackpad sticks out slightly instead of taking up space on the desk.

I also added a dedicated space for a flexible LED filament. I chose a flexible LED because it can follow the shape of the enclosure and add lighting without needing individual LEDs placed around the case. The lighting is mainly a visual design element and is integrated into the physical design of the hackpad.

# How it Works

The hackpad uses a Seeed Studio RP2040 as the main microcontroller.

The six mechanical switches act as USB Keyboard inputs. When a key is presses, the XIAO RP2040 sends the programmed keyboard shortcute to the computer.

The rotary encoder controls the computer volume. Pressing the encoder button changes the hack pad from the m=normal mode to Discord mode.

The OLED Display shows the current mode and volume percentage so I can see what the hackpad is doing without needing to look at the computer.

# Normal Mode

The normal mode is designed around programs and actions I commonly use.

SW1      Fusion 360          SW4      Valorant
SW2      New Chrome tab      SW5      Youtube
SW3      KiCad               SW6      Arduino IDE
Rotary Encoder Volume Up/Down
Encoder Button Switch to Discord Mode.

The six keys are programmed as shortcuts for quickly opening or switching to these programs and actions.

# Discord Mode

Pressing the rotary encoder button switches the hackpad into the Discord layer.

In this mode, the six keys are changed to Discord controls so the same physical buttons can be used for completely different functions.

SW1      Mute                  SW4      Toggle Video
SW2      Deafen                SW5      Discord Shortcut
SW3      Toggle Screen Share   SW6      Discord Shortcut
Rotary Encoder Volume Up/Down
Encoder Button Switch to Discord Mode.

This allows hack pad to have more functions without needing to add more physical buttons.

# OLED Display

The 0.9 inch OLED is used as a status display

It shows information such as:

Current Mode
Normal Mode / Discord Mode
Current Volume percentage

The display changes when the encoder button is pressed so it is easy to tell which set of functions the keys are currently using.

# Rotary Encoder

The Rotary Encoder has two main functions

Turning the Encoder

Turn clockwise - Increase Volume
Turn antiClockwise - Decrease Volume

Pressing the Encoder

Normal Mode - Discord Mode
Discord Mode - Normal Mode

This gives the Hack pas a simple way to switch between two different sets of controls.

# Challenges

One of the biggest challenges was figuring out how to fit six switches, a rotary encoder and an OLED display into a compact design while still making everything comfortable to use.

I also had to figure out how the XIAO RP2040 GPIO pins would be assigned to each component and make sure the schematic and PCB matched the firmware.

Another challenge was getting the rotary encoder to work correctly for both volume control and mode switching.

Designing the PCB in KiCad also took some troubleshooting, especially when working with footprints, silkscreen and the physical placement of the components.

The enclosure was another part of the project that required adjustments. I had to design the case around the actual PCB and components instead of treating the enclosure as a separate part.

What I Learned
How to design a custom PCB in KiCad
How to use the XIAO RP2040
How USB HID keyboard input works
How to program mechanical keyboard switches
How rotary encoders work
How to use an OLED display
How to create multiple keyboard layers
How to send keyboard shortcuts from a microcontroller
How to design a 3D-printed enclosure around a PCB
How to use KiCad DRC to check a PCB
How hardware and firmware have to work together

# Components

1x Seeed Studio XIAO RP2040
6x MX-style mechanical keyboard switches
6x White blank DSA keycaps
1x Rotary encoder
1x 0.9 inch OLED display
Custom PCB
Connecting wires
3D-printed enclosure
M3 hardware

# PCB

The PCB was designed in KiCad and connects the XIAO RP2040 to the six switches, rotary encoder and OLED display.

The component placement was designed around the physical layout of the final hackpad.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/pcb%20image.png?raw=true)

# Schematic

The schematic shows the electrical connections between the XIAO RP2040 and the different inputs and display components.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/schematic%20images.png?raw=true)

# Case Design

The enclosure was designed specifically for the PCB and components.

I wanted the final design to look more like a finished product instead of just a PCB with switches attached to it. The case holds the electronics while keeping the switches, rotary encoder and OLED accessible.

# Under-Desk Stand

I designed a custom stand for mounting the hackpad underneath my desk.

The stand positions the hackpad at roughly a 40-degree angle so the buttons are easy to press and the OLED screen can still be seen while sitting at the desk.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/Look%20with%20Stand.png?raw=true)

Mounting it underneath the desk also keeps the main desk surface clear while making the hackpad easy to access.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/Stand.png?raw=true)

# Flexible LED

I also designed a dedicated space in the enclosure for a flexible LED filament.

I chose a flexible LED instead of using individual LEDs because it can bend around the shape of the design and give the hackpad a cleaner appearance.

The LED is integrated into the enclosure so it becomes part of the physical design rather than having separate LEDs mounted around the PCB.

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/LEd%20Spacing.png?raw=true)

![image alt](https://github.com/VickB8/Dis-Cord/blob/main/Images/led.jpg?raw=true)

# Firmware

The firmware is written in Arduino/C++ and runs on the XIAO RP2040.

It handles:

Six mechanical switches
Rotary encoder input
Volume control
OLED display
Normal keyboard layer
Discord keyboard layer
Mode switching
USB HID keyboard commands

The firmware allows the same physical buttons to perform different actions depending on the current mode.

# Software

Arduino IDE
Arduino/C++
USB HID keyboard functionality
OLED display libraries

# Features

6 programmable mechanical keys
XIAO RP2040 microcontroller
Rotary encoder
Computer volume control
0.9 inch OLED display
Two different control layers
Discord control layer
USB HID keyboard functionality
Custom PCB
Custom 3D-printed enclosure
Custom key layout

# Design Files

The repository contains the files for the different parts of the project including:

KiCad schematic
KiCad PCB
PCB design files
3D enclosure files
Firmware
Project images

# Final Result

The finished hackpad combines the PCB, firmware, switches, OLED and enclosure into one device.

The main goal of the project was to make something that was both useful and custom instead of just making a basic macro pad. The two-layer system lets me use the same six buttons for normal computer shortcuts and Discord controls.

This project helped me learn more about PCB design, embedded programming, USB HID, OLED displays, rotary encoders and designing physical enclosures for electronics.
