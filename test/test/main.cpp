#include <string>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;
class IObj
{
public:
	virtual int callback(string t_data) = 0;
};


class AppleObj : public IObj
{

public:
	virtual int callback(string t_data) final
	{
		cout << "this is  appleobj : " << endl;
		return 0;
	}
};

class BananaObj : public IObj
{
public:
	virtual int callback(string t_data) final
	{
		cout << "this is  banana object: " << endl;
		return 1;
	}
};


class DeleManager
{
public:
	DeleManager() {};
	~DeleManager() {};
	void addObj(function<int(string)> t_dele)
	{
		_dele_list.push_back(t_dele);
	}
	void notify(string t_msg)
	{
		if (_dele_list.empty())
		{
			cout << "list is empty " << endl;
			return;
		}

		for (auto itor : _dele_list)
		{
			itor(t_msg);
		}
	}

private:
	vector <function<int(string)>> _dele_list;
};

void main()
{
	string a = "-0.12345";
	cout << a.substr(2) << endl;
	cout << atof(a.c_str()) << endl;
}
