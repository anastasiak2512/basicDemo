#include <unistd.h>
#include <pwd.h>

#include <iostream>

class User {
    std::string m_name;
    enum class Privileges {
        Unset,
        Normal,
        Root
    };
    Privileges m_privileges;

    Privileges detectPrivileges() {
        Privileges privileges = Privileges::Normal;
        if( m_name == "root" ) {
            privileges = Privileges::Root;
        }
        return privileges;
    }

public:
    User()
    :   m_name( getpwuid( geteuid())->pw_name ),
        m_privileges( detectPrivileges() )
    {
        if( m_privileges != Privileges::Root && m_privileges != Privileges::Normal )
            throw std::domain_error( "Unable to deduce privileges" );
    }

    auto name() const { return m_name; }


    friend std::ostream& operator<<( std::ostream& os, User const& user ) {
        os << "user: '" << user.m_name << "'";
        if( user.m_privileges == Privileges::Root )
            os << " (root user)";
        else
            os << " (non-root user)";
        return os;
    }
};

int main() {
    User user;
    std::cout << user << "\n";
}
