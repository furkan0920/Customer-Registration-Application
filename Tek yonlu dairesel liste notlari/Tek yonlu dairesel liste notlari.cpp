#include<iostream>
using namespace std;

struct node {
	int veri;
	node* next;
};
node* head = NULL;		//bas düğüm
void basaekle(int key) {
	node* eleman = new node;	//eleman oluştu
	eleman->veri = key;
	if (head == NULL)            //ilk elelman boşsa
	{
		head = eleman;           //eleman hem baş hem son elelman olcak
		head->next = head;
		cout << head->veri << "ilk kayit eklendi" << endl;
	}
	else {
		if (head->next == head) //tekdüğüm varsa
		{
			eleman->next = head;
			head->next = eleman;
			head = eleman;
			cout << head->veri << "kayit basa eklendi" << endl;
		}
		else    //listede birden fazla düğüm varsa
		{
			node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			eleman->next = head;
			head = eleman;
			temp->next = head;
			cout << head->veri << "kayit basa eklendi" << endl;
		}
	}
}
void sonaekle(int key) {
	node* eleman = new node;	//eleman oluştu
	eleman->veri = key;
	if (head == NULL)            //ilk elelman boşsa
	{
		head = eleman;           //eleman hem baş hem son elelman olcak
		head->next = head;
		cout << head->veri << "ilk kayit eklendi" << endl;
	}
	else {
		if (head->next == head) //tekdüğüm varsa
		{

			head->next = eleman;
			eleman->next = head;
			cout << head->veri << "kayit sona eklendi" << endl;
		}
		else    //listede birden fazla düğm varsa
		{
			node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = eleman;
			eleman->next = head;
			cout << eleman->veri << "kayit sona eklendi" << endl;
		}
	}
}
void yazdir()
{
	system("cls");

	node* temp = head;
	if (head == NULL)
		cout << "liste bos" << endl;
	else {
		while (temp->next != head) {
			cout << temp->veri << " ";
			temp = temp->next;
		}
		cout << temp->veri << " ";
	}
}
void arayaekle(int key, int sayi) {
	bool sonuc = false;
	node* eleman = new node;	//eleman oluştu
	eleman->veri = key;
	if (head == NULL)            //ilk elelman boşsa
	{
		head = eleman;           //eleman hem baş hem son elelman olcak
		head->next = head;
		cout << head->veri << " Listeye ilk kayit eklendi" << endl;
	}
	else {
		if (head->next == head) //tekdüğüm varsa
		{
			eleman->next = head;
			head->next = eleman;
			head = eleman;
			cout << head->veri << " kayit basa eklendi" << endl;
			sonuc = true;
		}
		else
		{
			node* temp = head;
			while (temp->next != head)
			{
				if (temp->next->veri == sayi) {
					node* temp2 = temp;
					node* temp3 = temp->next;
					temp2->next = eleman;
					eleman->next = temp3;
					cout << " araya elelman eklendi" << endl;
					sonuc = true;
					break;
				}
				temp = temp->next;
			}
		}
		if (!sonuc) {
			cout << "ekleme yapilmadi" << endl;
		}
	}
}
void bastanSil() {
	if (head == NULL) {
		cout << "liste bos,silinecek eleman yok" << endl;
	}
	else {
		if (head->next == head) //tekdüğüm varsa
		{
			delete head;
			head = NULL;
			cout << "Listede kalan son dugum silindi" << endl;
		}
		else {
			node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			node* temp2 = head->next;
			delete head;
			head = temp2;
			temp->next = head;
			cout << "bastaki eleman silindi" << endl;
		}
	}
}
void sondanSil() {
	if (head == NULL) {
		cout << "liste bos,silinecek eleman yok" << endl;
	}
	else {
		if (head->next == head) //tekdüğüm varsa
		{
			delete head;
			head = NULL;
			cout << "Listede kalan son dugum silindi" << endl;
		}
		else {
			node* temp = head;
			while (temp->next->next != head)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = head;
			cout << "sondaki dugum silindi" << endl;
		}
	}
}
void aradanSil(int key) {
	bool sonuc = false;
	if (head == NULL) {
		cout << "liste bos,silinecek eleman yok" << endl;
	}
	else {
		if (head->next == head && head->veri == key) //tekdüğüm varsa
		{
			delete head;
			head = NULL;
			cout << "Listede kalan son dugum silindi" << endl;
		}
		else {
			node* temp = head;
			while (temp->next != head)
			{
				if (temp->next->veri == key)
				{
					node* temp2 = temp;
					node* temp3 = temp->next->next;
					delete temp->next;
					temp2->next = temp3;
					cout << "aradaki dugum silindi" << endl;
					sonuc = true;
					break;
				}
				temp = temp->next;
			}
		}
		if (!sonuc)
			cout << key << " degerli dugum listede yoktur" << endl;
	}
}
int main() {
	int sayi, sayi2, secim;
	while (1)
	{
		cout << endl;
		cout << "TYDBL uygulamasi" << endl;
		cout << "1--Basa ekle" << endl;
		cout << "2--Sona ekle" << endl;
		cout << "3--Araya ekle" << endl;
		cout << "4--Bastan sil" << endl;
		cout << "5--Sondan sil" << endl;
		cout << "6--Aradan sil" << endl;
		cout << "7--Yazdir" << endl;
		cin >> secim;
		switch (secim)
		{
		case 1:cout << "basa eklenecek sayi: ";
			cin >> sayi;
			basaekle(sayi);
			break;
		case 2:cout << "sona eklenecek sayi: ";
			cin >> sayi;
			sonaekle(sayi);
			break;
		case 3:
			cout << "Araya eklenecek sayi: " << endl;
			cin >> sayi;
			cout << "hangi sayidan once eklensin" << endl;
			cin >> sayi2;
			arayaekle(sayi, sayi2);
			break;
		case 4:
			bastanSil();
			break;
		case 5:
			sondanSil();
			break;
		case 6:cout << "aradan silmek istediginiz deger:";
			cin >> sayi;
			aradanSil(sayi);
			break;
		case 7:
			yazdir();
			break;
		default:
			cout << "Lutfen seceneklerdeki numaralardaki sayilari giriniz!!!" << endl;
			break;
		}

	}

}
