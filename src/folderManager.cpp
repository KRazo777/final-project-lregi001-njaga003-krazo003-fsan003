#include "../include/folderManager.h"
#include "../include/folder.h"
#include <iostream>
#include <algorithm>


FolderManager::FolderManager(){};
FolderManager::~FolderManager(){};

void FolderManager::createFolder(const string& name){
    Folder newFolder(name);


    folders.push_back(newFolder);
};


bool FolderManager::folderIsEmpty(){
    return folders.empty();
};

Folder FolderManager::getFolder(int index) {
    return folders.at(index);
}

unsigned FolderManager::getFolderSize(){
    return folders.size();
};

bool FolderManager::folderExists(const int& fileNum){
    if (fileNum < 0 || fileNum > folders.size()) {
        return false;
    }


    return true;
};

void FolderManager::deleteFolder(const int& fileNum){
    // can't delete anything if it's empty
    //folders is a vector of <Folder> objects
    if (folders.empty()) {
        return;
    }


    if (folderExists(fileNum)){
        //get the name of the file we will delete
        string deletedFile = folders.at(fileNum-1).getFolderName();


        //delete the file
        folders.erase(folders.begin() + (fileNum - 1));


        //Confirm message about file being deleted
        cout << "File '" << deletedFile << "' deleted" << endl;
    } else {
        cout << "Invalid file number." << endl;
    }


    return;
};


void FolderManager::printFolders(){
    if (folders.empty()) {
        cout << "No folders have been created" << endl;
        return;
    }


    cout << "Folders: ";


    cout << endl;
    for (unsigned i = 0; i < folders.size(); i++){
        cout << i + 1 << ". ";
        cout << folders.at(i).getFolderName() << endl;
    };
};

void FolderManager::renameFolder(const int& fileNum){
    if(folders.empty()){
        return;
    }
    else{
        string userFolderName;
        cout << "Enter your new folder name: ";
        cin.ignore();
        getline(cin, userFolderName);

    
        //makes sure user enters a non-empty string that isn't just whitepsace and isn't the same title
        while( (userFolderName.find_first_not_of(' ') == std::string::npos) || (userFolderName == folders.at(fileNum-1).getFolderName()) ){
            if (userFolderName == folders.at(fileNum-1).getFolderName()){
                cout << "\nPlease enter a NEW folder title" << endl;
            } else if (userFolderName.find_first_not_of(' ') == std::string::npos){
                cout << "\nPlease enter a new folder title that is not empty" << endl;
            }
            
            cout << "Enter your new folder title for " << folders.at(fileNum-1).getFolderName() << ": ";
            getline(cin, userFolderName);
        }

        folders.at(fileNum-1).setFolderName(userFolderName);
    }

};

