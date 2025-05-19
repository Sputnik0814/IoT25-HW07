# HW7 - BLE-Based Distance Estimation Experiment

## Objective
The goal of this experiment is to collect RSSI (Received Signal Strength Indicator) values from BLE advertisements and estimate the physical distance between two ESP32 devices using a known RSSI-to-distance formula.

We observe how the estimated distance changes with varying RSSI values and physical positioning, and analyze the accuracy and consistency of the results.

## System Configuration
- **BLE Server**: Sends BLE advertisements using the device name `"HW7_SERVER"`
- **BLE Client**: Scans for nearby BLE devices, filters by name, and collects RSSI values
- **Distance Estimation Formula**:  
  \[
  \text{distance} = 10^{\frac{(TxPower - RSSI)}{10 \cdot n}}
  \]  
  - `TxPower`: -59 dBm (RSSI at 1m)
  - `n`: 2.0 (typical indoor environment)
- **Hardware**: 2 × ESP32 boards
- **Output**: Estimated distance printed to the serial monitor

## Experiment Method
1. Place the BLE server and client at fixed distances (0.5m to 3.0m)
2. Run a BLE scan for 2–5 seconds at each position
3. Collect RSSI values and compute estimated distance using the formula
4. Record and compare estimated results with actual distances

## RSSI vs. Estimated Distance Table

| Measurement No. | RSSI (dBm) | Estimated Distance (m) |
|------------------|------------|--------------------------|
| 1                | -72        | 1.18                     |
| 2                | -72        | 1.18                     |
| 3                | -80        | 2.28                     |
| 4                | -80        | 2.28                     |
| 5                | -84        | 3.16                     |
| 6                | -83        | 2.91                     |

## Analysis
- RSSI values decrease consistently as the distance increases.
- Some signal fluctuations were observed, likely due to interference and reflection in the indoor environment.
- The BLE RSSI-based formula provided a **reasonable approximation** of distance.
- However, due to the **instability of RSSI**, additional calibration, filtering, or averaging techniques may be required for more accurate real-world applications.
