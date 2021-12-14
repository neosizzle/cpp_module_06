#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
	int	num;
	
	srand(time(0));
	num = rand() % 3;

	std::cout << "generated class " << static_cast<char>(num + 'A') << "\n";
	switch (num)
	{
	  case 0:
		return new A();
		break;
	
	  case 1:
		return new B();
		break;	

	  case 3:
		return new C();
		break;	
	
	  default:
		break;
	}
	return 0;
}

void identify(Base* p)
{
	A* a;
	B* b;

	a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "Identified as A\n";
		return ;
	}
	b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "Identified as B\n";
		return ;
	}
	std::cout << "Identified as C\n";
}

void identify(Base& p)
{
	A* a;
	B* b;

	a = dynamic_cast<A *>(&p);
	if (a)
	{
		std::cout << "Identified as A from refrence\n";
		return ;
	}
	b = dynamic_cast<B *>(&p);
	if (b)
	{
		std::cout << "Identified as B from refrence\n";
		return ;
	}
	std::cout << "Identified as C from refrence\n";
}
int	main()
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
