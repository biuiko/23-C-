#include<iostream>
using namespace std;

class Adaptee
{
public:
	 Adaptee(){}
	~ Adaptee(){}
	
	void spacial_operate()
	{
		cout << "you need to do something at here."<<endl;
	}
};

class Target
{
public:
	Target(){};
	~Target(){};

	virtual void operate()=0;
};

class Adapter:public Target
{
private:
	Adaptee *adaptee;

public:
	Adapter(){}
	Adapter(Adaptee *a){adaptee = a;}
	~Adapter();
	void operate()
	{
		adaptee->spacial_operate();
	}
};

int main()
{
	Adaptee adaptee;
	Target *target = new Adapter(&adaptee);
	target->operate();
}