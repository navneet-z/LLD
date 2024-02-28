#include<iostream>
#include "random-id.cpp"

using namespace std;

class User {
    public:
        int id;
        string name;
        string email;
        User(string name, string email) {
            this->id = (new RandomIdGenerator())->generateRandomID();
            this->name = name;
            this->email = email;
        }
};
