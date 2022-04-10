#include<iostream>
using namespace std;
int fun(int x) {
	if (x > 20) {
		return 2 * x + fun(x / 5);
	}
	else if (x > 10) {
		return fun(x - 2) + fun(x - 3);
	}
	else if (x > 1) {
		return fun(x - 1) + fun(x - 2);
	}
	else if (x == 0) {
		return 1;
	}
	else if (x == 1) {
		return 5;
	}
	return -1;
}
int main() {
/*	int x6 = 12;
	int x5 = 0x000000000003fff;

	x5 = x5 >> 3;
	if (x5 >= 0) {
		x6 = 0 | -15;
	}
	x6 = x5 + x6;
	cout << x6;*/
	for (int i = 0; i <= 100; i++) {
		cout << "number:" << i;
		cout <<"; ans:"<< fun(i)<<endl;
	}
	
	system("PAUSE");
	return 0;
}