#include <iostream>
using namespace std;


// Function prototypes
struct node *insert_beg(node *, int );
struct node *insert_end(node *, int );
struct node *insert_after(node *, int );
struct node *insert_before(node *, int );

struct node *create(node *);

struct node *del_beg(node *);
struct node *del_end(node *);
struct node *del_after(node *);
struct node *del_before(node *);
struct node *del_element(node *);

void count(node *);
void display(node *);


/*

Declaring a structure called node
having two members:

  1) data block
  2) next block (which stores the address of the next node)

 */

struct node {
  int data;
  node *next;
};


/*

ALGORITHM FOR INSERTING AT THE BEGINNING:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> NEXT = START
  6) START = NEW_NODE
  7) EXIT

*/

node *insert_beg(node *start, int value) {
  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block
  new_node->data = value;
  new_node->next = start;

  // making the start point to be first element of the linked list
  start = new_node;

  return start;
}


/*

ALGORITHM FOR INSERTING AT THE END:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> NEXT = NULL
  6) PTR = START
  7) WHILE PTR -> NEXT != NULL
        PTR = PTR -> next

  8) PTR -> NEXT = NEW_NODE
  7) EXIT

*/

node *insert_end(node *start, int value) {
  // Storing the value of start to ptr
  node *ptr = start;

  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block
  new_node->data = value;
  new_node->next = NULL;

  // Searching for the last element after which we should insert
  while(ptr->next != NULL) {
    // Incrementing
    ptr = ptr->next;
  }

  // Storing the address of new node to the next pointer of ptr
  ptr->next = new_node;

  return start;
}


/*

ALGORITHM FOR INSERTING AFTER A GIVEN NODE:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) PTR = START
  6) PREPTR = PTR
  7) WHILE PREPTR -> NEXT != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  8) PREPTR -> NEXT = NEW_NODE
  9) NEW_NODE -> NEXT = PTR
  7) EXIT

*/

node *insert_after(node *start, int value) {
  int num;

  // Storing the value of start to ptr
  node *ptr = start;

  // Number after which to insert
  cout<<"Enter the number after which to insert: ";
  cin>>num;

  // Creating a new node
  node *new_node = new node;

  // Storing the data
  new_node->data = value;

  // Taking another node to store the location of
  // the element before ptr
  node *preptr = ptr;

  // Incrementing till the number is found
  while(preptr->data != num) {
    preptr = ptr;
    ptr = ptr->next;
  }

  // Adding the new node
  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}


/*

ALGORITHM FOR INSERTING BEFORE A GIVEN NODE:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) PTR = START
  6) PREPTR = PTR
  7) WHILE PTR -> NEXT != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  8) PREPTR -> NEXT = NEW_NODE
  9) NEW_NODE -> NEXT = PTR
  7) EXIT

*/

node *insert_before(node *start, int value) {
  int num;

  // Storing the value of start to ptr
  node *ptr = start;

  // Number after which to insert
  cout<<"Enter the number before which to insert: ";
  cin>>num;

  // Creating a new node
  node *new_node = new node;

  // Storing the data
  new_node->data = value;

  // Taking another node to store the location of
  // the element before ptr
  node *preptr = ptr;

  // Incrementing till the number is found
  while(ptr->data != num) {
    preptr = ptr;
    ptr = ptr->next;
  }

  // Adding the new node
  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}

// For creating the entire linked list
node *create(node *start) {
  int value;

  // Storing the value to be inserted
  cout<<"Enter -1 to stop\n";
  cout<<"Enter the value to be stored: ";
  cin>>value;

  while(value != -1){
    if(start == NULL) {
      node *new_node = new node;
      new_node->data = value;
      new_node->next = NULL;

      start = new_node;
    }
    else {
      // Elements are inserted at the end
      insert_end(start, value);
    }

    cout<<"Enter the value to be stored: ";
    cin>>value;
  }

  return start;
}


/*

ALGORITHM FOR DELETING FROM THE BEGINNING:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) START = START -> NEXT
  4) DELETE PTR
  5) EXIT

*/

node *del_beg(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start to ptr
    node *ptr = start;

    // Incrementing start to one position
    start = start->next;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the first element
    delete ptr;
  }

  return start;
}


/*

ALGORITHM FOR DELETING FROM THE END:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) PREPTR = PTR
  4) WHILE PTR -> NEXT != NULL
        PREPTR = PTR
        PTR = PTR -> NEXT

  5) PREPTR -> NEXT = NULL
  6) DELETE PTR
  7) EXIT

*/

node *del_end(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start to ptr
    node *ptr = start;

    // Defining another pointer for storing
    // the previous element of ptr
    node *preptr = ptr;

    // Incrementing till the last position
    while(ptr->next != NULL) {
      preptr = ptr;
      ptr = ptr->next;
    }

    // Storing null in the NEXT block as there
    // is no element after this
    preptr->next = NULL;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the last element
    delete ptr;
  }

  return start;
}


