#include "Console.h"
#include <iostream>
using namespace std;
void Console::meniu() {
	cout << "***CHELTUIELI DE FAMILIE*** \n";
	cout << "a. Adauga o cheltuiala  \n";
	cout << "b. Modifica o cheltuiala existenta \n";
	cout << "c. Stabilirea cheltuielilor cu anumite proprietati \n";
	cout << "d. Obtinerea unor proprietati a diferitelor subliste \n";
	cout << "e. Filtrarea listei de cheltuieli \n"; 
	cout << "f. Afisare cheltuieli adaugate \n";
	cout << "g. Afisare buget \n";
	cout << "x. Exit! \n";
}

int Console::console() {


	while (true)
	{
		meniu();
		char op = read_op();

		if (op == 'a') {

			cout << "1. Ex. Adauga 10 internet - adauga pentru ziua curenta o cheltuiala de 10 RON pentru internet \n";
			cout << "2. Ex. Insereaza 25 100 mancare - insereaza pentru ziua 25 a lunii curente o cheltuiala de 100 RON pentru mancare \n";


			char op2 = read_op();

			if (op2 == '1')
			{
				this->adaugare_fara_zi();
			}
			else if (op2 == '2')
			{
				this->adaugare_cu_zi();
			}
		}
		else if (op == 'b') {

			cout << "1. Ex. Elimina 15 - elimina toate cheltuielile din ziua 15 \n";
			cout << "2. Ex. Elimină 2 la 9 - elimină toate cheltuielile pentru zilele 2,3, ..., 9 \n";
			cout<< "3. Ex. Elimina mancare - elimina totate cheltuielile pentru mancare din luna curenta. \n";
			
			char op2 = read_op();

			if (op2 == '1')
			{
				this->sterge_cheltuiala();
			}
			else if (op2 == '2')
			{
				this->sterge_cheltuiala_intre_zile();
			}
			else if (op2 == '3')
			{
				this->sterge_dupa_tip();
			}
		}
		else if (op == 'c')
		{
			
			cout << "1. Ex. Listeaza mancare - afisarea tuturor cheltuielilor pentru mancare ";
			cout << "2. Ex. Listeaza mancare > 5 - afisarea tuturor cheltuielilor pentru mancare mai mari de 5 RON \n";
			cout << "3. Ex. Listeaza internet = 44 - afisarea tuturor cheltuielilor pentru internet in valoare de 44 RON \n";
			
			char op2 = read_op();

			if (op2 == '1')
			{
				this->show_cheltuiala_by_type();
			}
			else if (op2 == '2')
			{
				this->show_cheltuiala_by_type_and_cond();
			}
			else if (op2 == '3')
			{
				this->show_cheltuiala_by_type_and_cond_eq();
			}
		}
		else if (op == 'd') {
			
			cout << "1. Ex. Suma mancare - suma tuturor cheltuielilor din categoria mancare \n";
			cout << "2. Ex. Max zi - afisarea zilei cu cele mai mari cheltuieli \n";
			cout << "3. Ex. Sortare zi - afisarea sumelor cheltuite zilnic in ordine descrescatoare \n";
			cout << "4. Ex. Sorteaza mancare - afisarea sumelor cheltuite zilnic pentru mancare, ordonate crescator \n";
			
			
			char op2 = read_op();
			
			if (op2 == '1')
			{
				this->max_suma_tip();
			}
			else if (op2 == '2')
			{
				this->max_zi();
			}
			else if (op2 == '3')
			{
				this->suma_ord_desc();
			}
			else if (op2 == '4')
			{
				this->suma_tip_cresc();
			}
		}
		else if (op == 'e') {

			cout << "1. Ex. Filtrare mancare - pastreaza doar cheltuielile pentru mancare \n";
			cout << "2. Ex. Filtrare menaj < 100 - pastreaza doar cheltuielile pentru menaj mai mici decat 100 RON \n";
			cout << "3. Ex. Filtrare haine = 59 - pastreaza doar cheltuielile pentru haine egale cu 59 RON  \n";

			char op2 = read_op();

			if (op2 == '1') {
				this->filtrare_tip();
			}
			else if (op2 == '2') {
				this->filtrare_tip_cond();
			}
				

			else if (op2 == '3')
			{
				this->filtrare_tip_cond2();
			}

		}
		else if (op == 'f') {
			this->show_cheltuieli_familie();
		}
		else if (op == 'x')
			return 0;
		else if (op == 'g')
		{
			cout << this->service_cheltuieli.getBuget()<<"\n";
		}
	}
}

