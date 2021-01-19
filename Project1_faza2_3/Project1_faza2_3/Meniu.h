//#include <iostream>
//#include <string>
//#include "MeniuV.h"
//#include "Film.h"
//
//using namespace std;
//
//class Meniu : public MeniuV
//{
//	Film* film;
//public:
//	Meniu(Film* film)
//	{
//		this->film = film;
//	}
//
//	~Meniu()
//	{
//		delete film;
//	}
//
//	void afisareMeniu()
//	{
//		cout << "1 Adauga cinema\n";
//		cout << "2 Modifica cinema\n";
//		cout << "3 Sterge cinema\n";
//		cout << "4 Adauga film\n";
//		cout << "5 Modifica film\n";
//		cout << "6 Sterge film\n";
//		cout << "0 Revenire la meniu";
//
//		alegereOptiune();
//	}
//	void alegereOptiune()
//	{
//		int ok = 0; char caracter;
//		afisareMeniu();
//		int n;
//		cout << "\nAlegeti optiunea: ";
//		cin >> n;
//		while (ok == 0) {
//			switch (n) {
//			case 1: {
//				cout << "Afisare lista cinema";
//				break;
//			}
//			case 2: {
//				cout << "\nCe cinema doriti sa adaugati? ";
//				break;
//			}
//			case 3: {
//				cout << "\nCe cinema doriti sa modificati? ";
//				break;
//			}
//			case 4: {
//				cout << "\nAfisare lista filme ";
//				break;
//			}
//			case 5: {
//				cout << "\nCe film doriti sa adaugati ";
//				break;
//			}
//			case 0: {
//				cout << "0 Revenire la meniul anterior" << endl;
//				cout << "Introduceti: ";
//				int rev;
//				cin >> rev;
//				if (rev == 0)
//					break;
//			}
//			default: {
//				cout << "introduceti un numar valid";
//				break;
//			}
//			
//		}
//		cout << "\nContinuati? (D/N) "; 
//		cin >> caracter; 
//		caracter = toupper(caracter);
//		if (caracter == 'N')
//			{
//				ok = 1;
//			}
//			else if (caracter == 'D')
//			{
//				cout << "\nAlegeti optiunea: ";
//				cin >> n;
//			}
//		}
//	}
//};