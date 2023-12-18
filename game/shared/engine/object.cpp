#include "engine.h"
#include "object.h"

namespace engine {
  obj::obj(std::bitset<2> new_box, std::bitset<14> new_id) {
    this->box = new_box;
    this->id = new_id;
    this->objHealth = 255;
    engine::callBoxInit[new_box](this);
    engine::callIdInit[engine::connectBits(new_box, new_id)](this);
  }

  obj::obj(std::bitset<2> new_box, std::bitset<14> new_id, unsigned char new_health) {
    this->box = new_box;
    this->id = new_id;
    this->objHealth = new_health;
    engine::callBoxInit[new_box](this);
    engine::callIdInit[engine::connectBits(new_box, new_id)](this);
  }

  template<typename any1, typename any2>
  obj::obj(any1 new_box, any2 new_id) {
    engine::setTo(this->box, new_box);
    engine::setTo(this->id, new_id);
    this->objHealth = 255;
    engine::callBoxInit[new_box](this);
    engine::callIdInit[engine::connectBits(new_box, new_id)](this);
  }

  template<typename any1, typename any2, typename any3>
  obj::obj(any1 new_box, any2 new_id, any3 new_health) {
    engine::setTo(this->box, new_box);
    engine::setTo(this->id, new_id);
    this->objHealth = new_health;
    engine::callBoxInit[new_box](this);
    engine::callIdInit[engine::connectBits(new_box, new_id)](this);
  }

  obj::obj(engine::obj& copyObj) {
    this->box = copyObj.box;
    this->id = copyObj.id;
    this->objHealth = copyObj.objHealth;
    engine::callBoxInit[copyObj.box](this);
    engine::callIdInit[engine::connectBits(copyObj.box, copyObj.id)](this);
  }



  //inline std::bitset<2> obj::getBox()   const noexcept       {return this->box;}
  //inline std::bitset<14> obj::getID()   const noexcept       {return this-> id;}
  //inline unsigned char obj::getHealth() const noexcept {return this->objHealth;}

  inline void obj::setBox(std::bitset<2> new_box)             noexcept {this->box = new_box;}
  inline void obj::setID(std::bitset<14> new_id)              noexcept {this-> id =  new_id;}
  inline void obj::setHealth(unsigned char new_health) noexcept {this->objHealth=new_health;}

  void obj::changeHealth(short ch_Health) noexcept {
    if((0 < ch_Health + this->objHealth) && (ch_Health + this->objHealth < 256)) // 0 < change + current < 256
      this->objHealth += ch_Health;
    else
      if((ch_Health + this->objHealth) <= 0) this->destroy();
      else this->objHealth=255;
  }

  void obj::destroy() const {
  // Удалять из памяти сцены.
  }

  bool obj::canPass() const noexcept {return this->passSpeed > 0;}
  bool obj::canLeak() const noexcept {return this->leakSpeed > 0;}



  template<size_t size, typename any>
  void inline setTo(std::bitset<size>& In, any integer) {
    In = std::bitset<size>(integer);
  }

  //template<size_t size1, size_t size2>
}
namespace engine {}
