// A4-To create ADT that implement the "set" concept. a. Add (new Element) -Place a value into
// the set , b. Remove (element) Remove the value c. Contains (element) Return true if element 
// is in collection, d. Size () Return number of values in collection Iterator () Returnan iterator
// used to loop over collection, e. Intersection of two sets , f. Union of two sets,
// g. Difference between two sets, h. Subset

#include <iostream>
using namespace std;

class SetADT {
    int elements[100];
    int count;

public:
    SetADT() {
        count = 0;
    }

    void add(int value) {
        if (!contains(value)) {
            elements[count++] = value;
        }
    }

    void remove(int value) {
        for (int i = 0; i < count; ++i) {
            if (elements[i] == value) {
                for (int j = i; j < count - 1; ++j)
                    elements[j] = elements[j + 1];
                count--;
                return;
            }
        }
    }

    bool contains(int value) {
        for (int i = 0; i < count; ++i)
            if (elements[i] == value) return true;
        return false;
    }

    int size() {
        return count;
    }

    void iterator() {
        for (int i = 0; i < count; ++i)
            cout << elements[i] << " ";
        cout << endl;
    }

    SetADT intersection(SetADT &other) {
        SetADT result;
        for (int i = 0; i < count; ++i)
            if (other.contains(elements[i]))
                result.add(elements[i]);
        return result;
    }

    SetADT union_set(SetADT &other) {
        SetADT result;
        for (int i = 0; i < count; ++i)
            result.add(elements[i]);
        for (int i = 0; i < other.count; ++i)
            result.add(other.elements[i]);
        return result;
    }

    SetADT difference(SetADT &other) {
        SetADT result;
        for (int i = 0; i < count; ++i)
            if (!other.contains(elements[i]))
                result.add(elements[i]);
        return result;
    }

    bool is_subset(SetADT &other) {
        for (int i = 0; i < count; ++i)
            if (!other.contains(elements[i]))
                return false;
        return true;
    }
};

// Demo
int main() {
    SetADT A, B;
    A.add(1); A.add(2); A.add(3);
    B.add(2); B.add(3); B.add(4);

    cout << "Set A: "; A.iterator();
    cout << "Set B: "; B.iterator();

    SetADT uni = A.union_set(B);
    cout << "Union: "; uni.iterator();

    SetADT inter = A.intersection(B);
    cout << "Intersection: "; inter.iterator();

    SetADT diff = A.difference(B);
    cout << "Difference (A - B): "; diff.iterator();

    cout << "A is subset of B? " << (A.is_subset(B) ? "Yes" : "No") << endl;

    return 0;
}
