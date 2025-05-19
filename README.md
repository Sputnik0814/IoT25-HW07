# HW7 - BLE-Based Distance Estimation Experiment

## Objective
The goal of this experiment is to collect RSSI (Received Signal Strength Indicator) values from BLE advertisements and observe how they vary with distance.  
Rather than calculating distance using a formula, we focus on analyzing the correlation between actual distance and average RSSI values.

## System Configuration
- **BLE Server**: Sends BLE advertisements using the device name `"HW7_SERVER"`
- **BLE Client**: Scans for nearby BLE devices, filters by name, and collects RSSI values
- **Hardware**: 2 × ESP32 boards
- **Output**: RSSI values printed to the serial monitor

## Experiment Method
1. Place the BLE server and client at fixed distances (0.5m to 3.0m)
2. Run a BLE scan for 5 seconds at each position
3. Collect and average multiple RSSI readings per distance
4. Record the results in a table for analysis

> **No distance estimation formula** was used (e.g., `distance = 10^((TxPower - RSSI)/(10 * n))`)  
> Instead, we examine how RSSI changes with physical distance.

## Results (Example)

| Distance (m) | RSSI 1 | RSSI 2 | RSSI 3 | Avg RSSI (dBm) |
|--------------|--------|--------|--------|----------------|
| 0.5          | -52    | -53    | -51    | -52.0          |
| 1.0          | -58    | -59    | -57    | -58.0          |
| 2.0          | -66    | -65    | -67    | -66.0          |
| 3.0          | -73    | -72    | -74    | -73.0          |

See the bar chart in `/charts/ble_distance_graph.png`

## Analysis
- RSSI values decreased consistently as distance increased.
- Signal fluctuations occurred due to indoor obstacles and interference.
- The results show that BLE RSSI can provide a rough distance estimate,  
  but it requires averaging, filtering, or further calibration for practical use.
