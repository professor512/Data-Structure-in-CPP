#include <iostream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

// Struct for storing client data
struct Client {
    char name[50];
    long long number;
};

// Node structure for chaining
struct Node {
    Client data;
    Node* next;
};

// Linear Probing Class
class LinearProbing {
    Client table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

public:
    LinearProbing() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            occupied[i] = false;
    }

    int hashFunction(long long number) {
        return number % TABLE_SIZE;
    }

    void insert(const char* name, long long number) {
        int index = hashFunction(number);
        int start = index;

        while (occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "Hash table is full (Linear Probing)!\n";
                return;
            }
        }

        strcpy(table[index].name, name);
        table[index].number = number;
        occupied[index] = true;
    }

    int search(long long number, bool show = true) {
        int index = hashFunction(number);
        int start = index;
        int comparisons = 0;

        while (occupied[index]) {
            comparisons++;
            if (table[index].number == number) {
                if (show)
                    cout << "Found (Linear): " << table[index].name << " - " << table[index].number << " in " << comparisons << " comparisons\n";
                return comparisons;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }

        if (show)
            cout << "Not found (Linear) after " << comparisons << " comparisons\n";
        return comparisons;
    }

    void display() {
        cout << "\nLinear Probing Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (occupied[i])
                cout << "[" << i << "] " << table[i].name << " - " << table[i].number << "\n";
            else
                cout << "[" << i << "] EMPTY\n";
        }
    }
};

// Chaining Class
class Chaining {
    Node* table[TABLE_SIZE];

public:
    Chaining() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    int hashFunction(long long number) {
        return number % TABLE_SIZE;
    }

    void insert(const char* name, long long number) {
        int index = hashFunction(number);
        Node* newNode = new Node;
        strcpy(newNode->data.name, name);
        newNode->data.number = number;
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(long long number, bool show = true) {
        int index = hashFunction(number);
        int comparisons = 0;
        Node* temp = table[index];

        while (temp) {
            comparisons++;
            if (temp->data.number == number) {
                if (show)
                    cout << "Found (Chaining): " << temp->data.name << " - " << temp->data.number << " in " << comparisons << " comparisons\n";
                return comparisons;
            }
            temp = temp->next;
        }

        if (show)
            cout << "Not found (Chaining) after " << comparisons << " comparisons\n";
        return comparisons;
    }

    void display() {
        cout << "\nChaining Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]";
            Node* temp = table[i];
            while (temp) {
                cout << " -> " << temp->data.name << " (" << temp->data.number << ")";
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    ~Chaining() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* temp = table[i];
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
};

// Menu-driven program
int main() {
    LinearProbing linear;
    Chaining chaining;
    int choice;
    char name[50];
    long long number;

    do {
        cout << "\n--- Telephone Book Menu ---\n";
        cout << "1. Insert Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display Tables\n";
        cout << "4. Compare Searches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> number;
            linear.insert(name, number);
            chaining.insert(name, number);
            break;

        case 2:
            cout << "Enter number to search: ";
            cin >> number;
            linear.search(number);
            chaining.search(number);
            break;

        case 3:
            linear.display();
            chaining.display();
            break;

        case 4: {
            int n;
            cout << "How many numbers to compare? ";
            cin >> n;
            int totalLinear = 0, totalChaining = 0;

            for (int i = 0; i < n; ++i) {
                cout << "Enter number " << i + 1 << ": ";
                cin >> number;
                totalLinear += linear.search(number, false);
                totalChaining += chaining.search(number, false);
            }

            cout << "\nTotal Comparisons:\n";
            cout << "Linear Probing: " << totalLinear << "\n";
            cout << "Chaining: " << totalChaining << "\n";
            break;
        }

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
