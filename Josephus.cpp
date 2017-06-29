#include <iostream>
#include "Node.h"

using namespace std;
int main(){

  int people,i,j;
  int num;
  LinkedList list(1);


  cout<<"Enter the number of people in the circle (3 or more): "<<endl;
  cin>>people;
  cout<<endl;

  for (i=1;i<people;i++){
    j = i+1;
    list.AddToEnd(j);
  }

  cout<<"Enter the number of people that will be skipped: "<<endl;
  cin>>num;

  list.PrintLinkedList();

  for (j=0;i<num;j++){
    cout<<&num<<endl;
    list.NextNode();
  }

  cout << "Person Killed Off: " << list.RemoveCurrent() << endl;

  list.PrintLinkedList();

}
