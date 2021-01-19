#include<iostream>

using namespace std;

class Fastfood {
private:
	char* denumire;
	int nrMeniuri;
	float* preturi;
	bool renovat;
	const int id;
	static int nrLocuri;

public:
	Fastfood() :id(nrLocuri) {
		this->denumire = nullptr;
		this->nrMeniuri = 0;
		this->preturi = nullptr;
		this->renovat = false;
		nrLocuri++;
	}

	Fastfood(char* denumire, int nrMeniuri, float* preturi, bool renovat) :id(nrLocuri) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->nrMeniuri = nrMeniuri;
		this->preturi = new float[nrMeniuri];
		for (int i = 0; i < nrMeniuri; i++) {
			this->preturi[i] = preturi[i];
		}
		this->renovat = renovat;
		nrLocuri++;
	}

	~Fastfood() {
		if (denumire != nullptr) {
			delete[] denumire;
		}
		if (preturi != nullptr) {
			delete[] preturi;
		}
	}

	Fastfood(Fastfood& fast) :id(fast.nrLocuri) {
		this->denumire = new char[strlen(fast.denumire) + 1];
		strcpy_s(this->denumire, strlen(fast.denumire) + 1, fast.denumire);
		this->nrMeniuri = fast.nrMeniuri;
		this->preturi = new float[fast.nrMeniuri];
		for (int i = 0; i < fast.nrMeniuri; i++)
			this->preturi[i] = fast.preturi[i];
		this->renovat = fast.renovat;
		nrLocuri++;
	}

	Fastfood operator=(const Fastfood& fast) {
		if (denumire != nullptr) {
			delete[] denumire;
		}
		if (preturi != nullptr) {
			delete[] preturi;
		}
		this->denumire = new char[strlen(fast.denumire) + 1];
		strcpy_s(this->denumire, strlen(fast.denumire) + 1, fast.denumire);
		this->nrMeniuri = fast.nrMeniuri;
		this->preturi = new float[fast.nrMeniuri];
		for (int i = 0; i < fast.nrMeniuri; i++) {
			this->preturi[i] = fast.preturi[i];
		}
		this->renovat = fast.renovat;
		return *this;
	}

	int get_nrMeniuri() {
		return nrMeniuri;
	}

	void set_nrMeniuri(int nr) {
		if (nr > 1)
		{
			nrMeniuri = nr;
		}
		else
		{
			throw "Valoarea incorecta";
		}
	}

	char* get_nume() {
		return denumire;
	}
	void set_nume(char* valoare) {
		if (strlen(valoare) > 5) {
			if (denumire != nullptr)
				delete[]denumire;
			denumire = new char[strlen(valoare) + 1];
			strcpy_s(denumire, strlen(valoare) + 1, valoare);
		}
	}

	float* get_preturi() {
		return preturi;
	}
	const int get_id()
	{
		return id;
	}

	void set_preturi(float* vector, int _nrMeniuri) {
		if (_nrMeniuri > 1) {
			if (preturi)
				delete[]preturi;
			preturi = new float[_nrMeniuri];
			for (int i = 0; i < _nrMeniuri; i++) {
				preturi[i] = vector[i];
			}
			nrMeniuri = _nrMeniuri;
		}
	}

	float sumaPreturi() {
		float s = 0;
		for (int i = 0; i < this->nrMeniuri; i++)
			s += this->preturi[i];
		return s;
	}

	float operator()(int nr) {
		return nr * sumaPreturi();
	}
	float operator()() {
		return sumaPreturi();
	}

	Fastfood operator!() {
		Fastfood fast = *this;
		fast.renovat = !this->renovat;
		return fast;
	}

	float& operator[](int index) {
		if (index >= 0 && index < nrMeniuri)
			return preturi[index];
		else
			throw new exception("Depaseste numarul existent");
	}

	friend istream& operator >> (istream& in, Fastfood& fast)
	{
		char buffer[20];
		cout << "Denumire:";
		in >> buffer;
		if (fast.denumire)
			delete[]fast.denumire;
		fast.denumire = new char[strlen(buffer) + 1];
		strcpy_s(fast.denumire, strlen(buffer) + 1, buffer);
		cout << "Nr. meniuri:";
		in >> fast.nrMeniuri;
		cout << "Preturi:";
		if (fast.preturi)
			delete[]fast.preturi;
		fast.preturi = new float[fast.nrMeniuri];
		for (int i = 0; i < fast.nrMeniuri; i++) {
			in >> fast.preturi[i];
		}
		cout << "Este renovat? Da-1; Nu-0 ";
		in >> fast.renovat;
		return in;
	};

	friend ostream& operator<<(ostream& out, Fastfood fast) {
		out << "Denumire:" << fast.denumire << endl;
		out << "Nr meniuri:" << fast.nrMeniuri << endl;
		for (int i = 0; i < fast.nrMeniuri; i++) {
			out << fast.preturi[i] << endl;
		}
		out << "Renovat: " << fast.renovat << endl;
		return out;
	}
};
