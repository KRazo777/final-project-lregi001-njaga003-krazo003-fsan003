#ifndef __FOLDER_H__
#define __FOLDER_H__

#include "../include/note.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "note.h"
using namespace std;

class Folder {
    private:
        string folderName;
        vector<Note> notes; 
    public:
        Folder(const string& name);
        ~Folder();

        const string& getFolderName();
        void setFolderName(const string& name);
        void createNote(const string& name);
        void deleteNote(const string& name);
        void addContentToNote(const string& noteName);
        void printNote(const string& name);
        bool noteExists(const string& name);
};

#endif 