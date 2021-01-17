//
// Created by xiaoyong on 2020/12/26.
//

#ifndef SLC_STOPWATCH_H
#define SLC_STOPWATCH_H
#include <chrono>
namespace slc{
    class Stopwatch{
    private:
        std::chrono::steady_clock::time_point past, cur;
    public:
        void start();
        void stop();
        double timeSpan();
    };
}
#endif //SLC_STOPWATCH_H
