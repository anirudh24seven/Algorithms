#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int constructSegmentTreeCore (int inputArray[], int startPosition, int endPosition, int* segmentTree, int currentNode);
int getSumWrapper (int *segmentTree, int segmentTreeSize, int a, int b);
int getSumCore (int *segmentTree, int startPosition, int endPosition, int a, int b, int index);
void updateSegmentTreeWrapper (int inputArray[], int *segmentTree, int segmentTreeSize, int k, int value);
void updateSegmentTreeCore(int *segmentTree, int startPosition, int endPosition, int k, int difference, int index);

int main() {
    int i, n;
    cin>>n;

    vector<int> inputVector (n);
    int* inputArray = new int[n];
    // Take input vector inputVector
    for(i=0; i<n; i++) {
	    cin>>inputArray[i];
    }

    //int* inputArray = &inputVector[0];
    int inputArraySize = n;
    // Construct segment tree out of it
    // Height max of segment tree is log2 (size)
    int height = (int)(ceil(log(inputArraySize)/log(2)));
    int level = height+1;

    // Size max of segment tree is sigma(1...height)(n) = 2^height - 1
    int maxSize = (int)pow(2,level) - 1;
    cout<<"Size: "<<maxSize<<endl;

    int *segmentTree = new int[maxSize];

    constructSegmentTreeCore (inputArray, 0, inputArraySize-1, segmentTree, 0);

    int segmentTreeSize = sizeof(segmentTree)/sizeof(segmentTree[0]);

    for (i=0; i<maxSize; i++) {	  
      cout<<segmentTree[i]<<" ";	  
    }
    cout<<endl;
    
    for(i=0; i<n; i++) {
      cout<<inputArray[i]<<" ";
    }
    cout<<endl;
    
    // Get the sum of elements in range a...b
    int a, b;
    cin>>a>>b;
    int sum = getSumWrapper(segmentTree, maxSize, a, b);
    cout<<"Sum: "<<sum<<endl;

    // Update a value k
    int k, value;
    cin>>k>>value;

    updateSegmentTreeWrapper(inputArray, segmentTree, n, k, value);

    // Get the sum of elements in range a...b
    cin>>a>>b;
    sum = getSumWrapper(segmentTree, maxSize, a, b);
    cout<<"Sum: "<<sum<<endl;
}

int constructSegmentTreeCore (int inputArray[], int startPosition, int endPosition, int* segmentTree, int currentNode) {
	// If startPosition and endPosition are same, they point to the same node. Store the necessary value in the current node of the segment tree and return.
	if (startPosition == endPosition) {
		segmentTree[currentNode] = inputArray[startPosition];
		return inputArray[startPosition];
	}

	// Recursively fill left and right subtrees and store sum in this node
	int middlePosition = startPosition + (endPosition-startPosition)/2;
	segmentTree[currentNode] = constructSegmentTreeCore(inputArray, startPosition, middlePosition-1, segmentTree, currentNode*2+1) + constructSegmentTreeCore(inputArray, middlePosition, endPosition, segmentTree, currentNode*2+2);
	
	return segmentTree[currentNode];
}

int getSumWrapper (int *segmentTree, int segmentTreeSize, int a, int b) {
	if (a<0 || b>segmentTreeSize-1 || a>b) {
	  cout<<a<<" "<<b<<" "<<segmentTreeSize;
	  cout<<"Invalid input"<<endl;
	  return -1;
	}
	
	return getSumCore(segmentTree, 0, segmentTreeSize-1, a, b, 0);
}

int getSumCore (int *segmentTree, int startPosition, int endPosition, int a, int b, int index) {
	if (a<=startPosition && b>=endPosition) {
	  return segmentTree[index];
	}
	
	if (a > endPosition || b < startPosition) {
	  return 0;
	}
	
	int middlePosition = startPosition + (endPosition-startPosition)/2;
	
	return getSumCore(segmentTree, startPosition, middlePosition-1, a, b, 2*index+1) + getSumCore(segmentTree, middlePosition, endPosition, a, b, 2*index+2);
}

void updateSegmentTreeWrapper (int inputArray[], int *segmentTree, int segmentTreeSize, int k, int value) {
	if (k<0 || k>segmentTreeSize-1) {
		cout<<"Invalid element";
		return;
	}

	// Find out how much to add to other nodes. This is the difference between new and old k values
	int difference = value - inputArray[k];

	// Update node k
	inputArray[k] = value;

	updateSegmentTreeCore(segmentTree, 0, segmentTreeSize-1, k, difference, 0);
}

void updateSegmentTreeCore(int *segmentTree, int startPosition, int endPosition, int k, int difference, int index) {
	if (k<startPosition || k>endPosition) {
		return;
	}

	segmentTree[index] = segmentTree[index] + difference;

	if(startPosition != endPosition) {
		int middlePosition = startPosition + (endPosition-startPosition)/2;
		updateSegmentTreeCore(segmentTree, startPosition, middlePosition-1, k, difference, 2*index+1);
		updateSegmentTreeCore(segmentTree, middlePosition, endPosition, k, difference, 2*index+2);
	}
}
