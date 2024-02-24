#ifndef __FOLDERMANAGER_H__
#define __FOLDERMANAGER_H__

#include <vector>
#include <string>
using namespace std;

class FolderManager {
    private:
        string userName;
        char userChoice;
        vector<string> folders;
    public:
        FolderManager(const string& username);
        ~FolderManager();

        void printFolderMenu(const string& username);
        void createFolder(const string& name);
        void deleteFolder(const string& name);
        void renameFolder(const string& oldName, const string& newName);
        void printFolders();
        bool folderExists(const string& name);
};

#endif 
