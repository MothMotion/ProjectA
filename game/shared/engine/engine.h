#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <cmath>
#include <functional>
#include <bitset>
#include <map>
#include <iomanip>

#include "vector.h"

//namespace engine {  // Пространство движка. Включает в себя трёхпространственный вектор vec(short, short, char), его расширенную версию cxvec(float, float, float), структуры данных, объекты и методы взаимодействия с сценами.
    //template <typename TypeXY, typename TypeZ>
    //class vec;          // vec   [Vector]        : Создание вектора для координат сцены, карты, передвижения игрока, взаимодействия и др.
    //class cxvec;        // cxvec [Complex Vector]: Создание вектора для комплексного передвижения при помощи углов
    //class obj;          // obj   [Object]        : Координатная сетка сцены состоит из объектов. Благодаря объектам можно идентифицировать один объект от другого.
//};
namespace engine{
//class vec {
    template class engine::vec  <float, float>;         // vec   <float,float> для продвинутого перемещения по координатной сетке сцены.
    template class engine::vec<double, double>;         // vec<double, double> для расширенного метода перемещения по координатной сетке сцены или глобальной карте.
    template class engine::vec   <short, char>;         // vec   <short, char> для определения станданртной координатной сетки сцены.
    template class engine::vec     <long, int>;         // vec     <long, int> для определения стандонтной координатной сетки глобальной карты.
                            // ==Сопряжённая перегрузка дружественных функций==
template <typename TypeXY = short, typename TypeZ = char>
std::ostream& operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ>& Vector);     // Сопряжение с std::cout. ФОРМАТ ВЫВОДА: "x y z"
template <typename TypeXY = short, typename TypeZ = char>
std::istream& operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ>& Vector);           // Сопряжение с std::cin.  ФОРМАТ ВВОДА : "x y z"
// *----------------------------------------------*
//};
};

#endif
