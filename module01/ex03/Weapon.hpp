#include <string>

class Weapon {
	public:
		Weapon( str::string type){};
		~Weapon( void ){};
		str::string getType() const;
		str::string setType() const;
	private:
		std::string	type;
}
