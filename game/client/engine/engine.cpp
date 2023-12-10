#include "engine.h"

/*
 * Здесь находятся общие методы всех существующих классов.
 * Все методы относятся к пространству engine, но ни один
 * из них не принадлежат ни одному классу.
*/

inline void engine::arraySet(bool arr1[], bool arr2[], short size) noexcept {
  for(short i=0; i<size; ++i) arr1[i] = arr2[i];
}

template <typename TypeXY, typename TypeZ>
std::ostream& engine::operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ>& Vector) {
    Out << Vector.getX() << " " << Vector.getY() << " " << Vector.getZ();
    return Out;
}
template <typename TypeXY, typename TypeZ>
std::istream& engine::operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ>& Vector) {
    TypeXY x, y; TypeZ z; In >> x >> y >> z; Vector.setX(x); Vector.setY(y); Vector.setZ(z);
    return In;
}

template std::ostream& engine::operator<< <short, char>(std::ostream& Out, const engine::vec<short, char>& Vector);
template std::istream& engine::operator>> <short, char>(std::istream&  In, engine::vec<short, char>& Vector);

template std::ostream& engine::operator<< <float, float>(std::ostream& Out, const engine::vec<float, float>& Vector);
template std::istream& engine::operator>> <float, float>(std::istream&  In, engine::vec<float, float>& Vector);

template std::ostream& engine::operator<< <double, double>(std::ostream& Out, const engine::vec<double, double>& Vector);
template std::istream& engine::operator>> <double, double>(std::istream&  In, engine::vec<double, double>& Vector);

template std::ostream& engine::operator<< <long, int>(std::ostream& Out, const engine::vec<long, int>& Vector);
template std::istream& engine::operator>> <long, int>(std::istream&  In, engine::vec<long, int>& Vector);
