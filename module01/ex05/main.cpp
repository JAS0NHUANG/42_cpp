#include "Harl.hpp"

int	main(void) {
	Harl	this_is_harl;
	// Harl's complains
	this_is_harl.complain("DEBUG");
	this_is_harl.complain("INFO");
	this_is_harl.complain("WARNING");
	this_is_harl.complain("ERROR");

	// Bad argument
	this_is_harl.complain("");
	this_is_harl.complain("debug");
	this_is_harl.complain("IINNFFOO");

	return (0);
}
