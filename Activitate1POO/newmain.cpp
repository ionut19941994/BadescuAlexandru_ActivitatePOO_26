
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//#include<fstream>

using namespace std;

class Produs {
private:
	int id;
	char* nume;
	float pret;
	int cantitate;

	static int contorID;

public:
	Produs() {
		this->id = ++contorID;
		this->nume = nullptr;
		this->pret = 0;
		this->cantitate = 0;
	}

	Produs(const char* nume, float pret, int cantitate) {
		this->id = ++contorID;
		this->pret = pret;
		this->cantitate = cantitate;

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}


	Produs(const Produs& p) {
		this->id = ++contorID;
		this->pret = p.pret;
		this->cantitate = p.cantitate;

		if (p.nume != nullptr) {
			this->nume = new char[strlen(p.nume) + 1];
			strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
		}
		else {
			this->nume = nullptr;
		}
	}

	Produs& operator=(const Produs& p) {
		if (this != &p) {
			if (this->nume != nullptr)
				delete[] this->nume;

			this->pret = p.pret;
			this->cantitate = p.cantitate;

			if (p.nume != nullptr) {
				this->nume = new char[strlen(p.nume) + 1];
				strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
			}
			else {
				this->nume = nullptr;
			}
		}
		return *this;
	}

	~Produs() {
		if (this->nume != nullptr)
			delete this->nume;
	}

	void afisareProdus() {
		cout << this->id << ". Produsul ";
		if (this->cantitate > 0) {
			if (this->nume != nullptr) {
				cout << this->nume;
				cout << " cu pretul " << this->pret;
				cout << " si in stoc: " << this->cantitate << endl;
			}
			else {
				cout << "nedefinit";
			}
		}
		else {
			cout << "nu este in stoc!" << endl;
		}
	}

	int getId() { return this->id; }
	float getPret() { return this->pret; }
	int getCantitate() { return this->cantitate; }
	char* getNume() { return this->nume; }

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
		else {
			throw exception("Pret invalid");
		}
	}

	void setCantitate(int cantitate) {
		if (cantitate > 0)
			this->cantitate = cantitate;
	}

	void setNume(const char* numeNou) {
		if (this->nume != nullptr)
			delete[] this->nume;

		this->nume = new char[strlen(this->nume) + 1];
		strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
	}

	friend ostream& operator<<(ostream& out, const Produs& p) {
		out << "nID: " << p.id;
		out << " nNume: " << (p.nume ? p.nume : "N/A");
		out << " nPret: " << p.pret;
		out << " nCantitate: " << p.cantitate;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Produs& p) {
		char buffer[50];

		cout << "Nume:"; in >> buffer;
		if (p.nume != nullptr)
			delete[] p.nume;
		p.nume = new char[strlen(buffer) + 1];
		strcpy_s(p.nume, strlen(buffer) + 1, buffer);

		cout << "Pret: ";
		in >> p.pret;

		cout << "cantitate: ";
		in >> p.cantitate;

		return in;
	}

	Produs operator+(const Produs& p) const {
		Produs copie(*this);
		copie.pret = this->pret + p.pret;
		return copie;
	}

	float valoareStoc() const {
		return this->pret * this->cantitate;
	}
};

int Produs::contorID = 0;

void main() {
	try {
		Produs p1("Laptop", 3500, 10);
		Produs p2;
		Produs p3 = p1;

		p1.afisareProdus();
		p2.afisareProdus();
		p3.afisareProdus();

		p2 = p3;
		p2.afisareProdus();

		Produs p4("pERDON", 500, 20);
		p4.afisareProdus();
		cout << p4.getNume() << ", " << p4.getPret() << ", " << p4.getCantitate() << endl;

		p4.setNume("Lustra");
		p4.setPret(200);
		p4.setCantitate(50);

		cout << p4.getNume() << ", " << p4.getPret() << ", " << p4.getCantitate() << endl;

		p4.afisareProdus();

		cout << p1 << endl;
		cout << p2 << endl;
		cout << p3 << endl;
		cout << p4 << endl;


		/*Produs p5;
		cin >> p5;
		cout << p5;*/

		Produs p6 = p1 + p2 + p3;
		cout << p6;

		cout << "valoare stoc p1 : " << p1.valoareStoc();

		p6.setPret(-75);
		cout << p6 << endl;;
	}
	catch (exception& e) {
		cout << "Eroare: " << e.what();
	}

}
