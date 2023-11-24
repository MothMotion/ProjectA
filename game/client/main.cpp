#include "engine/engine.h"



int main() {
    engine::vec<short, char> test1(1,1,1);
    std::cout << test1;
    engine::vec<short, char> resolution(80, 24, 0);
    engine::vec<short, char> res(80, 24, 0);// int x(2);
    //resolution == res; resolution.operator*=(x);
    //engine::vec<short, char> test = res * 3;
    /*std::cout << test << std::endl;
    std::cout << engine::vec<short, short, char>(1,2) * 2 << std::endl;
    std::cout << engine::vec<short, char, int>(1,2) / engine::vec<short, chxar, int>(-1, 0, 2) << std::endl;
    */return 0;
}