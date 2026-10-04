# STM32 Real-Time Telemetry Dashboard

An embedded telemetry system developed on the **STM32 Nucleo-64 (STM32F030R8)** microcontroller. The project features local visual telemetry using a 0.96" SSD1306 OLED display over I2C, asynchronous hardware event processing via EXTI interrupts, and remote logging across a bidirectional USART2 serial interface.

---

## System Overview & Architecture

* **Target MCU:** STM32F030R8 (ARM Cortex-M0, 48 MHz)
* **Visual Interface:** SSD1306 128x64 Monochrome OLED (I2C1)
* **Event Ingestion:** Active-low user button (B1) on pin PC13 configured via EXTI13 and NVIC
* **Status Indication:** On-board user LED (LD2) on PA5
* **Host Telemetry Link:** USART2 over ST-LINK Virtual COM Port (38400 baud, 8N1)
* **Firmware Framework:** STM32Cube HAL & CMSIS

---

## Hardware Pin Mapping

| Peripheral | MCU Pin | Function / Alternate Function | Header Location |
| :--- | :--- | :--- | :--- |
| **SSD1306 SCL** | PB8 | I2C1_SCL (AF1) | Arduino Connector (D15) |
| **SSD1306 SDA** | PB9 | I2C1_SDA (AF1) | Arduino Connector (D14) |
| **User LED (LD2)** | PA5 | GPIO_Output (Push-Pull) | On-board Green LED |
| **User Button (B1)** | PC13 | GPIO_EXTI13 (Falling Edge) | On-board Blue Button |
| **USART2 TX** | PA2 | Virtual COM Port (ST-LINK) | Internal routing |
| **USART2 RX** | PA3 | Virtual COM Port (ST-LINK) | Internal routing |

---

## Key Features

1. **Bare-Metal Display Driver:** Implemented a lightweight, page-addressing frame-buffer driver (`ssd1306.c` / `ssd1306.h`) using a 5x7 ASCII character font map without heavy external graphics libraries.
2. **Interrupt-Driven Asynchronous Input:** Utilized the Nested Vectored Interrupt Controller (NVIC) to handle button debouncing and state changes asynchronously without CPU polling bottlenecks.
3. **Serial Telemetry Stream:** Transmits live JSON/string log packets over USART2 for external monitoring via serial consoles (PowerShell, PuTTY).
4. **Timebase Synchronization:** Employs the Cortex-M SysTick timer for accurate millisecond intervals and runtime telemetry calculations.

---

## How to Build & Flash

1. Clone this repository:
   ```bash
   git clone [https://github.com/Mihir-tech2004/stm32-telemetry-dashboard.git](https://github.com/Mihir-tech2004/stm32-telemetry-dashboard.git)
