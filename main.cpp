#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct Student {
	string id, name, className, birthday;
	double gpa;

	void detail() {
		cout << "| " 
			<< setfill(' ') << left << setw(4) << id << " | " 
			<< setfill(' ') << left << setw(20) << name << " | " 
			<< setfill(' ') << left << setw(20) << className << " | " 
			<< setfill(' ') << left << setw(20) << birthday << " | " 
			<< setfill(' ') << left << setw(5) << fixed << setprecision(2) << gpa << " |" 
			<< endl;

		cout << "|" 
			<< setfill('-') << left << setw(6) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
	}

	void input() {
		cout << "Nhap ma sinh vien: ";
		cin >> id;
		cout << "Nhap ten sinh vien: ";
		cin.ignore();
		getline(cin, name);
		cout << "Nhap lop: "; cin >> className;
		cout << "Nhap ngay sinh: ";
		cin >> birthday;
		cout << "GPA: ";
		cin >> gpa;
	}
};

void listHeader() {
	cout << "|" 
			<< setfill('-') << left << setw(6) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
		
	cout << "| " 
		<< setfill(' ') << left << setw(4) << "ID" << " | " 
		<< setfill(' ') << left << setw(20) << "Name" << " | " 
		<< setfill(' ') << left << setw(20) << "ClassName" << " | " 
		<< setfill(' ') << left << setw(20) << "Birthday" << " | " 
		<< setfill(' ') << left << setw(5) << "GPA" << " |" 
		<< endl;
		
	cout << "|" 
			<< setfill('-') << left << setw(6) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
}

void listStudent(Student a[], int n) {
	cout << "Thong tin danh sach sinh vien:\n";
	listHeader();

	for(int i = 0; i < n; i++) {
		a[i].detail();
	}
}

void searchId(Student a[], int n) {
	string id;
	cout << "Nhap ma sinh vien can tim: ";
	cin >> id;

	listHeader();
	for (int i = 0; i < n; i++) {
		if(a[i].id.find(id) != string::npos) {
			a[i].detail();
			return;
		}
	}
	
	cout << "Khong tim thay sinh vien co ma vua nhap !\n";
}

void listGPA(Student a[], int n) {
	// tim diem GPA cao nhat
	double res = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].gpa > res) res = a[i].gpa;
	}
	
	cout << "Danh sach sinh vien co diem gpa cao nhat :\n";
	listHeader();
	for(int i = 0; i < n; i++) {
		if(a[i].gpa == res) {
			a[i].detail();
		};
	}
}

string chuanhoa(string name) {
	stringstream ss(name); 
	vector<string> v;
	string token, res = "";
	while(ss >> token) {
		v.push_back(token);
	}
	res += v[v.size() - 1];
	for(int i = 0; i < v.size() -1; i++) res += v[i];
	return res;
}

bool cmp3(Student a, Student b){
	if(a.className != b.className) return a.className < b.className;
	string name1 = chuanhoa(a.name);
   	string name2 = chuanhoa(b.name);
   return name1 < name2;
}

bool cmp4(Student a, Student b){
	if(a.className != b.className) return a.className < b.className;
	return a.gpa > b.gpa;
}

void sortName(Student a[], int n) {
	sort(a, a + n, cmp3);
}

void sortClassName(Student a[], int n){
	sort(a, a + n, cmp4);
}

int main() {
	Student a[1000];
	int n;

	while(true) {
		cout << "-------------MENU-----------\n";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. Hien thi toan bo danh sach sinh vien\n";
		cout << "3. Tim kiem sinh vien theo ma\n";
		cout << "4. Liet ke sinh vien co diem GPA cao nhat\n";
		cout << "5. Sap xep sinh vien theo lop va ten theo ABC\n";
		cout << "6. Sap xep sinh vien theo lop va diem GPA giam dan\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------\n";
		cout << "Nhap lua chon:  ";
		int lc;
		cin >> lc;
	
		switch(lc) {
			case 1:
				a[n].input();
				++n;
				break;
			case 2:	
			    listStudent(a, n);
			    break;
			case 3:
			    searchId(a ,n);
			    break;
			case 4:
			    listGPA(a, n);
				break;
			case 5:
			    sortName(a, n);
			    listStudent(a, n);
				break;
			case 6:
			    sortClassName(a ,n);
			    listStudent(a, n);
			    break;
			case 0:
			    cout << "Thoat!!!\n";
				return 0;
			default:
			    cout << "Khong hop le !" << endl;   
		}
	}
 return 0;
}
