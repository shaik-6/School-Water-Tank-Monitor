# School Water Tank Level and Overflow Monitor

## Problem Statement

Many schools experience water wastage because overhead tanks overflow or become empty without anyone noticing. This project monitors the tank's water level, provides local alerts, detects sensor faults, and simulates data transmission using Wi-Fi.

---

## Objective

To build an ESP32-based water tank monitoring system that:

- Measures water level
- Alerts for overflow and low water level
- Detects sensor faults
- Simulates Wi-Fi communication
- Demonstrates store-and-forward functionality
- Uses non-blocking programming with millis()

---

## Components Used

- ESP32 DevKit
- Potentiometer (Water Level Sensor Simulation)
- Green LED
- Red LED
- Buzzer
- Wokwi Simulator

---

## Software Used

- Wokwi Simulator
- Arduino IDE (ESP32)
- GitHub

---

## Circuit Connections

| Component | ESP32 Pin |
|----------|-----------|
| Potentiometer Middle Pin | GPIO34 |
| Potentiometer Left Pin | GND |
| Potentiometer Right Pin | 3V3 |
| Green LED | GPIO2 |
| Red LED | GPIO4 |
| Buzzer | GPIO5 |

---

## Features

- Water level monitoring
- Overflow alert
- Low water alert
- Moving average filtering
- Sensor fault detection
- Wi-Fi connection simulation
- Store-and-forward data simulation
- Non-blocking timing using millis()

---

## How to Run

1. Open the project in Wokwi.
2. Start the simulation.
3. Rotate the potentiometer to change the water level.
4. Observe the Serial Monitor.
5. Green LED indicates normal condition.
6. Red LED and buzzer indicate overflow or low water level.
7. Sensor fault is displayed if the reading remains unchanged for a long time.
8. Wi-Fi simulation demonstrates sending and storing data.

---

## Output

### Normal

- Green LED ON
- Red LED OFF
- Buzzer OFF
- Status: NORMAL

### Overflow

- Water Level > 90%
- Red LED ON
- Buzzer ON

### Low Water

- Water Level < 20%
- Red LED ON
- Buzzer ON

### Sensor Fault

- Sensor Fault message displayed
- Red LED ON
- Buzzer ON

### Network Down

- Reading Stored

### Network Restored

- Stored data uploaded

---

## Test Cases

| Test Case | Result |
|-----------|--------|
| Normal Water Level | Passed |
| Overflow Condition | Passed |
| Low Water Level | Passed |
| Sensor Fault | Passed |
| Wi-Fi Simulation | Passed |

---

## Project Structure

```
School-Water-Tank-Monitor/
│
├── sketch.ino
├── diagram.json
├── README.md
├── wokwi-project.txt
├── screenshots/
└── demo-video.mp4
```

---

## Future Improvements

- Real ultrasonic water level sensor
- MQTT cloud integration
- Mobile notifications
- LCD display
- Automatic pump control

---

## Author

**Shaik Hisham S K**

BE Electrical and Electronics Engineering

Prince Shri Venkateshwara Padmavathy Engineering College

---

## License

This project is created for the SIH 2026 Practical Assessment and is intended for educational purposes.
