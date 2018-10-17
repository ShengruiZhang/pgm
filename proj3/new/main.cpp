#include "PlaylistNode.h"

#include <iostream>

using namespace std;

// Function Protortype
void PrintMenu();


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	// Initilize the list head
	PlaylistNode* _head = new PlaylistNode("_PlaylistHead", "none", "none", 0);

	cout << "Enter playlist's title:" << endl;
	getline(cin, _head->_title);
	// Test
	cout << "PL Title: " << _head->_title << endl;

	return 0;
}

void PrintMenu(PlaylistNode* head)
{
	string command;
	uint flag = 0;

	while(1)
	{
		if (flag == 1)
		{
			cout << head->_title;
			cout << "PLAYLIST MENU" << endl;
			cout << "a - Add song" << endl;
			cout << "d - Remove song" << endl;
			cout << "c - Change position of song" << endl;
			cout << "s - Output songs by specific artist" << endl;
			cout << "t - Output total time of playlist (in seconds)" << endl;
			cout << "o - Output full playlist" << endl;
			cout << "q - Quit" << endl;
		}

		cout << endl << "Choose an option:";
		cin >> command;

		if(command.compare("q") == 0)
		{
			break;
		}


		////////////////////////////////////////////////
		else if (command.compare("a") == 0)
		{
			string _name;
			string _artist;
			string _id;
			string temp2;

			cout << "ADD SONG" << endl;
			cin.ignore();

			cout << "Enter song's unique ID:" << endl;
			getline(cin, _id);

			cout << "Enter song's name:" << endl;
			getline(cin, _name);

			cout << "Enter artist's'name:" << endl;
			getline(cin, _artist);

			cout << "Enter song's length (in seconds):" << endl;
			cin >> temp2;

			cout << endl;

			// _newItem is a pointer
			PlaylistNode* _newSong = new PlaylistNode(_id, _name, _artist, stoi(temp2));

			// To pass the object just created, dereference the pointer is needed
			// Link the new song to the existing list
			// TODO
		}


		////////////////////////////////////////////////
		else if (command.compare("d") == 0)
		{
			cout << "REMOVE SONG" << endl;
			cin.ignore();
			
			cout << "Enter song's unique ID:" << endl;
			getline(cin, command);

			cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("c") == 0)
		{
			// TODO
			cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("i") == 0)
		{
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			// TODO
			cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("o") == 0)
		{
			cout << endl << "OUTPUT SHOPPING CART" << endl;
			// TODO
		}


		////////////////////////////////////////////////
		else {
			flag = 0;
		}
	}
}
