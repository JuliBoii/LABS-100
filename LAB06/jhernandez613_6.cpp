#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class HashTable {
private:
    std::list<int> *map;
    int size;
    int hashFunction(int k) const {
        return k % size;
    }

public:
    // Creates a default Hash Table of size 10 in the HT is not initialized with a value
    HashTable() {
        this->size = 10;
        map = new std::list<int>[this->size];
    }

    //Creates a Hash Table based on the size desired
    HashTable(int size) {
        this->size = size;
        map = new std::list<int>[this->size];
    }

    // Destructor to free memory when done using Hash Table
    ~HashTable() {
        delete[] map;
    }

    // Inputs a value into the Hash table
    void insertItem(int item) {
        int bPos = hashFunction(item); // Finds the position of the element in the Hash Table using the Hash Function
        map[bPos].push_front(item); // Inserts the element into the Hash Table. (it does not sort the element when pushed in)
    }

    // Looks for the element in the respective position of the Hash Table
    void searchItem(int item) {
        int bPos = hashFunction(item), count = 0;   // Finds the position fo the element in the Hash table using the Hash Function, Initializes the count to zero.
        auto it= find(map[bPos].begin(), map[bPos].end(), item); // Looks for the item in the specified location of the Hash Table and save the position in the linked list

        // If the item was not found print out that the item was not found
        if (it == map[bPos].end()) {
            std::cout << item << ":NOT_FOUND;" << std::endl;
        }
        else {
            // Since the item was found now we have to find its numerical position in the linked list
            for(auto y = map[bPos].begin(); y != map[bPos].end(); y++) {
                // If the item is equal to the item we found previously stop looking
                if (*y == *it) {
                    break;
                }
                    // Otherwise, increment the numerical position
                else if (*y != *it) {
                    count++;
                }
            }
            std::cout << item << ":FOUND_AT" << bPos << "," << count << ";" << std::endl;   // Print out that it was found along with its position in the Hash Table and Linked list
        }
    }

    // Removes an item from the Hash Table
    void deleteItem(int item) {
        int bPos = hashFunction(item);  // Finds the position fo the element in the Hash table using the Hash Function
        auto it = find(map[bPos].begin(), map[bPos].end(), item); // Looks for the item in the specified location and  save the position.

        // If the item was not found we print a failure to delete message to user
        if (it == map[bPos].end()) {
            std::cout << item << ":DELETE_FAILED;" << std::endl;
        }
        else {
            // Otherwise, we remove the element from the linked list at the specified position in the Hash Table
            map[bPos].erase(it);
            std::cout << item << ":DELETED;" << std::endl;
        }
    }

    // Prints out the Hash Table and the linked list at each location in the Hash Table
    void printTable () {
        for (int i = 0; i < size; i++) {
            std::cout << i << ":";
            for (int & j : map[i]) {
                std::cout << j << "->";
            }
            std::cout << ";" << std::endl;
        }
    }
};

int main() {
    int size = 0, num;
    std::string usrInput;

    std::cin >> size;

    HashTable HT(size); // Initialize a Hash Table of the users desired size

    // The program will continuously ask for an usrInput, until "e" is entered
    // Then the program will finally end
    do {
        std::cin >> usrInput;  // Takes users usrInput

        // Checks to see if the usrInput has the following char's in front: i, s, d, o
        // The user will usrInput each key char followed with their desired value
        // i signifies the user wants to usrInput a value into the Hash table
        if (usrInput[0] == 'i') {
            usrInput.erase(usrInput.begin()); // we remove the i from the usrInput
            num = stoi(usrInput);  // Then we convert the string usrInput from the user into an int
            HT.insertItem(num); // Then we insert the value into the Hash Table
        }
            // s signifies the user wants to search for a value in the Hash table
        else if (usrInput[0] == 's') {
            usrInput.erase(usrInput.begin()); // we remove the s from the usrInput
            num = stoi(usrInput); // Then we convert the string usrInput from the user into an int
            HT.searchItem(num); // Then we search for the value in the Hash Table
        }
            // d signifies the user wants to delete a value in the Hash table
        else if (usrInput[0] == 'd') {
            usrInput.erase(usrInput.begin()); // we remove the d from the usrInput
            num = stoi(usrInput); // Then we convert the string usrInput from the user into an int
            HT.deleteItem(num); // Then we delete the value from the Hash Table, if it exists
        }
        else if (usrInput == "o") {
            HT.printTable(); // Prints out the current state of the Hash Table
        }
    } while (usrInput != "e"); // Terminates the user inputs and ends the program.

    return 0;
}