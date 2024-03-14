#ifndef __FOLDER_H__
#define __FOLDER_H__

#include "../include/note.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "note.h"
using namespace std;

class Folder {
    private:
        string folderName;
        vector<Note> ListOfNotes; 
    public:
        Folder();
        Folder(const string& name);
        ~Folder();

        const string& getFolderName();
        void AddNotetoFolder(Note& noteToAdd);
        void createNote(const string& name, const string& body, const string& lastEditOfNote); //might be redundant /unneeded
        void setFolderName(const string& name);

        Note getNote(int index);
      
        void deleteNote(const string& name);
        void addContentToNote(int noteNum, const string& addedContent);
        void printAllNoteTitles();
        unsigned getFolderSize();
        bool empty();
        void updateNote(int index, Note& newNote);
};

#endif 