#include <thread>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class A
{
public:
	A() :m_ptr(new int(0))
	{
	}

	~A()
	{
		delete m_ptr;
	}
private:
	int* m_ptr;
};

A Get(bool flag)
{
	A a;
	A b;
	if (flag)
		return a;
	else
		return b;
}


void PrintT(int& t)
{
	std::cout << "LLLL" << std::endl;
}

template<typename T>
void PrintT(T &&t)
{
	cout << "RRRR" << endl;
}
template<typename T>
void TestForward(T && v)
{
	PrintT(v);
	PrintT(forward<T>(v));
	PrintT(move(v));
}

int main()
{
	//A a = Get(false);
	int x = 1;
	//TestForward(x);

	TestForward(forward<int>(x));
}