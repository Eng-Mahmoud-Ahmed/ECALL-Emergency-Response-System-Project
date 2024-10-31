/*
 *@Auther  : Mahmoud Ahmed.
 *@Linkedin: www.linkedin.com/in/mahmoud-ahmed-b4a639202
 *@Date    : Oct 2024.
 *@Summary : Implement Emergency call class with dependecies.   
*/

#ifndef _ECALLSYSTEM_HPP_
#define _ECALLSYSTEM_HPP_

//Dependencies
#include <iostream>
#include <memory>
#include <string>

#include "utilities_functions.hpp"
#include "vehicles.hpp"
#include "NotificationServices.hpp"
#include "logs.hpp"


class ECALLSystem
{   
    private:
        std::shared_ptr<Vehicle> mp_vehicle;
        std::shared_ptr<NotificationService> mp_notif;
        std::shared_ptr<Logs> m_log_service;

    public:
        // Constructor with m_log_service initialization
        ECALLSystem(std::shared_ptr<Vehicle> v, std::shared_ptr<NotificationService> n, std::shared_ptr<Logs> log_service)
            : mp_vehicle(v), mp_notif(n), m_log_service(log_service) {}

        void HandleAccidentDetected()
        {
            if(mp_vehicle->detectAccident()) // accident detected.
            {   
                std::string msg = std::string("\nAccident detected. Initiating emergency call...\n") 
                    + "Vehicle ID: " + mp_vehicle->getId() + "\n"
                    + "Location: ( " + std::to_string(mp_vehicle->getX()) + ", " + std::to_string(mp_vehicle->getY()) + " )\n"
                    + "Speed: " + std::to_string(mp_vehicle->getSpeed()) + " km/h\n" 
                    + "Acceleration: " + std::to_string(mp_vehicle->getAcceleration()) + " m/s^2\n"
                    + "Time: " + gettime() + "\n";

                // send data msg as notification
                mp_notif->sendNotification(msg);
                // append accident log to file
                m_log_service->append_accident_log(msg);
            }
        }
};


#endif