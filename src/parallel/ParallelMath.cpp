//
// Created by Xiaoyong on 2020/12/28.
//

#include <parallel/ParallelMath.hpp>

namespace slc {
    void ParallelMath::setLogger(Logger &log) { this->logger = log; }

    void ParallelMath::setConfigure(IniConfiguration &config) { this->configuration = config; }

#pragma region accelerate with open mp

    int *ParallelMath::add(const int *a, const int *b, int c) {
        int* res = new int[c];
#pragma omp parallel for
        for (int i = 0; i < c; ++i) {
            res[i] = a[i] + b[i];
        }

        return res;
    }

#pragma endregion
}