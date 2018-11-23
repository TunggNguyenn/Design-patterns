#include <iostream>
using namespace std;


/*Class AttackBehavior*/
class AttackBehavior
{
public:
	virtual void attack() = 0;
};

/*Class FireBallAttack*/
class FireBallAttack : public AttackBehavior
{
public:
	void attack()
	{
		cout << "I'm attacking with a fire ball.\n";
	}
};


/*Class LegAttack*/
class LegAttack : public AttackBehavior
{
public:
	void attack()
	{
		cout << "I'm attacking with a big leg to kick.\n";
	}
};

/*Class SwordAttack*/
class SwordAttack : public AttackBehavior
{
public:
	void attack()
	{
		cout << "I'm attacking with a long sword.\n";
	}
};


/*Class SpecialFunction*/
class SpecialFunction
{
public:
	virtual void specialFunction() = 0;
};

/*Class Fly*/
class Fly : public SpecialFunction
{
public:
	void specialFunction()
	{
		cout << "I have a special function which is fly.\n";
	}
};

/*Class Invisibility*/
class Invisibility : public SpecialFunction
{
public:
	void specialFuntion()
	{
		cout << "I have a pecial function which is invisible.\n";
	}
};

/*Class Character*/
class Character
{
private:
	float HP;
	AttackBehavior* aBehavior;
	SpecialFunction* sFunction;
public:
	Character()
	{

	}
	~Character()
	{
		if (this->aBehavior != NULL)
		{
			delete this->aBehavior;
		}
		if (this->sFunction != NULL)
		{
			delete this->sFunction;
		}
	}

	virtual void display()
	{
		cout << "I'm a model character.\n";
	}

	void setAttackBehavior(AttackBehavior* ab)
	{
		this->aBehavior = ab;
	}

	void setSpecialFunction(SpecialFunction* sf)
	{
		this->sFunction = sf;
	}

	void performAttackBehavior()
	{
		if (this->aBehavior == NULL)
		{
			cout << "I don't have any attack ability.\n";
		}
		else
		{
			this->aBehavior->attack();
		}
	}

	void performSpecialFunction()
	{
		if (this->sFunction == NULL)
		{
			cout << "I don't have any special ability.\n";
		}
		else
		{
			this->sFunction->specialFunction();
		}
	}

	void setHP(const float& hp)
	{
		this->HP = hp;
	}

	float getHP()
	{
		return this->HP;
	}
};

/*Class Warrior*/
class Warrior : public Character
{
public:
	Warrior()
	{

	}
	void display()
	{
		cout << "I'm a warrior.\n";
	}
};

/*Class Wizard*/
class Wizard : public Character
{
public:
	Wizard()
	{

	}
	void display()
	{
		cout << "I'm a wizard.\n";
	}
};

int main()
{
	Character* warrior = new Warrior;
	warrior->display();

	warrior->setAttackBehavior(new FireBallAttack);
	warrior->performAttackBehavior();

	warrior->setSpecialFunction(new Fly);
	warrior->performSpecialFunction();

	system("pause");
	return 0;
}