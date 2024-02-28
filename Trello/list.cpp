#include <iostream>
#include <map>
#include "card.cpp"

using namespace std;

class List {
    private:
        int id;
        string name;
        int boardId;
        map<int, Card*> cards;

    public:
        List(string name, int boardId) {
            this->name = name;
            this->boardId = boardId;
            this->id = (new RandomIdGenerator())->generateRandomID();
        }

        int getListId() {
            return this->id;
        }

        int addCard(string cardName, Priority priority) {
            Card* card = new Card(cardName, priority, this->id);
            cards[card->getCardId()] = card;
            return card->getCardId();
        }

        Card* getCardById(int cardId) {
            return cards[cardId];
        }

        void deleteCard(int cardId) {
            cards.erase(cardId);
        }

        void deleteAllCards() {
            cards.clear();
        }
};
