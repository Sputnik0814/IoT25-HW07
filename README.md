# HW7 - BLE-Based Distance Estimation Experiment

## Objective
The goal of this experiment is to collect RSSI (Received Signal Strength Indicator) values from BLE advertisements and estimate the physical distance between two ESP32 devices using a standard RSSI-to-distance formula.

We observe how the estimated distance changes with varying RSSI values and physical positioning, and analyze the accuracy and consistency of the results.

## System Configuration
- **BLE Server**: Continuously sends BLE advertisements using the device name `"HW7_SERVER"`
- **BLE Client**: Scans for nearby BLE devices, filters by device name, and collects RSSI values
- **Distance Estimation Formula**:  
  \[
  \text{distance} = 10^{\frac{(TxPower - RSSI)}{10 \cdot n}}
  \]  
  - `TxPower`: -59 dBm (RSSI at 1 meter)
  - `n`: 2.0 (signal propagation constant for indoor environments)
- **Hardware**: 2 × ESP32 development boards
- **Output**: Estimated distance printed to the serial monitor (via UART)

## Experiment Method
1. Place the BLE server and client at fixed distances (0.5m to 4.0m)
2. Run a BLE scan for 2–5 seconds at each distance
3. Collect multiple RSSI readings and apply the estimation formula
4. Record and compare estimated distances with actual measurements

## RSSI and Estimated Distance Table

| Measurement No. | Actual Distance (m) | RSSI (dBm) | Estimated Distance (m) |
|------------------|----------------------|------------|--------------------------|
| 1                | 0.5                  | -72        | 0.53                     |
| 2                | 1.0                  | -72        | 1.07                     |
| 3                | 2.0                  | -80        | 2.12                     |
| 4                | 3.0                  | -84        | 3.18                     |
| 5                | 4.0                  | -83        | 4.26                     |

![image](https://github.com/user-attachments/assets/73910b57-b7b7-4500-a78f-725973c517ca)


## Analysis
- RSSI values decreased consistently as the distance increased, which matches the expected theoretical behavior.
- Minor fluctuations in RSSI were observed due to indoor interference, reflections, and environmental factors.
- The BLE-based distance estimation formula provided a **reasonable approximation** of actual distance.
- However, due to the **unreliable nature of RSSI**, further techniques such as averaging, filtering, or environmental calibration would be needed for higher accuracy in real-world scenarios.
