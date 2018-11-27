#include "Graph.h"

#include <string>

using namespace std;

uint User::Set_username(string _a)
{
	username = _a;
	return 1;
}

uint User::Set_count_follower(uint _c)
{
	count_follower = _c;
	return 1;
}

uint User::Get_count_follower()
{
	return count_follower;
}

uint User::Set_count_following(uint _b)
{
	count_following = _b;
	return 1;
}

uint User::Get_count_following()
{
	return count_following;
}
