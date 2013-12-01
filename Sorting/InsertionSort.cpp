#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> inputElements) {
  vector<int> sortedList = inputElements;    
  
  // Core of InsertionSort goes here - Ascending sort
  int pointerToUnsortedElements, pointerToElementInSortedList;
  for (pointerToUnsortedElements = 1; pointerToUnsortedElements<sortedList.size(); pointerToUnsortedElements++) {
    int elementToBeInserted = sortedList[pointerToUnsortedElements];    
    
    for(pointerToElementInSortedList = pointerToUnsortedElements-1; pointerToElementInSortedList>=0; pointerToElementInSortedList--) {
      if (elementToBeInserted >= sortedList[pointerToElementInSortedList]) {
        break;
      }
      sortedList[pointerToElementInSortedList+1] = sortedList[pointerToElementInSortedList];
    }
    
    sortedList[pointerToElementInSortedList+1] = elementToBeInserted;
  }
  
  return sortedList;
}

vector<int> GetInputVector() {
  // Get the input
  int numberOfElements;
  cin>>numberOfElements;
  
  vector<int>inputElements(numberOfElements);
  
  for(int inputPointer = 0; inputPointer<numberOfElements; inputPointer++) {
    cin>>inputElements[inputPointer];
  }
  
  return inputElements;
}

void ShowOutput(vector<int> inputElements) {
  // Call algorithm
  vector<int> outputElements = InsertionSort(inputElements);
  
  // Print output here
  for(int outputPointer = 0; outputPointer<outputElements.size(); outputPointer++)
  {
    cout<<outputElements[outputPointer]<<" ";
  }
  cout<<endl;
}

int main() {  
  vector<int> inputElements = GetInputVector();
  
  ShowOutput(inputElements);
  
  return 0;
}