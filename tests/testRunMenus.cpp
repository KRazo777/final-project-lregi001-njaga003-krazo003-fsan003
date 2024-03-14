#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"
#include <filesystem>
// Test runMenus Class 
// (we have to find a way for googletest to provide mock user input so that tests can run independently)

// Initialize GTest
int mainTest4(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//test For Load Function

TEST(runMenusTests, testLoad){
    string userName;
    vector <string> folderNames {"Instruments", "Cheese Types"};
    string noteNamesForInstruments = "Violin";
    string noteNamesForInstruments2 = "poop";
    vector <string> noteNamesForCheeseTypes {"Mozzarella", "Cheddar"};
    string bodyOfViolin = "string instrument, 4 strings; has a e, a, g, d string\n";
    string bodyOfMozzarella = "-mild, semisoft white itialian Cheese\n-used in pizza, pasta and similar dishes\n-good as a melting topping\n";
    string bodyOfCheddar = "-cheddar cheeeeese yum\n";
    string lastEdit1 = "03-04-2024 - 12:36:21";
    string lastEdit2 = "04-05-2024 - 12:36:22";
    string lastEdit3 = "05-06-2024 - 12:36:23";

    FolderManager listOfFolders;
    //void load(const string& infoFileName, string userName, FolderManager &listOfFolders)

    ifstream inputFile("tests/readFrom.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cout<< "Error opening the file!";
        FAIL();
    }

    load(inputFile, userName, listOfFolders);
    int i;
    string check;

    //check if username is read correctly
    EXPECT_EQ(userName, "joseph joseph");

    //check if all folders loaded correctly
    for(i=0; i<listOfFolders.getListOfFoldersSize(); i++){
        check = listOfFolders.getFolder(i).getFolderName();
        EXPECT_EQ(check, folderNames.at(i));
    }

    //check if notes
    EXPECT_EQ(listOfFolders.getFolder(0).getNote(0).getTitle(), noteNamesForInstruments);

    for(i=0; i<listOfFolders.getFolder(1).getFolderSize(); i++){
        check = listOfFolders.getFolder(1).getNote(i).getTitle();
        EXPECT_EQ(check, noteNamesForCheeseTypes.at(i));
    }

    EXPECT_NO_THROW(listOfFolders.getFolder(0).getNote(0).getLastEdit());

    for(i=0; i<listOfFolders.getFolder(1).getFolderSize(); i++){
        EXPECT_NO_THROW(listOfFolders.getFolder(1).getNote(i).getLastEdit());
    }

    //check bodies of notes
    check = listOfFolders.getFolder(0).getNote(0).getBody();
    EXPECT_EQ(check , bodyOfViolin);
    
    check = listOfFolders.getFolder(1).getNote(0).getBody();
    EXPECT_EQ(check, bodyOfMozzarella);

    check = listOfFolders.getFolder(1).getNote(1).getBody();
    EXPECT_EQ(check, bodyOfCheddar);

    //check setLastEdit of notes
    check = listOfFolders.getFolder(0).getNote(0).getLastEdit();
    EXPECT_EQ(check, lastEdit1);

    check = listOfFolders.getFolder(1).getNote(0).getLastEdit();
    EXPECT_EQ(check, lastEdit2);

    check = listOfFolders.getFolder(1).getNote(1).getLastEdit();
    EXPECT_EQ(check, lastEdit3);


    inputFile.close();

}



