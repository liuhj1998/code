#include <iostream>

class base
{
	int value;

public:
	base(int v);
	~base();

	void dump();
};

base::base(int v) : value(v)
{
	std::cout << "Base class constructor. Passed in param is: " << v << std::endl;
}
base::~base()
{
	std::cout << "Base class destructor." << std::endl;
}

void base::dump()
{
	std::cout << "Base dump. value is " << value << std::endl;
}

class helper
{
	int h;

public:
	helper(int v);
	~helper();
};

helper::helper(int v) : h(v)
{
	std::cout << "Helper constructor. Passed in param is " << v << std::endl;
}
helper::~helper()
{
	std::cout << "Helper destructor." << std::endl;
}

class child : base
{
	int cv;
	helper hc;
	helper hc2;

public:
	child(int p);
	~child();

	void dump();
};
child::child(int p) : hc2(p*4),  cv(p), base (p * 2), hc(p*3)
{
	std::cout << "Child class constructor. Passed in para is " << p << std::endl;
}
child::~child()
{
	std::cout << "Child class destructor" << std::endl;
}

void child::dump()
{
	std::cout << "Child dump. Value is " << cv << std::endl;
}


int main()
{
	std::cout << "Testing virtual destructor." << std::endl;

	child c(3);
	std::cout << "after child 111111" << std::endl;

	return 1;
}	
