#pragma once
#include <string>

class Animal {
private:
	std::string specie;
	int cantitate;
	int pret;
	double procentVanzare;

public:
	Animal(const std::string specie, int cantitate, int pret, double procentVanzare);
	~Animal() {}

	std::string getSpecie() const;
	int getCantitate() const;
	int getPret() const;
	double getProcentVanzare() const;

	void setCantitate(int newCantitate);
	void setPret(int newPret);
	void setProcentVanzare(double newProcentVanzare);

	int estimareVanzare() const;
	int estimarePastrare() const;	
	void afisare() const;
	void afisareIstoric() const;
};