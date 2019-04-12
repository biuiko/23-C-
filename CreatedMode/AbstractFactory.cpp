#include<bits/stdc++.h>
using namespace std;

class ProductA
{
public:
	virtual void product_name()=0;	
};

class ConcreteProductA1:public ProductA
{
public:
	void product_name()
	{
		cout << "Product A1"<<endl;
	}
};
class ConcreteProductA2:public ProductA
{
public:
	void product_name()
	{
		cout << "Product A2"<<endl;
	}
};

class ProductB
{
public:
	virtual void product_name()=0;	
};

class ConcreteProductB1:public ProductB
{
public:
	void product_name()
	{
		cout << "Product B1"<<endl;
	}
};
class ConcreteProductB2:public ProductB
{
public:
	void product_name()
	{
		cout << "Product B2"<<endl;
	}
};


class Factory
{
public:
	virtual ProductA* create_product_a() = 0;
	virtual ProductB* create_product_b() = 0;
};

class ConcreteFactory1:public Factory
{
public:
	ProductA* create_product_a()
	{
		return new ConcreteProductA1;
	}
	ProductB* create_product_b()
	{
		return new ConcreteProductB1;
	}
	
};

class ConcreteFactory2:public Factory
{
public:
	ProductA* create_product_a()
	{
		return new ConcreteProductA2;
	}
	ProductB* create_product_b()
	{
		return new ConcreteProductB2;
	}
	
};
int main()
{
	Factory* factory = new ConcreteFactory1;
	ProductA* producta = factory->create_product_a();
	ProductB* productb = factory->create_product_b();
	cout<<"FROM FACTORY 1"<<endl;
	producta->product_name();
	productb->product_name();
	delete factory;
	factory = NULL;
	factory = new ConcreteFactory2;
	producta = factory->create_product_a();
	productb = factory->create_product_b();	
	cout<<"FROM FACTORY 2"<<endl;
	producta->product_name();
	productb->product_name();
	delete factory;
}