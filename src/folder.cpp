#include "../include/folder.h"

Folder::Folder(): folderName("Untitled Folder") {};
Folder::Folder(const string& name): folderName(name) {};
Folder::~Folder(){};


void Folder::AddNotetoFolder(Note& noteToAdd) {
    notes.push_back(noteToAdd);
}

void Folder::createNote(const string& name){}; //look at folder.h's note
void Folder::deleteNote(const string& name){};
void Folder::addContentToNote(const string& noteName){};

void Folder::printNote(const string& name) //PROBABLY MOVE FUNCTION TO NOTE CLASS
{
    unsigned notePos = 0;

    for (notePos = 0; notePos < notes.size(); notePos++) // Locate note to be displayed in the note vector
    {
        if (notes.at(notePos).getTitle() == name) // Note with matching title found
        {
            break;
        }
    }

    // Now print out note to terminal for viewing

    cout << setw(99) << setfill('-') << '-' << endl;
    cout << setw(0) << "Title: " << notes.at(notePos).getTitle() << "     Last Edit: " << notes.at(notePos).getLastEdit() << endl;
    cout << setw(50) << setfill('-') << "BODY";
    cout << setw(49) << setfill('-') << "-" << endl;
    
    cout << notes.at(notePos).getBody() << endl;
};

void Folder::printAllNoteTitles(){
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


void Folder::setFolderName(const string& name){
    folderName = name;

}
const string& Folder::getFolderName(){
    return folderName;
};

