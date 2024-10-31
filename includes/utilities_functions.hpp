/**@Author  : Mahmoud Ahmed.
 *@Linkedin: www.linkedin.com/in/mahmoud-ahmed-b4a639202
 *@Date    : Oct 2024.
 *@Summary : These are Helper Functions that used by classes .   */



#ifndef _UTILITIES_FUNCTIONS_HPP_
#define _UTILITIES_FUNCTIONS_HPP_


#include <iostream>
#include <memory>
#include <ctime>
#include <string>
#include "vehicles.hpp"


std::string gettime()
{
        //current date/time based on current system
        time_t now = time(0);
        //convert now to string form
        char* dt = ctime(&now);
        return std::string(dt);
}
void inputData(std::shared_ptr<Vehicle> ve)
{
    double spd,acc, Xs, Ys;
    std::cout<< "Enter vehicle speed: " ;
    std::cin >> spd;
    ve->setSpeed(spd);

    std::cout<< "Enter vehicle location (latitude, longitude): " ;
    std::cin >> Xs >> Ys;
    ve->setX(Xs);
    ve->setY(Ys);

    std::cout<< "Enter vehicle Acceleration: " ;
    std::cin >> acc;
    ve->setAcceleration(acc);
}



#endif
