#ifndef SL_ICOMRESSION
#define SL_ICOMRESSION
namespace slc{
    class ICompression{
    public:
        virtual void Decompress();
        virtual void Encompress();
    };
}
#endif