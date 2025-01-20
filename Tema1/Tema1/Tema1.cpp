#include <iostream>
#include <string>
using namespace std;

void my_func_rezolvare_ex1_5() {

	int myNumber = 50;
	float myNumber1 = 75.5;

	myNumber++;
	myNumber1--;

	cout << myNumber << " " << myNumber1 << endl;

	int suma;
	float sumaReal;

	suma = myNumber + myNumber1;
	sumaReal = myNumber + myNumber1;

	cout << suma << " " << sumaReal << endl;

	suma *= 5;
	suma /= 12;

	sumaReal *= 5;
	sumaReal /= 12;

	float rest = sumaReal - suma;

	cout << rest << endl;
}

string my_func_rezolvare_ex6_9(string nume, string prenume) {
	string numeComplet = nume + prenume;

	string sirul_meu = "Acesta este continutul initial al sirului";
	cout << sirul_meu << endl;

	return numeComplet;
}

unsigned int my_func_rezolvare_10_1(unsigned int a, unsigned int b, unsigned int c) {
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

unsigned int my_func_rezolvare_10_2(unsigned int a, unsigned int b, unsigned int c) {
	//unsigned float nu e posibil
	return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

void my_func_rezolvare_12() {

	const float a = 23.6;
	//a *= 72 nu este posibil pentru ca a este o constanta
	cout << ((a < 1500.3) ? 1500.3 : a) << endl;
}

int my_func_rezolvare_13() {
	float y = 2379.8909, z = 11.4;
	//unsigned float nu e posibil

	int k = y / z;

	return k;

}

int main() {

	string nume = "Hammoud", prenume = "Ahmad";
	int a, b, c;

	my_func_rezolvare_ex1_5();

	my_func_rezolvare_ex6_9(nume, prenume);

	a = 7, b = 9, c = 3;
	my_func_rezolvare_10_1(a, b, c);

	a = 72.3, b = 1387.12344, c = 6;
	my_func_rezolvare_10_2(a, b, c);

	my_func_rezolvare_12();

	cout << my_func_rezolvare_13();

	//nu am stiut sa fac ex 15

	return 0;
}