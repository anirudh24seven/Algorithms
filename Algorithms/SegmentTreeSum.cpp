#include <iostream>
#include <vector>
using namespace std;

int *constructSegmentTree (vector<int> inputVector);
int getSum (int *segmentTree, int segmentTreeSize, int a, int b);
void updateSegmentTree (int *segmentTree, int segmentTreeSize, vector<int> inputVector, int k, int value);

int main() {
	int i, n;
	cin>>n;

	vector<int> inputVector (n);

	// Take input vector inputVector
	for(i=0; i<n; i++) {
		cin>>inputVector[i];
	}

	// Construct segment tree out of it
	int *segmentTree = constructSegmentTree(inputVector);
	int segmentTreeSize = sizeof(segmentTree)/sizeof(segmentTree[0]); 

	// Get the sum of elements in range a...b
	int a, b;
	cin>>a>>b;
	int sum = getSum(segmentTree, segmentTreeSize, a, b);
	cout<<"Sum: "<<sum<<endl;

	// Update a value k
	int k, value;
	cin>>k>>value;

	updateSegmentTree(segmentTree, segmentTreeSize, inputVector, k, value);

	// Get the sum of elements in range a...b
	cin>>a>>b;
	sum = getSum(segmentTree, segmentTreeSize, a, b);
	cout<<"Sum: "<<sum<<endl;
}


int *constructSegmentTree (vector<int> inputVector) {

}

int getSum (int *segmentTree, int segmentTreeSize, int a, int b) {

}

void updateSegmentTree (int *segmentTree, int segmentTreeSize, vector<int> inputVector, int k, int value) {

}