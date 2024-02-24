#ifndef __FOLDERMANAGER_H__
#define __FOLDERMANAGER_H__

#include <vector>
#include <string>
#include "folder.h"
using namespace std;

class FolderManager {
    private:
        vector<Folder> folders;
    public:
        FolderManager();
        ~FolderManager();

        void createFolder(const string& name);
        void deleteFolder(const int& fileNum);
        void renameFolder(const string& oldName, const string& newName);
        void printFolders();
        bool folderIsEmpty();
        bool folderExists(const int& fileNum);
};

#endif 
