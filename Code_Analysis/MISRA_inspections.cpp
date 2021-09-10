// To enable MISRA Check
// go to Settings/Preferences | Editor | Inspections | C/C++ | General | MISRA Checks
// note that clang-tidy is built one and calngd via clang-tidy is enabled


void check(int argc[]) { // 3-1-3
    switch (argc[0]) {
        default: // 6-4-6
        case 1:
            break;
    }

    bool a = true, b = false, c = a < b; // 4-5-1

    int ***pInt = nullptr; // 5-0-19

    float f = (float) 1; // 5-2-4
}

