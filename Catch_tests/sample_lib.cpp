#include "sample_lib.h"

auto intToBasedString( int value, int base ) -> std::string {
    std::string digits;
    do {
        int units = value % base;
        char c = static_cast<char>( units < 10 ? '0'+units : 'A'+units-10 );
        digits = std::string(1,c) + digits;
        value /= base;
    }
    while( value > 0 );

    return digits;
}
