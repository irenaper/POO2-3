#include <string>
#include<iostream>
#include<fstream>
#include<list>
#include "Bilet.h"
#include "FastFood.h"
#include "Spectacol.h"

using namespace std;
int Bilet::nrBilete = 0;
int Film::nrFilme = 0;
int Cinema::nrCinema = 0;
int Fastfood::nrLocuri = 1;

void main() {
	Cinema c1("Cinema 1", 1, new int{ 10 });
	Cinema c2("Cinema 2", 2, new int[2]{ 10,18 });
	//cin >> c1;
	cout << c1 << c2;

	ofstream out1("ListaCinema.txt");
	out1 << c1 << c2;
	out1.close();

	cout << "Afisare cinema din fisier txt" << endl;
	ifstream input("ListaCinema.txt");
	if (input.is_open()) {
		while (!input.eof()) {
			string linieFisier;
			char buffer[1000];
			input.getline(buffer, 1000);
			linieFisier = string(buffer);
			cout << "Linie fisier: " << linieFisier << endl;
		}
		input.close();
	}
	else {
		cout << endl << "Nu gasesc fisierul";
	}

	Cinema c3("Cinema 3", 3, new int[3]{ 30,30,30 });
	Cinema c4("Cinema 4", 4, new int[4]{ 40,40,40,40 });

	Film f1("Moon Light", 1, new int{ 10 }, 1, new Cinema{ c1 });
	Film f2("Little Sunshine", 2, new int[2]{ 20, 20 }, 1, new Cinema[2]{ c1, c2 });
	Film f3("SOlaris", 2, new int[3]{ 30,30,30 }, 1, new Cinema[2]{ c2,c3 });

	//CINEMA FISIERE
	ofstream fisBin("Cinema.bin", ios::out, ios::binary);
	if (fisBin.is_open()) {
		c1.scrieCinemaBinar(fisBin);
		c2.scrieCinemaBinar(fisBin);
		c3.scrieCinemaBinar(fisBin);
		fisBin.close();
	}

	ifstream fisBin2("Cinema.bin", ios::in, ios::binary);
	if (fisBin2.is_open()) {
		Cinema c1;
		c1.citireCinemaBinar(fisBin2);
		c2.citireCinemaBinar(fisBin2);
		c3.citireCinemaBinar(fisBin2);
		cout << "Citire filme din fisier binar " << endl;
		cout << c1 << c2 << c3;
		/*cout << c2;
		cout << c3;*/
		fisBin2.close();
	}
	else {
		cout << endl << "NU am deschis fisierul !";
	}

	//adaugare la un film
	//f1.adaugareCinema(&c2);//scrie si in binar in lista
	//f1.adaugareCinema(&c3);


	//FILME

	ofstream out2("ListaFilme.txt");
	out2 << f1 << f2;
	out2.close();

	/*cout << "afisare lista filme din fisier txt" << endl;
	ifstream in2("ListaFilme.txt");
	in2 >> f1 >> f2;
	in2.close();*/

	/*cout << "Afisare lista filme din fisier txt" << endl;
	ifstream in("ListaFilme.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			string linieFisier;
			char buffer[1000];
			in.getline(buffer, 1000);
			linieFisier = string(buffer);
			cout << "Linie fisier: " << linieFisier << endl;
		}
		in.close();
	}
	else {
		cout << endl << "Nu gasesc fisierul";
	}*/

	ofstream fisBin3("Filme.bin", ios::out, ios::binary);
	if (fisBin3.is_open()) {
		f1.scrieFilmBinar(fisBin3);
		f2.scrieFilmBinar(fisBin3);
		f3.scrieFilmBinar(fisBin3);
		fisBin3.close();
	}

	//ifstream fisBin4("Filme.bin", ios::in, ios::binary);
	//if (fisBin4.is_open()) {
	//	Cinema c1;
	//	f1.citireFilmBinar(fisBin4);
	//	f2.citireFilmBinar(fisBin4);
	//	f3.citireFilmBinar(fisBin4);
	//	cout << "Citire filme din fisier binar " << endl;
	//	cout << f1 << f2 << f3;
	//	/*cout << c2;
	//	cout << c3;*/
	//	fisBin4.close();
	//}
	//else {
	//	cout << endl << "NU am deschis fisierul !";
	//}

	//scriere in binar
	/*ofstream h("cinemas.bin");
	h << c1;
	h << c2;
	h.close();

	ifstream g("cinemas.bin");
	g >> c1;
	g >> c2;
	g.close();
	cout << endl << "Citire cu afisare cinema din binar" << endl;
	cout << c1;
	cout<< c2 << endl;*/

	//Cinema listaCinema[3]{ c1,c2 };	
	//f1.salvareFisierBinar("test.dat",listaCinema, 3 );
	//f2.salvareFisierBinar("test.dat", listaCinema, 3);
	//f3.salvareFisierBinar("test.dat",listaCinema, 3 );


	//BILETE


	//	Bilet b1,b2,b3;
	//	cin >> b1;
	//	cin >> b2;
	//	//cin >> b2;
	//	//cin >> b3;
	//
	//	int rev[2] = { 20,30 };
	//	int rev1[2] = { 30,40 };
	//	Film f1("Film1", 2, rev, 1, &b1);
	//	Film f2("Film2", 2,rev1,1, &b2);
	//
	//	cout << f1 << f2;
	//	//Film f3("Film3",2,rev1,1, &b3);
	//	//Film f4 = f1;
	//	cout << "---------------------------------" << endl;
	//
	//	Film listaFilme1[1] = { f1 };
	//	Cinema c1("Dacia", 1, new int{ 10 }, 1, listaFilme1);
	//	cout << c1;
	//
	//	Film listaFilme2[2]={ f1, f2 };//	
	//	Cinema c2("City Mall", 1, new int{ 20 }, 2, listaFilme2);
	//cout << c2;	//
	//	cout << c2.getlistaFilme()<< endl;
	///
	//	Film listaFilme[4] = { f1, f2, f3, f4 };
	//	Cinema c4("Vivo",4, listaFilme);
	//	cout << c2 << c3 << c4;
	//	cout << "-----------------------" << endl;
	//	
	//
	//	c2 += f3;
	//	cout << c2;
	//	c2 -= ("Film1");//eliminarea film cu numele dat
	//	cout << c2;
	//	//c1 += f2;
	//	//c1 += f3;*/
	//	//cout << c1 << endl;
	
	//
	//	//c2 += f2;
	
	//
	//	c2 -= ("Film1");//eliminarea film cu numele dat
	//	cout << c2;
	//
	//	c2 -= f2; //eliminare listaFilme din lista
	//	cout << c2 << endl;
	//


}