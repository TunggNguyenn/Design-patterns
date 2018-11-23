#include <iostream>
#include <string>
#include <list>
using namespace std;

/*Packing*/
class Packing
{
public:
	virtual string pack() = 0;
};


/*Item*/
class Item
{
public:
	virtual string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};



/*Wrapper*/
class Wrapper : public Packing
{
public:
	virtual string pack()
	{
		return "Wrapper";
	}
};

/*Bottle*/
class Bottle : public Packing
{
public:
	virtual string pack()
	{
		return "Bottle";
	}
};

/*Burger*/
class Burger : public Item
{
public:
	virtual Packing* packing()
	{
		Wrapper *wrapper = new Wrapper;
		return wrapper;
	}
	virtual float price() = 0;
};

/*ColdDrink*/
class ColdDrink : public Item
{
public:
	virtual Packing* packing()
	{
		Bottle *bottle = new Bottle;
		return bottle;
	}

	virtual float price() = 0;
};

/*VegBurger*/
class VegBurger : public Burger
{
public:
	virtual float price()
	{
		return 25.0f;
	}

	virtual string name()
	{
		return "Veg Burger";
	}
};

/*ChickenBurger*/
class ChickenBurger : public Burger
{
public:
	virtual float price()
	{
		return 50.5f;
	}
	virtual string name()
	{
		return "Chicken Burger";
	}
};

/*Coke*/
class Coke : public ColdDrink
{
	virtual float price()
	{
		return 30.0f;
	}

	virtual string name()
	{
		return "Coke";
	}
};

/*Pepsi*/
class Pepsi : public ColdDrink
{
public:
	virtual float price()
	{
		return 35.0f;
	}
	virtual string name()
	{
		return "Pepsi";
	}
};

/*Meal*/
class Meal
{
private:
	Item *items[2];
	int count;
public:
	Meal()
	{
		this->count = 0;
	}
	void addItem(Item *item)
	{
		this->count++;
		this->items[count - 1] = item;
	}

	float getCost()
	{
		float cost = 0.0f;
		for (auto i : this->items)
		{
			cost += i->price();
		}
		return cost;
	}

	void showItems()
	{
		for (auto i : this->items)
		{
			cout << "Item: " << i->name();
			cout << ", Packing: " << i->packing()->pack();
			cout << ", Price: " << i->price() << endl;
		}
	}
};

/*MealBuilder*/
class MealBuilder
{
public:
	Meal prepareVegMeal()
	{
		Meal *meal = new Meal;
		VegBurger *vegBurger = new VegBurger;
		meal->addItem(vegBurger);
		Coke *coke = new Coke;
		meal->addItem(coke);
		return *meal;
	}

	Meal prepareNonVegMeal()
	{
		Meal *meal = new Meal;
		ChickenBurger *chickenBurger = new ChickenBurger;
		meal->addItem(chickenBurger);
		Pepsi *pepsi = new Pepsi;
		meal->addItem(pepsi);
		return *meal;
	}
};

int main()
{
	MealBuilder *mealBuilder = new MealBuilder;

	Meal vegMeal = mealBuilder->prepareVegMeal();
	cout << "Veg Meal: " << endl;
	vegMeal.showItems();
	cout << "Total Cost: " << vegMeal.getCost() << endl;
	cout << "-------------------------------------------------------------" << endl;
	Meal nonVegMeal = mealBuilder->prepareNonVegMeal();
	cout << "Non-Veg Meal: " << endl;
	nonVegMeal.showItems();
	cout << "Total Cost: " << nonVegMeal.getCost() << endl;
	system("pause");
	return 0;
}