#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int> inputElements) {
  vector<int> sortedList = inputElements;
  
  // Core of BubbleSort goes here
  int i,j;
  int numberOfElements = sortedList.size();
  
  for(i=0; i<numberOfElements; i++) {
    for (j=numberOfElements-1; j>i; j--) {
      if (sortedList[j] < sortedList[j-1]) {
        // Swap the elements
        int temp = sortedList[j];
        sortedList[j] = sortedList[j-1];
        sortedList[j-1] = temp;
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