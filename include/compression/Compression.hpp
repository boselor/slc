#include <compression/ICompression.hpp>
#ifndef SL_COMRESSION
#define SL_COMRESSION
namespace slc{
    class Compression{
    public:
        static ICompression createZiper();
        static ICompression create7Zer();
        static ICompression createWinRarer();
    };
}
#endif