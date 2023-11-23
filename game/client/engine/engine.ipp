#include "engine.hpp"
//template <typename TypeXY, typename TypeZ, typename Tnm>
//typedef engine::vec<TypeXY, TypeZ, Tnm> VecT;

namespace engine {
    template <typename TypeXY, typename TypeZ, typename Tnm>
    class vec {
        vec::vec() noexcept {
            this -> x=0;
            this -> y=0;
            this -> z=0;
        }
        vec::vec(TypeXY x, TypeXY y, TypeZ z) {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
        vec::vec(TypeXY x, TypeXY y) {
            this -> x = x;
            this -> y = y;
            this -> z = 0;
        }
        vec::vec(engine::vec& copyData) noexcept {
            x = copyData.x;
            y = copyData.y;
            z = copyData.z;
        }
        vec& vec::operator= (engine::vec& newData) noexcept {
            if(*this == newData) return *this;
            x = newData.x;
            y = newData.y;
            z = newData.z;
            return  *this;
        }
        engine::vec::~vec() {}



        inline TypeXY vec::getX() const noexcept {return x;}
        inline TypeXY vec::getY() const noexcept {return y;}
        inline TypeZ  vec::getZ() const noexcept {return z;}

        inline void vec::setX(TypeXY newX) noexcept {x = newX;}
        inline void vec::setY(TypeXY newY) noexcept {y = newY;}
        inline void vec::setZ(TypeZ  newZ) noexcept {z = newZ;}



        double vec::getLen() const noexcept {return (double(x*x) + double(y*y) + double(z*z));}
        double vec::getLen(const vec& centerData) const noexcept
                                        {return (double((x-centerData.x)*(x-centerData.x))
                                                + double((y-centerData.y)*(y-centerData.y))
                                                + double((z-centerData.z)*(z-centerData.z)));}
        double vec::getDist() const noexcept {return sqrt(this -> getLen());}
        double vec::getDist(const vec& centerData) const noexcept {return sqrt(this -> getLen(centerData));}



        vec& vec::operator+= (const vec& vectorData) noexcept {x += vectorData.x; y += vectorData.y; z += vectorData.z; return *this;}
        vec& vec::operator-= (const vec& vectorData) noexcept {x -= vectorData.x; y -= vectorData.y; z -= vectorData.z; return *this;}
        vec& vec::operator*= (const vec& vectorData) noexcept {x *= vectorData.x; y *= vectorData.y; z *= vectorData.z; return *this;}
        vec& vec::operator*= (const Tnm& integerNum) noexcept {x *= integerNum;   y *= integerNum;   z *= integerNum;   return *this;}
        vec& vec::operator/= (const vec& vectorData) {x /= vectorData.x; y /= vectorData.y; z /= vectorData.z; return *this;}
        vec& vec::operator/= (const Tnm& integerNum) {x /= integerNum;   y /= integerNum;   z /= integerNum;   return *this;}

        vec vec::operator* (const Tnm& integerNum) const noexcept {return vec(x*integerNum,   y*integerNum,   z*integerNum);  }
        vec vec::operator/ (const Tnm& integerNum) const          {return vec(x/integerNum,   y/integerNum,   z/integerNum);  }
        vec vec::operator* (const vec& vectorData) const noexcept {return vec(x*vectorData.x, y*vectorData.y, z*vectorData.z);}
        vec vec::operator/ (const vec& vectorData) const          {return vec(x/vectorData.x, y/vectorData.y, z/vectorData.z);}              //!!!!! Деление 0 на 0! Необходимо выдавать ошибку bad value(vector.[INCORRECT_VALUE_CORD])
        vec vec::operator+ (const vec& vectorData) const noexcept {return vec(x+vectorData.x, y-vectorData.x, z-vectorData.z);}
        vec vec::operator- (const vec& vectorData) const noexcept {return vec(x-vectorData.x, y-vectorData.y, z-vectorData.z);}



        bool vec::operator== (const vec& vectorData) const noexcept {return x == vectorData.x && y == vectorData.y && z == vectorData.z;}
        bool vec::operator!= (const vec& vectorData) const noexcept {return !(*this == vectorData);}
    };
};
template <typename TypeXY, typename TypeZ, typename Tnm>
std::ostream& operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ, Tnm>& Vector) {
    Out << Vector.x << " " << Vector.y << " " << Vector.z;
    return Out;
}
template <typename TypeXY, typename TypeZ, typename Tnm>
std::istream& operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ, Tnm>& Vector) {
    TypeXY x, y; TypeZ z; In >> x >> y >> z; 
    Vector = engine::vec(x,y,z); return In;
}
//}

//int main() {return 0;}