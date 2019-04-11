#include<iostream>
using namespace std;

class Product
{
public:
	virtual void show_product_name()=0;
};

class ConcreteProductA:public Product
{
public:
	void show_product_name()
	{
		cout << "Product A"<<endl;
	}
};

class ConcreteProductB:public Product
{
public:
	void show_product_name()
	{
		cout << "Product B"<<endl;
	}
};

class Factory
{
public:
	virtual Product* create_product() =0;
};

class ConcreteFactoryA:public Factory
{
public:
	Product* create_product()
	{
		return new ConcreteProductA;
	}
};

class ConcreteFactoryB:public Factory
{
public:
	Product* create_product()
	{
		return new ConcreteProductB;
	}
};

int main()
{
	Factory* factory = new ConcreteFactoryA;
	
	Product* product1 = factory->create_product();
	product1->show_product_name();

	factory = new ConcreteFactoryB;
	
	Product* product2 = factory->create_product();
	product2->show_product_name();
}