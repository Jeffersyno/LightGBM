#ifndef LIGHTGBM_REPORTING_H_
#define LIGHTGBM_REPORTING_H_

#include <iostream>
#include <fstream>

namespace LightGBM {


/**
 * Write floats to a file for debugging (e.g. estimating distribution of
 * scores).
 */
class FloatWriter {
public:
    FloatWriter(const std::string &filename, double sample_prob);

    template <typename F>
    void
    WriteFloats(size_t num_floats, F const *floats);

private:
    std::ofstream file_;
    double sample_prob_;
};


} // namespace LightGBM


#endif // LIGHTGBM_REPORTING_H_
