#include "engine/engine.ipp"



int main() {
    engine::vec resolution(short(80), short(24));
    engine::vec res(short(80), short(24)); int x(2);
    resolution == res; resolution *= x;
    engine::vec test = res * x;
    std::cout << test << std::endl;
    std::cout << engine::vec<short, short, char>(1,2) * 2 << std::endl;
    std::cout << engine::vec<short, char, int>(1,2) / engine::vec<short, char, int>(-1, 0, 2) << std::endl;
    return 0;
}