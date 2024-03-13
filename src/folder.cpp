#include "../include/folder.h"

Folder::Folder(): folderName("Untitled Folder") {};
Folder::Folder(const string& name): folderName(name) {};

Folder::~Folder(){};

void Folder::createNote(const string& name){};
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


    // Delete note from the save file

    deleteNoteFromFile(name);
};


void Folder::AddNotetoFolder(Note& noteToAdd) {
    ListOfNotes.push_back(noteToAdd);
}

void Folder::addContentToNote(const string& noteName){};

void Folder::printAllNoteTitles(){
    if (this->empty()) {
        cout << "No notes have been created";
        return;
    }

    cout << this->getFolderName() << ":" << endl;
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

bool Folder::noteExists(const string& name){
    for (unsigned i = 0; i < ListOfNotes.size(); ++i) {
        if (name == ListOfNotes.at(i).getTitle()) {
            return true;
        }
    }
    return false;
};


void Folder::setFolderName(const string& name){
    folderName = name;
}

Note Folder::getNote(int index) {
    return ListOfNotes.at(index);
}

const string& Folder::getFolderName(){
    return folderName;
};

void Folder::deleteNoteFromFile(const string& name) // Helper function for the deleteNote method. Handles deleting the note from the save file.
{
    long startPos; // Start location of the note in the file
    long endPos; // End location of the note in the file
    string data; // Holds lines pulled from the saveFile (used for comparison and transfer purposes)
    
    fstream saveFile("ListOfAllNotes.txt"); // File containing currently saved notes
    ofstream transferFile; // File to be created and deleted for the purposes of deleting a note

    if (!saveFile.good()) // If the saveFile "ListOfAllNotes.txt" has not been found or created (no need to check files)
    {
        return;
    }

    saveFile.open("ListOfAllNotes.txt");
    transferFile.open("Transfer.txt");

    while (data != name) // Find start location of the note
    {

        if (saveFile.eof()) // If note title can't be found
        {
            saveFile.close();
            transferFile.close();
            remove("Transfer.txt");

            return;
        }

        if (data == "~BEGIN NOTE") // Update whenever coming across a "~BEGIN NOTE" and stop when the note has a matching title
        {
            startPos = saveFile.tellg() - long(12);
        }
        
        getline(saveFile, data);

    }

    while (true) // Find ending of the note (stops at the end of file in the case the last note is to be deleted)
    {

        if (data == "~END NOTE") // End of the note has been found
        {
            endPos = saveFile.tellg();
            break;
        }

        getline(saveFile, data);

    }

    if (saveFile.fail()) // End of file was reached when looking for the ending position (note to be deleted is the only/last note), transfer lines until the start of the deleted note
    {
        saveFile.clear(); // Clear failbit so file can be read from
        saveFile.seekg(0);

        while(saveFile.tellg() != startPos) // Transfer save file contents to a new file until the beginning of the deleted note is reached
        {
            getline(saveFile, data);
            if (saveFile.tellg() != startPos)
            {
                transferFile << data << endl;
            }
            else
            {
                transferFile << data;
            }
        }
    }
    else if (startPos == 0) // If its the first note in the file, just skip the first note and transfer lines until the end
    {
        saveFile.seekg(endPos);
        while (!saveFile.eof())
        {
            getline(saveFile, data);
            if (!saveFile.eof())
            {
                transferFile << data << endl;
            }
            else
            {
                transferFile << data;
            }
        }
    }
    else // If not the first or last note in file, transfer all lines before and after the deleted note
    {
        saveFile.seekg(0);
        while(saveFile.tellg() != startPos)
        {
            getline(saveFile, data);
            transferFile << data << endl;
        }

        saveFile.seekg(endPos);
        while(!saveFile.eof())
        {
            getline(saveFile, data);
            if (!saveFile.eof())
            {
                transferFile << data << endl;
            }
            else
            {
                transferFile << data;
            }
        }
    }

    saveFile.close();
    transferFile.close();

    remove("ListOfAllNotes.txt"); // Delete current save file containing the note to be deleted
    rename("Transfer.txt", "ListOfAllNotes.txt"); // Rename the newly created save file without the note to be deleted

};