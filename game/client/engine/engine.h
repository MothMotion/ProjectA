#include <iostream>
#include <fstream>
#include <cmath>

#ifndef ENGINE_H
#define ENGINE_H



namespace engine {  // Пространство движка. Включает в себя трёхпространственный вектор vec(short, short, char), его расширенную версию cxvec(float, float, float), структуры данных, объекты и методы взаимодействия с сценами.
    template <typename TypeXY, typename TypeZ>
    class vec;          // vec   [Vector]        : Создание вектора для координат сцены, карты, передвижения игрока, взаимодействия и др.
    //class cxvec;        // cxvec [Complex Vector]: Создание вектора для комплексного передвижения при помощи углов
    class obj;          // obj   [Object]        : Координатная сетка сцены состоит из объектов. Благодаря объектам можно идентифицировать один объект от другого.
}


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
        vec& operator*= (const any& integerNum) noexcept;                //
        vec& operator/= (const vec& vectorData);                         //
        template <typename any>                                          //
        vec& operator/= (const any& integerNum);                         //
                                                    // *---------------------------------------*

                                                    // *==    Операторы суммы и умножения    ==*
        template <typename any>                                          //
        vec operator* (const any& integerNum) const noexcept;            //
        template <typename any>                                          //
        vec operator/ (const any& integerNum) const;                     //
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
                            // ==Сопряжённая перегрузка дружественных функций==
template <typename TypeXY = short, typename TypeZ = char>
std::ostream& operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ>& Vector);     // Сопряжение с std::cout. ФОРМАТ ВЫВОДА: "x y z"
template <typename TypeXY = short, typename TypeZ = char>
std::istream& operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ>& Vector);           // Сопряжение с std::cin.  ФОРМАТ ВВОДА : "x y z"
// *----------------------------------------------*
};

#endif