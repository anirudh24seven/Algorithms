#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int> inputElements) {
  vector<int> sortedList = inputElements;
  
  // Core of BubbleSort goes here
  int pointerToElementInSortedList,pointerToUnsortedElements;
  int numberOfElements = sortedList.size();
  
  for(pointerToElementInSortedList=0; pointerToElementInSortedList<numberOfElements; pointerToElementInSortedList++) {
    for (pointerToUnsortedElements=numberOfElements-1; pointerToUnsortedElements>pointerToElementInSortedList; pointerToUnsortedElements--) {
      if (sortedList[pointerToUnsortedElements] < sortedList[pointerToUnsortedElements-1]) {
        // Swap the elements
        int temp = sortedList[pointerToUnsortedElements];
        sortedList[pointerToUnsortedElements] = sortedList[pointerToUnsortedElements-1];
        sortedList[pointerToUnsortedElements-1] = temp;
      }
    }
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
  vector<int> outputElements = BubbleSort(inputElements);
  
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