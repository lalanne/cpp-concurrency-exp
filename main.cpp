
#include <iostream>

int sum(const int a, const int b) { return a + b; }

int main() {
    std::cout << "hello world\n";

    const auto a{4};
    const auto b{5};

    auto c{sum(a, b)};

    std::cout << "result[" << c << "]\n";

    return 0;
}
