#include<iostream>
#include<memory>
using namespace std;

class Singleton
{
private:
	Singleton(){cout << "CREARE MODE" <<endl;}
	~Singleton(){cout << "DELETE MODE" <<endl;}
	Singleton(const Singleton& );
    Singleton& operator=(const Singleton& );
    
	static void Destory(Singleton *){cout <<"HERE TO DESTORY MDOE"<< endl;} //my deleter
	

public:
	static shared_ptr<Singleton> getInstance()
	{
		static shared_ptr<Singleton> Instance(new Singleton(),Singleton::Destory);
		return Instance;
	}
};

int main()
{
	shared_ptr<Singleton> s1 = Singleton::getInstance();
	shared_ptr<Singleton> s2 = Singleton::getInstance();
	shared_ptr<Singleton> s3 = Singleton::getInstance();

	return 0;
}