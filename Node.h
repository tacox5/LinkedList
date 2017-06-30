#include <iostream>

using namespace std;



// Forward declaration of LinkedList to be declared as a friend class to Node
template <typename T> class LinkedList;


// Create a templated Node class
template <typename T> class Node{
  friend class LinkedList<T>; // Allow the LinkedList to use Node private variables
  private:
    T value; // Templated value for the Node
    Node* Next; // Pointer to the next node

  public:
    Node(void){
      // If no value is given, initialize a node with no value
      Next = NULL;
    }
    Node(int val){
      // If value is given, initialize a node with a value
      value = val;
      Next = NULL;
    }
};


//Create a templated LinkedList class
template <typename T> class LinkedList{
  private:
    Node<T> *Head; // Templated Node pointer to the beginning node
    Node<T> *Current; // Templated Node pointer to the current node

  public:
    // Constructor for no given value
    LinkedList(){
      Head = NULL; // Head is Null
      Current = Head; // Current is set to head
    }

    // Constructor for a given templated value
    LinkedList(T val){
      Head = new Node<T>(val); // Initialize a node with a value
      Current = Head;
    }

    // Declaration of all other methods used in this class
    // Defined below
    void AddToFront(T data);
    void AddToEnd(T data);
    void RemoveFirst(T data);
    void RemoveAll(T data);
    void AddAtIndex(T data, T index);
    void NextNode();
    void InsertAfterCurrent(T data);
    int RemoveCurrent();
    T RemoveAtIndex(T index); //
    int RemoveFromFront();
    int RemoveFromEnd();
    bool ElementExists(T data); //
    Node<T>* Find(T data); //
    int IndexOf(T data); //
    int RetrieveFront();
    int RetrieveEnd();
    T Retrieve(T index); //
    int* ToArray(T length); //
    void Empty();
    int Length();
    ~LinkedList(void);

    void PrintLinkedList();
};

template <class T>
LinkedList<T>::~LinkedList(void){
}

// Method to print nodes in the LinkedList
template <class T>
void LinkedList<T>::PrintLinkedList()
{
    Node<T>* temp = new Node<T>(); // Initialize a temporary node
    temp = Head; // Set the node equal to the head

    // If the node is empty, the list is empty. Inform the user
    if (temp == NULL) {
        cout << "\nThe list is empty" << endl;
        return; // Exit the method
    }

    cout << "Survivor(s): ";

    // Run through the LinkedList while the temp node is not null
    while (temp!=NULL) {
        cout << temp->value<<" "; // Print the value and whitespace
        temp = temp->Next; // Move to the next node
    }
    cout << endl;
    delete temp; // Remove the node
}

//Method to add a node to the end of the LinkedList
template <class T>
void LinkedList<T>::AddToEnd(T data){
  Node<T>* newNode = new Node<T>(data); // create a node with given data to be added
  newNode->Next=NULL;

  // If the list is empty, make the new node the head
  if (Head == NULL){
    Head = newNode;
  }

  // Otherwise the list has nodes, so move through the list
  else{
    Node<T>* temp = new Node<T>(); // Create a temp node to traverse the list
    temp = Head; // Initialize it to the head

    // Move through the list until the next node is NULL
    while(temp->Next!=NULL){
      temp = temp->Next; // Move onto the next node
    }
    newNode->Next = NULL; // Initialize the new nodes next to null
    temp->Next = newNode; // Make the temp's next node point to the new node
  }
}


// Method to add a new node to the front
template <class T>
void LinkedList<T>::AddToFront(T data){

  Node<T> *newNode = new Node<T>(data); // Create a new node with the data provided
  newNode->Next=NULL;

  // If the Head is Null, make the Head the new node
  if (Head == NULL){
    Head = newNode;
  }

  // Otherwise create a new head
  else{
    Node<T> *temp = new Node<T>(); // Temp to store the info for the head node
    temp = Head; // Set the temp equal to the head
    Head = newNode; // Make the head the new node
    Head->Next = temp; // Set the Head's next node equal to the old Head
  }
}

// Method to remove the first node with the same value of
// inputted data
template <class T>
void LinkedList<T>::RemoveFirst(T data){
  // Create two nodes to keep track of positions
  Node<T>* temp = new Node<T>();
  Node<T>* temp2 = new Node<T>();

  // If the Head has the value
  if(Head->value==data){
    temp2 = Head;
    Head = temp2->Next;
    delete temp2;
    return;
  }

  temp = Head;
  temp2 = Head->Next;

  while (temp2!=NULL){
    if(temp->value==data){
      temp->Next = temp2->Next;
      delete temp2;
    }
    temp = temp2;
    temp2 = temp2->Next;
  }
}

template <class T>
void LinkedList<T>::RemoveAll(T data){
    Node<T>* temp = new Node<T>();
    Node<T>* del = new Node<T>();
    temp = Head;

    while (temp != NULL && temp->value == data)
    {
        Head = temp->Next;
        delete temp;
        temp = Head;
    }

    while (temp != NULL)
    {
        while (temp != NULL && temp->value != data)
        {
            del = temp;
            temp = temp->Next;
        }
        if (temp == NULL)
          return;
        del->Next = temp->Next;
        delete temp;  // Free memory
        temp = del->Next;
    }
}

