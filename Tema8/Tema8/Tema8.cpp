#include <iostream>

using namespace std;


//ex1
class Cutie {
private:
	int lungime, latime, inaltime;

public:
	Cutie(int lungime, int latime, int inaltime) : lungime(lungime), latime(latime), inaltime(inaltime){}

	void afis() const{
		cout << "Dimensiuni cutie: Lungime: " << lungime << "; Latime: " << latime << ": Inaltime: " << inaltime << endl;
	}

	friend class Operatii;
};

class Operatii {
public:
	static void calcVolum(Cutie& c) {
		int volum = c.lungime * c.latime * c.inaltime;
		cout << "Volumul cutiei este: " << volum << endl;
	}

	static void modify(Cutie& c, int l, int w, int h) {
		c.lungime = l;
		c.latime = w;
		c.inaltime = h;
	}
};

int main() {

	Cutie cutieMica(2, 3, 4);
	Operatii::calcVolum(cutieMica);
	Operatii::modify(cutieMica, 4, 5, 6);
	cutieMica.afis();

	return 0;
}



//ex2
class Persoana{
private:
	int varsta;
	string nume;

public:
	Persoana(int varsta, string nume):varsta(varsta), nume(nume){}

	void afis() {
		cout << "Nume: " << nume << ", varsta: " << varsta << endl;
	}

};

class Angajat : public Persoana {
private:
	string functie, job;

public:
	Angajat(int varsta, string nume, string functie, string job) : Persoana(varsta, nume), functie(functie), job(job) {}

	void afisAngajat() {
		cout << "Functie: " << functie << " la jobul: " << job;
	}
};

int main() {

	Angajat angajat(32, "Andrei", "Manager", "Companie");
	angajat.afis();
	angajat.afisAngajat();

	return 0;
}