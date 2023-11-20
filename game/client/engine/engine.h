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
        vec();
        vec(short int cord1, short int cord2, char cord3);
        vec(short int cord1, short int cord2);
        vec& operator= (vec& newData);
        ~vec();

        inline short int getX();
        inline short int getY();
        inline char      getZ();

        void setX(short int newX);
        void setY(short int newY);
        void setZ(char      newZ);

        friend std::ostream& operator<< (std::ostream& Out, vec& Vector);
        friend std::istream& operator>> (std::istream&  In, vec& Vector);
};
#endif