#include<bits/stdc++.h>
using namespace std;

class SV{
	int msv;
	string ht, gt, qq, ns;
	public:
		SV();
		SV(int,string,int,string,string);
		friend ostream&operator<<(ostream &, SV);
		friend istream&operator>>(istream &, SV &);  

		int get_msv(){
			return msv;
		}
		void set_msv(int ma){
			msv = ma;
		}

		string get_ns(){
			return ns;
		}
		void set_ns(string date){
			ns = date;
		}

		string get_ten(){
			return ht;
		}
		void set_ten(string ten){
			ht = ten;
		}

		string get_gt(){
			return gt;
		}
		void set_gt(string gioitinh){
			gt = gioitinh;
		}

		string get_qq(){
			return qq;
		}
		void set_qq(string que){
			qq = que;
		}
};
SV::SV(){
	msv = 0;
	ht = ns = gt = qq = "";
}
SV::SV(int msv, string ten, int ns, string gt,string qq){
	this->msv = msv;
	this->ht = ten;
	this->gt = gt;
	this->ns = ns;
	this->qq = qq;
}
ostream &operator<<(ostream &os, SV a){
	os << setw(10) << left << a.msv << "|" << setw(10) << left << a.ht << "|" << setw(10) << left << a.ns << "|" << setw(7) << left << a.gt << "|" << setw(15) << left << a.qq <<endl;
	return os;
}
istream &operator>>(istream &is, SV &a){
	cout << "\nMSV: ";
	is >> a.msv;
	cin.ignore();
	cout << "Ten: ";
	getline(cin, a.ht);
	string date;
	while (true) {
        cout << "Ngay sinh(dd/mm/yyyy): ";
        cin >> date;
        if (date.length() == 10 && date[2] == '/' && date[5] == '/') {
            a.set_ns(date);
            break;
        } else {
            cout << "Dinh dang ngay sinh khong hop le! Vui long nhap lai: " << endl;
        }
    }
	cout << "Gioi tinh: ";
	is>>a.gt;
	cin.ignore();
	cout << "Que quan: ";
	getline(cin, a.qq);
	return is;
}

class Node {
public:
	SV data;
	Node* next;
	Node(){
		next=NULL;
		}
	Node(SV data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;
	public:
		Linkedlist() { head = NULL; }
		int dem();
		void insertFirst(SV);
		void insertLast(SV);
		void insertMiddle(SV,int);
		void deleteFirst();
		void deleteLast();
		void deleteMiddle(int);
		void printList();
		void searchbyid(int);
		void searchbyname(string);
		void editbyid(int);
};
int Linkedlist::dem(){
	int arc=1;
	if(head==NULL){
		return 0;
	}
	Node*tmp=head;
	while(tmp->next!=NULL){
		arc++;
		tmp=tmp->next;
	}
	return arc;
}

void Linkedlist::insertFirst(SV data){
	Node* tmp =new Node(data);
	if(head==NULL){
		head=tmp;
	}else{
		tmp->next=head;
		head=tmp;
	}
}
void Linkedlist::insertLast(SV data){
	Node* tmp =new Node(data);
	if(head==NULL){
		head=tmp;
	}
	Node* p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=tmp;
}
void Linkedlist::insertMiddle(SV data, int x){
	Node* tmp=new Node(data);
	if(head==NULL){
		head=tmp;
	}
	Node *p=head;
	for(int i=1;i<x-1;i++){
		p=p->next;
	}
	tmp->next=p->next;
	p->next=tmp;
}
void Linkedlist::deleteFirst(){
	if(head==NULL){
		return;
	}
	head=head->next;
}
void Linkedlist::deleteLast()
{
	Node* trc=new Node;
	Node* sau=new Node;
	if(head==NULL){
		return;
	}else{
		trc=NULL;sau=head;
		while(sau->next!=NULL){
			trc=sau;sau=sau->next;
		}
		if(trc==NULL){
			head=NULL;
		}
		else{
			trc->next=NULL;
		}
		
	}
}
void Linkedlist::deleteMiddle(int x){
	if(head==NULL){
		return;
	}
	Node* trc=NULL;
	Node* sau=head;
	for(int i=1;i<x;i++){
		trc=sau;
		sau=sau->next;
	}
	trc->next=sau->next;
}
		
	

void Linkedlist::printList()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
void Linkedlist::editbyid(int id)
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;

	}
	while (temp!=NULL)
	{
		if(temp->data.get_msv() == id){
			string ht, gt, qq, ns;
			cout<<"MSV: "<< temp ->data.get_msv()<<endl;
			cout<<"Ho Ten: ";cin>>ht;temp->data.set_ten(ht);
			while (true) {
				cout << "Ngay sinh(dd/mm/yyyy): ";
				cin >> ns;
				if (ns.length() == 10 && ns[2] == '/' && ns[5] == '/') {
					temp->data.set_ns(ns);
					break;
				} else {
					cout << "Dinh dang ngay sinh khong hop le! Vui long nhap lai: " << endl;
				}
			}
			cout<<"Gioi Tinh: ";cin>>gt;temp->data.set_gt(gt);
			cout<<"Que Quan: ";cin>>qq;temp->data.set_qq(qq);
			break;
		}else{
			cout<< "Not fint";
			return;
		}
	}
	
}
void Linkedlist::searchbyid(int id)
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}
	while (temp!=NULL)
	{
		if(temp->data.get_msv() == id){
			cout<<temp->data;
			break;
		}else{
			cout<< "Not fint";
			break;
		}
	}
}

