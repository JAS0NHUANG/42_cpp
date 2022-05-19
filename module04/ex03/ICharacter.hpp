// Copyright 2022 jahuang
#ifndef MODULE04_EX03_INCS_ICHARACTER_HPP_
#define MODULE04_EX03_INCS_ICHARACTER_HPP_

#include <string>

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual std::string const & getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, const ICharacter& target) = 0;
};

#endif  // MODULE04_EX03_INCS_ICHARACTER_HPP_
