#include <core/EDateTime.h>
#include <chrono>
namespace slc {
    EDateTime::EDateTime() {
        auto now = std::chrono::system_clock::now();
    }

    EDateTime EDateTime::Now() {
        return EDateTime();
    }
}