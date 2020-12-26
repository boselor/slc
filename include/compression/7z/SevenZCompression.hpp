#include <compression/ICompression.hpp>
#ifndef SLC_SevenZCompression
#define SLC_SevenZCompression
namespace slc{
    class SevenZCompression: public ICompression{
    public:
        void Decompress();
        void Encompress();
    };
}
#endif