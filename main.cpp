
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int sum(const int a, const int b) {
    std::this_thread::sleep_for(5000ms);
    return a + b;
}

int main() {
    std::cout << "hello world\n";

    const auto a{4};
    const auto b{5};

    // thread based approach
    std::thread t([] {
        auto c{sum(a, b)};
        std::cout << "result[" << c << "]\n";
    });

    std::cout << "waiting for thread based computation\n";
    std::this_thread::sleep_for(6000ms);

    const auto c{5};
    const auto d{10};

    // task based approach
    auto fut = std::async(std::launch::async, [&] {
        auto e{sum(c, d)};
        return e;
    });

    std::cout << "waiting for task based computation\n";
    std::cout << "result[" << fut.get() << "]\n";

    return 0;
}
