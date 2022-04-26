#include<iostream>
using namespace std;

struct node {
	int id;
	string ad;
	string soyad;
	string adres;
	string urudnAd;
	int ucret;
	node* next;
};
node* head = NULL;

void ekle(int id, string ad, string soyad, string adres, string urudnAd, int ucret)
{
	system("cls");
	node* eleman = new node;
	eleman->id = id;
	eleman->ad = ad;
	eleman->soyad = soyad;
	eleman->adres = adres;
	eleman->urudnAd = urudnAd;
	eleman->ucret = ucret;

	if (head == NULL) {
		head = eleman;
		head->next = head;
		cout << id << " numarali musteri listeye ilk kayit olarak eklendi" << endl;
	}
	else if (head->next == head) {
		eleman->next = head;
		head = eleman;
		head->next->next = head;
		cout << id << " numarali musteri listeye eklendi" << endl;
	}
	else {
		node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		eleman->next = head;
		head = eleman;
		temp->next = head;
		cout << id << " numarali musteri listeye eklendi" << endl;
	}
}
void cikar(int id) {
	bool sonuc = false;
	system("cls");
	if (head == NULL) {
		cout << "Liste bos cikartilacak musteri yoktur" << endl;
		sonuc = true;
	}
	else if (head->next == head && head->id == id)
	{
		delete head;
		head = NULL;
		cout << id << " numarali son musteri listeden silindi" << endl;
		sonuc = true;
	}
	else {
		node* temp = head;
		while (temp->next != head)
		{
			if (temp->next->id == id) {
				node* temp2 = temp;
				node* temp3 = temp->next->next;
				delete temp->next;
				temp2->next = temp3;
				cout << id << " numarali musteri silindi" << endl;
				sonuc = true;
				break;
			}
			temp = temp->next;
		}
	}
	if (!sonuc)
		cout << id << " numarali musteri liste yoktur" << endl;
}
void ara(int id) {
	bool sonuc = false;
	system("cls");
	if (head == NULL) {
		cout << " liste bostur, her hangi bir musteri kaydi yoktur " << endl;
		bool sonuc = true;
	}
	else {
		node* temp = head;
		while (temp->next != head)
		{
			if (temp->id == id) {
				cout << id << " numarali musteri bilgileri" << endl;
				cout << "ad      :" << head->ad << endl;
				cout << "soyad   :" << head->soyad << endl;
				cout << "adres   :" << head->adres << endl;
				cout << "UrunAd  :" << head->urudnAd << endl;
				cout << "Ucret   :" << head->ucret << endl;
				break;
			}
			temp = temp->next;
		}
		if (!sonuc)
			cout << id << " numarali musteri liste yoktur" << endl;
	}
}
void yazdir()
{
	system("cls");
	if (head == NULL)
	{
		cout << " liste bostur, her hangi bir musteri kaydi yoktur " << endl;
	}
	else
	{
		node* temp = head;
		while (temp->next != head)
		{
			cout << temp->id << " numarali musteri bilgileri... \n";
			cout << "ad      :" << temp->ad << endl;
			cout << "soyad   :" << temp->soyad << endl;
			cout << "adres   :" << temp->adres << endl;
			cout << "UrunAd  :" << temp->urudnAd << endl;
			cout << "Ucret   :" << temp->ucret << endl;
			temp = temp->next;

		}
		cout << temp->id << " numarali musteri bilgileri...\n";
		cout << "ad      :" << temp->ad << endl;
		cout << "soyad   :" << temp->soyad << endl;
		cout << "adres   :" << temp->adres << endl;
		cout << "UrunAd  :" << temp->urudnAd << endl;
		cout << "Ucret   :" << temp->ucret << endl;
	}

}

int main() {
	int id, ucret, secim;
	string ad, soyad, adres, urunAd;
	while (1)
	{
		cout << endl;
		cout << "TYDABL Musteri Kayit Uygulamasi" << endl;
		cout << "1-- yeni kayit" << endl;
		cout << "2-- kayit sil" << endl;
		cout << "3-- kayit ara" << endl;
		cout << "4-- tum kayitlari getir" << endl;
		cout << "0-- CIKIS" << endl;
		cin >> secim;
		switch (secim)
		{
		case 1:
			cout << "Yeni kayit yapilacak musteri bilgileri : " << endl;
			cout << "id      :"; cin >> id;
			cout << "Ad      :"; cin >> ad;
			cout << "Soyad   :"; cin >> soyad;
			cout << "Adres   :"; cin >> adres;
			cout << "UrunAd  :"; cin >> urunAd;
			cout << "Ucret   :"; cin >> ucret;
			ekle(id, ad, soyad, adres, urunAd, ucret);
			break;
		case 2:
			cout << " Silinecek musteri id: "; cin >> id;
			cikar(id);
			break;
		case 3:
			cout << " Aranan musteri id:"; cin >> id;
			ara(id);
			break;
		case 4:
			yazdir();
			break;
		case 0:
			cout << "Programdan cikiliyor..." << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "Lutfen listede belirtilen secenek numaralarini giriniz" << endl;
			break;
		}

	}


}