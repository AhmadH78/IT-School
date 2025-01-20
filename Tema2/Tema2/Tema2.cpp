#include <iostream>
using namespace std;

int ex_1(int n) {

	for (int i = 2; i <= i / 2; i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

int ex_2(int a, int b) {

	int x = 1;

	for (int i = 2; i < a / 2 && i < b / 2; i++) {
		if (a % i == 0 && b % i == 0)
			x *= i;
	}
	return x;
	//stiu ca exercitiul e gresit am facut tot ce am stiut
}

int main() {

	int n, a, b;
	cin >> n;

	if (ex_1(n) == 1)
		cout << "Numarul este prim";
	else
		cout << "Numarul nu este prim";

	cin >> a >> b;
	cout << ex_2(a, b);

	//nu am inteles cerinta de la ex 3
	return 0;
}