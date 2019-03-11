#include <algorithm>
#include <cinttypes>
#include <vector>

#include "sgx_trts.h"

template<class result_type_param = uint32_t>
class sgx_random_device
{
public:
    using result_type = result_type_param;

    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }

    result_type operator()() {
        result_type val;
        if (sgx_read_rand((unsigned char*)&val, sizeof(result_type)) == SGX_SUCCESS) {
            return val;
        }
        throw 0;
    }
};

void ecall_sgx_random_device()
{
    sgx_random_device<> rd;

    // Uniformly random integers in range [0, 100]
    std::uniform_int_distribution<> uni_int{0, 100};
	uint32_t a = uni_int(rd);
	uint32_t b = uni_int(rd);

    // Randomly shuffle vector.
    std::vector<int> v{0, 1, 2, 3, 4, 5};
    std::shuffle(v.begin(), v.end(), rd);
}
