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
		void SetID(std::string id) { uniqueID = id; }

		std::string GetArtistName() { return artistName; }
		void SetName(std::string name) { artistName = name; }

		std::string GetSongName() { return songName; }
		void SetSong(std::string song) { songName = song; }

		uint GetSongLength() { return songLength; }
		void SetLength(uint length) { songLength = length; }

		PlaylistNode* GetNext() { return nextNodePtr; }
		void SetNext(PlaylistNode* nextptr) { nextNodePtr = nextptr; }

		void PrintPlaylistNode();

		void InsertAfter(PlaylistNode* song) { nextNodePtr = song; }
		uint _RemoveSong(PlaylistNode* head, std::string target);

		// The title of the playlist
		std::string _title;
};

#endif
