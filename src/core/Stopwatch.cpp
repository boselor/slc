#include <core/Stopwatch.hpp>

namespace slc {
    void Stopwatch::start() {
        past = std::chrono::steady_clock::now();
    }

    void Stopwatch::stop() {
        cur = std::chrono::steady_clock::now();
    }

    double Stopwatch::timeSpan() {
        std::chrono::duration<double> duration_cost = std::chrono::duration_cast<
                std::chrono::duration<double> >(cur - past);
        return duration_cost.count();
    }
}