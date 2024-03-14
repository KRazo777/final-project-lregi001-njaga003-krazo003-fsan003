#include <iostream>
using namespace std;


void runNotesMenu(Folder& folderToOpen);
void runFolderMenu(const string& userName, istream& cin);
void save(string& userName, string& infoFileName, FolderManager& listOfFolder);
void load(ifstream& infoFileName, string &userName, FolderManager &listOfFolders);
