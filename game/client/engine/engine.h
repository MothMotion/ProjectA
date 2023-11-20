#include <iostream>
#include <fstream>

#ifndef ENGINE_H
#define ENGINE_H

namespace engine { // Пространство движка. Включает в себя трёхпространственный вектор vec(short, short, char)
    class vec;
}



class engine::vec {         // Трёхпространственный вектор формата (short, short, char). Таким образом максимально возможное поле ограничивается размерами 2^16 x 2^16 x 2^8. Отсчёт идёт с 0 и возможны отрицательные значения.
    private:
        short int x;        // Крайние границы -32,726 - 32,726
        short int y;        // Крайние границы -32,726 - 32,726
        char z;             // Глубина
    public:
                            // Конструкторы вектора:
        vec();
        vec(short int cord1, short int cord2, char cord3);
        vec(short int cord1, short int cord2);
        vec& operator= (vec& newData);
                            // *-------------------*
                            // Деструкторы вектора:
        ~vec();
                            // *-------------------*


                            // Внешние функции получения и установки координат
        inline short int getX();    // Внешнее получение координаты X
        inline short int getY();    // Внешнее получение координаты Y
        inline char      getZ();    // Внешнее получение координаты Z

        void setX(short int newX);  // Внешняя установка координаты X
        void setY(short int newY);  // Внешняя установка координаты Y 
        void setZ(char      newZ);  // Внешняя установка координаты Z
                            // *----------------------------------------------*

                            // Определение операндов
        vec& operator+= (vec& vectorData);
        vec& operator-= (vec& vectorData);
        vec& operator*= (vec& vectorData);
        vec& operator*= (int& integerNum);
        vec& operator/= (vec& vectorData);
        vec& operator/= (int& integerNum);

        vec operator* (const int& integerNum) const;
        vec operator/ (const int& integerNum) const;
        vec operator* (const vec& vectorData) const;
        vec operator/ (const vec& vectorData) const;

        bool operator== (vec& vectorData) const;
        bool operator!= (vec& vectorData) const;
                            // *-------------------*

                            // Сопряжённая перегрузка дружественных функций
        friend std::ostream& operator<< (std::ostream& Out, const vec& Vector);   // Сопряжение с std::cout. ФОРМАТ ВЫВОДА: "x y z"
        friend std::istream& operator>> (std::istream&  In, vec& Vector);   // Сопряжение с std::cin.  ФОРМАТ ВВОДА : "x y z"
                            // *------------------------------------------*
};
#endif