template <class T>
int LinkedList<T>::Length(){
  Node<T>* temp = new Node<T>();
  temp = Head;
  int count=0;

  while(temp!=NULL){
    temp = temp->Next;
    count++;
  }
  return count;
}


template <class T>
bool LinkedList<T>::ElementExists(T data){
  Node<T>* temp = new Node<T>();
  Node<T>* del = new Node<T>();
  bool exists = false;

  if(Head->value==data){
    exists = true;
    return exists;
  }

  temp = Head;
  del = Head->Next;

  while (del!=NULL){
    if(temp->value==data){
      exists = true;
      return exists;
    }
    temp = del;
    del = del->Next;
  }
  return exists;
}

template <class T>
int LinkedList<T>::IndexOf(T data){
  Node<T>* temp = new Node<T>();
  temp = Head;
  int count=0;

  while(temp!=NULL){
    if (temp->value == data)
      return count;
    temp = temp->Next;
    count++;
  }
  return -1;
}

template <class T>
Node<T>* LinkedList<T>::Find(T data){
  Node<T>* temp = new Node<T>();
  temp = Head;

  while(temp!=NULL){
    if (temp->value == data)
      return temp;
    temp = temp->Next;
  }
  return NULL;
}

template <class T>
int LinkedList<T>::RetrieveFront(){
  if (Head!=NULL)
    return Head->value;
  else
    return 0;
}

template <class T>
int LinkedList<T>::RetrieveEnd(){
  Node<T>* temp = new Node<T>();
  int val;
  temp = Head;

  while (temp!=NULL){
    val = temp->value;
    temp = temp->Next;
  }
  return val;
}

template <class T>
T LinkedList<T>::Retrieve(T index){
  Node<T>* temp = new Node<T>();
  temp = Head;
  int i=0;
  while (temp!=NULL){
    if (i==index)
      return temp->value;
    temp=temp->Next;
    i++;
  }
  return -1;
}

template <class T>
int* LinkedList<T>::ToArray(T length){
  Node<T>* temp = new Node<T>();
  temp = Head;

  int i=0;
  int* array = new int[length];

  while (temp!=NULL){
    array[i] = temp->value;
    temp=temp->Next;
    i++;
  }

  return array;
}

template <class T>
void LinkedList<T>::Empty(){
  Node<T>* temp = new Node<T>();
  Node<T>* next = new Node<T>();
  temp = Head;

  while(temp!=NULL){
    next=temp->Next;
    free(temp);
    temp = next;
  }

  Head = NULL;
}

template <class T>
void LinkedList<T>::NextNode(){

  if (Current->Next!=NULL){
    Current = Current->Next;
  }
  else{
    Current = Head;
  }

}

template <class T>
void LinkedList<T>::InsertAfterCurrent(T data){
  Node<T>* newNode = new Node<T>(data);

  if (Current->Next==NULL){
    newNode->Next = NULL;
    Current->Next = newNode;
  }
  else{
    newNode->Next=Current->Next;
    Current->Next = newNode;
  }
}

template <class T>
int LinkedList<T>::RemoveFromEnd(){
  Node<T>* temp = new Node<T>();
  int val;
  temp = Head;

  if (Head==NULL)
    return -1;
  else if (Head->Next==NULL){
    val = Head->value;
    delete temp;
    Head = NULL;
  }
  else{
    Node<T>* temp2 = Head->Next;

    while (temp2->Next!=NULL){
      temp2 = temp2->Next;
      temp = temp->Next;
    }
    val = temp2->value;
    temp->Next = NULL;
    delete temp2;
  }
  return val;
}

template <class T>
int LinkedList<T>::RemoveFromFront(){
  Node<T>* temp = new Node<T>();
  int val;

  temp = Head;
  val = Head->value;
  Head = Head->Next;
  delete temp;
  return val;
}

template <class T>
int LinkedList<T>::RemoveCurrent(){
  Node<T>* temp = Head;

  int val = Current->value;

  if (temp==Current){
    Head = Head->Next;
    Current = Head;
    delete temp;
  }
  else{

    Node<T>* temp2 = Head->Next;

    while (temp2!=Current){
      temp = temp->Next;
      temp2 = temp2->Next;
    }
    if (temp2->Next!=NULL){
      temp->Next = temp2->Next;
      Current = Current->Next;
    }
    else{
      temp->Next = NULL;
      Current = Head;
    }

    delete temp2;
  }
  return val;
}

template <class T>
T LinkedList<T>::RemoveAtIndex(T index){
  Node<T>* temp = new Node<T>();
  Node<T>* temp2 = new Node<T>();

  int i=1,val;

  temp = Head;
  temp2 = Head->Next;
  if (index==0){
    val = Head->value;
    Head = Head->Next;
    delete temp;
    return val;
  }
  else{
    while (temp2!=NULL){
      if (i==index){
        temp->Next=temp2->Next;
        val = temp2->value;
        delete temp2;
        return val;
      }
      temp=temp->Next;
      temp2=temp2->Next;
      i++;
    }
  }
  return -1;
}
