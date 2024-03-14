#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"
#include <istream>


// FolderManager tests should be written here
TEST(folderManagerTests, testNoThrow) {
    EXPECT_NO_THROW( 
        FolderManager folderMenu;
        folderMenu.createFolder("myFolder");
        folderMenu.deleteFolder(1);
     );
}

TEST(folderManagerTests, testConstructor){
    EXPECT_NO_THROW(FolderManager myManager);
    
}

// IsEmpty() / createFolder() / deleteFolder() TESTS-------------------------------------------------
// empty Folders Vector
TEST(folderManagerTests, testIsEmptyTrue) {
    FolderManager folderMenu;
    EXPECT_EQ(folderMenu.isEmpty(), true);
}

// non-empty Folders vector
TEST(folderManagerTests, testIsEmptyFalse) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");

    EXPECT_EQ(folderMenu.isEmpty(), false);
}

// empty Folders vector after deletion
TEST(folderManagerTests, testIsEmptyAfterDeletion) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");

    // user is asked which number folder they want to delete, and passed in is number of the folder (index-1)
    folderMenu.deleteFolder(1);

    EXPECT_EQ(folderMenu.isEmpty(), true);
}

// getFolder() / createFolder() / deleteFolder() TESTS-------------------------------------------------------
// getFolder is only called when the user is asked for the number of the folder
// index passed in is authenicated before calling function
TEST(folderManagerTests, testGetFolder) {

    FolderManager folderMenu;
    folderMenu.createFolder("myFolder1");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");

    // b/c getFolder returns a FOLDER object, must get it's name to test if they are equal 
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "myFolder1");
    EXPECT_EQ(folderMenu.getFolder(1).getFolderName(), "myFolder2");
    EXPECT_EQ(folderMenu.getFolder(2).getFolderName(), "myFolder3");
}

TEST(folderManagerTests, testGetFolderSpecial) {

    FolderManager folderMenu;
    folderMenu.createFolder("A folder with spaces");
    folderMenu.createFolder("A   folder   with   many   spaces");

    // folder with numbers and symbols
    folderMenu.createFolder("---3244 { } 283---+");

    // A blank folder input is authenicated to not be accpeted by program, but should still work correctly
    folderMenu.createFolder("         ");

    // b/c getFolder returns a FOLDER object, must get it's name to test if they are equal 
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "A folder with spaces");
    EXPECT_EQ(folderMenu.getFolder(1).getFolderName(), "A   folder   with   many   spaces");
    EXPECT_EQ(folderMenu.getFolder(2).getFolderName(), "---3244 { } 283---+");
    EXPECT_EQ(folderMenu.getFolder(3).getFolderName(), "         ");
}

TEST(folderManagerTests, testGetFolderAfterDeletions) {

    FolderManager folderMenu;
    folderMenu.createFolder("myFolder1");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");
    folderMenu.createFolder("myFolder4");
    folderMenu.createFolder("myFolder5");

    //current folders list goes 1->2->3->4->5
    folderMenu.deleteFolder(3); //deletes myFolder3
    // should now be 1->2->4->5 (index 2 should be myFolder4)
    EXPECT_EQ(folderMenu.getFolder(2).getFolderName(), "myFolder4");

    //current folders list: 1->2->4->5
    folderMenu.deleteFolder(1); //deletes myFolder1
    // should now be 2->4->5 (index 0 should be myFolder2)
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "myFolder2");

    //current folders list: 2->4->5
    folderMenu.deleteFolder(2); //deletes myFolder4
    // should now be 2->5 (index 1 should be myFolder5)
    EXPECT_EQ(folderMenu.getFolder(1).getFolderName(), "myFolder5");

    //current folders list: 2->5
    folderMenu.deleteFolder(1); //deletes first folder
    // should just be myFolder5 (index 0 should be myFolder5)
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "myFolder5");
}

// folderExists() / createFolder() / deleteFolder() TESTS-------------------------------------------------
// NOTE: number passed into is index + 1 (first folder is #1)
// empty Folders Vector
TEST(folderManagerTests, testfolderExistsEmpty) {
    FolderManager folderMenu;
    EXPECT_EQ(folderMenu.folderExists(1), false);
}

