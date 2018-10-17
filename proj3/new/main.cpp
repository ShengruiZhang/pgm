#include "PlaylistNode.h"

#include <iostream>

using namespace std;

// Function Protortype
void PrintMenu();


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	PlaylistNode* _head = new PlaylistNode;

	cout << "Enter playlist's title:" << endl;
	getline(cin, _head->_title);
	// Test
	cout << "PL Title: " << _head->_title << endl;

	return 0;
}

void PrintMenu(PlaylistNode head)
{
	string command;

	while(1)
	{
		cout << " PLAYLIST MENU" << endl;
	}
}
