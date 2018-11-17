#include <ios>
#include <iomanip>

#include <stdlib.h>

#include <LightGBM/reporting.h>
#include <LightGBM/utils/log.h>

namespace LightGBM {

FloatWriter::FloatWriter(const std::string &filename, double sample_prob)
    : sample_prob_(sample_prob)
{
    file_.open(filename);
    Log::Info("FloatWriter(\"%s\") constructed with sample probability %f",
            filename.c_str(), sample_prob);
}

template <typename F>
void
FloatWriter::WriteFloats(size_t num_floats, F const *floats)
{
    size_t count = 0;
    for (size_t i = 0; i < num_floats; ++i) {
        auto r = (rand() * 1.0) / RAND_MAX;
        if (r <= sample_prob_) {
            file_ << std::scientific << std::setprecision(4) << floats[i] << ' ';
            ++count;
        }
    }
    file_ << std::endl << std::endl;
    Log::Info("FloatWriter: Wrote %d out of %d floats to file", count, num_floats);
}

template
void
FloatWriter::WriteFloats(size_t, float const*);

template
void
FloatWriter::WriteFloats(size_t, double const*);


} // namespace LightGBM
