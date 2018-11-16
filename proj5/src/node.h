// This header constains the definition of class
// 	*CONNECTION*, which is used to keep track
// 	of users' follower and who's following

#ifndef NODE_H
#define NODE_H

typedef unsigned int uint;

#include <string>
#include <vector>

class CONNECTION
{
	private:
		std::vector <std::string> _Followers;
		std::vector <std::string> _Following;
	public:
		uint Add_followers(std::string _x);
		std::vector <std::string> Get_followers_list();

		uint Add_following(std::string _xx);
		std::vector <std::string> Get_following_list();
};

#endif
