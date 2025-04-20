// C15- You have a business with several offices; you want to lease phone lines to connect them 
// up with each other; and the phone company charges different amounts of money to connect 
// different pairs of cities. You want a set of lines that connects all your offices with a 
// minimum total cost. Solve the problem by suggesting appropriate data structures. 

#include <iostream>
using namespace std;

class tree {
    int a[20][20], l, u, w, i, j, v, e, visited[20];
public:
    void input();
    void display();
    void minimum();
};

void tree::input() {
    cout << "========== INPUT BRANCH AND CONNECTION DETAILS ==========" << endl;
    cout << "Enter the total number of branches (offices): ";
    cin >> v;

    // Initialize adjacency matrix and visited array
    for (i = 0; i < v; i++) {
        visited[i] = 0;
        for (j = 0; j < v; j++) {
            a[i][j] = 999; // Use 999 to represent no direct connection
        }
    }

    cout << "\nEnter the number of available phone line connections between branches: ";
    cin >> e;

    cout << "\nNOTE: Branch numbers should be from 1 to " << v << "." << endl;
    cout << "For each connection, enter:\n  - First branch number\n  - Second branch number\n  - Cost charged by the phone company\n" << endl;

    for (i = 0; i < e; i++) {
        cout << "Connection " << i + 1 << ":" << endl;
        cout << "  Enter first branch number: ";
        cin >> l;
        cout << "  Enter second branch number: ";
        cin >> u;
        cout << "  Enter cost to connect Branch " << l << " and Branch " << u << ": ";
        cin >> w;

        // Store cost in both directions (undirected graph)
        a[l - 1][u - 1] = a[u - 1][l - 1] = w;
    }
}

void tree::display() {
    cout << "\n========== ADJACENCY MATRIX ==========" << endl;

    // Print column headers
    cout << "     ";
    for (i = 0; i < v; i++) {
        cout << "B" << (i + 1) << "   ";
    }
    cout << endl;

    for (i = 0; i < v; i++) {
        // Print row header
        cout << "B" << (i + 1) << "  ";
        for (j = 0; j < v; j++) {
            if (a[i][j] == 999)
                cout << "0   "; // Use infinity symbol for no connection
            else {
                if (a[i][j] < 10)
                    cout << a[i][j] << "   "; // Align single digits
                else if (a[i][j] < 100)
                    cout << a[i][j] << "  ";  // Align double digits
                else
                    cout << a[i][j] << " ";   // Align triple digits
            }
        }
        cout << endl;
    }
}

void tree::minimum() {
    int p = 0, q = 0, total = 0, min;
    visited[0] = 1;

    cout << "\n========== MINIMUM COST CONNECTIONS ==========" << endl;
    for (int count = 0; count < v - 1; count++) {
        min = 999;

        for (i = 0; i < v; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < v; j++) {
                    if (visited[j] != 1 && a[i][j] < min) {
                        min = a[i][j];
                        p = i;
                        q = j;
                    }
                }
            }
        }

        visited[q] = 1;
        total += min;

        cout << "Branch " << (p + 1) << " -> Branch " << (q + 1)
             << " with charge: " << min << endl;
    }

    cout << "\nThe minimum total cost to connect all branches is: " << total << endl;
}

int main() {
    int ch;
    tree t;

    do {
        cout << "\n========== PRIM'S ALGORITHM MENU ==========" << endl;
        cout << "1. Input Branch and Connection Details\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Find Minimum Cost to Connect Branches\n";
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.input();
                break;
            case 2:
                t.display();
                break;
            case 3:
                t.minimum();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "❌ Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (ch != 4);

    return 0;
}
