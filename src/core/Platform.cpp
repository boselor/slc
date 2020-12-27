#include <core/Platform.hpp>

namespace slc {
    Platform::Platform(/* args */) {
    }

    Platform::~Platform() {
    }
    bool Platform::IsPlatform(EString val) {
        return false;
    }
    bool Platform::IsWindows() {
#ifdef __WIN32
        return true;
#else
        return false;
#endif
    }
    bool Platform::IsLinux() {
#ifdef __LINUX__
        return true;
#else
        return false;
#endif
    }
}