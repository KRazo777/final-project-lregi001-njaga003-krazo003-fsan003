#include "../include/folder.h"

Folder::Folder(): folderName("Untitled Folder") {};
Folder::Folder(const string& name): folderName(name) {};
Folder::~Folder(){};

const string& Folder::getFolderName(){
    return folderName;
};

void Folder::AddNotetoFolder(Note& noteToAdd) {
    notes.push_back(noteToAdd);
}

void Folder::createNote(const string& name){}; //look at folder.h's note
void Folder::deleteNote(const string& name){};
void Folder::addContentToNote(const string& noteName){};
void Folder::printAllNotes(){
    if (this->empty()) {
        cout << "No notes have been created";
        return;
    }

    cout << "Notes: " << endl;
    cout << endl;
    for (unsigned i = 0; i < notes.size(); i++){
        cout << i + 1 << ". ";
        cout << notes.at(i).getTitle() << endl;
    };
};
bool Folder::empty() {
    return notes.size() == 0;
};
bool Folder::noteExists(const string& name){
    for (unsigned i = 0; i < notes.size(); ++i) {
        if (name == notes.at(i).getTitle()) {
            return true;
        }
    }
    return false;
};
