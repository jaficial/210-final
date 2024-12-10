// COMSC-210 | Jed Aficial | Final
// github link: https://github.com/jaficial/210-final

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

using namespace std;

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
};

void pop_head(Node *, Node *);
void push_back(Node *, Node *, int);

void pop_head(Node *head, Node *next){

}

int main(){
    
    srand(time(0));


    
    return 0;
}