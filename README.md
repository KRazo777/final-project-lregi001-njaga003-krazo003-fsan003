# Notetastic
[![CI_for_NotesApplication](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/actions/workflows/master.yml/badge.svg)](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/actions/workflows/master.yml)
 
 > Authors: [Liam Regina](https://github.com/liamregina), [Nidhi Jagadeesh](https://github.com/n1dh1001), [Kevin Razo](https://github.com/KRazo777), [Francis Miguel San Juan](https://github.com/Mooogy)

## Project Description

Reason For Making This: As students we have all faced difficulties in keeping track of lists, due dates, and writing down ideas. This is why we decided to resolve this issue by creating a note taking app. This application will allow users to save notes into a file they will be able to access later, to view as well as edit.

Tools/Technologies: It will utilize C++ and if time permits, we will possibly implement a GUI. We would use certain libraries, like time and filestream, but that will be updated as we go. 

Input/Output: The input/output of our project is taking in what the user wants to include in their notes, and saving it; while output is accessing the file that they have saved to see what input they had given as well as the last time it had been edited. It will also request them to title the file before they save it which will be how they are going to be able to access files later on.

Features: Some of our features include adding, editing, and deleting notes. Another would be the ability to create folders in the notes app and move notes into those folders. There will be a function to quit the app as well as possibly implement a trash system in which deleted notes may be accessed or permanently deleted.

## User Interface Specification

### Navigation Diagram
<img width="464" alt="Screenshot 2024-02-12 011423" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/9f66d436-6c70-4f32-bacd-e06a5f9a61b6">


### Screen Layouts
<img width="450" alt="Screenshot 2024-02-12 011934" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/5a77acb0-50f2-4c70-a2c7-4b5ab34c6efb">
<p> When the user initially runs the program, they will prompted to enter their username. </p>
<img width="450" alt="Screenshot 2024-02-12 011955" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/b9d5eb9e-f5d5-40a6-afbd-cf77729309f7">
<p> Once the user enters their username, this will be prompted with a "folders menu" where they have control over creating, deleting, editing folder titles, opening folders to access notes, as well as the choice to quit the program. </p>
<img width="450" alt="Screenshot 2024-02-12 012006" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/fa32adac-3dc3-4a38-a195-8e7b36ddcc84">
<p> If the user enters "n" to create a folder, they will be shown their currently active folders and will be asked to enter a name for their new folder. </p>
<img width="450" alt="Screenshot 2024-02-12 012014" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/c2eb8e4f-e411-4e2b-b760-39426f4f4f3c">
<p> If the user chooses "d" to delete a folder, they will be shown their currently active folders and will be asked to enter the name for the folder they want to delete. The folder name must be a currently active folder in order to be deleted. </p>
<img width="450" alt="Screenshot 2024-02-12 012025" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/3de237b9-2f52-4344-a48c-10dc7ddb1514">
<p> If the user chooses to edit a folder title, they will be shown their currently active folders and will be asked enter the name of the folder they want to edit. If they enter the name of a currently active folder, they will then be prompted to enter the updated title for the folder. </p>
<img width="450" alt="Screenshot 2024-02-12 012033" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/acc124ce-8dac-488d-98a5-5e3874670247">
<p> If the user chooses "o" in the menu to open a folder and enter the name of an active folder, they will be prompted to the "notes menu". Here, they will be shown the name of the folder they are currently in, the currently active notes in the folder, and a set of options for creating, deleting, adding to, and opening notes. They also have the option of returning to the folders menu or quitting the program. </p>
<img width="450" alt="Screenshot 2024-02-12 012045" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/93435d06-3b0e-4115-ba31-d2fdfd45c873">
<p> If the user chooses "n" to create a new note, they will be prompted to enter the title for the note and then type anything they wish into their note. </p>
<img width="450" alt="Screenshot 2024-02-12 012055" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/708f39f3-eea7-4da1-9b4e-dc2165da17af">
<p> If the user chooses "o" to open a new note and they enter the name of a currently active note, they will be shown the note's title, body, and time of last edit. They will have the option to exit the note and return to the notes menu or quit the program. </p>
<img width="450" alt="Screenshot 2024-02-12 012106" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/d213ac69-25f4-4828-aa2e-fd3abdc10686">
<p> If the user chooses "d" to delete a note, they will be shown their active notes and will be prompted to enter the number for the active note they want to delete or enter "c" to cancel the operation and return to the notes menu. </p>
<img width="450" alt="Screenshot 2024-02-12 012116" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/52036178-0fc5-46ee-9e73-6de490ade2e7">
<p> If the user chooses "a" to add to an existing note, they will be shown their active notes and prompted to enter the number for the note they want to add to or "c" to cancel the operation. If they enter the number of an active note they will be brought to the next screen ↓ </p>
<img width="450" alt="Screenshot 2024-02-12 012130" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/b7e78eaf-58e3-442a-86a2-c1ebd906d541">
<p> After, they enter the number for an active note to add to, they will be shown the current title and body of the note, and will be able to add to the body of the note. </p>
<img width="450" alt="Screenshot 2024-02-12 012141" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/7d93985e-7623-4acb-baef-f2a4c8150c68">
<p> If the user chooses "q" to quit the program in either the folders or notes menu, they will be shown a message saying the program was terminated and then the program will exit. </p>


## Class Diagram
![ClassDiagram (2)](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/103863739/77fe80f7-de93-4ded-8171-fe07c8f786c6)




  Our main class acts as an start of the program, where users intially enter their username and are then taken to the folder menu. It is here where they will be able to manage and create their collection of folders. The runMenus class is responsible for running the menus of our program, which is the primary method the user utilizes to interact with the program. These menus display a GUI for the user in order for them to swiftly decide how they may want to manage their folders (using the Folder Menu) or notes (using the Notes Menu). The folder menu allows the user to control the amount of folders they have, change names of folders, as well as being able to open these folders and create notes in each individual folder. Within the notes menu, the user is given the ability to manage their notes within each respective folder, add to notes, or view their created notes.
 <br> The Notes class is an object class that manages what is inside of a singular note. This includes writing to a note as well as making sure the time of last edit is updated. It is where all actions that can be taken on note as well as helper functions are implemented. 
 <br>The Folders class contains notes within it and has an aggregation relationship with the class. This is where notes are managed; adding and deleting notes as well as seeing all the notes in the folder are allowed here.
 <br> The Folder Manager class contains folders within it and is what is used to manage all the folders that are contained within.
<br> Solid principles that we applied included Single Responsibility which is shown throughout addition to the Folder Manager Class. We noticed that our Folder class was assigned with many tasks that didn’t align with only one singular goal, so we separated it into a Folder Class and a separate class that manages our folders called FolderManager. This helps us write better code as because each class follows the single responsibility principle, it makes our code easier to implement as well as prevent any bugs or unexpected changes in the future to be limited rather than spread throughout. 

 > ## Final deliverable
 
 ## Screenshots
 ### After Logging In...
 ![image](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/006dd721-45c4-42f5-a337-dd98e54cb39c)
 ### Making a New Folder
![image2](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/95277325-3af1-43d9-8dd5-263163932396)
![image3](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/2e76682b-e62e-4dfc-a20b-99dc934a7889)
### Making a New Note
![image4](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/f9435e9b-de98-4ed9-8d9e-0574c11e86fd)
![image5](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/0850c6b4-000f-4d37-bae7-c8ade6fa44ec)
### Adding to a New Note
![image6](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/08aa6ddf-8dd0-4db5-9c9e-d1e0d46c878a)
![image7](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/1e7159c0-ff2e-4936-838a-5d5733ee4cea)
### Deleting a Note
![image8](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/126de1a6-a029-457f-966e-01973f205f38)
![image9](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/213fd86e-3745-4647-a614-c0796120a364)
### Renaming a Folder
![image10](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/2209505e-199c-4da4-b8ed-5f2877b44019)
![image11](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/d9f7e656-0348-432c-bea8-d9b21af85430)
### Deleting a Folder
![image12](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/0293dc3e-5026-4d5b-b1d5-3f94375ab544)
![image13](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/f0e6f928-df8d-4d17-94ba-eff110030354)
### Quitting The Program
![image14](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/7b1f7b09-940a-4bba-8f16-c125394a446c)
![image15](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/102709181/cba6dde0-5412-4a6a-a543-72b875bde739)

 ## Installation/Usage
 To begin using Notetastic, we'll be cloning the repository into our own IDE, like VSCode. With the IDE of your choice, <br>
 in the terminal type: `git clone --recursive https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003.git`
 <br> <br>
 Next, we'll be using cmake and make to construct the Notetastic executable. In the terminal, type `cmake .` and use `make` to build the executable.
 <br> <br>
 Now that our executable has been built! <br>
 We can run Notetastic by typing `./bin/runProgram` in the terminal and begin writing all the notes we'll ever need!
 ## Testing
Notetastic’s functionality was validated through the use of continuous integration, in which we triggered a build every time we would open a pull request or merge a pull request into our default branch. This build would run all of our tests, which would verify that a pull request was satisfactory for merging and that we could catch any errors that may have appeared from adding new code or functions. This build used a variety of tests for every class that we implemented, ensuring that we accounted for as many types of user input as we could. If a pull request did not pass the build, we would debug on the branch of the pull request and make sure we made the necessary commits so that the build would pass, allowing us to review and eventually approve the pull request. This process made our debugging process a lot more efficient and allowed us to rapidly deploy crucial implementations or fixes.
### Memcheck-Clean
<img width="888" alt="Screenshot 2024-03-14 at 2 49 08 AM" src="https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/103863739/4e3f8fdb-b730-476e-9b32-577385d669c7">

 
