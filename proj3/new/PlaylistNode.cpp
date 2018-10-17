#include "PlaylistNode.h"

#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////
/////////////////////////////////////////////////
//void PrintPlaylistNode();
void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << this->GetID() << endl;
	cout << "Song Name: " << this->GetSongName() << endl;
	cout << "Artist Name: " << this->GetArtistName() << endl;
	cout << "Song Length (in seconds): " << this->GetSongLength() << endl;
}
// END OF FUNCTION///////////////////////////////////////////////
// //////////////////////////////////////////////////////////////
