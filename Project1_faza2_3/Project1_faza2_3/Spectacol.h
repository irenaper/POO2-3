#include<iostream>

using namespace std;

class Spectacol {
private:
	char* nume;
	int nrReprez;
	float pret;
	bool* adulti;

	const int nrMese;
	static float TVA;
public:
	Spectacol() :nrMese(1) {
		this->nume = new char[strlen("Spectacol") + 1];
		strcpy_s(this->nume, strlen("Spectacol") + 1, "Spectacol");
		this->nrReprez = 0;
		this->pret = 0;
		this->adulti = nullptr;
	}

	Spectacol(const char* nume, int nrReprez, float pret, bool* adulti, int nrMese) :nrMese(10) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nrReprez = nrReprez;
		this->pret = pret;
		this->adulti = new bool[nrReprez];
		for (int i = 0; i < nrReprez; i++) {
			this->adulti[i] = adulti[i];
		}
	}

	Spectacol(Spectacol& sp) : nrMese(sp.nrMese) {
		this->nume = new char[strlen(sp.nume) + 1];
		strcpy_s(this->nume, strlen(sp.nume) + 1, sp.nume);
		this->pret = sp.pret;
		this->nrReprez = sp.nrReprez;
		this->adulti = new bool[sp.nrReprez];
		for (int i = 0; i < sp.nrReprez; i++) {
			this->adulti[i] = sp.adulti[i];
		}
	}

	~Spectacol() {
		delete[]nume;
		delete[]adulti;
	}

	Spectacol operator=(const Spectacol& sp) {
		if (this->nume != nullptr)
			delete[]this->nume;
		this->nume = new char[strlen(sp.nume) + 1];
		strcpy_s(this->nume, strlen(sp.nume) + 1, sp.nume);
		this->nrReprez = sp.nrReprez;
		this->pret = sp.pret;
		if (adulti)
			delete[]adulti;
		this->adulti = new bool[sp.nrReprez];
		for (int i = 0; i < sp.nrReprez; i++) {
			this->adulti[i] = sp.adulti[i];
		}
		return *this;
	}




	const char* getNume() {
		return nume;
	}

	void setNume(const char* numeN) {
		if (strlen(numeN) > 2) {
			if (nume != nullptr)
				delete[] nume;
			nume = new char[strlen(numeN) + 1];
			strcpy_s(nume, strlen(numeN) + 1, numeN);
		}
	}

	int getNrReprez() {
		return nrReprez;
	}

	void setNrReprez(int valoare) {
		if (valoare > 0)
		{
			nrReprez = valoare;
		}
		else
		{
			throw "Gresit";
		}
	}



	Spectacol operator+(Spectacol sp) {
		Spectacol copie = *this;
		copie.nrReprez = this->nrReprez + sp.nrReprez;
		if (pret < sp.pret) {
			copie.pret = sp.pret;
		}
		if (copie.adulti != nullptr)
			delete[]copie.adulti;
		copie.adulti = new bool[copie.nrReprez];
		for (int i = 0; i < this->nrReprez; i++) {
			copie.adulti[i] = this->adulti[i];
		}
		for (int i = this->nrReprez; i < copie.nrReprez; i++) {
			copie.adulti[i] = sp.adulti[i - this->nrReprez];
		}
		return copie;
	}

	Spectacol operator+(float valoare) {
		Spectacol copie = *this;
		copie.pret = this->pret + valoare;
		return copie;
	}

	int nrAdulti() {
		int s = 0;
		for (int i = 0; i < this->nrReprez; i++)
			s += this->adulti[i];
		return s;
	}

	bool operator==(Spectacol sp) {
		return this->nrAdulti() == sp.nrAdulti();
	}

	explicit operator float() {
		return this->pret;
	}

	Spectacol operator++() {
		this->pret += 30;
		return *this;
	}

	Spectacol operator++(int) {
		Spectacol copie = *this;
		this->pret += 50;
		return copie;
	}

	/*int& operator[](int index) {
		if (index >= 0 && index < this->nrReprez) {
			return adulti[index];
		}
		else
			throw new exception("index out of bounds");
	}*/

	Spectacol operator()(float valoare) {
		Spectacol copie = *this;
		copie.pret += valoare;
		return copie;
	}

	Spectacol operator()() {
		Spectacol copie = *this;
		copie.pret++;
		return copie;
	}

	Spectacol operator!() {
		Spectacol copie = *this;
		if (copie.pret > 20)
			copie.pret = 25;
		else
			copie.pret = 15;

		return copie;
	}

	static float getTVA() {
		return TVA;
	}

	static void setTaxa(float TVA1) {
		TVA = TVA1;
	}

	friend Spectacol operator+(float valoare, Spectacol sp) {
		Spectacol copie = sp;
		copie.pret = sp.pret + valoare;
		return copie;
	}

	friend ostream& operator<<(ostream& out, Spectacol sp) {
		out << sp.nume << endl;
		out << sp.nrReprez << endl;
		for (int i = 0; i < sp.getNrReprez(); i++)
		{
			out << sp.adulti[i] << endl;
		}
		return out;
	}

	friend istream& operator >> (istream& in, Spectacol& sp) {
		cout << "Numele: ";
		char buffer[20];
		in >> buffer;
		if (sp.nume)
			delete[]sp.nume;
		sp.nume = new char[strlen(buffer) + 1];
		strcpy_s(sp.nume, strlen(buffer) + 1, buffer);
		cout << "Pret: ";
		in >> sp.pret;
		cout << "Numar reprezentatii:";
		in >> sp.nrReprez;
		if (sp.adulti)
			delete[]sp.adulti;
		sp.adulti = new bool[sp.nrReprez];
		for (int i = 0; i < sp.nrReprez; i++) {
			cout << "Adult 1 - Da; 0 - NU";
			in >> sp.adulti[i];
		}
		return in;
	}
};