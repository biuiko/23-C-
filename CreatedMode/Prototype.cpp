#include<iostream>
#include<string>
using namespace std;

class Prototype
{
private:
	string my_name;
public:
	Prototype(){}
	virtual void show_name()=0;
	virtual void set_name(string name) =0;
	virtual Prototype* clone()=0;
};

class ConcretePrototype1:public Prototype
{
private:
	string my_name;
public:
	ConcretePrototype1(){};
	explicit ConcretePrototype1(const string &name) :my_name(name){}
	void show_name(){cout<<my_name<<endl;}
	void set_name(string name){my_name=name;}
	Prototype* clone()
	{
		ConcretePrototype1* temp = new ConcretePrototype1;
		*temp = *this;
		return temp;
	}	
};

class ConcretePrototype2:public Prototype
{
private:
	string my_name;
public:
	ConcretePrototype2(){};
	explicit ConcretePrototype2(const string &name):my_name(name){}
	void show_name(){cout<<my_name<<endl;}
	void set_name(string name){my_name=name;}
	Prototype* clone()
	{
		ConcretePrototype2* temp = new ConcretePrototype2;
		*temp = *this;
		return temp;
	}	
};

int main()
{
	Prototype* obj1 =new ConcretePrototype1("iko");
	obj1->show_name();
	Prototype* obj2 = obj1->clone();
	obj2->show_name();

	obj2->set_name("ooo");
	obj1->show_name();
	obj2->show_name();

	return 0;
}