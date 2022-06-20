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
		std::cout << "Create a span with 11 slots.\n";
		Span	newSpan = Span(11);
		std::cout << "Add number 22 and 11 into it.\n";
		newSpan.addNumber(22);
		newSpan.addNumber(11);
		std::cout << "First two numbers in the span: " << \
			newSpan.getElementByIndex(0) << ", " << \
			newSpan.getElementByIndex(1) << "\n";

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
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
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
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Test auto addNumber ~~~~~ \n";
	{
		Span sp = Span(100);
		sp.addNumber();
		printSpan(sp);
		std::cout << "span size: " << sp.size() << "\n";
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";
	return 0;
}
