#include <iostream>

using namespace std;

class Register {
    private:
        int value;

    public:
        int getValue() {
            return this->value;
        }

        void setValue(int val) {
            this->value = val;
        }
};
