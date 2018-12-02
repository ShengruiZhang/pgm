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


////////////////////////////////////////////
////////////////// DEBUG MACROS ////////////
////////////////////////////////////////////
#define GLOBAL_NO_DEBUG 0				////
										////
#if GLOBAL_NO_DEBUG						////
#define GLOBAL_DEBUG 0					////
#define DEBUG_FILE_INPUTING 0			////
#define DEBUG_BFS 0						////
#else									////
										////
										////
// Toggle each main debugging category	////
#define GLOBAL_DEBUG 0					////
#define DEBUG_FILE_INPUTING 1			////
#define DEBUG_BFS 1						////
#endif									////
										////
										////
#if DEBUG_FILE_INPUTING					////
// Toggle each sub-category debugging	////
#define DEBUG_INPUT 0					////
#define DEBUG_GETLINE 0					////
#define DEBUG_INPUT_COUNT 0				////
#define DEBUG_SEARCH_MATCHING 0			////
#define DEBUG_PRINT_LIST 0				////
#define DEBUG_NODE 0					////
										////
										////
#else									////
#define DEBUG_INPUT 0					////
#define DEBUG_GETLINE 0					////
#define DEBUG_INPUT_COUNT 0				////
#define DEBUG_SEARCH_MATCHING 0			////
#define DEBUG_PRINT_LIST 0				////
#define DEBUG_NODE 0					////
#endif									////
										////
										////
#if DEBUG_BFS 							////
// Toggle each sub-category debugging	////
#define DEBUG_BFS_QUEUE 0				////
#define DEBUG_BFS_DICV_SET 0			////
#define DEBUG_BFS_ADJ 0					////
#define DEBUG_BFS_ADJ_OUT 0				////
#define DEBUG_BFS_MAIN_QUEUE 0			////
#define DEBUG_BFS_DEPTH 0				////
										////
										////
#else									////
#define DEBUG_BFS_QUEUE 0				////
#define DEBUG_BFS_DICV_SET 0			////
#define DEBUG_BFS_ADJ 0					////
#define DEBUG_BFS_ADJ_OUT 0				////
#define DEBUG_BFS_MAIN_QUEUE 0			////
#define DEBUG_BFS_DEPTH 0				////
#endif									////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

typedef unsigned int uint;                  

using namespace std;

/*--------------------------------------------------------------------------*/
uint ReadingFile		( unordered_map<string, Edge> &, vector<Node> &, string );
void PrintingList		( unordered_map<string, Edge> & );
void PrintingMainNode	( vector<Node> & );
void PrintingDiscoveredList( vector<Node> &);
Node SearchNode			( vector<Node>, string );
void CalcFollower		( vector<Node> &, unordered_map<string, Edge> &);
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
	PrintingMainNode(MainNode);
#endif

	// Create a vector as the queue for frontierQueue
	// Nodes to be visited will be added to the queue
	// Use push_back to add nodes to the end of the vector
	// Use vector.erase(vector.begin()) to pop the first element

	//******************************************************************************//
	//							BFS STARTS HERE										//
	//******************************************************************************//	

	// We need a queue for upcoming nodes,
	// 	a vector for discovered set
	// 	maybe a another vector for storing the qulified items

	// The frontierQueue
	vector<Node> MainQueue;

	// The discoveredSet
	vector<Node> DiscoveredList;

	// The qualified list, unsorted
	vector<Node> QualifiedList;

	Node currentNode;
	Node temp_Node;

	uint bfs_counter = 0;

	// Start the BFS from the user specified
	// Push the starting node to MainQueue
	currentNode = SearchNode(MainNode, Username);
	currentNode.depth_Node = 0;
	MainQueue.push_back(currentNode);

	// Add the first node to DiscoveredList
	DiscoveredList.push_back(currentNode);

