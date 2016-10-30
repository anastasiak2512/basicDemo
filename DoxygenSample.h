//
// Created by AK on 30/10/16.
//

#ifndef DEMOMORE_DOXYGENSAMPLE_H
#define DEMOMORE_DOXYGENSAMPLE_H


#include "DemoSamples.h"

class DoxygenSample {
public:
    //Generate documentation
    static bool checkIntVal(int val) { return true; }


    /// @brief The date of nth x-day in month.
    /// @return The date.
    DemoSamples CheckNDay(int n, ///< [in] The number of the x-day.
                          int x, ///< [in] x = 0 means Sunday, x = 1 means Monday, and so on.
                          int month, ///< [in] Month given.
                          int year, ///< [in] Year given.
                          int day = 0 ///< [in] Day given. If day is omitted or 0, it defaults
                                      ///       to 1 if n>0, and month's last day otherwise.
    ) {
        //TODO:
    }

};


#endif //DEMOMORE_DOXYGENSAMPLE_H
