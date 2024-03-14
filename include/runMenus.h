#include <iostream>
using namespace std;


void runNotesMenu(Folder& folderToOpen);
void runFolderMenu(const string& userName);
void save(const string& infoFileName, FolderManager& listOfFolders);
void load(ifstream& infoFileName, string &userName, FolderManager &listOfFolders);
