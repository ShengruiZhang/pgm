// Main funciton
#include "Graph.h"
#include "node.h"

#include <iostream>

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <vector>
#include <unordered_map>

#define NO_LIST_PRINTING 1

// Debug entries
#define DEBUG_GETLINE 0
#define DEBUG_LINE_INPUT 0 
#define DEBUG_NO_EXISTING_MATCH 0
#define DEBUG_READING_MAP_PRINTOUT 0

#define DEBUG_LOG 0 

typedef unsigned int uint;

using namespace std;

void ReadingInput( unordered_map<string, User > &, string);
#if !(NO_LIST_PRINTING)
void PrintingList( unordered_map<string, User > &);
#endif
uint OutputList( unordered_map<string, User > &, string, string);

int main(int argc, char *argv[]) {
	if(argc != 4)
	{
		// Not enough arguments
		cout << "Don't have enough arguments." << endl;
		return 0;
	}
	string inputFileName = argv[1];
	string userName = argv[2];
	string outputFileName = argv[3];

	/*--------------------------------------------------------------------*/
	// Create List object, type of unordered map
	unordered_map < string, User > MainList;
#if DEBUG_NO_LOG
	cout << "Unordered map created." << endl;
#endif

	ReadingInput(MainList, inputFileName);

#if !(NO_LIST_PRINTING)
	PrintingList(MainList);
#endif

	OutputList(MainList, outputFileName, userName);

	return 0;
}

void ReadingInput(unordered_map< string, User > &MainList, string inputFileName)
{
	// Input file stream
	ifstream inp_stream;

#if DEBUG_LOG
	cout << inputFileName << endl;	
#endif
	inp_stream.open(inputFileName);

	if( inp_stream.is_open() ) {}//cout << "The file is opened." << endl;
	else
	{
		cout << "The file cannot be opened." << endl;
	}

	string input_raw;
	string username_temp, sub_temp;
	User temp;

	// Input string stream
	istringstream inp_SS;
#if DEBUG_NO_LOG
	cout << "Stringstream created." << endl;
#endif

	auto search_match = MainList.find("test");

	//////////////////////////////////////////////////////////////////////////////////
	// Reading files
	while( !inp_stream.eof() )
	{
#if DEBUG_GETLINE
		cout << "Getting a line" << endl;
#endif

		getline(inp_stream, input_raw);

#if DEBUG_GETLINE
		cout << "Raw: " << input_raw << endl;
#endif

		inp_SS.clear();
		inp_SS.str(input_raw);

		inp_SS >> username_temp;
		inp_SS >> sub_temp;

		// Use the temp as the container for the followers
		temp.Set_username(username_temp);

////////////////////////////////////////////////////////////
#if DEBUG_LINE_INPUT
		cout << endl << "-------------------------------------" << endl;
		cout << "username_temp: " << setw(20) << left << username_temp 
			<< " sub_temp: " << setw(20) << left << sub_temp << endl;

		//cout << "List size: " << MainList.size() << endl;
#endif
////////////////////////////////////////////////////////////

		search_match = MainList.find(username_temp);
		if(search_match != MainList.end())
		{
#if DEBUG_NO_LOG
			cout << "Username: " << username_temp << " already existed." << endl;
			cout << "New follower: " << sub_temp << endl;
#endif
			MainList.at(username_temp)._Followers.push_back(sub_temp);
		}
		else
		{
#if DEBUG_NO_EXISTING_MATCH
			cout << "No match found." << endl;
			cout << "Creating a new entry in unordered map." << endl;
#endif
			// Create a new entry in the unordered map
			temp._Followers.clear();
			temp._Followers.push_back(sub_temp);
			MainList.insert( {username_temp, temp} );
		}
#if DEBUG_READING_MAP_PRINTOUT
		auto vector_test = MainList.at(username_temp)._Followers.end();
		cout << "debug: " << username_temp << endl;
		//cout << MainList.at(username_temp).Get_username() << " has follower: " << MainList.at(username_temp)._Followers.at(vector_test) << endl;
		cout << endl;
#endif
	}
	inp_stream.close();
}

#if !(NO_LIST_PRINTING)
void PrintingList( unordered_map<string, User > &MainList)
{
	cout<<endl<<endl;
	for(auto& it: MainList) {
		cout << "------------------------------" << endl;
		cout << "Outter Loop: " << endl;
		cout << it.first << endl;
		for(uint i = 0; i < it.second._Followers.size(); ++i)
		{
			cout << endl << "Inner Loop: " << endl;
			cout << it.second._Followers.at(i) << endl;
		}
		cout << endl;
	}
}
#endif


uint OutputList( unordered_map<string, User > &MainList, string outputFileName, string userName)
{
	//cout << userName.length() << endl;
	if(userName.length() > 15)
	{
		return 0;
	}

	ofstream oup_stream;
	oup_stream.open(outputFileName);
	//i(userName == "Poweraidus") return 0;
	if(!oup_stream.is_open())
	{
		cout << "File can't be opened." << endl;
		return 0;
	}

	uint count;
	uint count_userName_match = 0;
	auto search = MainList.find(userName);
	if(search == MainList.end())
	{
		count = 0;
	}
	else
	{
		count = MainList.at(userName)._Followers.size();	
	}
	if(search != MainList.end())
	{
		for(uint i = 0; i < MainList.at(userName)._Followers.size(); ++i)
		{
			cout << MainList.at(userName)._Followers.at(i).length() << endl;
			if(MainList.at(userName)._Followers.at(i).length() > 15)
			{
				return 0;
			}
		}
	}
	for(auto& it: MainList) {
		for(uint i = 0; i < it.second._Followers.size(); ++i)
		{
			//cout << it.second._Followers.at(i) << endl;
			if(it.second._Followers.at(i) == userName)
			{
				//cout << it.second._Followers.at(i) << endl;
				count_userName_match += 1;
			}
		}
	}
	cout << count_userName_match << endl;
	if(count_userName_match == 0) return 0;

	oup_stream << "Looking for new accounts for " << userName;
	oup_stream << " (" << count;
	oup_stream << ") to follow" << endl;

	oup_stream.close();

	return 1;
}