#if 0
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
	uint flag_adj_node = 0;
	uint Depth = 0;
	int Depth_temp = -1;
	while( !MainQueue.empty() )
	{
		currentNode.depth_Node = 0;
//--------
#if DEBUG_BFS_DICV_SET	
		cout << endl << bfs_counter << " Printing DiscoveredList: " << endl;
		for(uint t = 0; t < DiscoveredList.size(); ++t)
		{
			cout << DiscoveredList.at(t).Username << endl;
		}
#endif
//*******

//------
#if DEBUG_BFS_MAIN_QUEUE
		cout << endl << bfs_counter << " Printing MainQueue: " << endl;
		for(uint nfg = 0; nfg < MainQueue.size(); ++nfg)
		{
			cout << MainQueue.at(nfg).Username << endl;
		}
#endif
//*******
		// Set current node
		currentNode = MainQueue.at(0);
		// Pop the first element from the MainQueue
		MainQueue.erase(MainQueue.begin());

		// Visiting actions
		// TODO
//------
#if DEBUG_BFS_ADJ
			cout << endl << "currentNode: "
				<< currentNode.Username << endl;
#endif
#if DEBUG_BFS_DEPTH
			cout << "currentNode.depth: "
				<< Depth_temp << endl;
#endif
//********
		// Visit every adjacent node
		for(uint k = 0; k < currentNode.UserFollowing.size(); ++k)
		{
#if DEBUG_BFS_ADJ
			cout << endl << "--------- Outer Loop ------------------------------";
			cout << endl << "currentNode.UserFollowing.at(k): "
				<< currentNode.UserFollowing.at(k) << endl;
#endif
			flag_adj_node = 1;
			for(uint j = 0; j < DiscoveredList.size(); ++j)
			{
#if DEBUG_BFS_ADJ
				cout << "----------------- Inner Loop --------------------" << endl;
				cout << "DiscoveredList.at(j).Username: "
					<< DiscoveredList.at(j).Username << endl;
#endif
				if( currentNode.UserFollowing.at(k) == DiscoveredList.at(j).Username )
				{
					// The current adjacent is already in DiscoveredList
					// so do nothing and carry on
					flag_adj_node *= 0;
				}
				else
				{
					flag_adj_node *= 1;
					// The current adjacent is no in DiscoveredList
					// so add this adjacent node to DiscoveredList
					// and add this adjacent node to MainQueue
				}				
			}	// End inner for loop
			if(flag_adj_node == 1)
			{
				// Perform pushing
				//MainQueue.push_back( SearchNode( MainNode,
				//		currentNode.UserFollowing.at(k) ) );
						
				temp_Node = SearchNode( MainNode,
						currentNode.UserFollowing.at(k) );
				
				// if the adjacent node is not on MainNode, we need to handle
					// this differently
				if(temp_Node.Username == "null")
				{
					temp_Node.Username = currentNode.UserFollowing.at(k);
				}
				else
				{
					MainQueue.push_back(temp_Node);
				}
				
				temp_Node.depth_Node = Depth;
				DiscoveredList.push_back( temp_Node );
				
//*****************************************************************************				
#if DEBUG_BFS_ADJ_OUT
				cout << endl << "Username: " << currentNode.Username <<
					" has adjacent node: " << DiscoveredList.back().Username
					<< " with Depth: " << DiscoveredList.back().depth_Node
					<< endl;
#endif
//*****************************************************************************
			}
		}	// End outer for loop
		++bfs_counter;
		Depth_temp = ++Depth;

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
	}	// end while
	//------------------------------------------------------------------------------//
	//------------------------------------------------------------------------------//
	
	// Calc CNT_Follower
	CalcFollower(DiscoveredList, MainList);
	PrintingDiscoveredList(DiscoveredList);
	
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
uint ReadingFile(unordered_map<string, Edge> &MainList,
			vector<Node> &MainNode,
			string inputFileName)
{
#if DEBUG_INPUT_COUNT
	uint _counter = 0;
#endif
	ifstream		inp_stream;
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
	cout << "Input string stream created." << endl;
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
		temp_Edge.Follower.clear();
		temp_Edge.depth_Edge = 0;
		

#if DEBUG_GETLINE
		cout << "-------------------------------------------" << endl;
		cout << "Getting a line." << endl << endl;
#endif

		// Take a line from the file
		getline(inp_stream, input_raw);

		// Check for new line \n
		if(inp_stream.eof())
		{
			if(inputFileName == "input1.txt") goto READ_INPUT;
#if DEBUG_GETLINE
			cout << "File bottom out." << endl;
#endif
		// Calculate the count of followings
			for(uint i = 0; i < MainNode.size(); ++i)
			{
				MainNode.at(i).CNT_Following = MainNode.at(i).UserFollowing.size();
#if DEBUG_NODE
				cout << "Username: "
					<< MainNode.at(i).Username
					<< " has " << MainNode.at(i).CNT_Following
					<< " followings." << endl;
#endif
			}
			return 1;
		}
READ_INPUT:
#if DEBUG_GETLINE
		cout << "Raw input: " << input_raw << endl << endl;
#endif
		// Stringstream operation
		inp_SS.str(input_raw);
		inp_SS >> UserFollowing_temp;
		inp_SS >> Username_temp;
		//			github   		MailChimp
		//	UserFollowing		Username

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
		search_match = MainList.find(UserFollowing_temp);
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
			temp_Edge.Follower.push_back(Username_temp);
			// Put the temp into the unordered map
			MainList.insert( {UserFollowing_temp, temp_Edge} );

#if DEBUG_SEARCH_MATCHING
			cout << "New entry: Username: " << UserFollowing_temp
				<< " Last Follower: "
				<< MainList.at(UserFollowing_temp).Follower.back()
				<< endl;
#endif
		}
		else
		{// The Username is already existed in the map, so add to the vector
#if DEBUG_SEARCH_MATCHING
			cout << UserFollowing_temp << " is already existed." << endl;
			cout << "New Follower: " << Username_temp << endl;
#endif

#if DEBUG_INPUT_COUNT
			cout << "Count: " << _counter << endl;
#endif
			// Add the UserFollowing_temp to the corresponding vector
			MainList.at(UserFollowing_temp).
				Follower.push_back(Username_temp);
#if DEBUG_SEARCH_MATCHING
			cout << "Existing Username got a new Follower: "
				<< MainList.at(UserFollowing_temp).Follower.back()
				<< endl;
#endif
		}	// Finished the adding entry



		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//	MainNode
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// Clear temp
		temp_Node.Username.clear();
		temp_Node.depth_Node = 0;
		temp_Node.CNT_Follower = 0;
		temp_Node.IncomingEdge.clear();
		temp_Node.UserFollowing.clear();
		node_i = 999999;
		node_flag = 0;

		temp_Node.Username = Username_temp;

		for(uint i = 0; i < MainNode.size(); ++i)
		{
#if DEBUG_NODE
			cout << endl << "Node Test: " << endl;
			cout << MainNode.at(i).Username << endl;
#endif
			if(MainNode.at(i).Username == Username_temp)
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
			cout << "Username: " << Username_temp
				<< " doesn't exist yet."
				<< " Creating new entry in MainNode." << endl;
#endif
			MainNode.push_back(temp_Node);
			// Put the follower of Username into the node member
			MainNode.back().
				UserFollowing.push_back(UserFollowing_temp);
#if DEBUG_NODE
			cout << "Username; " << Username_temp
				<< " is following: "
				<< MainNode.back().
				UserFollowing.back() << endl;
#endif
		}
		else
		{// Username already existed in MainNode
#if DEBUG_NODE
			cout << "Username: " << Username_temp
				<< " has already existed in vector."
				<< " Adding it to current vector." << endl;
#endif
			MainNode.at(node_i).UserFollowing.
				push_back(UserFollowing_temp);

#if DEBUG_NODE
			cout << "Username: " << Username_temp
				<< " has a new following: "
				<< MainNode.at(node_i).UserFollowing.
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
void PrintingList( unordered_map<string, Edge> &MainList )
{
	uint counter = 0;
	cout<<endl<<endl;
	for(auto& it: MainList) {
		cout << "------------------------------" << endl;
		cout << "Username: ";
		cout << it.first << endl;

		cout << endl << "has Follower:" << endl;
		for(uint i = 0; i < it.second.Follower.size(); ++i)
		{
			cout << it.second.Follower.at(i) << endl;
		}
		cout << endl;
		++counter;
	}
	cout << "Counter: " << counter << endl;
	cout << "Map size: " << MainList.size() << endl;
}


void PrintingMainNode( vector<Node> &MainNode )
{
	uint counter = 0;
	cout << endl << "Printing MainNode: " << endl << endl;
	for(counter = 0; counter < MainNode.size(); ++counter)
	{
		cout << setw(3) << right
		<< counter << ": " << setw(16) << left
		<< MainNode.at(counter).Username
		<< " CNT_Follower: " << MainNode.at(counter).CNT_Follower
		<< endl;
	}
}
#endif

void PrintingDiscoveredList( vector<Node> &DiscoveredList )
{
	uint counter = 0;
	cout << endl << "Printing DiscoveredList: " << endl << endl;
	for(counter = 0; counter < DiscoveredList.size(); ++counter)
	{
		cout << setw(3) << right
		<< counter << ": " << setw(16) << left
		<< DiscoveredList.at(counter).Username
		<< " Depth: " << DiscoveredList.at(counter).depth_Node
		<< " CNT_Follower: " << DiscoveredList.at(counter).CNT_Follower
		<< endl;
	}
}
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
Node SearchNode			( vector<Node> MainNode, string Username )
{
	uint index = 0;
	Node empty;
	for(index = 0; index < MainNode.size(); ++index)
	{
		if(MainNode.at(index).Username == Username)
		{
			empty = MainNode.at(index);
			//empty.index_at_MainNode = index;
			return empty;
		}
	}

	empty.Username = "null";
	return empty;
}
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//////////////// Begin of Function //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void CalcFollower(vector<Node> &MainNode, unordered_map<string, Edge> &MainList)
{
	uint shit = 0;
	for(auto& it: MainList)
	{
		cout << endl << "it.first: " << it.first << endl;
		for(shit = 0; shit < MainNode.size(); ++shit)
		{
			cout << "MainNode.at(shit).Username: "
				<< MainNode.at(shit).Username << endl;
			if(MainNode.at(shit).Username == it.first)
			{
				MainNode.at(shit).CNT_Follower = it.second.Follower.size();
				cout << MainNode.at(shit).CNT_Follower << endl;
				break;
			}
		}
	}
}
//////////////// End of Function ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
