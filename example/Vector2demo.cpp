#include <cligfx/cligfx.hpp>

int main()
{
	cf::Vector2 a(4, -2); // Vector2<int>
	cf::Vector2 b = {2.25, 1.25}; //Vector2<double>

	std::cout << a.print(); //Default print parameters
	std::cout << b.print("()", " : ", " - printing with custom formatting\n");
	std::cout << "|" << a.print("{}", ", ", "") << "| (magnitude) = " << a.magnitude() << "\n";
	std::cout << a.print("{}", ", ", "") << " normalized = " << a.normalized().print();
	std::cout << a.print("{}", ", ", "") << " + " << b.print("{}", ", ", "") << " = " << (a + b).print();
	std::cout << b.print("{}", ", ", "") << " - " << a.print("{}", ", ", "") << " = " << (b - a).print();
	std::cout << "2 * " << b.print("{}", ", ", "") << " = " << (2 * b).print();
	std::cout << a.print("{}", ", ", "") << " * -1.25f" << " = " << (a * -1.25f).print();
	std::cout << b.print("{}", ", ", "") << " / 3" << " = " << (b / 3).print();
	std::cout << a.print("{}", ", ", "") << " . " << b.print("{}", ", ", "") << " (the dot/scalar product) = " << a.dot(b);
	return 0;
}