#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i, n;
	cin>>n;

	vector<int> input(n);
	vector<int> occurrence(1001);

	for(i=0; i<n; i++) {
		cin>>input[i];
		occurrence[input[i]]++;
	}
	
	bool yes = true;
	if(n%2==0) {
		for(i=1;i<=1000;i++) {
			if(occurrence[i]>(n/2)) {
				cout<<"NO"<<endl;
				yes = false;
				break;
			}
		}
	}
	else {
		for(i=1;i<=1000;i++) {
			if(occurrence[i]>((n/2)+1)) {
				cout<<"NO"<<endl;
				yes = false;
				break;
			}
		}
	}

	if(yes) {
		cout<<"YES"<<endl;
	}

	return 0;
}