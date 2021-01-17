#include <core/EString.hpp>
#ifndef SLC_EDATETIME_H
#define SLC_EDATETIME_H
namespace slc{
    class EDateTime{
    public:
        int Year = 1990, Month = 1, Day = 1, Hour = 0, Minutes = 0, Second = 0, MicroSeconds = 0, MiuSeconds = 0;
        EDateTime();
        ~EDateTime();
        static EDateTime Now();
        EString toString(EString format);
        EDateTime TimeSpan(EDateTime date);

        EDateTime operator+(const EDateTime data);
        EDateTime operator-(const EDateTime date);

        int toYears();
        int toMonths();
        int toDays();
        int toMinutes();
        int toSeconds();
        long toMicroSeconds();
        long toMiuSeconds();
    };
}
#endif //SLC_EDATETIME_H
