//
// Created by home-6 on 12.04.20.
//

#pragma once

namespace Logger{

const int DBG  = 10;
const int INFO = 20;
const int WARN = 30;
const int FUCK = 40;

void log( int severity, const std::string& msg);
void dbg(  const std::string& msg );
void info( const std::string& msg );
void warn( const std::string& msg );
void fuck( const std::string& msg );

extern int severity;

}
