#include "PlaylistNode.h"

#include <iostream>

using namespace std;

// Function Protortype
void PrintMenu(PlaylistNode* head);
void SongAdd(PlaylistNode* head, PlaylistNode* newsong);
void SongSwap(PlaylistNode* head, uint _old, uint _new);
uint PrintPlaylist(PlaylistNode* head);
uint PlaylistRemove(PlaylistNode* head, string songID);


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	// Initilize the list head
	PlaylistNode* _head = new PlaylistNode("_PlaylistHead", "none", "none", 0);

	_head->SetNext(nullptr);

	cout << "Enter playlist's title:" << endl << endl;
	getline(cin, _head->_title);

	// Test
	//cout << "PL Title: " << _head->_title << endl;

	PrintMenu(_head);

	return 0;
}

void PrintMenu(PlaylistNode* head)
{
	string command;
	uint flag = 1;

	while(1)
	{
		if (flag == 1)
		{
			cout << head->_title;
			cout << " PLAYLIST MENU" << endl;
			cout << "a - Add song" << endl;
			cout << "d - Remove song" << endl;
			cout << "c - Change position of song" << endl;
			cout << "s - Output songs by specific artist" << endl;
			cout << "t - Output total time of playlist (in seconds)" << endl;
			cout << "o - Output full playlist" << endl;
			cout << "q - Quit" << endl;
		}

		cout << endl << "Choose an option:" << endl;
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

			cout << "Enter artist's name:" << endl;
			getline(cin, _artist);

			cout << "Enter song's length (in seconds):" << endl;
			cin >> temp2;

			//cout << endl;

			// _newItem is a pointer
			PlaylistNode* _newSong = new PlaylistNode(_id, _name, _artist, stoi(temp2));

			// To pass the object just created, dereference the pointer is needed
			// Link the new song to the existing list
			SongAdd(head, _newSong);

			cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("d") == 0)
		{
			cout << "REMOVE SONG" << endl;
			cin.ignore();

			cout << "Enter song's unique ID:" << endl;
			getline(cin, command);

			PlaylistRemove(head, command);

			cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("c") == 0)
		{
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;

			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.ignore();
			//getline(cin, command);
			cin >> command;


			string temp;
			cout << "Enter new position for song:" << endl;
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.ignore();
			//getline(cin, temp);
			cin >> temp;

			//cout << command << " " << temp;
			SongSwap(head, stoi(command), stoi(temp));

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
			cout << head->_title << " - OUTPUT FULL PLAYLIST" << endl;

			PrintPlaylist(head);

			//cout << endl;
		}


		////////////////////////////////////////////////
		else if (command.compare("s") == 0)
		{
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
			cout << "Enter artist's name:" << endl;
			cin.ignore();
			getline(cin, command);
			cout << endl;
			uint counter = 0;
			PlaylistNode* __temp = head;
			while(__temp != nullptr)
			{
				if(__temp->GetArtistName() == command)
				{
					cout << counter << "." << endl;
					cout << "Unique ID: " << __temp->GetID() << endl;
					cout << "Song Name: " << __temp->GetSongName() << endl;
					cout << "Artist Name: " << command << endl;
					cout << "Song Length (in seconds): " << __temp->GetSongLength() << endl;
					cout << endl;
					++counter;
					__temp = __temp->GetNext();
				}
				else {
					++counter;
					__temp = __temp->GetNext();
				}
			}

			//cout << endl;
		}




		////////////////////////////////////////////////
		else if (command.compare("t") == 0)
		{
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			PlaylistNode* __temp = head;
			uint total_time = 0;
			while(__temp != nullptr)
			{
				total_time += __temp->GetSongLength();
				__temp = __temp->GetNext();
			}
			cout << "Total time: " << total_time << " seconds" << endl;
			cout << endl;
		}





		////////////////////////////////////////////////
		else {
			flag = 0;
		}
	}
}


void SongAdd(PlaylistNode* head, PlaylistNode* newsong)
{
	PlaylistNode* temp = head;

	if(head->GetNext() == nullptr)
	{
		head->SetNext(newsong);

		newsong->SetNext(nullptr);

		//debug
		//cout << "after head" << endl;

	}
	else if(head->GetNext() != nullptr)
	{
		temp = head->GetNext();

		while(1)
		{
			if(temp->GetNext() == nullptr)
			{
				//debug
				//cout << "Linking to the list" << endl;
				temp->SetNext(newsong);
				newsong->SetNext(nullptr);
				//debug
				//cout << "Link to the list" << endl;
				break;
			}
			else {
				temp = temp->GetNext();
				//debug
				//cout << "Move to next" << endl;
			}
		}
	}
}


