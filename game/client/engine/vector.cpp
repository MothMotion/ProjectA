#include "engine.h"
/*
template class engine::vec<float, float>;       // Для точечного передвижения по глобальной карте. Координатная сетка сцены располагается на short int и char
template class engine::vec<short, char>;        // Стандартный вектор для координатной сетки основной сцены
template class engine::vec<long, int>;          // Стандартный вектор для глобальной карты
template class engine::vec<double, double>;     // Расширенный верктор глобальной карты или точечного передвижения
*/
template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>::vec() noexcept {this->x=0; this->y=0; this->z=0;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>::vec(TypeXY x, TypeXY y, TypeZ z) {this->x=x; this->y=y; this->z=z;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>::vec(TypeXY x, TypeXY y) {this->x=x; this->y=y; this->z=0;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>::vec(vec& copyData) noexcept {
    x = copyData.x;
    y = copyData.y;
    z = copyData.z;
}
template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>& engine::vec<TypeXY, TypeZ>::operator= (vec<TypeXY, TypeZ>& newData) noexcept {
    if(*this == newData) return *this;
    x = newData.x;
    y = newData.y;
    z = newData.z;
    return  *this;
}



template <typename TypeXY, typename TypeZ>
inline TypeXY engine::vec<TypeXY, TypeZ>::getX() const noexcept {return x;}
template <typename TypeXY, typename TypeZ>
inline TypeXY engine::vec<TypeXY, TypeZ>::getY() const noexcept {return y;}
template <typename TypeXY, typename TypeZ>
inline TypeZ  engine::vec<TypeXY, TypeZ>::getZ() const noexcept {return z;}

template <typename TypeXY, typename TypeZ>
inline void engine::vec<TypeXY, TypeZ>::setX(TypeXY newX) noexcept {x = newX;}
template <typename TypeXY, typename TypeZ>
inline void engine::vec<TypeXY, TypeZ>::setY(TypeXY newY) noexcept {y = newY;}
template <typename TypeXY, typename TypeZ>
inline void engine::vec<TypeXY, TypeZ>::setZ(TypeZ  newZ) noexcept {z = newZ;}



template <typename TypeXY, typename TypeZ>
double engine::vec<TypeXY, TypeZ>::getLen() const noexcept {return (double(x*x) + double(y*y) + double(z*z));}
template <typename TypeXY, typename TypeZ>
double engine::vec<TypeXY, TypeZ>::getLen(const vec& centerData) const noexcept
                                    {return (double((x-centerData.x)*(x-centerData.x))
                                                     + double((y-centerData.y)*(y-centerData.y))
                                                     + double((z-centerData.z)*(z-centerData.z)));}
template <typename TypeXY, typename TypeZ>
inline double engine::vec<TypeXY, TypeZ>::getDist() const noexcept {return sqrt(this -> getLen());}
template <typename TypeXY, typename TypeZ>
inline double engine::vec<TypeXY, TypeZ>::getDist(const vec& centerData) const noexcept {return sqrt(this -> getLen(centerData));}



template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>& engine::vec<TypeXY, TypeZ>::operator+= (const vec& vectorData) noexcept {x += vectorData.x; y += vectorData.y; z += vectorData.z; return *this;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>& engine::vec<TypeXY, TypeZ>::operator-= (const vec& vectorData) noexcept {x -= vectorData.x; y -= vectorData.y; z -= vectorData.z; return *this;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>& engine::vec<TypeXY, TypeZ>::operator*= (const vec& vectorData) noexcept {x *= vectorData.x; y *= vectorData.y; z *= vectorData.z; return *this;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ>& engine::vec<TypeXY, TypeZ>::operator/= (const vec& vectorData) {x /= vectorData.x; y /= vectorData.y; z /= vectorData.z; return *this;}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ> engine::vec<TypeXY, TypeZ>::operator* (const vec& vectorData) const noexcept {return vec(x*vectorData.x, y*vectorData.y, z*vectorData.z);}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ> engine::vec<TypeXY, TypeZ>::operator/ (const vec& vectorData) const          {return vec(x/vectorData.x, y/vectorData.y, z/vectorData.z);}              //!!!!! Деление 0 на 0! Необходимо выдавать ошибку bad value(vector.[INCORRECT_VALUE_CORD])

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ> engine::vec<TypeXY, TypeZ>::operator+ (const vec& vectorData) const noexcept {return vec(x+vectorData.x, y-vectorData.x, z-vectorData.z);}

template <typename TypeXY, typename TypeZ>
engine::vec<TypeXY, TypeZ> engine::vec<TypeXY, TypeZ>::operator- (const vec& vectorData) const noexcept {return vec(x-vectorData.x, y-vectorData.y, z-vectorData.z);}



template <typename TypeXY, typename TypeZ>
bool engine::vec<TypeXY, TypeZ>::operator== (const vec& vectorData) const noexcept {return x == vectorData.x && y == vectorData.y && z == vectorData.z;}
template <typename TypeXY, typename TypeZ>
bool engine::vec<TypeXY, TypeZ>::operator!= (const vec& vectorData) const noexcept {return !(*this == vectorData);}
