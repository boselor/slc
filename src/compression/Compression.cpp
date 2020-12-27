#include <compression/Compression.hpp>
#include <compression/7z/SevenZCompression.hpp>

namespace slc {
    ICompression Compression::createZiper() {
        SevenZCompression seven;
        return seven;
    }

    ICompression Compression::create7Zer() {
        SevenZCompression seven;
        return seven;
    }

    ICompression Compression::createWinRarer() {
        SevenZCompression sc;
        return sc;
    }
}