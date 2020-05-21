//
// Created by home-6 on 12.04.20.
//

#include <iostream>

#include "Log.h"

void Logger:: dbg( const std::string& msg ) {log(DBG, msg);}
void Logger::info( const std::string& msg ) {log(INFO, msg);}
void Logger::warn( const std::string& msg ) {log(WARN, msg);}
void Logger::fuck( const std::string& msg ) {log(FUCK, msg);}

void Logger::log( int value, const std::string & msg){

    if (value < Logger::severity) return;
    switch(value) {
        case(DBG ): std::cout << "DBG "; break;
        case(INFO): std::cout << "INFO"; break;
        case(WARN): std::cout << "WARN"; break;
        case(FUCK): std::cout << "FUCK"; break;
        default:
        std::cout << std::cout.width(4) << std::cout.fill(' ') << value;
    }

    std::cout << ": " << msg << std::endl;

}

int Logger::severity = 20;



// TODO create instances for subject in their respective namespace;
// use classes;
// namespace Arduino {Logger log(prefix, severity, ...);}