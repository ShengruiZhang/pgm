// This is the header for the class User, which contains the Username and the IncomingEdge

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

typedef unsigned int uint;
/*-------------------------------------------------------------------------------*/
class Node {
	private:
	public:
		uint CNT_Follower;

		std::string Username;
		std::vector <std::string> IncomingEdge;
};

#endif
