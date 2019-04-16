#include<iostream>
#include<string>
using namespace std;

class Component
{
public:
	Component(){};
	~Component(){};
	virtual void show()=0;
	virtual void add(string other)
	{
		name+=other;
	}
private:
	string name;
};

class ConcreteComponent:public Component
{
public:
	ConcreteComponent(string n):name(n){}
	~ConcreteComponent(){};
	void show()
	{
		cout << name <<endl;
	}
	void add(string other)
	{
		name+=other;
	}
private:
	string name;
};

class Decorator:public Component
{
public:
	Decorator(){}
	Decorator(Component *com):component(com){}
	~Decorator(){}
	virtual void show(){component->show();}
	virtual void operate() = 0;
private:
	Component* component;
	
};

class ConcreteDecoratorA:public Decorator
{
public:
	ConcreteDecoratorA(Component* com):component(com){}
	~ConcreteDecoratorA(){};
	void show()
	{
		component->show();
	}
	void operate()
	{
		component->add(" milk");
	}
private:
	Component* component;

};

class ConcreteDecoratorB:public Decorator
{
public:
	ConcreteDecoratorB(Component* com):component(com){}
	~ConcreteDecoratorB(){};
	void show()
	{
		component->show();
	}

	void operate()
	{
		component->add(" chocolate");
	}
private:
	Component* component;

};

int main()
{
	// add milk at first,add chocolate at second 
	Component *c = new ConcreteComponent("cake");
	c->show();
	Decorator *d = new ConcreteDecoratorA(c);	
	d->operate();	//add milk
	d->show();
	delete d;
	d = nullptr;

	d = new ConcreteDecoratorB(c);
	d->operate();	//add chocolate after milk 
	d->show();
	delete d;
	delete c;
	d = nullptr;
	c= nullptr;

	// add chocolate at first ,add milk at second
	c = new ConcreteComponent("cake");
	c->show();
	d = new ConcreteDecoratorB(c);	
	d->operate();	//add chocolate
	d->show();
	delete d;
	d = nullptr;

	d = new ConcreteDecoratorA(c);
	d->operate();	//add milk after chocolate
	d->show();
	delete d;
	delete c;
	d = nullptr;
	c= nullptr;

	return 0;
}