#include <cligfx/cligfx.hpp>

int main()
{
    Vector2 a(4, -2); // Vector2<int>
    Vector2 b = {1., 4.}; //Vector2<double>

    std::cout << a.print(); //Default print parameters
    std::cout << b.print("()", " : ", " - printing with custom formatting\n");
    std::cout << "|" << a.print("{}", ", ", "") << "| (magnitude) = " << a.magnitude() << "\n";
    std::cout << a.print("{}", ", ", "") << " normalized = " << a.normalized().print();
    std::cout << a.print("{}", ", ", "") << " + " << b.print("{}", ", ", "") << " = " << (a + b).print();
    std::cout << b.print("{}", ", ", "") << " - " << a.print("{}", ", ", "") << " = " << (b - a).print();
    std::cout << "2 * " << b.print("{}", ", ", "") << " = " << (2 * a).print();
    std::cout << a.print("{}", ", ", "") << " * -1.25f" << " = " << (a * -1.25f).print();
    std::cout << a.print("{}", ", ", "") << " * " << b.print("{}", ", ", "") << " (the dot/scalar product) = " << a * b;
}
