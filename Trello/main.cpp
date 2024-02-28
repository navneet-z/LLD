#include <iostream>
#include "trello.cpp"

using namespace std;

int main() {
    // singleton instance
    Trello* trello = new Trello();

    int boardId = trello->addBoard("my-project");
    Board* myProjectBoard = trello->getBoardById(boardId);

    vector<User*> users;
    User* user = new User("navneet", "nav123iitr@gmail.com");
    users.push_back(user);
    myProjectBoard->addUsers(users);

    int listId = myProjectBoard->addList("lld-tasks");
    List* list = myProjectBoard->getListById(listId);

    int cardId = list->addCard("trello-desing", PriorityHigh);
    Card* card = list->getCardById(cardId);

    card->assignUser(user);
}
