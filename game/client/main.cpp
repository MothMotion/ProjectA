#include "engine/engine.h"



int main() {
    engine::vec resolution(80, 24);
    engine::vec res(80, 24); int x(2);
    resolution == res; resolution *= x;
    engine::vec test = res * x;
    std::cout << test;
    std::cout << engine::vec(1,2) * 2;
    return 0;
}