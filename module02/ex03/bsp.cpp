#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int		dotProduct( Point const start, Point const end, Point const point) {
	Fixed	result;

	result = ((end.getY() - start.getY()) * (point.getX() - start.getX()) +
			 (start.getX() - end.getX()) * (point.getY() - start.getY()));
	return (result.toInt());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	int	productAB = dotProduct(a, b, point);
	int	productBC = dotProduct(b, c, point);
	int	productCA = dotProduct(c, a, point);

	if (productAB > 0 && productBC > 0 && productCA > 0)
		return true;
	if (productAB < 0 && productBC < 0 && productCA < 0)
		return true;

	return false;
};
