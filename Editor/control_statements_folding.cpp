// Control statements (if/else, do/while, for, switch) can be folded/expanded via
// Shift+Ctrl+Period/Ctrl+= on Linux/Windows and ⇧⌘./⌘+ on macOS.
// It works for any block with more than one line of code or any block inside the braces
// You can view the folded content via hover.

#include <iostream>
#include <algorithm>
#include <string>

void generate_permutation(std::string input)
{
    int count = 0;
    std::sort(input.begin(), input.end());

    do {
        count++;
        std::cout << input << '\n';
    } while(std::next_permutation(input.begin(), input.end()));
}
