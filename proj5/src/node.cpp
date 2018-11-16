#include "node.h"

#include <string>
#include <vector>

using namespace std;

uint CONNECTION::Add_followers(string _x)
{
	if(_x.size() != 0)
	{
		_Followers.push_back(_x);
	}
	return _Followers.size();
}

vector<string> CONNECTION::Get_followers_list()
{
	return _Followers;
}

uint CONNECTION::Add_following(string _xx)
{
	if(_xx.size() != 0)
	{
		_Following.push_back(_xx);
	}
	return _Following.size();
}

vector<string> CONNECTION::Get_following_list()
{
	return _Following;
}
