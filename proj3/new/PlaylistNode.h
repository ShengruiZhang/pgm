#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <string>

typedef unsigned int uint;

class PlaylistNode
{
	private:
		std::string uniqueID;
		std::string songName;
		std::string artistName;
		uint songLength;
		
		PlaylistNode* nextNodePtr;
		
	public:
		
		PlaylistNode();
		PlaylistNode(std::string _uniqueID, std::string _songName, std::string _artistName, uint _songLength);
		
		std::string GetID() { return uniqueID; }
		std::string GetArtistName() { return artistName; }
		std::string GetSongName() { return songName; }
		uint GetSongLength() { return songLength; }
		
		PlaylistNode* GetNext() { return nextNodePtr; }
		
		void PrintPlaylistNode();

		uint _RemoveSong(PlaylistNode* head, std::string target);

		// The title of the playlist
		std::string _title;
};

#endif
