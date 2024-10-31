/*
 *@Auther  : Mahmoud Ahmed.
 *@Linkedin: www.linkedin.com/in/mahmoud-ahmed-b4a639202
 *@Date    : Oct 2024.
 *@Summary : Implement Logs class that support the user to:
 *                    1- Append accident log.  
 *                    2- Read all previous logs.  
*/

#ifndef _LOGS_HPP_
#define _LOGS_HPP_

//Dependencies
#include <iostream>
#include <string>
#include <fstream>


class Logs
{
    private:
        std::string m_path;
    public:
        //Parameterized constructor
        Logs(std::string path):m_path(path){}
        void append_accident_log(std::string s)
        {
            // First, check if the file exists by opening it in read mode
            std::ifstream checkFile(m_path);
            if (!checkFile.is_open())
            {
                std::cerr << "Error: Log file does not exist.\n";
                return;
            }
            checkFile.close();

            // Now open the file in append mode to add the log
            std::ofstream logfile(m_path, std::ios::app);
            if (logfile.is_open())
            {
                logfile << s;
            }
            else
            {
                std::cerr << "Error: Could not open log file for writing\n";
            }
            logfile.close();
        }
        void ReadAllLogs()
        {
            std::ifstream file(m_path);
            std::string line;

            if (file.is_open())
            {
                while (std::getline(file, line))
                {
                    std::cout << line << std::endl;
                }
                file.close();
            }
            else
                std::cerr << "Error: Log file does not exist.\n";
        }  

};

#endif


