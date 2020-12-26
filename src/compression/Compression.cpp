#include <compression/Compression.hpp>
#include <compression/7z/SevenZCompression.hpp>

namespace slc {
    ICompression Compression::createZiper() {}

    ICompression Compression::create7Zer() {}

    ICompression Compression::createWinRarer() {
        SevenZCompression sc;
        return sc;
    }
}