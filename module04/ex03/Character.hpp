// Copyright 2022 jahuang
#ifndef MODULE04_EX03_INCS_CHARACTER_HPP_
#define MODULE04_EX03_INCS_CHARACTER_HPP_

#include <string>

class Character : public ICharacter {
 private:
    AMateria*  _inventory[4];
 public:
    // canonical
    Character(void);
    ~Character(void);
    Character(const Character &toCopy);
    Character &operator=(const Character &toAssign);

    // getter / setter
    std::string const &getName(void) const;

    // member functions
    void  equip(AMateria *m);
    void  unequip(int idx);
    void  use(int idx, const ICharacter &target);
};

#endif  // MODULE04_EX03_CHARACTER_HPP_
