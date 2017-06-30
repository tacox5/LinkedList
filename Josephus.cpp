#include <iostream>
#include "Node.h"

using namespace std;
int main(){

  int people,i,count=1;
  int num,val;
  LinkedList<int> list(1);


  cout<<"\nEnter the number of people in the circle: ";
  cin>>people;

  for (i=1;i<people;i++){
    list.AddToEnd(i+1);
  }
  cout<<endl;
  list.PrintLinkedList();

  cout<<"\nEnter the number of people that will be skipped: ";
  cin>>num;

  cout<<endl;

  while (list.Length()>1){
    for (i=0;i<=num;i++){
      list.NextNode();
    }

    cout << "\nRound " << count << endl;
    cout << "\nEliminated: "<< list.RemoveCurrent() << endl;
    list.PrintLinkedList();
    cout << endl;
    count++;
  }
  cout<<endl;

}
