#include <iostream>
#include "Node.h"

using namespace std;
int main(){

  int people,i; // Number of people in a circle and loop variable
  int num,count=1; // Variables for the number of people skipped and current round count
  LinkedList<int> list(1); // Initialize a LinkedList object


  // Prompt the user for number of people in the circle
  cout<<"\nEnter the number of people in the circle: ";
  cin>>people;

  for (i=1;i<people;i++){
    list.AddToEnd(i+1); // Add numbers to the list
  }
  cout<<endl;
  list.PrintLinkedList(); // Display the list created


  // Prompt the user for the number of people skipped
  cout<<"\nEnter the number of people that will be skipped: ";
  cin>>num;

  cout<<endl;

  // While loop that goes until there is only one node left in the list
  while (list.Length()>1){

    for (i=0;i<=num;i++){
      list.NextNode(); // Move the number of nodes equal to the skip value
    }

    cout << "\nRound " << count << endl; // Display the round
    cout << "\nEliminated: "<< list.RemoveCurrent() << endl; // Output the node removed
    list.PrintLinkedList(); // Print the remaining list
    cout << endl;
    count++; // Increase the count
  }
  cout<<endl;

}
