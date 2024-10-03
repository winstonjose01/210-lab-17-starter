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
    Node *newVal = new Node; // Create a new node
    newVal->next = head;    // Assign the value to the new node
    newVal->value = tmp;    // Point the new node to the current head of the list
    head = newVal;          // Update the head to be the new node.
}

// This functions adds a new node to end of the list
// arguments: Node *head reference, and integer tmp (random generated integer)
// return: void
void add_node_tail (Node *&head, int tmp){
    Node *newVal = new Node;  // Create a new node
    Node *current = new Node; 
    newVal->next = nullptr; // Since its the last node, pointer is set to nullptr
    newVal->value = tmp;  // Assign the value to the new node

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

    Node * current = head; // Start pointer at the head of the list
    Node * prev = head;  // Create a pointer to track the previous node
    // Travers the list to find the n position
    for (int i = 0; i < (n); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //At this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000; // Assign the value to the new node
    newnode->next = current; // Insert the new node between prev and current
    prev->next = newnode; // The previous node points to the new node

}

// This functions deletes a new node to the linked list
// arguments: Node * head, and integer n (user entry)
// return: void
void delete_node (Node *&head, int n){

    Node * current = head; // Start pointer at the head of the list
    Node *prev = head; // Create a pointer to track the previous node
    // Traverse the list to find the nth node
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
        delete current; // Delete the node
        current = nullptr; // Set the pointer to null
    }

}

void delete_list(Node *&head){

    Node * current = head; // Start pointer at the head of the list
    while (current) {       // Loop until current is nullptr
        head = current->next; // Move the pointer to the next node
        delete current;     // Delete the current node
        current = head;     // Move the current node to the next node
    }
    head = nullptr; // Once all nodes deleted, set head to nullptr

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