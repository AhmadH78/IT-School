#include <iostream>
#include <string>
using namespace std;

void ex1() {
	int n;
	cout << "Introdu numar de elemente: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Introdu elementele: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void ex2() {
	int n, fact = 1;
	int* pFact = &fact;
	cout << "Alege un numar pentru factorial: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		*pFact *= i;
	}

	cout << "Factorialiul numarului " << n << " este: " << *pFact << endl;
}

void ex3() {
	int v = 0, c = 0;
	int* pv = &v;
	int* pc = &c;

	string s;
	cout << "Introdu un string: ";
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			(*pv)++;
		else
			(*pc)++;
	}

	cout << "Numar de vocale: " << *pv << " si numar de consoane: " << *pc << endl;
}

void ex4() {
	int n, aux;
	cout << "Introdu numar de elemente: ";
	cin >> n;

	int* arr = new int[n];

	cout << "Introdu elementele: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

}

int main() {

	ex1();
	ex2();
	ex3();
	ex4();

	return 0;
}