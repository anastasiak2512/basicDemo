#ifndef CLION2017_1DEMO_SAMPLE_LIB_H
#define CLION2017_1DEMO_SAMPLE_LIB_H

#include <string>

auto intToBasedString( int value, int base ) -> std::string;

template<int base>
class Base {
    static_assert( base <= 26, "Out of letters!" );

    int m_decimalValue;

public:
    constexpr Base( const int decimalEncoded ) : m_decimalValue( decimalEncoded ) {}

    auto asString() const { return intToBasedString( m_decimalValue, base ); }

    bool operator==( std::string const& other ) const {
        return other == asString();
    }
};

template<typename T>
constexpr T answer = { 6*9 };


#endif //CLION2017_1DEMO_SAMPLE_LIB_H