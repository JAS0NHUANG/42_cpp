#include "Span.hpp"

#include <iostream>

void	printSpan(Span & sp) {
	std::cout << "The values inside the span: ";
	for(int i = 0; i < sp.size(); i++) {
		std::cout << sp.getElementByIndex(i);
		if (i == sp.size() - 1) {
			std::cout << "\n";
			break ;
		}
		std::cout << ", ";
	}
}

int	main(){
	std::cout << " ~~~~~ Simple span test ~~~~~ \n";
	{
		Span	newSpan = Span(11);
		newSpan.addNumber(22);
		std::cout << newSpan.getElementByIndex(0) << "\n";
		std::cout << newSpan.getElementByIndex(1) << "\n";
		std::cout << newSpan.getElementByIndex(2) << "\n";
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Test in subject ~~~~~ \n";
	{
		Span sp = Span(5);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printSpan(sp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Test with negative value ~~~~~ \n";
	{
		Span sp = Span(5);
		sp.addNumber(-88);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printSpan(sp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
