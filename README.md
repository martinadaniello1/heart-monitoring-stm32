# Embedded Systems for E-Health: Wearable Health Monitoring System

This repository contains the final project for the "Embedded Systems for E-Health" course, developed at the **Università degli Studi di Salerno**.

## Table of Contents

*   [About the Project](#about-the-project)
*   [Key Features](#key-features)
*   [Hardware Components](#hardware-components)
*   [Software & Firmware](#software--firmware)
*   [System Operating Modes](#system-operating-modes)
*   [Getting Started](#getting-started)


## About the Project

This project focuses on the development of a wearable health monitoring system using a **NUCLEO-G474RE development board**. The core functionality involves the acquisition and real-time processing of Electrocardiogram (ECG) and Photoplethysmogram (PPG) signals. These signals are crucial for deriving vital health parameters such as Heart Rate (HR) and Heart Rate Variability (HRV), which serve as key indicators of overall human health.

The system integrates various embedded techniques, sensor integration, robust signal processing algorithms, and real-time data handling to design and implement a comprehensive health monitoring solution effectively.

**Disclaimer:** This embedded device demonstrated tested reliability in experimental settings; however, it is not recommended for clinical use or self-diagnosis of pathologies.

## Key Features

*   **ECG & PPG Signal Acquisition:** Real-time capture of Electrocardiogram and Photoplethysmogram signals.
*   **Vital Signs Calculation:** Accurate calculation of Heart Rate (HR) and Heart Rate Variability (HRV) from processed signals.
*   **Multi-Mode Operation:** Three distinct operating modes for different monitoring needs: Home Mode, Waveform Monitoring Mode, and Advanced Mode.
*   **Real-time Display:** Visualization of health metrics and waveforms on an SSD1306 OLED display.
*   **Sensor Contact Detection:** Functionality to alert the user of incorrect sensor contact.
*   **Abnormal Value Alerts:** Warnings for high/low HR and HRV values exceeding predefined thresholds.
*   **Advanced Metrics:** Extraction of Systolic Time Duration, Diastolic Time Duration, and Pulse Arrival Time (PAT).
*   **UART Data Transmission:** Raw ECG and PPG data samples are transmitted via UART for further processing, analysis, or storage.
*   **Filtering Techniques:** Implementation of moving average and high-pass filters for signal noise reduction and baseline wander elimination.

## Hardware Components

The system is built around the **NUCLEO-G474RE development board** and incorporates several sensors and peripherals:

*   **NUCLEO-G474RE Development Board:** The central microcontroller unit.
*   **AD8232 Heart Monitor Module:** Used for ECG signal acquisition.
*   **Pulse Sensor:** Utilized for PPG signal detection.
*   **SSD1306 OLED Display:** For real-time visual feedback of data and waveforms.
*   **DS3231 Real-Time Clock (RTC):** Ensures precise timekeeping for measurements.
*   **Red LED:** Provides visual indication of cardiovascular state via PWM.
*   **Push-Button:** Allows user interaction for mode switching and debouncing.
*   **Analog-to-Digital Converters (ADCs):** ADC1 for Pulse Sensor (PC2) and ADC5 for AD8232 (PA8) handle analog-to-digital conversion of sensor signals at 250Hz.

## Software & Firmware

The firmware is the core of the system, managing hardware interaction, data acquisition, processing, and display.

*   **Architecture Design:** Employs an **Interrupt-Driven Model** for efficient, responsive, and real-time task handling.
*   **Signal Processing:**
    *   **Moving Average Filter:** Applied to detected signals to smooth data by reducing noise and fluctuations.
    *   **High-pass Filter:** Used to remove low-frequency components and baseline wander from signals.
*   **Timers:** Various timers (TIM1, TIM2, TIM6, TIM7) are configured for specific tasks, including push-button debouncing, ADC sampling frequency (250Hz), PWM generation, and periodic HR/HRV calculations and display updates.
*   **Interfaces:**
    *   **GPIO:** Used for controlling external LED (PA0) and reading push-button status (PA6), and driving the Pulse Sensor LED (PB6).
    *   **UART (USART2):** For transmitting raw data to a serial terminal.
    *   **I2C:** For communication with the DS3231 RTC and SSD1306 OLED display (PC8 for SCL, PC9 for SDA).

## System Operating Modes

The wearable system operates in three primary modes:

1.  **Home Mode:** (Default mode) Displays Heart Rate (HR) and Heart Rate Variability (HRV) on the OLED screen, updated every 30 seconds. Uses PPG signal for calculations.
2.  **Waveform Monitoring Mode:** Continuously displays raw ECG and PPG waveforms on the OLED screen. Transmits raw data via UART. The LED brightness varies with heart rate.
3.  **Advanced Mode:** Graphically represents temporal trends of HR and HRV, updating every 5 seconds. Extracts and displays Systolic Time Duration, Diastolic Time Duration, and Pulse Arrival Time (PAT).

## Getting Started

*(This section will be expanded with more specific instructions once the code and hardware setup details are available in the repository.)*

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/martinadaniello1/heart-monitoring-stm32.git
    cd heart-monitoring-stm32
    ```
3.  **Firmware Compilation & Flashing:**
    *   Set up your development environment for STM32 microcontrollers (e.g., STM32CubeIDE).
    *   Import the project firmware.
    *   Compile the code.
    *   Flash the compiled firmware onto the NUCLEO-G474RE development board.
4.  **Serial Monitor:** Use a serial terminal configured for UART communication to observe raw data outputs in Waveform Monitoring Mode.

