#include <iostream>

using namespace std;

#include "timer.h"

class Listener : public IListener {
public:
    void OnTimeout() override {
        static uint32_t elapsed_second = 0;
        ++elapsed_second;
        std::cout << "Elapsed time(s): " << elapsed_second << std::endl;
    }
};

int main() {
    Timer timer(std::make_shared<Listener>());
    timer.Start(1000);

    std::cin.get();

    return 0;
}
