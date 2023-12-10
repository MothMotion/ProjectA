//#include "engine.h"
#ifndef ENGINE_VECTOR
#define ENGINE_VECTOR

#include "engine.h"

namespace engine {
template <typename TypeXY=short, typename TypeZ=char>
class vec {         // Трёхпространственный вектор формата (short, short, char). Таким образом максимально возможное поле ограничивается размерами 2^16 x 2^16 x 2^8. Отсчёт идёт с 0 и возможны отрицательные значения.
    private:
        TypeXY x;                // Ожидаемые крайние границы -32 768 - 32 768
        TypeXY y;                // Ожидаемые крайние границы -32 768 - 32 768
        TypeZ  z;                // Ожидаемые крайние границы -128 - 127
    public:
                            // ==Конструкторы вектора:==
        vec() noexcept;
        vec(TypeXY cord1, TypeXY cord2, TypeZ cord3);
        vec(TypeXY cord1, TypeXY cord2);
        vec(vec& copyData) noexcept;
        vec& operator= (vec& newData) noexcept;
                            // *-----------------------*
                            // ==Деструктор   вектора:==
        ~vec() = default;
                            // *----------------------*


                            // ==Внешние функции получения и установки координат==
        inline TypeXY getX() const noexcept;        // Внешнее получение координаты X
        inline TypeXY getY() const noexcept;        // Внешнее получение координаты Y
        inline TypeZ  getZ() const noexcept;        // Внешнее получение координаты Z

        void setX(TypeXY newX) noexcept;            // Внешняя установка координаты X
        void setY(TypeXY newY) noexcept;            // Внешняя установка координаты Y 
        void setZ(TypeZ  newZ) noexcept;            // Внешняя установка координаты Z
                            // *-------------------------------------------------*
                            // == Методы ==
                                    // *==   Методы  длины   ==*
        double getLen() const noexcept;                         // Нахождение квадратной длины относительно 0 0 0
        double getLen(const vec& centerData) const noexcept;    // Нахождение квадратной длины относительно вектора

        inline double getDist() const noexcept;
        inline double getDist(const vec& centerData) const noexcept;
                                    // *-----------------------*
                            // *----------*

                            // ==Определение операторов==
                                                    // *==Операторы сопряжённые с присвоением==*
        vec& operator+= (const vec& vectorData) noexcept;                //
        vec& operator-= (const vec& vectorData) noexcept;                //
        vec& operator*= (const vec& vectorData) noexcept;                // 
        template <typename any>                                          //
        vec& operator*= (const any& integerNum) noexcept {this->x*=integerNum; this->y*=integerNum; this->z*=integerNum; return *this;};                //
        vec& operator/= (const vec& vectorData);                         //
        template <typename any>                                          //
        vec& operator/= (const any& integerNum)          {this->x/=integerNum; this->y/=integerNum; this->z/=integerNum; return *this;};                         //
                                                    // *---------------------------------------*

                                                    // *==    Операторы суммы и умножения    ==*
        template <typename any>                                          //
        vec operator* (const any& integerNum) const noexcept {return vec<TypeXY, TypeZ>(this->x*integerNum, this->y*integerNum, this->z*integerNum);};            //
        template <typename any>                                          //
        vec operator/ (const any& integerNum) const          {return vec<TypeXY, TypeZ>(this->x/integerNum, this->y/integerNum, this->z/integerNum);};                     //
        vec operator* (const vec& vectorData) const noexcept;            //
        vec operator/ (const vec& vectorData) const;                     //
        vec operator+ (const vec& vectorData) const noexcept;            //
        vec operator- (const vec& vectorData) const noexcept;            //
                                                    // *---------------------------------------*

                                                    // *==         Булевые операторы         ==*
        bool operator== (const vec& vectorData) const noexcept;
        bool operator!= (const vec& vectorData) const noexcept;
                                                    // *---------------------------------------*
                            // *-----------------------*
};
}
#endif
