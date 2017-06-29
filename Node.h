#include <iostream>

using namespace std;

class Node{
  friend class LinkedList;
  private:
    int value;
    Node *Next;

  public:
    Node(void){
      Next = NULL;
    }
    Node(int val){
      value = val;
      Next = NULL;
    }
    Node(int val, Node* next){
      value = val;
      Next = next;
    }
    int getValue(void){
      return value;
    }

    Node* getNext(void){
      return Next;
    }
};

class LinkedList{
  private:
    Node *Head;
    Node *Current;

  public:
    LinkedList(void);
    LinkedList(int val);
    void AddToFront(int data);
    void AddToEnd(int data);
    void RemoveFirst(int data);
    void RemoveAll(int data);
    void AddAtIndex(int data, int index);
    void NextNode();
    void InsertAfterCurrent(int data);
    int RemoveCurrent();
    int RemoveAtIndex(int index);
    int RemoveFromFront();
    int RemoveFromEnd();
    bool ElementExists(int data);
    Node* Find(int data);
    int IndexOf(int data);
    int RetrieveFront();
    int RetrieveEnd();
    int Retrieve(int index);
    int* ToArray(int length);
    void Empty();
    int Length();
    ~LinkedList(void);

    void PrintLinkedList();
};

LinkedList::LinkedList()
{
    Head = NULL;
    Current = Head->Next;
}

LinkedList::LinkedList(int val)
{
    Head = new Node(val);
    Current = Head;
}

LinkedList::~LinkedList()
{
}

void LinkedList::PrintLinkedList()
{
    Node* temp = new Node();
    temp = Head;

    if (temp == NULL) {
        cout << "\nThe list is empty" << endl;
        return;
    }
    cout << "LinkedList: "<<endl;
    while (temp!=NULL) {
        cout << temp->value<<endl;
        temp = temp->Next;
    }
}

void LinkedList::AddToEnd(int data){
  Node* newNode = new Node();
  newNode->value=data;
  newNode->Next=NULL;

  if (Head == NULL){
    Head = newNode;
  }
  else{
    Node* temp = new Node();
    temp = Head;
    while(temp->Next!=NULL){
      temp = temp->Next;
    }
    newNode->Next = NULL;
    temp->Next = newNode;
  }
}

void LinkedList::AddToFront(int data){
  Node *newNode = new Node();
  newNode->value=data;
  newNode->Next=NULL;

  if (Head == NULL){
    Head = newNode;
  }

  else{
    Node *temp = new Node();

    temp = Head;
    Head = newNode;
    Head->Next = temp;
  }
}

void LinkedList::RemoveFirst(int data){
  Node* temp = new Node();
  Node* del = new Node();

  if(Head->value==data){
    del = Head;
    Head = del->Next;
    delete del;
    return;
  }

  temp = Head;
  del = Head->Next;

  while (del!=NULL){
    if(temp->value==data){
      temp->Next = del->Next;
      delete del;
      break;
    }
    temp = del;
    del = del->Next;
  }
}

void LinkedList::RemoveAll(int data){
    Node* temp = new Node();
    Node* del = new Node();
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

int LinkedList::Length(){
  Node* temp = new Node();
  temp = Head;
  int count=0;

  while(temp!=NULL){
    temp = temp->Next;
    count++;
  }
  return count;
}


bool LinkedList::ElementExists(int data){
  Node* temp = new Node();
  Node* del = new Node();
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

int LinkedList::IndexOf(int data){
  Node* temp = new Node();
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

Node* LinkedList::Find(int data){
  Node* temp = new Node();
  temp = Head;

  while(temp!=NULL){
    if (temp->value == data)
      return temp;
    temp = temp->Next;
  }
  return NULL;
}

int LinkedList::RetrieveFront(){
  if (Head!=NULL)
    return Head->value;
  else
    return 0;
}

int LinkedList::RetrieveEnd(){
  Node* temp = new Node();
  int val;
  temp = Head;

  while (temp!=NULL){
    val = temp->value;
    temp = temp->Next;
  }
  return val;
}

int LinkedList::Retrieve(int index){
  Node* temp = new Node();
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

int* LinkedList::ToArray(int length){
  Node* temp = new Node();
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

void LinkedList::Empty(){
  Node* temp = new Node();
  Node* next = new Node();
  temp = Head;

  while(temp!=NULL){
    next=temp->Next;
    free(temp);
    temp = next;
  }

  Head = NULL;
}

void LinkedList::NextNode(){
  if (Current->Next!=NULL){
    Current = Current->Next;
  }
  else{
    Current = Head;
  }
}

void LinkedList::InsertAfterCurrent(int data){
  Node* newNode = new Node(data);

  if (Current->Next==NULL){
    newNode->Next = NULL;
    Current->Next = newNode;
  }
  else{
    newNode->Next=Current->Next;
    Current->Next = newNode;
  }
}

int LinkedList::RemoveFromEnd(){
  Node* temp = new Node();
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
    Node* temp2 = Head->Next;

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

int LinkedList::RemoveFromFront(){
  Node* temp = new Node();
  int val;

  temp = Head;
  val = Head->value;
  Head = Head->Next;
  delete temp;
  return val;
}

int LinkedList::RemoveCurrent(){
  Node* temp = new Node();
  Node* temp2 = new Node();

  int val;

  temp = Head;
  temp2 = Head->Next;

  while (temp2!=Current){
    temp = temp->Next;
  }

  val = temp2->value;
  temp->Next = temp2->Next;
  Current = Current->Next;

  delete temp2;
  return val;
}

int LinkedList::RemoveAtIndex(int index){
  Node* temp = new Node();
  Node* temp2 = new Node();
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
