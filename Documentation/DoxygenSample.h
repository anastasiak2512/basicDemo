//- Preview compound Doxygen comment
//- Generate Doxygen documentation stub.
//- Rename some parameter, check changes in Doxygen comment

#ifndef DEMOMORE_DOXYGENSAMPLE_H
#define DEMOMORE_DOXYGENSAMPLE_H

class DoxygenSample {
public:
    // Generate
    static bool checkIntVal(int myVal) { return true; }


    /// @brief The date of nth x-day in month.
    /// @return The dete.
    int CheckNDay(int n, ///< [in] The number of the x-day.
                          int x, ///< [in] x = 0 means Sunday, x = 1 means Monday, and so on.
                          int month, ///< [in] Month given.
                          int year, ///< [in] Year given.
                          int day = 0 ///< [in] Day given. If day is omitted or 0, it defaults
                                      ///       to 1 if n>0, and month's last day otherwise.
    ) {
        //TODO:
        return 1;
    }

};


#endif //DEMOMORE_DOXYGENSAMPLE_H
