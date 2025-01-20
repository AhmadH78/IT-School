#include <iostream>
using namespace std;


void ex1() {

	struct meteo {
		double temp[7];
	}sapt;

	cout << "Introduceti temperaturile: " << endl;
	for (int i = 0; i < 7; i++) {
		cout << "Ziua " << i + 1 << ": ";
		cin >> sapt.temp[i];
	}
	cout << endl;

	int maxi = sapt.temp[0];
	for (int i = 1; i < 7; i++) {
		if (sapt.temp[i] > maxi)
			maxi = sapt.temp[i];
	}

	cout << "Temperatura maxima inregistrata in data: " << endl;
	for (int i = 0; i < 7; i++) {
		if (sapt.temp[i] == maxi)
			cout << i + 1 << " cu o temperatura de: " << sapt.temp[i] << " grade" << endl;
	}
	cout << endl;
}

void ex2() {

	class Angajat {

	public:
		string nume;
	private:
		float salariu;
		int ore;

	public:
		Angajat() {}
		Angajat(string n, float s, int o) {
			nume = n;
			salariu = s;
			ore = o;
		}


		float getSalariu() {
			return salariu;
		}
		int getOre() {
			return ore;
		}


		void setSalariu(float s) {
			salariu = s;
		}
		void setOre(int o) {
			ore = o;
		}



		float calcSalariu() {
			return getOre() * getSalariu();
		}

		void display() {
			cout << "Numele angajatului este " << nume << " si are un salariu de " << getSalariu() << " pe ora si a facut " << calcSalariu() << " saptamana asta" << endl;
		}
	};

	Angajat angajat1("ion", 22.5, 40);
	angajat1.display();

	Angajat angajat2;
	angajat2.nume = "alex";
	angajat2.setSalariu(20);
	angajat2.setOre(50);
	angajat2.display();
}

int main() {

	ex1();
	ex2();

	return 0;
}