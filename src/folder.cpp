#include "../include/folder.h"

Folder::Folder(): folderName("Untitled Folder") {};
Folder::Folder(const string& name): folderName(name) {};

Folder::~Folder(){};

void Folder::createNote(const string& name, const string& body, const string& lastEditOfNote){
    Note newNote(name, body, lastEditOfNote);
    ListOfNotes.push_back(newNote);

};

void Folder::deleteNote(const string& name) // Deletes a note from the vector and the save file.
{
    // Delete note from the note vector

    unsigned deletePos = 0;

    for (unsigned i = 0; i < ListOfNotes.size(); i++) // Loop through notes vector to find the position of the note
    {
        if (ListOfNotes.at(i).getTitle() == name)
        {
            deletePos = i;
        }
    }

    ListOfNotes.erase(ListOfNotes.begin() + deletePos);

};


void Folder::AddNotetoFolder(Note& noteToAdd) {
    ListOfNotes.push_back(noteToAdd);
}

void Folder::printAllNoteTitles(){
    cout << this->getFolderName() << ":" << endl;

    if (this->empty()) {
        cout << "No notes have been created";
        return;
    }

    cout << endl;
    for (unsigned i = 0; i < ListOfNotes.size(); i++){
        cout << i + 1 << ". ";
        cout << ListOfNotes.at(i).getTitle() << endl;
    };
};

unsigned Folder::getFolderSize() {
    return ListOfNotes.size();
}

bool Folder::empty() {
    return ListOfNotes.size() == 0;
};

void Folder::setFolderName(const string& name){
    folderName = name;
}

Note& Folder::getNote(int index) {
    return ListOfNotes.at(index);
}

const string& Folder::getFolderName(){
    return folderName;
};

void Folder::updateNote(int index, Note& newNote) {
    ListOfNotes.at(index) = newNote;
}