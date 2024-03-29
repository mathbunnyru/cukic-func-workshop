#include <iostream>
#include <vector>
#include <functional>
#include <range/v3/view.hpp>

using namespace ranges::v3;
using namespace std::placeholders;

bool index_filter(size_t index) {
    return index % 3 != 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> xs = { -1, -3, -5, 1, 3, 5};

    // In order to get indices with the values,
    // we can simply zip the xs range with an infinite range
    // of integers.
    auto results =
        view::zip(xs, view::ints(1))
           | view::filter([] (auto value) { return index_filter(value.second); })
           | view::transform([] (auto value) { return value.first; });

    for (auto value: results) {
        std::cout << value << std::endl;
    }

    return 0;
}
