#include <iostream>
#include <list>
#include <cstring>
#include <vector>
using namespace std;


void ex1() {
	list<string> fructe = { "mere", "pere", "banane" };
}

//ex2 unsigned int nu poate avea numere negative dar poate contine numere mai mari ca un int

//ex3 last = v[n-1], n fiind numarul de elemente din vector

void ex5(list<int> a) {

}

//ex7 getline(cin, a)

//ex8 [a,b,c,...,y,z,A,B,C,...,Y,Z]

/*ex9 nu este corect
* int* r = new int(3);
* cout << *r << endl;
* delete r;
*/

//ex10 -1 1

/*ex11 
* void printChar(char c){
*   cout<< c << endl;
* }
* 
* int main(){
*   printChar('3');
*   printChar('+');
*   printChar('2');
*   printChar('=');
*   printChar('5');
* 
*   return 0;
* }
*/

/*ex12
*int a = 0;
*{
*	int* b = new int(7);
*	a = *b;
*	delete b;
*}
*cout << “Numarul magic este : “ << a << endl;
*/

int ex13(int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) 
		s += arr[i];
	return s;
}

/*ex14 
*Un pointer pointeaza spre o variabila si contine adresa in memorie a acestie si daca valorea variabilei se schimba.
*O referinta pointeaza spre aceasi variabila si ocupa aceasi adresa in memorie. Daca se schimba valoarea variabilei se schimba si referinta si invers.
*/

void ex15() {
	int ok = 1;
	char s[20];
	cout << "Introduce un cuvant: ";
	cin >> s;

	if (strlen(s) % 2 == 0)
		cout << "Cuvantul nu poate fi palindrom" << endl;
	else{
		for (int i = 0; i < strlen(s)/2 && ok==1; i++) {
			if (s[i] != s[strlen(s) - 1 - i])
				ok = 0;
		}

		if (ok == 1)
			cout << "Este palindrom";
		else
			cout << "Nu este palindrom";
	}
}

//ex16 double, float
//ex17 unsigned int nu poate avea numere negative dar poate contine numere mai mari ca un int
//ex18 last = v[n-1], n fiind numarul de elemente din vector

//ex21 char si double sunt ambele folosite pentru a memora siruri de caractere si ambele pot folosii functiile din biblioteca cstring.
//ex22 initializam variabila si dupa folosim cin sa citim 

//ex24 linia "int &r = 4;" este gresita fiind ca u referinta nu poate pointa spre o valoare ci doar o variabila. Putem sa declaram o variabila b = 4 si  &r= b
//ex25 este corect fiind ca b nu primeste nici o valoare. Ca sa primeasca b o valoare din functia foo trebuie sa declaram a ca referinta

/*ex26
*vector<int> str;
*str.push_back(1);
*str.push_back(2);
*str.push_back(3);
*/

//ex27 trebuie dereferetiata variabila a

int main()
{
	list<int> lista = { 1, 2, 3, 4 };
	ex5(lista);

	const int n = 5;
	int v[n] = { 1,2,3,4,5 };
	cout<<ex13(v, n);
    
	ex15();

	return 0;
}
