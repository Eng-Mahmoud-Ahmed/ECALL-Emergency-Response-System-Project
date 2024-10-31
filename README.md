# ECALL Emergency Response System

## Project Overview
The ECALL Emergency Response System is a C++ application that simulates accident detection for vehicles and notifies emergency services accordingly. Using an object-oriented approach, the project manages various types of vehicles, notification services, and logs accident data.

## UML Diagram for the project classes and associations
![uml](https://github.com/user-attachments/assets/906f2301-1a5f-460e-aa49-2f31fadc6720)

## File Structure
- **ECALLSystem.hpp**: Defines the ECALL system and manages accident detection and notifications.
- **logs.hpp**: Implements the logging functionality to record accident data.
- **NotificationServices.hpp**: Contains the base class for notification services and derived classes for SMS and Email notifications.
- **vehicle.hpp**: Defines the base class for vehicles and specific implementations for cars and trucks.
- **utilities_functions.hpp**: Provides helper functions, including time retrieval for logging.

## Classes and Description

### 1. Vehicle
- **Purpose**: Abstract base class representing a vehicle.
- **Methods**:
  - `virtual bool detectAccident() = 0`: Detects accidents.

### 2. Car
- **Inherits from**: Vehicle
- **Purpose**: Represents a car and implements accident detection logic.

### 3. Truck
- **Inherits from**: Vehicle
- **Purpose**: Represents a truck and implements accident detection logic.

### 4. NotificationService
- **Purpose**: Abstract class for notification services.
- **Methods**:
  - `virtual void sendNotification(std::string message) = 0`: Sends notifications.

### 5. SMS_Service
- **Inherits from**: NotificationService
- **Purpose**: Sends SMS notifications.

### 6. Email_Service
- **Inherits from**: NotificationService
- **Purpose**: Sends Email notifications.

### 7. Logs
- **Purpose**: Handles logging of accident data.
- **Methods**:
  - `void append_accident_log(std::string s)`: Appends a log entry to the file.
  - `void ReadAllLogs()`: Reads and displays logs.

### 8. ECALLSystem
- **Purpose**: Manages the ECALL system functionalities.
- **Methods**:
  - `void HandleAccidentDetected()`: Detects an accident and triggers notifications and logging..

### 9.Accident Detection Logic in Code
For each vehicle, the detectAccident function checks these conditions:
-    **Car**: return (m_acceleration < -9.8 && m_speed == 0);
-   **Truck**: return (m_acceleration < -8.5 && m_speed == 0);
    
    
## Usage Instructions
### 1. Clone the Repository

git clone https://github.com/Eng-Mahmoud-Ahmed/ECALL-Emergency-Response-System-Project.git


### 2. Build the Project with CMake

mkdir build
cd build
cmake ..
make

### 3. Run the Application
./ecall_system

### 4. Input Data
When prompted, enter the vehicle speed, location, and acceleration for accident simulation.

### 5. View Accident Logs
Accident logs are saved in the specified log file and can be accessed to view the complete history of events.
License



