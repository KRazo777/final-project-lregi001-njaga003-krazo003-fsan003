#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"

// Test runMenus Class 

// FOLDER MENU TESTS---------------------------------------------------------------

// This Test will authenticate correct ERROR MESSAGES are being outputted
// It will test user using invalid input within the folder menu itself, 
// and also will test invalid input when creating, deleting, editing, 
// outputting when there no folders, and opening folders when no folders
TEST(runMenusTest, testRunFolderMenuInavlidInputs) {
    // expected output for Invalid user input on each menu option of runFolder
    // EXPECTED OUTPUT MUST BE FORMATTED ON SINGLE LINE OR ELSE IT BREAKS
    std::string expectedOutput = 
    "Hello, userName!\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nInvalid choice. Please try again.\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEnter new folder name: No file name entered. Folder Creation Canceled.\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nNo folders have been created\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nNo folders have been created\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nNo folders have been created.\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nNo folders have been created\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nQuitting program...\n";

    // user input that enters input that is not a character on folder menu ("menuINVALIDINPUT"), invalid input when asked for name of folder (user pressing enter with nothing entered), 
    // trying to delete with no folders present, trying to edit with no folders present, outputting when there no folders, and trying to open folders when no folders present
    std::istringstream userInput("menuINVALIDINPUT\nn\n\nu\nd\ne\no\nq\n");

    // redirect cout to a stringstream to capture output
    std::stringstream capturedOutput;

    // save cout buffer
    std::streambuf* coutBuffer = std::cout.rdbuf(); 

    // make cout capture what is actually outputted to terminal
    std::cout.rdbuf(capturedOutput.rdbuf()); 
    
    // make sure that folderMenu itself doesn't cause any errors
    EXPECT_NO_THROW(runFolderMenu("userName", userInput));

    // reload the cout buffer and update it what what the terminal printed
    std::cout.rdbuf(coutBuffer);

    // test to see if that the output by folderMenu is exact same as what was expected to be outputted
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}


TEST(runMenusTest, testRunFolderMenuAllOptions) {
    // Create expected output of user creating two new folders, deleting FOLDER1 (1st folder), renaming the remaining folder (FOLDER2->NEWFOLDERNAME), user outputting folders, and then quitting program
    // EXPECTED OUTPUT MUST BE FORMATTED ON SINGLE LINE OR ELSE IT BREAKS
    std::string expectedOutput = 
    "Hello, userName!\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEnter new folder name: Folders: \n1. FOLDER1\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEnter new folder name: Folders: \n1. FOLDER1\n2. FOLDER2\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nFolders: \n1. FOLDER1\n2. FOLDER2\nEnter number for the folder you want to delete: File 'FOLDER1' deleted\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEditing folder title...\nFolders: \n1. FOLDER2\nEnter number for the folder name you want to edit: Enter your new folder name: \nFolder #1 succesfully updated.\nFolders: \n1. NEWFOLDERNAME\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nFolders: \n1. NEWFOLDERNAME\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nQuitting program...\n";

    // Create user input of user creating two new folders, deleting FOLDER1 (1st folder), renaming the remaining folder (FOLDER2->NEWFOLDERNAME), user outputting folders, and then quitting program
    std::istringstream userInput("n\nFOLDER1\nn\nFOLDER2\nd\n1\ne\n1\nNEWFOLDERNAME\nu\nq\n");

    // redirect cout to a stringstream to capture output
    std::stringstream capturedOutput;

    // save cout buffer
    std::streambuf* coutBuffer = std::cout.rdbuf(); 

    // make cout capture what is actually outputted to terminal
    std::cout.rdbuf(capturedOutput.rdbuf()); 
    
    // make sure that folderMenu itself doesn't cause any errors
    EXPECT_NO_THROW(runFolderMenu("userName", userInput));

    // reload the cout buffer and update it what what the terminal printed
    std::cout.rdbuf(coutBuffer);

    // test to see if that the output by folderMenu is exact same as what was expected to be outputted
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}

TEST(runMenusTest, testRunFolderMenu) {
    // expected output of user creating two new folders, deleting one of them, and then quit program
    // EXPECTED OUTPUT MUST BE FORMATTED ON SINGLE LINE OR ELSE IT BREAKS
    std::string expectedOutput = 
    "Hello, userName!\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEnter new folder name: Folders: \n1. FOLDER1\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nEnter new folder name: Folders: \n1. FOLDER1\n2. FOLDER2\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nFolders: \n1. FOLDER1\n2. FOLDER2\nEnter number for the folder you want to delete: File 'FOLDER1' deleted\n\n---------------------------------------------------------------------------------\nNew Folder (n)\nOutput Folders (u)\nDelete Folder (d)\nEdit Folder Title (e)\nOpen Folder (o)\nQuit (q)\nEnter your choice: \n---------------------------------------------------------------------------------\nQuitting program...\n";

    // Create user input of user creating two new folders, delete one of them, and then quit program
    std::istringstream userInput("n\nFOLDER1\nn\nFOLDER2\nd\n1\nq\n");

    // redirect cout to a stringstream to capture output
    std::stringstream capturedOutput;

    // save cout buffer
    std::streambuf* coutBuffer = std::cout.rdbuf(); 

    // make cout capture what is actually outputted to terminal
    std::cout.rdbuf(capturedOutput.rdbuf()); 
    
    // make sure that folderMenu itself doesn't cause any errors
    EXPECT_NO_THROW(runFolderMenu("userName", userInput));

    // reload the cout buffer and update it what what the terminal printed
    std::cout.rdbuf(coutBuffer);

    // test to see if that the output by folderMenu is exact same as what was expected to be outputted
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}



// Initialize GTest
int mainTest4(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
