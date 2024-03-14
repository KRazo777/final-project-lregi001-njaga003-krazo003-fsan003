#ifndef __FOLDERMANAGER_H__
#define __FOLDERMANAGER_H__

#include "../include/folder.h"
#include <vector>
#include <string>
#include <istream>
#include "folder.h"
using namespace std;

class FolderManager {
    private:
        string userName;
        char userChoice;
        vector<Folder> folders;
    public:
        FolderManager();
        ~FolderManager();

        void createFolder(const string& name);
        void deleteFolder(const int& fileNum);
        void updateFolder(int index, Folder& newFolder);
        void renameFolder(const int& fileNum, istream& input);
        void printFolders();
        bool isEmpty();
        int getSizeofManager();
        Folder& getFolder(int index);
        unsigned getListOfFoldersSize();
        bool folderExists(const int& fileNum);
};

#endif 