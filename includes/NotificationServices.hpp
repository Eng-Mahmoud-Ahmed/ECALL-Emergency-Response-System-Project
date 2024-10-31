/*
 *@Author  : Mahmoud Ahmed.
 *@Linkedin: www.linkedin.com/in/mahmoud-ahmed-b4a639202
 *@Date    : Oct 2024.
 *@Summary : NotificationSercice class as abstract class using polymorphism concept.   
*/

#ifndef _NOTIFICATION_SERVICES_HPP_
#define _NOTIFICATION_SERVICES_HPP_

//Dependencies
#include <iostream>
#include <string>

class NotificationService {
    public: 
        //Pure virtuall function for applying polymorphism concept.
        virtual void sendNotification(std::string message) =0;
};
class SMS_Service : public NotificationService
{
        void sendNotification(std::string message) override
        {
            std::cout << "Sending SMS: " << message << std::endl;
        }
};
class Email_Service : public NotificationService
{
        void sendNotification(std::string message) override
        {
            std::cout << "Sending Email: " << message << std::endl;
        }
};


#endif
