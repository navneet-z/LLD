#include <iostream>
#include "my-bits.h"

using namespace std;

class RandomIdGenerator {
    public:
        // Function to generate a random ID
        int generateRandomID() {
            // Seed the random number generator using std::random_device
            random_device rd;
            
            // Use the Mersenne Twister engine for randomness
            mt19937 gen(rd());
            
            // Define the range of possible IDs (adjust as needed)
            uniform_int_distribution<int> distribution(1000, 9999);
            
            // Generate and return a random ID
            return distribution(gen);
        }
};
