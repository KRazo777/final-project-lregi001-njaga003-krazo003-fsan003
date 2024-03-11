#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"

// Test runMenus Class 
// (we have to find a way for googletest to provide mock user input so that tests can run independently)

// Initialize GTest
int mainTest4(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
