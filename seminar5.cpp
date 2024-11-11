#include <iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50.0;

		this->salarii = NULL;
	}

	Magazin(
		string oras,
		int nrAngajati,
		float suprafata,
		int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
		{
			this->salarii[i] = 2000 + i;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int numar, float* salarii) {
		if (numar > 0) {
			this->nrAngajati = numar;
			if (this->salarii != NULL) {
				delete this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafata) {
		if (suprafata) {
			this->suprafata = suprafata;
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Magazin operator+ (Magazin m2) const {
		Magazin temp = *this;	// constructor de copiere
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i+this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii) {
			delete[] temp.salarii;
		}

		temp.salarii = aux;


		
		return temp;
	}


	void afisare() {
		cout
			<< "Oras: "
			<< this->oras
			<< endl;
		cout
			<< "Angajati: "
			<< this->nrAngajati
			<< endl;
		cout
			<< "Suprafata: "
			<< this->suprafata
			<< endl;
		cout
			<< "An deschidere: "
			<< this->anDeschidere
			<< endl;
		cout
			<< endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati)
			return this->suprafata / this->nrAngajati;
		else return 0;
	}

	static void modificaImpozit(int impozitNou) {
		if (impozitNou > 0)
			Magazin::impozitM2 = impozitNou;
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++)
			suma += vector[i].suprafata;
		return suma;
	}

	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	~Magazin() {
		if (this->salarii) {
			delete[] this->salarii;
		}
	}


	Magazin operator = (const Magazin& m) {
		if (&m != this) {	// verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[] this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}

	Magazin& operator += (Magazin m) {
		*this = *this + m;
		return *this;
	}

	Magazin operator + (float salariu) const{
		Magazin temp = *this;
		if (temp.salarii) {
			delete[] temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < temp.nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;

	}
	


	friend Magazin operator+ (float salariu, Magazin m);

};

int Magazin::impozitM2 = 2;

Magazin operator+ (float salariu, Magazin m) {
	float valoare = m.nrAngajati;

	return m + salariu;
	
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

void main() {
	

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2019);

	int a = 9;
	int b = 6;
	int c = a + b;

	Magazin m3 = m1 + m2;
	Magazin m4 = m1.operator+(m2);

	Magazin m5 = m1 + 2000.0f;

	Magazin m6 = 3000.0f + m1; 

	m1 += m2; 