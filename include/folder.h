#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <vector>
#include <string>
#include "note.h"
using namespace std;

class Folder {
    private:
        string folderName;
        vector<Note> notes; 
    public:
        Folder();
        Folder(const string& name);
        ~Folder();

        const string& getFolderName();
        void AddNotetoFolder(Note& noteToAdd);
        void createNote(const string& name); //might be redundant /unneeded
        void deleteNote(const string& name);
        void addContentToNote(const string& noteName);
        void printAllNotes();
        bool empty();
        bool noteExists(const string& name);
};

#endif 
