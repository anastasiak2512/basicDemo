#include <ctime>
#include <iostream>

// TODO: rework function
//  - calculate local time
//  - return string not int
//  - use chrono::system_clock
int calculate_date() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    return (now->tm_year + 1900) +
           (now->tm_mon + 1) +
           (now->tm_mday);
}

