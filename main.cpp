// COMSC-210 | Jed Aficial | Final
// github link: https://github.com/jaficial/210-final

#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <string>
#include <ctime>
#include <list>

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

struct Name{
    string customer_name;
    // Constructor for the customer's name:
    Name(string name) : customer_name(name) {}
};

void pop_head(Node *, Node *);
void push_back(Node *, Node *, string, string);
void delete_linked_list(Node *, Node *);
void output_linked_list(Node *);
void output_deque(deque<string> );
void output_vector(vector<string> );

// iterates through the whole linked list and deletes every node
void delete_linked_list(Node * current, Node *head){ 
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
}

// pops the head node of the list, head->next becomes the new head
void pop_head(Node *head, Node *next_node){
    Node *temp_node;
    temp_node = head->next;
    delete head;
    head = temp_node;

}

// pushes a new node to the back of the list
void push_back(Node *tail, Node *newnode, string temp_name, string temp_drink){
    tail->next = newnode;
    newnode->customer_name = temp_name;
    newnode->drink_order = temp_drink;
    newnode->next = nullptr;
}


void output_linked_list(Node *linked_list){
    if (!linked_list){
        cout << "Noone is currently in queue." << endl;
        return;
    }

    Node *current = linked_list;
    while (current){
        cout << "Customer Name: " << current->customer_name << ", Customer Order: " << current->drink_order << endl;
        current = current->next;
    }
}

void output_deque(deque<Name> muffin_q){
    cout << "Current Queue for Muffin Shop:" << endl;
    if (muffin_q.empty()){
        cout << "Nobody in queue." << endl;
    }

    for (auto iter : muffin_q){
        cout << iter.customer_name << endl;
    }
}

void output_vector(vector<Name> bracelets_q){
    cout << "Current Queue for Bracelets Shop:" << endl;
    if (bracelets_q.empty()){
        cout << "Nobody in queue." << endl;
        return;
    }
    for (auto iter : bracelets_q){
        cout << iter.customer_name << endl;
    }
}

int main(){
    
    srand(time(0));
    Node *head = nullptr;
    Node *tail = head;
    deque<Name> muffin_q;
    vector<Name> bracelets_q;
    
    int rand_drink_indx = 0;
    int rand_name_indx = 0;

    // initializing the deque, vector, and list with 3 customers
    // NOTE: std:: list will be my choice for the 4th data structure
    for (int i = 0; i < 3; i++){
        rand_name_indx = rand() % TOTAL_CUSTOMERS;
        Name temp_name(names[rand_name_indx]);
        muffin_q.push_back(temp_name);

        rand_name_indx = rand() % TOTAL_CUSTOMERS;
        temp_name(names[rand_name_indx]);
        bracelets_q.push_back(temp_name);
    }

    // initializing linked list with 3 customers/nodes
    // CITED: Cited my lab-18 submission for initializing a linked list

    for (int i = 0; i < 3; i++){
        string temp_name;
        string temp_drink;
        rand_drink_indx = rand() % TOTAL_DRINKS;
        rand_name_indx = rand() % TOTAL_CUSTOMERS;
        
        Node *newNode = new Node;
        if (!head){
            newNode->next = nullptr;
            newNode->customer_name = names[rand_name_indx];
            newNode->drink_order = drinks[rand_drink_indx];
            head = newNode;
            tail = head;
        }

        else {
            
            temp_name = names[rand_name_indx];
            temp_drink = drinks[rand_drink_indx];
            push_back(tail, newNode, temp_name, temp_drink);
        }
    }

    Node *current = head; // current will be used to iterate through linked list
    output_linked_list(head);
    
    int probability = 0;
    for (int i = 0; i < 10; i++){
        rand_drink_indx = rand() % TOTAL_DRINKS;
        rand_name_indx = rand() % TOTAL_CUSTOMERS;
        string temp_name = names[rand_name_indx];
        string temp_drink = drinks[rand_drink_indx];
        Node *temp_node = new Node;
        probability = rand() % 100;

        // FOR COFFEE BOOTH QUEUE
        if (probability < 50){ // someone joins the queue
            if (!head){ // there is no head node
                temp_node->next = nullptr;
                temp_node->customer_name = names[rand_name_indx];
                temp_node->drink_order = drinks[rand_drink_indx];
                head = temp_node;
                tail = head;
                output_linked_list(head);
            }

            else{
                temp_name = names[rand_name_indx];
                temp_drink = drinks[rand_drink_indx];
                push_back(tail, temp_node, temp_name, temp_drink);
                output_linked_list(head);
            }
        }

        else { // nooone joins the queue, 
            if(!head){ // if there isn't anyone in the queue
                cout << "There is noone in the queue currently." << endl;
            }

            else{
                pop_head(head, head->next);
                output_linked_list(head);
            }
            
        }

        // FOR MUFFIN QUEUE
        probability = rand() % 100;
        if (probability < 50){ // someone joins queue
            cout << endl;
            rand_name_indx = rand() % TOTAL_CUSTOMERS;
            temp_name = names[rand_name_indx];
            muffin_q.push_back(temp_name);
            muffin_q.pop_front();
            output_deque(muffin_q);
        }

        else{ // noone joins the queue
            cout << endl;
            muffin_q.pop_front();
            output_deque(muffin_q);
        }

        // FOR BRACELETS QUEUE
        probability = rand() % 100;
        if (probability < 50){ // someone joins the queue
            cout << endl;
            rand_name_indx = rand() % TOTAL_CUSTOMERS;
            temp_name = names[rand_name_indx];
            bracelets_q.push_back(temp_name);
            auto bracelets_q_head = bracelets_q.begin();// NOTE: vector doesn't have pop_front method, use .begin() to access the head element
            bracelets_q.erase(bracelets_q_head);
            output_vector(bracelets_q);
        }

        else{ // noone joins the queue
            cout << endl;
            auto bracelets_q_head = bracelets_q.begin();
            bracelets_q.erase(bracelets_q_head);
            output_vector(bracelets_q);
        }


    }
    return 0;
}