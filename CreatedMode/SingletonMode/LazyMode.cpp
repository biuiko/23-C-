#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
		cout << "CREATE MODE" <<endl;
	}
	~Singleton()
	{
		cout << "DELETE MODE" <<endl;
	}
	Singleton(const Singleton& );
    Singleton& operator=(const Singleton& );
public:
	static Singleton* getInstance()
	{
		static Singleton Instance;	//here is my instance,when i need to use it at first time,it creates.
		return &Instance;
	}
};

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	Singleton *s3 = Singleton::getInstance();

	return 0;
}