/*
Nama : Difa Bagasputra M
NPM : 140810180057
Kelas : A
Tanggal : 26 Maret 2019
*/
#include <iostream>

using namespace std;

struct ElementList{
	char npm[14];
	char nama[40];
	float ipk;
	ElementList* next;
};
typedef ElementList* pointer;
typedef pointer list;

void createList(list& first){
	first=NULL;
}

void createElement(pointer& pBaru){
	pBaru=new ElementList;
	cout<<"Nama : ";cin.ignore();cin.getline(pBaru->nama,40);
	cout<<"NPM : ";cin>>pBaru->npm;
	cout<<"IPK : ";cin>>pBaru->ipk;
	pBaru->next=NULL;
}

void insertSortNpm(list& first, pointer pBaru){
	pointer last;
	if(first==NULL)
		first=pBaru;
	else{
		last=first;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal(list first){
	pointer pBantu;
	int i=1;
	if(first==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=first;
		while(pBantu!=NULL){
			cout<<i<<". "<<pBantu->npm<<" "<<pBantu->nama<<" "<<pBantu->ipk<<endl;
			pBantu=pBantu->next;
			i++;
		};
	}
	cout<<endl;
}

int main(){
	pointer p;
	list l;
	int n;
	
	cout<<"Banyak Data Mahasiswa : ";cin>>n;
	createList(l);
	for(int i=0; i<n; i++){
		cout<<"\nData Mahasiswa ke-"<<i+1<<endl;
		createElement(p);
		insertSortNpm(l,p);
	}
	traversal(l);
}
