#ifndef __FOLDERMANAGER_H__
#define __FOLDERMANAGER_H__

#include "../include/folder.h"
#include <vector>
#include <string>
using namespace std;

class FolderManager {
    private:
        string userName;
        char userChoice;
        vector<Folder> folders;
    public:
        FolderManager();
        ~FolderManager();

        void printFolderMenu(const string& username);
        void createFolder(const string& name);
        void deleteFolder(const int& name);
        void renameFolder(const string& oldName, const string& newName);
        void printFolders();
        bool folderExists(const int& name);
        bool folderIsEmpty();
        
};

#endif 
