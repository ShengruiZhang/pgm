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
	/*	old
		uint CNT_Follower;
		uint depth_Node;
		uint index_at_MainNode;

		std::string Username;
		std::vector <std::string> IncomingEdge;
		*/

		uint CNT_Following;
		uint CNT_Follower;
		std::string Username;
		uint depth_Node;
		std::vector<std::string> UserFollowing;
		std::vector <std::string> IncomingEdge;
};

#endif
