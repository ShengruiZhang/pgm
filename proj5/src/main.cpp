// This is the main program

#include "Graph.h"
#include "node.h"

#include <iostream>

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <vector>
#include <unordered_map>
#include <algorithm> // To use std::find

#define GLOBAL_NO_DEBUG 0

#if GLOBAL_NO_DEBUG
#define GLOBAL_DEBUG 0
#define DEBUG_FILE_INPUTING 0
#define DEBUG_BFS 0
#else


// Toggle each main debugging category
#define GLOBAL_DEBUG 0
#define DEBUG_FILE_INPUTING 0
#define DEBUG_BFS 1
#endif


#if DEBUG_FILE_INPUTING
// Toggle each sub-category debugging
#define DEBUG_INPUT 1
#define DEBUG_GETLINE 1
#define DEBUG_INPUT_COUNT 1
#define DEBUG_SEARCH_MATCHING 1
#define DEBUG_PRINT_LIST 0
#define DEBUG_NODE 1


#else
#define DEBUG_INPUT 0
#define DEBUG_GETLINE 0
#define DEBUG_INPUT_COUNT 0
#define DEBUG_SEARCH_MATCHING 0
#define DEBUG_PRINT_LIST 0
#define DEBUG_NODE 0
#endif


#if DEBUG_BFS
// Toggle each sub-category debugging
#define DEBUG_BFS_QUEUE 1
#define DEBUG_BFS_DICV_SET 1
#define DEBUG_BFS_ADJ 1


#else
#define DEBUG_BFS_QUEUE 0
#define DEBUG_BFS_DICV_SET 0
#define DEBUG_BFS_ADJ 0
#endif

typedef unsigned int uint;

using namespace std;

/*--------------------------------------------------------------------------*/
uint ReadingFile		( unordered_map<string, Edge> &, vector<Node> &, string);
void PrintingList		( unordered_map<string, Edge> &);
Node SearchNode			( vector<Node>, string);
/*--------------------------------------------------------------------------*/



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Main function /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
	if(argc != 4)
	{
#if GLOBAL_DEBUG
		cout << "Don't have enough arguments." << endl;
#endif
		return 0;
	}

	string inputFileName = argv[1];
	string Username = argv[2];
	string outputFileName = argv[3];


	/*----------------------------------------------*/
	unordered_map <string, Edge> MainList;
	vector<Node> MainNode;
#if GLOBAL_DEBUG
	cout << "Unordered map created." << endl;
#endif

	// Read the input file
	ReadingFile(MainList, MainNode, inputFileName);

#if DEBUG_PRINT_LIST
	PrintingList(MainList);
#endif

	// Create a vector as the queue for frontierQueue
	// Nodes to be visited will be added to the queue
	// Use push_back to add nodes to the end of the vector
	// Use vector.erase(vector.begin()) to pop the first element
	//

	// Here starts the BFS search
	
	// We need a queue for upcoming nodes,
	// 	a vector for discovered set
	// 	maybe a another vector for storing the qulified items
	
	// The frontierQueue
	vector<Edge> MainQueue;

	// The discoveredSet
	vector<Node> DiscoveredList;

	// The qualified list, unsorted
	vector<Node> QualifiedList;

	Node currentNode;
	Edge currentEdge;
	

	// Start the BFS from the user specified
	// Push the starting node to MainQueue
	MainQueue.push_back( MainList.at(Username) );

	// Add the first node to DiscoveredList
	for(uint i = 0; i < MainNode.size(); ++i)
	{
			if(MainNode.at(i).Username == Username)
			{
					DiscoveredList.push_back( MainNode.at(i) );
					
					// also set the currentNode for the first use
					currentNode = MainNode.at(i);
			}
	}

#if DEBUG_BFS_DICV_SET
	cout << endl << "DiscoveredList Last: "
			<< DiscoveredList.back().Username << endl;
#endif

#if DEBUG_BFS_QUEUE
	cout << endl;
	cout << "Debug: start at: " << Username
			<< ". This Username follows these people: " << endl;
	cout << endl;
	for(uint i = 0; i < MainQueue.back().UserFollowing.size(); ++i)
	{
			cout << MainQueue.back().UserFollowing.at(i);
	}
	cout << endl;
