#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<int> MergeSort(vector<int> elements, int firstPointer, int lastPointer);
vector<int> Merge (vector<int> firstPart, int firstPointer, int mid, int lastPointer);
vector<int> CreateVector (vector<int> elements, int firstPointer, int lastPointer);

vector<int> CallMergeSort(vector<int> inputElements) {
  vector<int> sortedList = MergeSort (inputElements, 0, inputElements.size()-1);
  return sortedList;
}

vector<int> MergeSort(vector<int> elements, int firstPointer, int lastPointer) {
  vector<int> sortedList;

  if (firstPointer < lastPointer) {
    int mid = (firstPointer + lastPointer)/2;

    vector<int> firstVector = MergeSort(elements, firstPointer, mid);
    vector<int> secondVector = MergeSort(elements, mid+1, lastPointer);

    for (int i=0; i<firstVector.size(); i++) {
      elements[firstPointer+i] = firstVector[i];
    }

    for (int j=0; j<secondVector.size(); j++) {
      elements[mid+1+j] = secondVector[j];
    }

    sortedList = Merge(elements, firstPointer, mid, lastPointer);
  }

  return sortedList;
}

vector<int> CreateVector (vector<int> elements, int firstPointer, int lastPointer) {

  vector<int> createdVector;
  int i;
  for(i = firstPointer; i<= lastPointer; i++) {
    createdVector.push_back(elements[i]);
  }

  return createdVector;
}

vector<int> Merge (vector<int> elements, int firstElement, int mid, int lastElement) {

  vector<int> firstPart = CreateVector(elements, firstElement, mid);
  vector<int> secondPart = CreateVector(elements, mid+1, lastElement);
  vector<int> sortedMergedList;

  firstPart.push_back(INT_MAX);
  secondPart.push_back(INT_MAX);

  int firstPointer, secondPointer;

  for (firstPointer = 0, secondPointer = 0; firstPointer<firstPart.size()-1 || secondPointer<secondPart.size()-1;) {
    int element1 = firstPart[firstPointer];
    int element2 = secondPart[secondPointer];
    if (element1<element2) {
      sortedMergedList.push_back(element1);
      firstPointer++;
    }
    else {
      sortedMergedList.push_back(element2);
      secondPointer++;
    }
  }

  return sortedMergedList;
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
  vector<int> outputElements = CallMergeSort(inputElements);

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
