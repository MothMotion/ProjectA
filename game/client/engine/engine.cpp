#include "engine.h"

/*
 * Здесь находятся общие методы всех существующих классов.
 * Все методы относятся к пространству engine, но ни один
 * из них не принадлежат ни одному классу.
*/


namespace engine {
  std::bitset<16> connectBits(std::bitset<2>& bitset1, std::bitset<14>& bitset2) {
  std::bitset<16> temp;
  for(unsigned char i=0; i<16; ++i)
    (i<2) ? (temp[i] = bitset1[i]) : (temp[i] = bitset2[i-2]);
  return temp;
  }


template <typename TypeXY, typename TypeZ>
std::ostream& operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ>& Vector) {
    Out << Vector.getX() << " " << Vector.getY() << " " << Vector.getZ();
    return Out;
}
template <typename TypeXY, typename TypeZ>
std::istream& operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ>& Vector) {
    TypeXY x, y; TypeZ z; In >> x >> y >> z; Vector.setX(x); Vector.setY(y); Vector.setZ(z);
    return In;
}

template std::ostream& operator<< <short, char>(std::ostream& Out, const engine::vec<short, char>& Vector);
template std::istream& operator>> <short, char>(std::istream&  In, engine::vec<short, char>& Vector);

template std::ostream& operator<< <float, float>(std::ostream& Out, const engine::vec<float, float>& Vector);
template std::istream& operator>> <float, float>(std::istream&  In, engine::vec<float, float>& Vector);

template std::ostream& operator<< <double, double>(std::ostream& Out, const engine::vec<double, double>& Vector);
template std::istream& operator>> <double, double>(std::istream&  In, engine::vec<double, double>& Vector);

template std::ostream& operator<< <long, int>(std::ostream& Out, const engine::vec<long, int>& Vector);
template std::istream& operator>> <long, int>(std::istream&  In, engine::vec<long, int>& Vector);
}
