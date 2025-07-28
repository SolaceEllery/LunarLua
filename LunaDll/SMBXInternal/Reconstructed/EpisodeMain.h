// EpisodeLoader.h
#ifndef EpisodeLoader_hhh
#define EpisodeLoader_hhh

#include <string>
#include <vector>

#include "../Menu.h"
#include "../../libs/PGE_File_Formats/file_formats.h"

#include "../Functions.h"
#include "../Types.h"
#include "../Variables.h"

extern int EpisodeCount;
extern int EpisodeIdx;
extern bool SaveFileExists;

struct EpisodeList
{
    std::wstring episodeName;
    std::wstring episodePath;
    std::wstring episodeWorldFile;
    int blockedCharacters[4];

    // Constructor
    EpisodeList()
    {
        Reset();
    }

    // Reset function
    void Reset()
    {
        episodeName = L"";
        episodePath = L"";
        episodeWorldFile = L"";
    }
};

extern EpisodeList g_episodeList[32767];

class EpisodeMain {
    public:
        EpisodeMain();
        ~EpisodeMain();

        void LaunchEpisode(std::wstring wldPathWS, int saveSlot, int playerCount, Characters firstCharacter, Characters secondCharacter);
        int FindSaves(std::string worldPathS, int saveSlot);
        int WriteLegacyEpisodeEntry(VB6StrPtr worldNameVB6, VB6StrPtr worldPathVB6, VB6StrPtr worldFileVB6, WorldData wldData, bool isNewEpisode);

        void PopulateEpisodeList();
        
        int GetEpisodeCount();
        int GetEpisodeIdx();

        bool CheckCollision(SMBX13::Types::Location_t momentumA, SMBX13::Types::Location_t momentumB);
};

extern EpisodeMain gEpisodeMain;

#endif