void SongSwap(PlaylistNode* head, uint _old, uint _new)
{
	PlaylistNode* temp = head;
	PlaylistNode* temp_old = nullptr;
	PlaylistNode* last = nullptr;
	PlaylistNode* last_2 = nullptr;
	uint counter = 0;

	if(head->GetNext() == nullptr) { cout<<"Empty List. Exiting"<<endl; return; }

	// debug
	//cout << endl;

	//cout << _old << " " << _new << endl;

	while(temp != nullptr)
	{
		// debug
		//cout << temp->GetID() << endl;

		if(counter != _old)
		{
			++counter;
			last = temp;
			temp = temp->GetNext();
			// debug
			//cout << "after increment: " << counter << endl;
		}
		else if(counter == _old)
		{
			temp_old = temp;
			break;
		}
	}

	//debug
//cout << temp->GetID() << endl;


	temp = head;
	counter = 0;
	while(temp != nullptr)
	{
		if(counter != _new)
		{
			++counter;
			last_2 = temp;
			temp = temp->GetNext();
		}
		else if(counter == _new)
		{
			break;
		}
	}

	//debug
	///cout << temp->GetID() << endl;
		if ((temp_old != last_2) && (_new < _old))
		{
			last->SetNext(temp_old->GetNext());
			temp_old->SetNext(temp);
			last_2->InsertAfter(temp_old);
		}
		else if(temp_old != last_2)
		{
			last->SetNext(temp_old->GetNext());
			temp_old->SetNext(temp->GetNext());
			temp->InsertAfter(temp_old);
		}
		else if(temp_old == last_2)
		{
			last->SetNext(temp_old->GetNext());
			last_2->SetNext(temp->GetNext());
			temp->InsertAfter(last_2);
		}

/*
	PlaylistNode* _temp = new PlaylistNode(temp->GetID(),
						temp->GetSongName(), temp->GetArtistName(), temp->GetSongLength());
	temp->SetID(temp_old->GetID());
	temp->SetName(temp_old->GetArtistName());
	temp->SetSong(temp_old->GetSongName());
	temp->SetLength(temp_old->GetSongLength());

	temp_old->SetID(_temp->GetID());
	temp_old->SetName(_temp->GetArtistName());
	temp_old->SetSong(_temp->GetSongName());
	temp_old->SetLength(_temp->GetSongLength());
	*/

/*
	last->SetNext(temp);
	temp_old->SetNext(temp->GetNext());
	temp->SetNext(last_2);
	last_2->SetNext(temp_old);
	*/
	//debug
	//cout << "after swap: " << temp->GetID() << endl;
	//debug
	//cout << temp_old->GetID() << endl;

	cout << "\"" << temp_old->GetSongName() << "\" moved to position " << _new << endl;

}

uint PrintPlaylist(PlaylistNode* head)
{
	if(head->GetNext() == nullptr)
	{ cout << "Playlist is empty" << endl << endl; return 0; }

	uint i = 1;

	// MOVE TO NEXT ONE, HEAD HAS NOTHING
	PlaylistNode* temp = head->GetNext();

	do {
		cout << i << "." << endl;
		cout << "Unique ID: " << temp->GetID() << endl;
		cout << "Song Name: " << temp->GetSongName() << endl;
		cout << "Artist Name: " << temp->GetArtistName() << endl;
		cout << "Song Length (in seconds): " << temp->GetSongLength() << endl;
		cout << endl;

		temp = temp->GetNext();
		++i;

	} while(temp != nullptr);

	return 1;
}


uint PlaylistRemove(PlaylistNode* head, string songID)
{
	PlaylistNode* temp = head;
	PlaylistNode* last = head;

	if(temp->GetNext() == nullptr) { return 0; }

	temp = head->GetNext();

	while(temp != nullptr)
	{
		//cout<< temp->GetID();
		if(temp->GetID() == songID)
		{
			last->SetNext(temp->GetNext());

			cout << "\"" << temp->GetSongName() << "\" removed." << endl;

			// Attempt to delete the object
			delete temp;
			return 1;
		}
		else if(temp->GetID() != songID)
		{
			last = temp;
			temp = temp->GetNext();
		}
	}

	return 0;
}
