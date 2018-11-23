#include<iostream>
using namespace std;

class VietNamese//abstract target
{
public:
	virtual void VNSpeaking() = 0;
};

class VietNameseGirl :public VietNamese//concrete target
{
public:
	virtual void VNSpeaking()
	{
		cout << "Gai Viet Nam noi tieng Viet.";
	}
};

class American//abstract adaptee
{
public:
	virtual void USSpeaking() = 0;
};

class AmericanGirl :public American//concrete adaptee
{
public:
	virtual void USSpeaking()
	{
		cout << "US girls speak English.";
	}
};

class VietNamStyle
{
public:
	void show(VietNamese* vn)
	{
		cout << "\nNguoi Viet Nam tu tin the hien ca tinh: ";
		vn->VNSpeaking();
	}
};

class VietNamAdapter :public VietNamese
{
private:
	American* american;
public:
	VietNamAdapter(American* US)
	{
		american = US;
	}

	void VNSpeaking()
	{
		american->USSpeaking();
	}

};

int main()
{
	VietNameseGirl* vnGirl = new VietNameseGirl;
	AmericanGirl* usGirl = new AmericanGirl;

	VietNamAdapter* adaptedUS = new VietNamAdapter(usGirl);

	VietNamStyle vnStyle;
	cout << "\n\n--------- Viet Nam girl--------";
	vnStyle.show(vnGirl);
	cout << "\n\n--------- Adapted US girl--------";
	vnStyle.show(adaptedUS);


	delete vnGirl;
	delete usGirl;
	delete adaptedUS;

	system("pause");
	return 0;
}