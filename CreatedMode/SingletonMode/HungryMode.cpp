#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton(){cout << "CREARE MODE" <<endl;}
	~Singleton(){cout << "DELETE MODE" <<endl;}
	Singleton(const Singleton& );
    Singleton& operator=(const Singleton& );
	static Singleton Instance; //here is my instance
public:
	static Singleton* getInstance()
	{
		return &Instance;
	}
};

Singleton Singleton::Instance;

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	Singleton *s3 = Singleton::getInstance();

	return 0;
}