#include <cligfx/cligfx.hpp>

int main()
{
	cf::Vector3 a(4, -2, 5); // Vector3<int>
	cf::Vector3 b = {1.f, 4.f, .5f}; //Vector3<double>

	std::cout << a.print(); //Default print parameters
	std::cout << b.print("()", " : ", " - printing with custom formatting\n");
	std::cout << "|" << a.print("{}", ", ", "") << "| (magnitude) = " << a.magnitude() << "\n";
	std::cout << a.print("{}", ", ", "") << " normalized = " << a.normalized().print();
	std::cout << a.print("{}", ", ", "") << " + " << b.print("{}", ", ", "") << " = " << (a + b).print();
	std::cout << b.print("{}", ", ", "") << " - " << a.print("{}", ", ", "") << " = " << (b - a).print();
	std::cout << "2 * " << b.print("{}", ", ", "") << " = " << (2 * b).print();
	std::cout << a.print("{}", ", ", "") << " * -1.25f" << " = " << (a * -1.25f).print();
	std::cout << a.print("{}", ", ", "") << " * " << b.print("{}", ", ", "") << " (the dot/scalar product) = " << a.dot(b) << "\n";
	std::cout << a.print("{}", ", ", "") << " x " << b.print("{}", ", ", "") << " (the cross/vector product) = " << a.cross(b).print() << "\n";
}
