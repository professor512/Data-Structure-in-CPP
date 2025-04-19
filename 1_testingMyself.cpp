#include<iostream>
#include<cstring>
using namespace std;

const int TABLE_SIZE = 10;

struct Client{
    char name[50];
    long long number;
};

struct Node{
    Client data;
    Node* next;
};

class LinearProbing{
    Client table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    public:
        LinearProbing(){
            for(int i = 0; i < TABLE_SIZE; ++i)
                occupied[i] = false;
            
        }

        int hashFunction(long long number){
            return number % TABLE_SIZE;
        }

        void insert(const char* name, long long number){
            int index = hashFunction(number);
            int start = index;

            while(occupied[index]){
                index = (index + 1) % TABLE_SIZE;
                if(index == start){
                    cout<<"Table is Full\n";
                    return;
                }
            }
            strcpy(table[index].name, name);
            table[index].number = number;
            occupied[index] = true;
        }

        int search(long long number, bool show = true){
            int index = hashFunction(number);
            int start = index;
            int comparisons = 0;

            while(occupied[index]){
                comparisons++;
                if(table[index].number == number){
                    if(show){
                        cout<<"(Number Found)(LINEAR): "<<table[index].name<<" - "<<table[index].number<<" in "<< comparisons <<"comparisons\n";
                    }
                    return comparisons;
                }
                index = (index + 1) % TABLE_SIZE;
                if(index == start) break;
            }
            if (show){
                cout<<"(LENEAR Not Found) after "<<comparisons<<" Comparions\n";
            }
            return comparisons;
        }

        void display(){
            cout<<"\n Linear Probing Table: \n";
            for(int i = 0; i < TABLE_SIZE; ++i){
                if(occupied[i]){
                    cout<<"["<< i <<"]"<<table[i].name<<" - "<<table[i].number<<"\n";
                }
                else{
                    cout<<"["<< i <<"] EMPTY\n";
                }
            }
        }

};

class Chaining{
    Node* table[TABLE_SIZE];

    public:
        Chaining(){
            for(int i = 0; i < TABLE_SIZE; ++i){
                table[i] = nullptr;
            }
        }

        int hashFunction(long long number){
            return number % TABLE_SIZE;
        }

        void insert(const char* name, long long number){
            int index = hashFunction(number);
            Node *newNode = new Node;
            strcpy(newNode->data.name, name);
            newNode->data.number = number;
            newNode->next = table[index];
            table[index] = newNode;
            
        }

        int search(long long number, bool show = true){
            int index = hashFunction(number);
            int comparisons = 0;
            Node *temp = table[index];

            while(temp){
                comparisons++;
                if(temp->data.number == number){
                    if (show){
                        cout<<"(Number Found)(CHAINING): "<<temp->data.name<<" - "<<temp->data.number<<" in "<< comparisons <<"comparisons\n";
                    }
                    return comparisons;
                }
                temp = temp->next;
            }
            if (show){
                cout<<"(CHAINING Not Found) after "<< comparisons <<" Comparisons";
            }
            return comparisons;
        }

        void display(){
            cout<<"\n Chaining Table: \n";
            for(int i = 0; i < TABLE_SIZE; ++i){
                cout<<"["<< i <<"]";
                Node *temp = table[i];
                while(temp){
                    cout<<"->"<<temp->data.name <<"("<<temp->data.number<<")";
                    temp = temp->next;
                }
                cout<<"\n";
            }
        }
};
int main(){
    LinearProbing Linear;
    Chaining Chain;
    int choice;
    char name[50];
    long long number;

    do{
        cout<<"\n\n<--Telephone Book Menu-->\n";
        cout<<"1. Insert new record\n";
        cout<<"2. Search Record\n";
        cout<<"3. Display Records\n";
        cout<<"4. Compare Records\n";
        cout<<"5. Exit\n\n";
        cout<<"ENter Your Choice:\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Name:\n";
                cin>>name;
                cout<<"Enter Number:\n";
                cin>>number;
                Linear.insert(name, number);
                Chain.insert(name, number);
                break;

            case 2:
                cout<<"Enter number to search\n";
                cin>>number;
                Linear.search(number);
                Chain.search(number);
                break;

            case 3:
                Linear.display();
                Chain.display();
                break;
        }
    }while(true);
    return 0;
}