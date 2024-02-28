Create an application like Trello which is a project management application, where you can manage your project by tracking smaller tasks. For reference : https://trello.com/

(think of it as similar to Jira Board)

Basic Features and workings :
The application contains multiple boards to signify different projects
Each board contains different lists to signify sub-project
Each list contain different cards signifying smaller tasks
Each card can be assigned to a user or may remain unassigned
Optional to take command line input OR write unit tests to test the functionality.
Definitions :
User: Each user should have a userId, name, email.
Board: Each board should have an id, name, url, members, lists
List: Each list should have an id, name and cards .
Card: Each card should have an id, name, assigned user, priority.
Attributes of card::
id, name, description, assigned user, priority.
Id to be unique , card to be identified by id .
Card to be uniquely identified on a board.
Requirements :
We should be able to create/delete boards, add/remove people from the members list (project members) and modify attributes. Deleting a board should delete all lists inside it.
We should be able to create/delete lists and modify attributes. Deleting a list should delete all cards inside it.
Cards inside a list should be sorted by priority
Deleting a member should assign cards associated with them to unassigned
We should be able to create/delete cards, assign/unassign a member to the card and modify attributes.
Users can create cards /edit boards.
We should also be able to move cards across lists in the same board
Ability to show a single board.
Cards should be unassigned by default
Ids should be auto-generated for board/list/card
Do not allow more than 5 issues to be assigned to an assignee in a board.
Updates to list, card, board should be thread safe.
Bonus:

Users should be able to do the Search. Search can be on user name, description,etc. Search can happen is 2 ways.
Search in the entire Board
Search in the entire List
We might add more such options in the future
