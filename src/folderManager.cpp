#include "../include/folderManager.h"
#include "../include/folder.h"
#include <iostream>
#include <algorithm>


FolderManager::FolderManager(){
   
};
FolderManager::~FolderManager(){};






void FolderManager::createFolder(const string& name){
    Folder newFolder(name);


    folders.push_back(newFolder);
};


bool FolderManager::folderIsEmpty(){
    return folders.empty();
};


bool FolderManager::folderExists(const int& fileNum){
    if (fileNum < 0 || fileNum > folders.size()) {
        return false;
    }


    return true;
};


void FolderManager::deleteFolder(const int& fileNum){
    // can't delete anything if it's empty
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




void FolderManager::renameFolder(const string& oldName, const string& newName){
    int i;
    bool found = false;


    for(i=0; i<folders.size(); i++){
        if(folders.at(i).getFolderName() == "oldName"){
            folder.at(i).setFolderName(newName);
            found = true;
        }
    }
    if(found == false){
        cout<<"Not able to find file";
    }
       
};
