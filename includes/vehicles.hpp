/*
 *@Author  : Mahmoud Ahmed.
 *@Linkedin: www.linkedin.com/in/mahmoud-ahmed-b4a639202
 *@Date    : Oct 2024.
 *@Summary : Implement Vehicle class as an abstract class in cpp.   
*/

#ifndef _VEHICLES_HPP_
#define _VEHICLES_HPP_

//Dependencies
#include <iostream>
#include <string>


class Vehicle{
    protected:
        std::string m_id;
        double m_speed;
        double m_xLocation;
        double m_yLocation;
        double m_acceleration;

    public: 
        //Constructors
        Vehicle(std::string id,double speed, double x, double y, double acc)
        : m_id(id), m_speed(speed), m_xLocation(x), m_yLocation(y), m_acceleration(acc){}
        //Destructor
        virtual ~Vehicle() = default;
        //Setters
        void setId(std::string id){m_id = id;}
        void setX(double x){m_xLocation=x;}
        void setY(double y){m_yLocation=y;}
        void setSpeed(double speed){
            if(speed>=0)
                m_speed=speed;
            else
                std::cout<<"Wrong input, speed must be positive value!\n";
            }
            
        void setAcceleration(double acc){m_acceleration=acc;}
        //Gettters
        std::string getId(){return m_id;}
        double getSpeed(){return m_speed;}
        double getAcceleration(){return m_acceleration;}
        void   getLocation(double *x, double *y)
        {
            *x=m_xLocation;
            *y=m_yLocation;
        }
        double getX(){return m_xLocation;}
        double getY(){return m_yLocation;}

        //accident detection 
        virtual bool detectAccident()=0;

};

//Car inheriting from Vehicle class
class Car : public Vehicle {
    public:
        Car(std::string id, double spd, double x, double y, double acc): Vehicle(id, spd, x, y, acc){}
        bool detectAccident() override
        {
             return (m_acceleration < -9.8 && m_speed == 0); //high deceleration and vehicle stopped
        }
};

//Truck inheriting from Vehicle class
class Truck : public Vehicle {
    public:
        Truck(std::string id, double spd, double x, double y, double acc): Vehicle(id, spd, x, y, acc){}
        //custom accident detection logic for trucks
        bool detectAccident() override
        {
            return ( m_acceleration < -8.5 && m_speed == 0); //Different threshold for trucks
        }
};


#endif
