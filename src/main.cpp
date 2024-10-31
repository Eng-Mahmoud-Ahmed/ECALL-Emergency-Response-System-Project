#include <iostream>
#include <memory>
#include "vehicles.hpp"
#include "NotificationServices.hpp"
#include "ECALLSystem.hpp"
#include "logs.hpp"
#include "utilities_functions.hpp"

int main()
{    
    std::string mypath = "../resources/accident_log.csv";
    std::shared_ptr<Logs> mylog(new Logs(mypath));

    std::shared_ptr<Vehicle> v1(new Car("xyz-15", 0, 316.5, 152, -15));     //Accident.
    std::shared_ptr<Vehicle> v2(new Truck("miraj-150", 0, 2.5, 7.5, -10));  //Accident.
    std::shared_ptr<Vehicle> v3(new Truck("nasr-11", 0, 55, 90, 0));        //Normal stop, Not accident.
    std::shared_ptr<Vehicle> red_car(new Car("dragon-50", 0, 0, 0, 0));     //get data from terminal.
    //Prompt the user for input data for red car.
    std::cout << "Enter data for Car dragon-50:\n";
    inputData(red_car);

    //Create notification services
    std::shared_ptr<NotificationService> notifi_email(new Email_Service);
    std::shared_ptr<NotificationService> notifi_sms(new SMS_Service);

    //Set up ECALL system instances with the vehicles and notification services
    ECALLSystem e1(v1, notifi_sms, mylog);
    ECALLSystem e2(v2, notifi_email, mylog);
    ECALLSystem e3(v3, notifi_sms, mylog);
    ECALLSystem e4(red_car, notifi_sms, mylog);

    //Check for accident detection and handle notifications
    e1.HandleAccidentDetected();
    e2.HandleAccidentDetected();    
    e3.HandleAccidentDetected();
    e4.HandleAccidentDetected();

    // Display all accident logs
    std::cout << "\n************************\n";
    std::cout << "Print all Accidents Logs";
    std::cout << "\n************************\n";

    mylog->ReadAllLogs();

    return 0;
}
