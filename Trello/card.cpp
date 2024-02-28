#include<iostream>
#include "user.cpp"
#include "priority.cpp"

using namespace std;

class Card {
    private:
        int id;
        string name;
        User* assignedUser;
        Priority priority;
        int listId;

    public:
        Card(string name, Priority priority, int listId) {
            this->name = name;
            this->priority = priority;
            this->id = (new RandomIdGenerator())->generateRandomID();
            this->listId = listId;
        }

        int getCardId() {
            return this->id;
        }

        void modifyPriority(Priority priority) {
            this->priority = priority;
        }

        void assignUser(User* assignedUser) {
            this->assignedUser = assignedUser;
        }

        void moveCard(int listId) {
            this->listId = listId;
        }
};
