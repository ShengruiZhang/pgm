#include "PlaylistNode.h"

#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////
/////////////////////////////////////////////////
PlaylistNode::PlaylistNode()
{
	uniqueID	= "none";
	songName	= "none";
	artistName	= "none";
	songLength	= 0;
	nextNodePtr	= NULL;
}

// END OF CONSTRUCTOR////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
/////////////////////////////////////////////////
PlaylistNode::PlaylistNode(std::string _uniqueID, std::string _songName, std::string _artistName, uint _songLength)
{
	uniqueID	= _uniqueID;
	songName	= _songName;
	artistName	= _artistName;
	songLength	= _songLength;
}
// END OF CONSTRUCTOR////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
/////////////////////////////////////////////////
void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << this->GetID() << endl;
	cout << "Song Name: " << this->GetSongName() << endl;
	cout << "Artist Name: " << this->GetArtistName() << endl;
	cout << "Song Length (in seconds): " << this->GetSongLength() << endl;
}
// END OF FUNCTION///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
uint PlaylistNode::_RemoveSong(PlaylistNode* head, string target)
{
	// Locate the song
	PlaylistNode* temp = head->nextNodePtr;
	while (temp->nextNodePtr != NULL)
	{
		if (temp->uniqueID == target)
		{
			// Debug
			cout << "found target" << endl;
			// TODO





			return 1;
		}
		else if (temp->uniqueID != target)
		{
			// Debug
			cout << "not found" << endl;
			cout << "move to next node" << endl;

			// TODO
		}
	}

	return 0;
}
// END OF FUNCTION///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
