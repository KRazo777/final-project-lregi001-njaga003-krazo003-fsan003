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
        Folder(string name);
        ~Folder();
        void createNote(const string& name);
        void deleteNote(const string& name);
        void addContentToNote(const string& noteName);
        void printNote(const string& name);
        bool noteExists(const string& name);
};

#endif 
