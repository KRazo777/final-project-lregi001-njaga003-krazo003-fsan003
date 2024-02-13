 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Notetastic
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Liam Regina](https://github.com/liamregina), [Nidhi Jagadeesh](https://github.com/n1dh1001), [Kevin Razo](https://github.com/KRazo777), [Francis Miguel San Juan](https://github.com/Mooogy)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description

Reason For Making This: As students we have all faced difficulties in keeping track of lists, due dates, and writing down ideas. This is why we decided to resolve this issue by creating a note taking app. This application will allow users to save notes into a file they will be able to access later, to view as well as edit.

Tools/Technologies: It will utilize C++ and if time permits, we will possibly implement a GUI. We would use certain libraries, like time and filestream, but that will be updated as we go. 

Input/Output: The input/output of our project is taking in what the user wants to include in their notes, and saving it; while output is accessing the file that they have saved to see what input they had given as well as the last time it had been edited. It will also request them to title the file before they save it which will be how they are going to be able to access files later on.

Features: Some of our features include adding, editing, and deleting notes. Another would be the ability to create folders in the notes app and move notes into those folders. There will be a function to quit the app as well as possibly implement a trash system in which deleted notes may be accessed or permanently deleted.

>
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

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
 > 
![ClassDiagram drawio](https://github.com/cs100/final-project-lregi001-njaga003-krazo003-fsan003/assets/156025210/c93730f9-a8af-48f3-95a8-3ca465b4af10)
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