/*

ALGORITHM FOR DELETING AN ELEMENT AFTER A GIVEN NODE:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) PREPTR = PTR
  4) WHILE PREPTR -> DATA != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  5) PREPTR -> NEXT = PTR -> NEXT
  6) DELETE PTR
  7) EXIT

*/

node *del_after(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    int num;

    // Storing the element, after which to be deleted
    cout<<"Enter the element after which to be deleted: ";
    cin>>num;

    // Storing start to ptr
    node *ptr = start;

    // Defining another pointer for storing
    // the previous element of ptr
    node *preptr = ptr;

    // Incrementing till num is found
    while(preptr->data != num) {
      preptr = ptr;
      ptr = ptr->next;
    }

    // Storing the address of element leaving one block,
    // which is to be deleted
    preptr->next = ptr->next;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the element
    delete ptr;
  }

  return start;
}


/*

ALGORITHM FOR DELETING AN ELEMENT BEFORE A GIVEN NODE:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) PREPTR = PTR
  4) WHILE PTR -> NEXT -> DATA != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  5) PREPTR -> NEXT = PTR -> NEXT
  6) DELETE PTR
  7) EXIT

*/

node *del_before(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    int num;

    // Storing the element, before which to be deleted
    cout<<"Enter the element before which to be deleted: ";
    cin>>num;

    // Storing start to ptr
    node *ptr = start;

    // Defining another pointer for storing
    // the previous element of ptr
    node *preptr = ptr;

    // Incrementing till num is found
    while(ptr->next->data != num) {
      preptr = ptr;
      ptr = ptr->next;
    }

    // Storing the address of element leaving one block,
    // which is to be deleted
    preptr->next = ptr->next;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the element
    delete ptr;
  }

  return start;
}


/*

ALGORITHM FOR DELETING CURRENT ELEMENT:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) PREPTR = PTR
  4) WHILE PTR -> DATA != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  5) PREPTR -> NEXT = PTR -> NEXT
  6) DELETE PTR
  7) EXIT

*/

node *del_element(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    int num;

    // Storing the element, which to be deleted
    cout<<"Enter the element which to be deleted: ";
    cin>>num;

    // Storing start to ptr
    node *ptr = start;

    // Defining another pointer for storing
    // the previous element of ptr
    node *preptr = ptr;

    // Incrementing till num is found
    while(ptr->data != num) {
      preptr = ptr;
      ptr = ptr->next;
    }

    // Storing the address of element leaving one block,
    // which is to be deleted
    preptr->next = ptr->next;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the element
    delete ptr;
  }

  return start;
}


/*

ALGORITHM FOR COUNTING THE NUMBER OF ELEMENTS:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) SET COUNT = 0
  4) WHILE PTR != NULL
        COUNT = COUNT + 1
        PTR = PTR -> NEXT

  5) WRITE COUNT
  6) EXIT

*/

void count(node *start) {
  int count = 0;

  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start in ptr
    node *ptr = start;

    // Incrementing till the end
    while(ptr != NULL) {
      count++;
      ptr = ptr->next;
    }
  }
  // Printing the number of elements
  cout<<"The number of elements present in the linked list are: "
      <<count
      <<endl;
}


/*

ALGORITHM FOR DISPLAYING THE ELEMENTS:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) WHILE PTR != NULL
        Write PTR -> DATA
        PTR = PTR -> NEXT
  4) EXIT

*/

void display(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start in ptr
    node *ptr = start;

    // Incrementing till the end
    while(ptr != NULL) {
      // Printing the elements
      cout<<ptr->data<<" ";
      ptr = ptr->next;

    } cout<<endl;
  }
}

// Main Function
int main() {
  // Initialize start to be null
  node *start = NULL;

  int option, value;

  // Continuing to show the menu till the program is exited
  do {
    cout<<"\n********** MENU **********\n"
        <<"1. Create the linked list\n"
        <<"2. Insert at the beginning\n"
        <<"3. Insert at the end\n"
        <<"4. Insert after an element\n"
        <<"5. Insert before an element\n"
        <<"6. Delete from the beginning\n"
        <<"7. Delete from the end\n"
        <<"8. Delete after an element\n"
        <<"9. Delete before an element\n"
        <<"10. Delete the element\n"
        <<"11. Count\n"
        <<"12. Display\n"
        <<"13. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      
      case 1: start = create(start);
              break;

      case 2: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_beg(start, value);
              break;

      case 3: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_end(start, value);
              break;

      case 4: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_after(start, value);
              break;

      case 5: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_before(start, value);
              break;

      case 6: start = del_beg(start);
              break;

      case 7: start = del_end(start);
              break;

      case 8: start = del_after(start);
              break;

      case 9: start = del_before(start);
              break;

      case 10: start = del_element(start);
              break;

      case 11: count(start);
              break;

      case 12: display(start);
              break;

      case 13: break;

      default: cout<<"Wrong option is selecred !!\n";
              break;
    }
  } while(option != 13);

  // Freeing the space occupied by start
  if(option == 13) {
    delete start;
  }
}
