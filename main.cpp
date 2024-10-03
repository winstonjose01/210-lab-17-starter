// COMSC210 | Lab 17 | Winston Jose
// IDE used: Visual Studio Code
// Github link: https://github.com/winstonjose01/210-lab-17-starter 


#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void add_node_front (Node *&, int); // Adds a node to the front (head) of the list
void add_node_tail (Node *&, int);  // Adds a node to the tail of the list
void add_node (Node *&, int);       // Adds a node in between other nodes
void delete_node(Node *&, int);     // Deletes a node
void delete_list(Node *&);          // Deletes the entire linked list

void output(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            add_node_front(head, tmp_val);
        }
        else { // its a second or subsequent node; place at the head
            add_node_tail(head, tmp_val);
        }
    }
    output(head);

    // deleting a node
    //Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    // Call function to delete a node
    delete_node(head, entry); 
    // Output the list after deleting the node
    output(head); 
    // Prompt the user which node to insert 10000
    cout << "After which node to insert 10000? " << endl;
    // Output the list to help user select
    output (head);
    cout << "Choice --> ";
    // Save the choice to variable entry
    cin >> entry;
    // Call function to add a node in the middle of the list
    add_node(head, entry);
    // Output the list after adding the 1000 value node
    output(head);
    // Call function to delete the entire list
    delete_list(head);
    // Output the list after deleting
    output(head); 

    return 0;
}

// This functions adds a new node to front of the list
// arguments: Node *head reference, and integer tmp (random generated integer)
// return: void
void add_node_front (Node *&head, int tmp){
    Node *newVal = new Node;
    newVal->next = head; // Assign the va
    newVal->value = tmp;
    head = newVal;
}

// This functions adds a new node to end of the list
// arguments: Node *head reference, and integer tmp (random generated integer)
// return: void
void add_node_tail (Node *&head, int tmp){
    Node *newVal = new Node;
    Node *current = new Node; //
    newVal->next = nullptr;
    newVal->value = tmp;

    if (!head){
        head = newVal; // If list empty new node becomes the head
    }
    else{
        current = head; // Start to traverse list from head
        while (current->next){ // Traverse until last node fuound
            current = current->next; // Move to the next node
        }
        current->next = newVal; //Set the next pointer of the current last node to the new node
    }

}

// This functions adds a new node to the linked list
// arguments: Node *head reference, and integer n (user entry)
// return: void
void add_node(Node *&head, int n){

    Node * current = head;
    Node * prev = head;
    for (int i = 0; i < (n); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;

}

// This functions deletes a new node to the linked list
// arguments: Node * head, and integer n (user entry)
// return: void
void delete_node (Node *&head, int n){

    Node * current = head;
    Node *prev = head;
    for (int i = 0; i < (n-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

}

void delete_list(Node *&head){

    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;

}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}