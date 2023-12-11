#ifndef ENGINE_OBJECT
#define ENGINE_OBJECT
#include "engine.h"

namespace engine {

  class obj {
  private:
    std::bitset<2> box;               // Образуем шаблонный метод для определения стандартных и базовых операций и взаимодействи.
    std::bitset<14> id;               // Идентификатор для более точечного определения методов и операций взаимодействий.
    unsigned char objHealth;            // "Здоровье объекта". Для газов и жидкости - давление. 15 - норма, < - пониженное, > - повышенное. При достижении отрицательных значений или 0 происходит вызов функции уничтожения объекта по шаблону и по идентификатору, а также последующее удаление.
  public:
    unsigned char passSpeed;      // Скорость движения твёрдых сущностей по объекту, через него, под ним.
    unsigned char leakSpeed;      // Скорость движения жидкости/газов через объект.
    unsigned char viewBlock[2];   // Блокировка зрения. 0 - снизу, 1 - сверху. Полностью блокирую выделенную область снизу и сверху.
    unsigned char transparent;    // Насколько объект прозрачен: 255 - прозрачный, 0 - нет. Влияет на дальность зрения.
    unsigned char lightness;      // Насколько объект подсвечен.
    bool isActive;                // Помещать ли isActive в буфер постоянной обработки или забыть.
    std::function<void(unsigned char)> actCode(unsigned char code); // Определяет возможные взаимодействия.в

    obj(std::bitset<2> box, std::bitset<14> id);
    obj(std::bitset<2> box, std::bitset<14> id, unsigned char objHealth);
    template<typename any1, typename any2>
    obj(any1 new_box, any2 new_id);
    template<typename any1, typename any2, typename any3>
    obj(any1 new_box, any2 new_id, any3 new_health);
    obj(obj& copyObj);

    ~obj() = default;

    std::bitset<2> getBox()   const noexcept;
    std::bitset<14> getID()   const noexcept;
    unsigned char getHealth() const noexcept;

    void setBox(std::bitset<2> box)           noexcept;
    void setID(std::bitset<14> id)            noexcept;
    void setHealth(unsigned char new_health)  noexcept;

    void changeHealth(short d_health) noexcept;
    void destroy()                    const;

    bool canPass() const noexcept;
    bool canLeak() const noexcept;
};

  template<size_t size>
  struct compareBits {
    bool operator() (const std::bitset<size>& bitset1, const std::bitset<size>& bitset2) const {
      for(char i=size-1; i>=0; --i) {
        if(bitset2[i] && !bitset1[i]) return true;
        else if(!bitset2[i] && bitset1[i]) return false;
      }
      return false;
    } 
  }; 

  extern std::map<std::bitset<2>, std::function<void(engine::obj*)>, engine::compareBits<2>> callBoxInit;
  extern std::map<std::bitset<16>, std::function<void(engine::obj*)>,engine::compareBits<16>> callIdInit;

  
  
  template<size_t size, typename any>
  inline void setTo(std::bitset<size>& In, any integer);

  //template<size_t size1, size_t size2>
}
namespace engine {std::bitset<16> connectBits(std::bitset<2>& bitset1, std::bitset<14>& bitset2);}

#endif
