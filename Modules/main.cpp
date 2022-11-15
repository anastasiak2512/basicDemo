#include <iostream>
import AdvancedMath;
import Talk;

int main() {
    std::cout << hello() << ' ' << English() << ' '
              << hi::hi_French()
              << hi::hi_Dutch()
              << hi::hi_German()
              << '\n';

    std::cout << "1+2 = " <<
        AdvancedMath::plus(1, 2)  << "\n";
    std::cout << "3-2 = " << AdvancedMath::minus(3,2) << "\n";
    std::cout << "3+2+10 = " << AdvancedMath::complex_add(3, 2, 10) << "\n";
}