#include <iostream>
#include <map>
#include "list.cpp"

using namespace std;

class Board {
    private:
        int id;
        string name;
        vector<User*> users;
        map<int, List*> lists;

    public:
        Board(string name) {
            this->name = name;
            this->id = (new RandomIdGenerator())->generateRandomID();
        }

        int getBoardId() {
            return this->id;
        }

        void addUsers(vector<User*> users) {
            this->users.insert(this->users.end(), users.begin(), users.end());
        }

        int addList(string listName) {
            List* list = new List(listName, this->id);
            lists[list->getListId()] = list;
            return list->getListId();
        }

        List* getListById(int listId) {
            return lists[listId];
        }

        void deleteList(int listId) {
            List* list = lists[listId];
            list->deleteAllCards();

            lists.erase(listId);
        }

        void deleteLists() {
            for (auto it = lists.begin(); it != lists.end(); it++) {
                deleteList(it->first);
            }
        }
};
