#include<iostream>
#include<string>
using namespace std;

struct student{
	string imie;
	string nazwisko;
	long int indeks;
	student*next;

	student(string imie, string nazwisko, long int indeks){
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->indeks = indeks;
		this->next = nullptr;
	}
};

void dodawanie_na_liste(student*&head, string imie, string nazwisko, long int indeks){
	if (head==nullptr) head = new student(imie, nazwisko, indeks);
	else {
		student *temp = head;
		while (temp->next !=nullptr){
			temp = temp->next;
		}
		temp->next = new student(imie, nazwisko, indeks);
		}
}

void wyszukiwanie_po_indeksie(student*&head, long int indeks){
	student*temp = head;
	if (temp->indeks == indeks&& head !=nullptr) cout<<temp;
	else wyszukiwanie_po_indeksie(temp->next, indeks);
}

void usuwanie_z_listy(student*&head, long int indeks){
	student*temp = head;
	student*d = nullptr;
	wyszukiwanie_po_indeksie(temp, indeks);
	while (temp->indeks != indeks){
		temp = temp->next;
	}
	d = temp->next;
	delete(temp);
	temp--;
	temp = d;
	
}

void wyswietl(student*&head){
	if (head==nullptr)cout << "Lista jest pusta";
	else{
		student*temp = head;
		cout << "Imie: " << temp->imie << "Nazwisko: " << temp->nazwisko << "Indeks: " << temp->indeks << endl << endl;
		while (temp->next !=nullptr){
			cout << "Imie: "<<temp->imie <<" Nazwisko: "<<temp->nazwisko<<" Indeks: "<<temp->indeks<< endl << endl;
			temp = temp->next;
		}
	}
}
int main() {
	student*head=nullptr;
	dodawanie_na_liste(head, "Agnieszka", "Gregulec", 126897);
	dodawanie_na_liste(head, "Bartosz", "Michta", 126905);
	dodawanie_na_liste(head, "Hubert", "Krzepkowski", 126895);
	wyswietl(head);
	usuwanie_z_listy(head, 126905);
	wyswietl(head);
}