#include <iostream>
#include <fstream>
#include <cmath>

#ifndef ENGINE_H
#define ENGINE_H

namespace engine {  // Пространство движка. Включает в себя трёхпространственный вектор vec(short, short, char), его расширенную версию cxvec(float, float, float), структуры данных, объекты и методы взаимодействия с сценами.
    template <typename TypeXY = short, typename TypeZ = char, typename Tnm = int>
    class vec;          // vec   [Vector]        : Создание вектора для координат сцены, карты, передвижения игрока, взаимодействия и др.
    //class cxvec;        // cxvec [Complex Vector]: Создание вектора для комплексного передвижения при помощи углов
    class obj;          // obj   [Object]        : Координатная сетка сцены состоит из объектов. Благодаря объектам можно идентифицировать один объект от другого.
}


template <typename TypeXY = short, typename TypeZ = char, typename Tnm = int>
class engine::vec {         // Трёхпространственный вектор формата (short, short, char). Таким образом максимально возможное поле ограничивается размерами 2^16 x 2^16 x 2^8. Отсчёт идёт с 0 и возможны отрицательные значения.
    private:
        TypeXY x;                // Ожидаемые крайние границы -32 768 - 32 768
        TypeXY y;                // Ожидаемые крайние границы -32 768 - 32 768
        TypeZ  z;                // Ожидаемые крайние границы -128 - 127
    public:
                            // ==Конструкторы вектора:==
        vec();
        vec(TypeXY cord1, TypeXY cord2, TypeZ cord3);
        vec(TypeXY cord1, TypeXY cord2);
        vec(vec& copyData);
        vec& operator= (vec& newData);
                            // *-----------------------*
                            // ==Деструкторы вектора:==
        ~vec();
                            // *----------------------*


                            // ==Внешние функции получения и установки координат==
        inline TypeXY getX();        // Внешнее получение координаты X
        inline TypeXY getY();        // Внешнее получение координаты Y
        inline TypeZ  getZ();        // Внешнее получение координаты Z

        void setX(TypeXY newX);      // Внешняя установка координаты X
        void setY(TypeXY newY);      // Внешняя установка координаты Y 
        void setZ(TypeZ  newZ);      // Внешняя установка координаты Z
                            // *-------------------------------------------------*
                            // == Методы ==
                                    // *==   Методы  длины   ==*
        double getLen() const;                         // Нахождение квадратной длины относительно 0 0 0
        double getLen(const vec& centerData) const;    // Нахождение квадратной длины относительно вектора

        double getDist() const;
        double getDist(const vec& centerData) const;
                                    // *-----------------------*
                            // *----------*

                            // ==Определение операторов==
                                                    // *==Операторы сопряжённые с присвоением==*
        vec& operator+= (const vec& vectorData);                //
        vec& operator-= (const vec& vectorData);                //
        vec& operator*= (const vec& vectorData);                // 
        vec& operator*= (const Tnm& integerNum);                //
        vec& operator/= (const vec& vectorData);                //
        vec& operator/= (const Tnm& integerNum);                //
                                                    // *---------------------------------------*

                                                    // *==    Операторы суммы и умножения    ==*
        vec operator* (const Tnm& integerNum) const;            //
        vec operator/ (const Tnm& integerNum) const;            //
        vec operator* (const vec& vectorData) const;            //
        vec operator/ (const vec& vectorData) const;            //
        vec operator+ (const vec& vectorData) const;            //
        vec operator- (const vec& vectorData) const;            //
                                                    // *---------------------------------------*

                                                    // *==         Булевые операторы         ==*
        bool operator== (const vec& vectorData) const;
        bool operator!= (const vec& vectorData) const;
                                                    // *---------------------------------------*
                            // *-----------------------*

                            // ==Сопряжённая перегрузка дружественных функций==
        friend std::ostream& operator<< (std::ostream& Out, const vec& Vector);     // Сопряжение с std::cout. ФОРМАТ ВЫВОДА: "x y z"
        friend std::istream& operator>> (std::istream&  In, vec& Vector);           // Сопряжение с std::cin.  ФОРМАТ ВВОДА : "x y z"
                            // *----------------------------------------------*
};
#endif