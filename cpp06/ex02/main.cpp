#include <iostream>
#include <cstdlib>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate(void)
{
	int randomNumber = std::rand() % 31;
	
    if (randomNumber % 3 == 0)
        return (new A);
    else if (randomNumber % 3 == 1)
        return (new B);
    else
        return (new C);
}


void	identify(Base *p)
{
	if (dynamic_cast< A* >(p))
		std::cout << "Type 'Class A'" << std::endl;
	else if (dynamic_cast< B* >(p))
		std::cout << "Type 'Class B'" << std::endl;
	else if (dynamic_cast< C* >(p))
		std::cout << "Type 'Class C'" << std::endl;
	else
		std::cout << "Type 'UnKnown'" << std::endl;
}

void	identify(Base &p)
{
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "Type 'Class A'" << std::endl;
        (void)a;
    } catch(const std::exception& e) { /* std::cout << e.what() << std::endl; */ }
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "Type 'Class B'" << std::endl;
        (void)b;
    } catch( const std::exception& e ) { /* std::cout << e.what() << std::endl; */ }
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "Type 'Class C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) { /* std::cout << e.what() << std::endl; */ }
}

void	gap()
{
	std::cout << "\n";
}

int main(int /*argc*/, char** /*argv*/)
{
    Base*   v1 = generate();
    Base*   v2 = generate();
    Base*   v3 = generate();
    Base*   v4 = generate();


	std::cout << "v1* = "; 
	identify(v1);
    std::cout << "v1& = ";
	identify( *v1 );
	std::cout << std::endl;

	gap();

    std::cout << "v2* = ";
	identify(v2);
    std::cout << "v2& = ";
	identify( *v2 );
	std::cout << std::endl;

	gap();

    std::cout << "v3* = ";
	identify(v3);
    std::cout << "v3& = ";
	identify( *v3 );
	std::cout << std::endl;

	gap();

    std::cout << "v4* = ";
	identify(v4);
    std::cout << "v4& = ";
	identify( *v4 );

	delete v1;
	delete v2;
	delete v3;
	delete v4;

	return (0);
}