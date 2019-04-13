#include<iostream>
#include<string>
using namespace std;


// person
class Product
{
private:
	string hat;
	string clothes;
	string shoes;
public:
	Product()
	{
		this->hat = "";
		this->clothes = "";
		this->shoes = "";
	}
	~Product();
	void set_hat(string hat)
	{
		this->hat = hat;
	}
	void set_clothes(string clothes)
	{
		this->clothes = clothes;
	}
	void set_shoes(string shoes)
	{
		this->shoes = shoes;
	}
	void show()
	{
		
		if(this->hat == "")
			cout <<"I have not been constructed"<<endl;
		else
		{
			cout << this->hat <<endl;
			cout << this->clothes <<endl;
			cout << this->shoes <<endl;
		}
		
	}
};

//Virtual Builder
class AbstractBuilder
{
public:
	virtual void build_hat() = 0;
	virtual void build_clothes() = 0;
	virtual void build_shoes() = 0;
	
	virtual Product* get_product() = 0;
};


//Builder1: build cool guy
class ConcreteBuilderCoolGuy: public AbstractBuilder
{
public:
	void build_hat()
	{
		product.set_hat("I am a cool guy,and I wear a white hat.");
	}
	void build_clothes()
	{
		product.set_clothes("I am a cool guy,and I wear black clothes.");
	}
	void build_shoes() 
	{
		product.set_shoes("I am a cool guy,and I wear a pair of white shoes.");
	}
	Product* get_product()
	{
		return &product;
	}
private:
	Product product;
};

//Builder2: build princess
class ConcreteBuilderPrincess: public AbstractBuilder
{
public:
	void build_hat()
	{
		product.set_hat("I am a princess,and I wear a pink hat.");
	}
	void build_clothes()
	{
		product.set_clothes("I am a princess,and I wear pink clothes.");
	}
	void build_shoes() 
	{
		product.set_shoes("I am a princess,and I wear a pair of pink shoes.");
	}
	Product* get_product()
	{
		return &product;
	}
private:
	Product product;
};

//leader
class Director
{
private:
	AbstractBuilder* builder;

public:
	Director(AbstractBuilder *builder)
	{
		this->builder = builder;
	}
	~Director()
	{
		delete this->builder;
		this->builder = NULL;
	}
	void construct()
	{
		this->builder->build_hat();
		this->builder->build_clothes();
		this->builder->build_shoes();
	}	
};

int main()
{
	AbstractBuilder* builder1 = new ConcreteBuilderCoolGuy;
	Director director1(builder1);
	Product* product = builder1->get_product();
	product->show();
	director1.construct();
	product->show();

	AbstractBuilder* builder2 = new ConcreteBuilderPrincess;
	Director director2(builder2);
	product = builder2->get_product();
	director2.construct();
	product->show();

	return 0;
}