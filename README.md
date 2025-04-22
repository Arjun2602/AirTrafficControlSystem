# Air Traffic Control System

A C++-based console application that simulates an air traffic control system, managing flight takeoffs and landings using multithreading. Designed using object-oriented principles with real-time runway allocation logic.

## Features

- **Multithreading**: Uses `std::thread` to simulate concurrent runway usage.
- **Runway Management**: Allocates runways based on flight weight and time constraints.
- **Real-Time Simulation**: Simulates actual delays and availability with `sleep_for`.
- **OOP Design**: Clean modular structure with classes like `Flight`, `Runway`, `System`, and `RunwayThreadManager`.
- **Console UI**: Menu-driven interface for takeoff, landing, and system monitoring.
- **Flight Types**: Predefined flights with max weight and time constraints.
- **Runway Status**: Tracks and displays busy/free status of each runway.

## Technologies Used

- **Language**: C++
- **Concepts**: Multithreading, OOP, STL (`map`, `unordered_map`)
- **Tools**: Git, GitHub

## How it Works

- User selects a flight operation (Takeoff or Landing).
- The system checks runway availability.
- Runways are dynamically allocated based on flight weight and maximum allowed seconds.
- Threads simulate runway usage for a given duration.
- Runways are marked busy during operations and freed after the thread completes.
