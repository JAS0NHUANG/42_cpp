#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 1       |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Point	a;
	Point	b(0.0f, 4.5f);
	Point	c(2.0f, 2.0f);
	Point	pointJ(1.0f, 2.0f);
	Point	pointQ(33.0f, 44.0f);
	Point	pointK(1.0f, 1.0f);

	std::cout << "a: " << a.getX() << ", " << a.getY() << "\n";
	std::cout << "b: " << b.getX() << ", " << b.getY() << "\n";
	std::cout << "c: " << c.getX() << ", " << c.getY() << "\n";
	std::cout << "J: " << pointJ.getX() << ", " << pointJ.getY() << "\n";
	std::cout << "Q: " << pointQ.getX() << ", " << pointQ.getY() << "\n";
	std::cout << "K: " << pointK.getX() << ", " << pointK.getY() << "\n";
	std::cout << std::endl;
	std::cout << "Point in J: " << bsp(a, b, c, pointJ) << "\n";
	std::cout << "Point out Q: " << bsp(a, b, c, pointQ) << "\n";
	std::cout << "Point out K: " << bsp(a, b, c, pointK) << "\n";

	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 2       |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Point p1(1.5, 1.1);
	Point p2(4.0, 4.75);
	Point p3(5.1, 1.22);
	Point point_in(4, 2);
	Point point_out(1, 4);
	std::cout << "p1: " << p1.getX() << ", " << p1.getY() << "\n";
	std::cout << "p2: " << p2.getX() << ", " << p2.getY() << "\n";
	std::cout << "p3: " << p3.getX() << ", " << p3.getY() << "\n";
	std::cout << "point_in: " << point_in.getX() << ", " << point_in.getY() << "\n";
	std::cout << "point_out: " << point_out.getX() << ", " << point_out.getY() << "\n";
	std::cout << std::endl;
	std::cout << "Point in  : " << bsp(p1, p2, p3, point_in) << std::endl;
	std::cout << "Point out : " << bsp(p1, p2, p3, point_out) << std::endl;

	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 3       |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Point p4(-3.2, 0);
	Point p5(3.22, 2.48);
	Point p6(3.5, -2.81);
	Point point_in_2(-1, 0);
	Point point_out_2(-4, 3.2);
	std::cout << "p4: " << p4.getX() << ", " << p4.getY() << "\n";
	std::cout << "p5: " << p5.getX() << ", " << p5.getY() << "\n";
	std::cout << "p6: " << p6.getX() << ", " << p6.getY() << "\n";
	std::cout << "point_in_2: " << point_in_2.getX() << ", " << point_in_2.getY() << "\n";
	std::cout << "point_out_2: " << point_out_2.getX() << ", " << point_out_2.getY() << "\n";
	std::cout << std::endl;
	std::cout << "Point in  : " << bsp(p4, p5, p6, point_in_2) << std::endl;
	std::cout << "Point out : " << bsp(p4, p5, p6, point_out_2) << std::endl;

	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 4       |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Point p7(-3.2, 0);
	Point p8(p7);
	Point p9;
	Point point_out_3(-1, 0);
	Point point_out_4(-4, 3.2);
	std::cout << "p7: " << p7.getX() << ", " << p7.getY() << "\n";
	std::cout << "p8: " << p8.getX() << ", " << p8.getY() << "\n";
	std::cout << "p9: " << p9.getX() << ", " << p9.getY() << "\n";
	std::cout << "point_out_3: " << point_out_3.getX() << ", " << point_out_3.getY() << "\n";
	std::cout << "point_out_4: " << point_out_4.getX() << ", " << point_out_4.getY() << "\n";
	std::cout << std::endl;
	std::cout << "Point out : " << bsp(p7, p8, p9, point_out_3) << std::endl;
	std::cout << "Point out : " << bsp(p7, p8, p9, point_out_4) << std::endl;

	return 0;
}