// non-empty Folders vector with folders
TEST(folderManagerTests, testfolderExistsNotEmpty) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");

    // no 4th folder
    EXPECT_EQ(folderMenu.folderExists(4), false);
    EXPECT_EQ(folderMenu.folderExists(3), true);
    EXPECT_EQ(folderMenu.folderExists(2), true);
    EXPECT_EQ(folderMenu.folderExists(1), true);

    //invalid index 
    EXPECT_EQ(folderMenu.folderExists(-1), false);
}

// non-empty Folders vector after deletes
TEST(folderManagerTests, testfolderExistsAfterDeletes) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");
    folderMenu.createFolder("myFolder4");
    folderMenu.createFolder("myFolder5");

    //current folders list goes 1->2->3->4->5
    folderMenu.deleteFolder(3); //deletes myFolder3
    // should now be 1->2->4->5 
    // no fifth folder anymore
    EXPECT_EQ(folderMenu.folderExists(5), false);
    EXPECT_EQ(folderMenu.folderExists(4), true);

    //current folders list goes 1->2->4->5
    folderMenu.deleteFolder(4); //deletes myFolder5
    // should now be 1->2->4 
    // no fourth folder anymore
    EXPECT_EQ(folderMenu.folderExists(4), false);
    EXPECT_EQ(folderMenu.folderExists(3), true);

    //current folders list goes 1->2->4
    folderMenu.deleteFolder(2); //deletes myFolder2
    // should now be 1->4 
    // no thirs folder anymore
    EXPECT_EQ(folderMenu.folderExists(3), false);
    EXPECT_EQ(folderMenu.folderExists(2), true);

    //current folders list goes 1->4
    folderMenu.deleteFolder(1); //deletes myFolder1
    // should now be ->4
    // no second folder
    EXPECT_EQ(folderMenu.folderExists(2), false);
    EXPECT_EQ(folderMenu.folderExists(1), true);

    //only myFolder4
    folderMenu.deleteFolder(1); //deletes myFolder4
    // no folders
    EXPECT_EQ(folderMenu.folderExists(1), false);
}

// getListOfFoldersSize() / createFolder() / deleteFolder() TESTS-------------------------------------------------
// empty Folders Vector
TEST(folderManagerTests, testFolderSizeEmpty) {
    FolderManager folderMenu;
    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 0);
}

// non-empty Folders vector
TEST(folderManagerTests, testFolderSize3) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");

    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 3);
}

// test getListOfFoldersSize() deletions
TEST(folderManagerTests, testFolderSizeAfterDeletions) {
    FolderManager folderMenu;
    folderMenu.createFolder("myFolder");
    folderMenu.createFolder("myFolder2");
    folderMenu.createFolder("myFolder3");
    folderMenu.createFolder("myFolder4");
    folderMenu.createFolder("myFolder5");

    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 5);

    // user is asked which number folder they want to delete, and passed in is number of the folder (index-1)
    folderMenu.deleteFolder(3);
    folderMenu.deleteFolder(2);

    // 5-2 = 3 folders
    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 3);

    // user is asked which number folder they want to delete, and passed in is number of the folder (index-1)
    folderMenu.deleteFolder(2);
    folderMenu.deleteFolder(1);

    // 3-2 = 1 folder
    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 1);

    folderMenu.deleteFolder(1);

    // empty folder 
    EXPECT_EQ(folderMenu.getListOfFoldersSize(), 0);
}

// renameFolder() / createFolder() / deleteFolder() TESTS-------------------------------------------------
// NOTE: Whoever's function this is:
// | Only way to test this function is figuring out a way to test this is by simulating user input
// | Would reocmmend maybe reworking function so it can take istream as parameter and working it that way
// | Left you a sample test below:

TEST(folderManagerTests, testRenameFolder) {

    FolderManager folderMenu;
    folderMenu.createFolder("myFolder1");

    // b/c getFolder returns a FOLDER object, must get it's name to test if they are equal 
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "myFolder1");

    //renames first folder
    istringstream newName(" newFolderName");
    folderMenu.renameFolder(1, newName);
    // simulate user input enterting new name
    EXPECT_EQ(folderMenu.getFolder(0).getFolderName(), "newFolderName");

    FolderManager folderMenu2;
    folderMenu2.createFolder("");
    //renames first folder
    istringstream newName2(" hasFolderName");
    folderMenu2.renameFolder(1, newName2);
    // simulate user input enterting new name
    EXPECT_EQ(folderMenu2.getFolder(0).getFolderName(), "hasFolderName");

}


// Initialize GTest
int mainTest2(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
