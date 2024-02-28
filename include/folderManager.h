#ifndef __FOLDERMANAGER_H__
#define __FOLDERMANAGER_H__

#include "../include/folder.h"
#include <vector>
#include <string>
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
        void renameFolder(const string& oldName, const string& newName);
        void printFolders();
        bool folderIsEmpty();
        unsigned getFolderSize();
        bool folderExists(const int& fileNum);
};

#endif 