void Linkedlist::searchbyname(string name)
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}
	while (temp!=NULL)
	{
		if(temp->data.get_ten() == name){
			cout<<temp->data;
			break;
		}else{
			cout<< "Not fint";
			break;
		}
	}
	
}

// Driver Code
int main()
{
	Linkedlist list;
	SV x,y,a;
	int i=1;
	while(i==1){
		cout<<"_____________________"<<endl;
		cout<<"0.Thoat."<<endl;
		cout<<"1.Chen 1 sv len dau."<<endl;
		cout<<"2.Chen 1 sv xuong cuoi."<<endl;
		cout<<"3.Chen 1 sv vi tri bat ki."<<endl;
		cout<<"4.Xoa 1 sv o dau."<<endl;
		cout<<"5.Xoa 1 sv o cuoi."<<endl;
		cout<<"6.Xoa 1 sv o vi tri giua."<<endl;
		cout<<"7.Sua thong tin 1 sv."<<endl;
		cout<<"8.Hien thi danh sach sv."<<endl;
		cout<<"9.Hien thi so sinh vien."<<endl;
		cout<<"10.Tim sinh vien theo MSV."<<endl;
		cout<<"11.Tim sinh vien theo ten."<<endl;
		cout<<"_____________________"<<endl;
		cout<<"Nhap lua chon(Chon xong nhan 2 lan Enter de tiep tuc chon): ";int ant;cin>>ant;
		switch(ant){
			case 0:cout<<"Cam on vi da su dung!";i=2;break;
			case 1:cout<<"Nhap thong tin sv can chen: ";cin>>x;list.insertFirst(x);system("pause");break;
			case 2:cout<<"Nhap thong tin sv can chen: ";cin>>y;list.insertLast(y);system("pause");break;
			case 3:cout<<"Nhap thong tin sv so can chen ";int b;cin>>a;cout<<"Nhap vi tri chen: ";cin>>b;list.insertMiddle(a,b);system("pause");break;
			case 4:list.deleteFirst();cout<<"Da xoa."<<endl;system("pause");break;
			case 5:list.deleteLast();cout<<"Da xoa."<<endl;system("pause");break;
			case 6:cout<<"Nhap vi tri can xoa: ";int z;cin>>z;list.deleteMiddle(z);cout<<"Da xoa."<<endl;system("pause");break;
			case 7:cout<<"Nhap MSV can sua: ";int m; cin>>m; list.editbyid(m); cout<<"Thanh cong."<<endl;system("pause");break;
			case 8:cout<<"Danh sach sv: "<<endl;
				cout<< setw(10) << left <<"Ma sinh vien |" << setw(10) << left <<"Ho ten |" << setw(10) << left <<"Ngay sinh |" << setw(7) << left <<"Gioi tinh |" << setw(15) << left << "Que quan" <<endl;
				list.printList();cout<<endl;system("pause");break;
			case 9:cout<<"So sinh vien co trong danh sach la: "<<list.dem()<<endl;system("pause");break;
			case 10:cout<<"Nhap MSV can tim: "; int ma; cin>>ma; list.searchbyid(ma);system("pause");break;
			case 11:cout<<"Nhap Ten SV can tim: "; string ten; cin>>ten; list.searchbyname(ten);system("pause");break;
		}
	}

}
