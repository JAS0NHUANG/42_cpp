#ifndef MODULE04_EX03_INCS_CHARACTER_HPP_
#define MODULE04_EX03_INCS_CHARACTER_HPP_

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
	std::string	_name;
    AMateria*  _inventory[4];
 public:
    // canonical
    Character(void);
    Character(std::string name);
    ~Character(void);
    Character(const Character &toCopy);
    Character &operator=(const Character &toAssign);

    // getter / setter
    std::string const &getName(void) const;
	AMateria* getMateria(int idx);

    // member functions
    void  equip(AMateria *m);
    void  unequip(int idx);
    void  use(int idx, ICharacter &target);
};

#endif  // MODULE04_EX03_CHARACTER_HPP_
