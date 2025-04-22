#pragma once
#include <string>

class Cereale
{
private:
	std::string tip;
	double cantitate;
	int pret;
	double procentVanzare;

public:
	Cereale(const std::string tip, double cantitate, int pret, double procentVanzare);
	~Cereale() {}

	std::string getTip() const;
	double getCantitate() const;
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