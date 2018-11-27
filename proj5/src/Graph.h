// This is the header for the class Edge, the edge of the graph
#ifndef GRAPH_H
#define GRAPH_H

typedef unsigned int uint;

#include <string>
#include <vector>

/*------------------------------------------------------------------------------*/
class Edge {
	private:
	public:
		uint depth;

		std::vector <std::string> UserFollowing;
};

#endif
