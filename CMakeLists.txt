cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(tests/googletest)

ADD_EXECUTABLE(runAllTests
  tests/testFolder.cpp
  tests/testFolManager.cpp
  tests/testNote.cpp
  tests/testRunMenus.cpp
  
  src/note.cpp 
  src/folder.cpp 
  src/folderManager.cpp
  src/runMenus.cpp
)

ADD_EXECUTABLE(runProgram
    src/main.cpp
    src/note.cpp 
    src/folder.cpp 
    src/folderManager.cpp
    src/runMenus.cpp
)

target_link_libraries(runAllTests gtest gtest_main)
