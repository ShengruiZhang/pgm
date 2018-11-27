// This header constains the definition for class *User*
#ifndef GRAPH_H
#define GRAPH_H

typedef unsigned int uint;

#include <string>
#include <vector>

/*-------------------------------------*/
class User
{
	private:
		std::string username;
		uint count_follower;
		uint count_following;

		//std::vector <std::string> _Followers;

	public:
		uint Set_username(std::string _a);
		std::string	Get_username() {return username;}

		uint Set_count_follower(uint _c);
		uint Get_count_follower();

		uint Set_count_following(uint _b);
		uint Get_count_following();

		std::vector <std::string> _Followers;
};

#endif