#endif

	//------------------------------------------------------------------------------//
	//------------------------------------------------------------------------------//
	//	Main while loop for MainQueue
	while( !MainQueue.empty() )
	{
			// Set current edge and current node
			currentEdge = MainQueue.at(0);

			// TODO: How to detemine the current node
#if DEBUG_BFS_QUEUE
			cout << endl;
			cout << "----------------------------------------";
			cout << endl << "Current Edge has these following: " << endl;
			for(uint i = 0; i < currentEdge.UserFollowing.size(); ++i)
			{
							cout << currentEdge.UserFollowing.at(i) << endl;
			}
			cout << "Finished printing out current Edge." << endl;
#endif

			// Pop the first element of the queue
			MainQueue.erase(MainQueue.begin());

			// Visiting actions
			// TODO


			// for loop for adjacent Node
			// TODO


	}
	//------------------------------------------------------------------------------//
	//------------------------------------------------------------------------------//








	/*----------------------------------------------------------*/
	ofstream oup_stream;
	oup_stream.open(outputFileName);
	oup_stream.close();
	return 0;
}
////////////////// End of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
uint ReadingFile(	unordered_map<string, Edge> &MainList,
			vector<Node> &MainNode,
			string inputFileName)
{
#if DEBUG_INPUT_COUNT
	uint _counter = 0;
#endif
	ifstream	inp_stream;
	istringstream	inp_SS;

#if DEBUG_INPUT
	cout << "Input file: " << inputFileName << endl;
#endif

	inp_stream.open(inputFileName);
	if( inp_stream.is_open() )
	{
#if DEBUG_INPUT
		cout << "File seems to be opened." << endl;
#endif
	}
	else
	{
#if DEBUG_INPUT
		cout << "File cannot be opened." << endl;
#endif
		return 0;
	}


	/////////////////////////////////////////
	// Create temps
	string input_raw;
	string Username_temp, UserFollowing_temp;
	Edge temp_Edge;
	Node temp_Node;
	auto search_match = MainList.find("null");

	uint node_flag = 0;
	uint node_i = 0;
	/////////////////////////////////////////


#if DEBUG_INPUT
	cout << "Input string steam created." << endl;
#endif

	//***********************************************************************/
	// Main Loop
	while( !inp_stream.eof() )
	{
		// Clear temps
		input_raw.clear();
		Username_temp.clear();
		UserFollowing_temp.clear();
		inp_SS.clear();
		temp_Edge.UserFollowing.clear();
		temp_Edge.depth = 0;

#if DEBUG_GETLINE
		cout << "-------------------------------------------" << endl;
		cout << "Getting a line." << endl << endl;
#endif

		// Take a line from the file
		getline(inp_stream, input_raw);

		// Check for new line \n
		if(inp_stream.eof())
		{
#if DEBUG_GETLINE
			cout << "File bottom out." << endl;
#endif
		// Calculate the count of followers
			for(uint i = 0; i < MainNode.size(); ++i)
			{
				MainNode.at(i).CNT_Follower = MainNode.at(i).IncomingEdge.size();
#if DEBUG_NODE
				cout << "Username: "
					<< MainNode.at(i).Username
					<< " has " << MainNode.at(i).CNT_Follower
					<< " followers." << endl;
#endif
			}
			return 1;
		}

#if DEBUG_GETLINE
		cout << "Raw input: " << input_raw << endl << endl;
#endif
		// Stringstream operation
		inp_SS.str(input_raw);
		inp_SS >> UserFollowing_temp;
		inp_SS >> Username_temp;

#if DEBUG_GETLINE
		cout << "Username temp: " << setw(15) << left << Username_temp
			<< " Follows: " << setw(20) << left << UserFollowing_temp
			<< endl << endl;
#endif

#if DEBUG_INPUT_COUNT
		++_counter;
#endif

		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//	MainList
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// Making the graph by checking if the Username is already existed
		search_match = MainList.find(Username_temp);
		if( search_match == MainList.end() )
		{// The Username is new, so create a new entry in the MainList

#if DEBUG_SEARCH_MATCHING
			cout << "No existing entry for Username: "
				<< Username_temp
				<< endl;
			cout << "Creating a new entry in unordered map." << endl;
#endif

#if DEBUG_INPUT_COUNT
			cout << "Count: " << _counter << endl;
#endif

			// Make the UserFollowing_temp as the first element of the temp
			// 	vector
			temp_Edge.UserFollowing.push_back(UserFollowing_temp);
			// Put the temp into the unordered map
			MainList.insert( {Username_temp, temp_Edge} );

#if DEBUG_SEARCH_MATCHING
			cout << "New entry: Username: " << Username_temp
				<< " Last Following: "
				<< MainList.at(Username_temp).UserFollowing.back()
				<< endl;
#endif
		}
		else
		{// The Username is already existed in the map, so add to the vector
#if DEBUG_SEARCH_MATCHING
			cout << UserFollowing_temp << " is already existed." << endl;
			cout << "New following: " << UserFollowing_temp << endl;
#endif

#if DEBUG_INPUT_COUNT
			cout << "Count: " << _counter << endl;
#endif
			// Add the UserFollowing_temp to the corresponding vector
			MainList.at(Username_temp).
				UserFollowing.push_back(UserFollowing_temp);
#if DEBUG_SEARCH_MATCHING
			cout << "Existing Username got a new following: "
				<< MainList.at(Username_temp).UserFollowing.back()
				<< endl;
#endif
		}	// Finished the adding entry



		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//	MainNode
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// Clear temp
		temp_Node.Username.clear();
		temp_Node.IncomingEdge.clear();
		node_i = 999999;
		node_flag = 0;

		temp_Node.Username = UserFollowing_temp;
		for(uint i = 0; i < MainNode.size(); ++i)
		{
#if DEBUG_NODE
			cout << endl << "Node Test: " << endl;
			cout << MainNode.at(i).Username << endl;
#endif
			if(MainNode.at(i).Username == UserFollowing_temp)
			{
				// Found existing
				node_flag = 1;
				node_i = i;
				break;
			}
			else
			{
				// Doesn't exist
				node_flag = 0;
				node_i = 999;
			}
		}

#if DEBUG_NODE
		cout << endl << "Node operation." << endl;
		cout << "i: " << node_i << endl;
#endif
		if(!node_flag)
		{// When Username doesn't exist in MainNode yet
#if DEBUG_NODE
			cout << "Username: " << UserFollowing_temp
				<< " doesn't exist yet."
				<< " Creating new entry in MainNode." << endl;
#endif
			MainNode.push_back(temp_Node);
			// Put the follower of Username into the node member
			MainNode.back().
				IncomingEdge.push_back(Username_temp);
#if DEBUG_NODE
			cout << "Username; " << UserFollowing_temp
				<< " has follower: "
				<< MainNode.back().
				IncomingEdge.back() << endl;
#endif
		}
		else
		{// Username already existed in MainNode
#if DEBUG_NODE
			cout << "Username: " << UserFollowing_temp
				<< " has already existed in vector."
				<< " Adding it to current vector." << endl;
#endif
			MainNode.at(node_i).IncomingEdge.
				push_back(Username_temp);

#if DEBUG_NODE
			cout << "Username: " << UserFollowing_temp
				<< " has a new follower: "
				<< MainNode.at(node_i).IncomingEdge.
				back() << endl;
#endif
		}
	}	// End while loop
	inp_stream.close();
	return 1;
}
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
#if DEBUG_PRINT_LIST
void PrintingList( unordered_map<string, Edge> &MainList)
{
	uint counter = 0;
	cout<<endl<<endl;
	for(auto& it: MainList) {
		cout << "------------------------------" << endl;
		cout << "Username: ";
		cout << it.first << endl;

		cout << endl << "Following:" << endl;
		for(uint i = 0; i < it.second.UserFollowing.size(); ++i)
		{
			cout << it.second.UserFollowing.at(i) << endl;
		}
		cout << endl;
		++counter;
	}
	cout << "Counter: " << counter << endl;
	cout << "Map size: " << MainList.size() << endl;
}
#endif
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
Node SearchNode			( vector<Node> MainNode, string Username)
{
				uint index = 0;
				for(index = 0; index < MainNode.size(); ++index)
				{
								if(MainNode.at(index).Username == Username)
								{
												return MainNode.at(index);
								}
				}

				Node empty;
				empty.Username = "Username cannot be found";
				return empty;
}
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
