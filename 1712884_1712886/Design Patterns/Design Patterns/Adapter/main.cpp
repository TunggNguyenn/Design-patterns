#include<iostream>
#include<string>

using namespace std;

string tachHoTen(string fullName, string x)
{
	string ho = "";
	string ten = "";
	int i = 0;
	int n = fullName.length();
	for (i; i < n; i++)
	{
		if (fullName[i] != ' ')
		{
			ho += fullName[i];
		}
		else
		{
			break;
		}
	}


	i = i + 1;
	for (i; i < n; i++)
	{
		ten += fullName[i];

	}

	if (x == "ho")
	{
		return ho;
	}
	else if (x == "ten")
	{
		return ten;
	}

}

class DH_layFullTen
{
private:
	string fullName;
public:
	void setName(string name)
	{
		fullName = name;
	}

	string getName()
	{
		return fullName;
	}
};

class DH_lay_ho_ten
{
protected:
	string ho;
	string ten;
public:
	void set_ho(string fn)
	{
		ho = fn;
	}

	void set_ten(string ln)
	{
		ten = ln;
	}
	string get_ho()
	{
		return ho;
	}
	string get_ten()
	{
		return ten;
	}
};

class DHfullName_to_DHHoTen_adapter :public DH_lay_ho_ten
{
private:
	DH_layFullTen khachHang;
	string ho;
	string ten;

public:
	DHfullName_to_DHHoTen_adapter(DH_layFullTen khach)
	{
		khachHang = khach;
		ho = tachHoTen(khach.getName(), "ho");
		ten = tachHoTen(khach.getName(), "ten");
	}

	void set_ho(string fn)
	{
		ho = fn;
	}

	void set_ten(string ln)
	{
		ten = ln;
	}
	string get_ho()
	{
		return ho;
	}
	string get_ten()
	{
		return ten;
	}


};


int main()
{
	DH_layFullTen khA;
	khA.setName("Lieu Tuong");
	cout << "\n\nDon hang lay full ten: ";
	cout << "\nFull name: " << khA.getName();

	DH_lay_ho_ten khB;
	khB.set_ho("Lieu");
	khB.set_ten("Tuong");
	cout << "\n\nDon hang tach ho, ten: ";
	cout << "\nHo: " << khB.get_ho();
	cout << "\nTen: " << khB.get_ten();


	DHfullName_to_DHHoTen_adapter adapter(khA);
	cout << "\n\nSau khi dung adapter cho don hang lay full ten: ";
	cout << "\nHo: " << adapter.get_ho();
	cout << "\nTen: " << adapter.get_ten();

	system("pause");
	return 0;
}