int Console::read_int() {
	cout << "Alege un numar: ";
	int a;
	cin >> a;
	return a;
}

char Console::read_op() {
	cout << "Alege o optiune: ";
	char a;
	cin >> a;
	return a;
}

char* Console::read_p_char()
{
	cout << "Scrie un cuvant: ";
	char b[100];
	cin >> b;
	char* a = new char[strlen(b) + 1];
	strcpy_s(a, strlen(b) + 1, b);
	return a;
}



void Console::show_cheltuieli_familie()
{
	int size = this->service_cheltuieli.getSizeRepo();
	Cheltuieli* cheltuieli = this->service_cheltuieli.getAll();
	for (int i = 0; i < size; i++) {
		cout << cheltuieli[i];

	}
}

void Console::adaugare_fara_zi() {
	int suma_bani = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.adaugare_cheltuiala_zi(suma_bani, tip);
}

void Console::adaugare_cu_zi() {
	int zi = read_int();
	int suma_bani = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.adaugare_cheltuiala(zi,suma_bani, tip);
}

void Console::sterge_cheltuiala() {
	int zi = read_int();

	this->service_cheltuieli.stergere_cu_zi(zi);
}

void Console::sterge_cheltuiala_intre_zile(){
	int zi_1 = read_int();
	int zi_2 = read_int();

	this->service_cheltuieli.stergere_interval(zi_1,zi_2);
}

void Console::sterge_dupa_tip() {
	char* tip = read_p_char();
	this->service_cheltuieli.stergere_tip(tip);
}

void Console::show_by_len(int n, Cheltuieli cheltuieli[]) {
	for (int i = 0; i < n; i++) {
		cout << cheltuieli[i];
		cout << "\n";
	}
}

void Console::show_cheltuiala_by_type() {
	char* tip = read_p_char();

	Cheltuieli de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByType(tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);

}

void Console::show_cheltuiala_by_type_and_cond() {
	char* tip = read_p_char();
	int nr = read_int();
	Cheltuieli de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByCondAndType(nr,tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);

}

void Console::show_cheltuiala_by_type_and_cond_eq() {
	char* tip = read_p_char();
	int nr = read_int();
	
	Cheltuieli de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.getElemByCond2AndType(nr, tip, de_afisat, resultlen);
	this->show_by_len(resultlen, de_afisat);

}

void Console::max_suma_tip() {
	char* tip = read_p_char();
	int sum = this->service_cheltuieli.suma_elem_tip(tip);

	cout << " Suma tuturor cheltuielilor din categoria " << tip << " este " << sum<< "\n";
}

void Console::max_zi() {
	int day = this->service_cheltuieli.max_zi_suma();

	cout << " Ziua cu cele mai mari cheltuieli este: " << day << "\n";

}

void Console::suma_ord_desc() {
	Cheltuieli de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.sortare_suma_desc(de_afisat, resultlen);
	
	for (int i = 0; i < resultlen; i++) {
		cout << de_afisat[i].getSumaBani() << " ";
	}

	cout << "\n";

}

void Console::suma_tip_cresc() {

	char* tip = read_p_char();
	Cheltuieli de_afisat[30];
	int resultlen = 0;
	this->service_cheltuieli.sortare_suma_tip(tip, de_afisat, resultlen);

	for (int i = 0; i < resultlen; i++) {
		cout << de_afisat[i].getSumaBani() << " ";
	}

	cout << "\n";

}


void Console::filtrare_tip() {
	char* tip = read_p_char();

	this->service_cheltuieli.filtrare_tip(tip);
}

void Console::filtrare_tip_cond() {
	int nr = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.filtrare_tip_cond(nr, tip);
}

void Console::filtrare_tip_cond2() {
	int nr = read_int();
	char* tip = read_p_char();

	this->service_cheltuieli.filtrare_tip_cond2(nr, tip);
}