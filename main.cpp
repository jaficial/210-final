// COMSC-210 | Jed Aficial | Final
// github link: https://github.com/jaficial/210-final

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <ctime>

using namespace std;
const int TOTAL_DRINKS = 5;
const int TOTAL_CUSTOMERS = 41;
string names[] = {"Ella", "Inga", "Zane", "Oleg", "Wade", "Yale", "Tami", 
                    "Tara", "Axel", "Ola", "Beth", "Boyd", "Rosa", "Ezra",
                     "Mara", "Rico", "Kurt", "Nell", "Cami", "Zeke", "Yoko", 
                     "Bree", "Seth", "Amos", "Luke", "Elle", "Jody", "Effy", 
                     "Cici", "Vivi", "Rene", "Zoie", "Arlo", "Erin", "Pete", 
                     "Amy", "Owen", "Joel", "Joey", "Eddy", "Hana"}; // CITED: Names used from lab-23's data file

string drinks[] = {"Black Coffee", "Latte", "Tea", "Water", "Juice"};

// NOTE: 4 BOOTHS TO CREATE:
/*
    COFFEE BOOTH: USE LINKED LIST
    - linked list struct should be a node that contains the customer's name and drink order
    - create data arrays with names and drink orders from which to randomly create customer data
    - run for 10 rounds
    - initialize queue with 3 customers
        - for any round, there's a 50% probability that someone will join the queue
        - customer at head of queue is always served
    - sometimes there might not be a customer being served 

*/ 

struct Node {
    string customer_name;
    string drink_order;
    Node *next;
};

void pop_head(Node *, Node *);
void push_back(Node *, Node *, int);
void delete_linked_list(Node *, Node *);
void output_linked_list(Node *);

// iterates through the whole linked list and deletes every node
void delete_linked_list(Node * current, Node *head){ 
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
}

// pops the head node of the list, head->next becomes the new head
void pop_head(Node *head, Node *next){
    Node *temp_node;
    temp_node = head->next;
    delete head;
    head = temp_node;

}

// pushes a new node to the back of the list
void push_back(Node *tail, Node *newnode){
    tail->next = newnode;
    newnode->next = nullptr;
}


void output_linked_list(Node *current){
    if (!current){
        cout << "Noone is currently in queue." << endl;
        return;
    }
    while (current){
        cout << "Customer Name: " << current->customer_name << ", Customer Order: "
    }
}

int main(){
    
    srand(time(0));
    Node *head = nullptr;
    Node *newNode = nullptr;
    Node *tail = nullptr;
    
    int rand_drink_indx = 0;
    int rand_name_indx = 0;
    
    // initializing linked list with 3 customers/nodes
    for (int i = 0; i < 2; i++){
        rand_drink_indx = rand() % TOTAL_DRINKS;
        rand_name_indx = rand() % TOTAL_CUSTOMERS;

        newNode->customer_name = names[rand_name_indx];
        newNode->drink_order = drinks[rand_drink_indx];
        if (!head){ // if this is the first node, it is the new head; CITED: cited from my lab-17 submission
            head = newNode;
            newNode->next = nullptr;
            tail = head;
        }

        else { // its a second node/following node
            push_back(tail, newNode);
        }
    }
    
    Node *current = head; // current will be used to iterate through linked list
    for (int i = 0; i < 2; i ++){
        cout << "This is the customer's name: " << current->customer_name << " and this is their drink order: " << current->drink_order << endl;

    }
    return 0;
}