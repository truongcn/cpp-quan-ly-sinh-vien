#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <string.h>

using namespace std;

struct Student 
{
	string id, name, className, birthday, gt;
	double gpa;

	void detail() 
	{  // hop nhap
		cout << "| " 
			<< setfill(' ') << left << setw(20) << id << " | " 
			<< setfill(' ') << left << setw(35) << name << " | " 
			<< setfill(' ') << left << setw(10) << className << " | " 
			<< setfill(' ') << left << setw(10) << birthday << " | " 
			<< setfill(' ') << left << setw(5) << gpa << " | "
			<< setfill(' ') << left << setw(5) << fixed << setprecision(2) << gt << " |" 
			<< endl;

		cout << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(37) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
	}

	void input() 
    {
		cout << "Nhap ma sinh vien: ";cin >> id;
		cout << "Nhap ten sinh vien: ";
		cin.ignore();
		getline(cin, name);
		cout << "Nhap lop: "; cin >> className;
		cout << "Nhap ngay sinh: ";cin >> birthday;
		cout << "Nhap gioi tinh: ";cin >> gt;
		cout << "GPA: ";cin >> gpa;
	}
};

void listHeader() 
{   // hop o ngoai
	cout << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(37) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
		
	cout << "| " 
		<< setfill(' ') << left << setw(20) << " ID" << " | " 
		<< setfill(' ') << left << setw(35) << " Name" << " | " 
		<< setfill(' ') << left << setw(10) << "ClassName" << " | " 
		<< setfill(' ') << left << setw(10) << "Birthday" << " | " 
		<< setfill(' ') << left << setw(5) << "GPA" << " |" 
		<< setfill(' ') << left << setw(6) << "GT" << " |" 
		<< endl;
		
	cout << "|" 
			<< setfill('-') << left << setw(22) << "" << "|" 
			<< setfill('-') << left << setw(37) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(12) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< setfill('-') << left << setw(7) << "" << "|" 
			<< endl;
}

void listStudent(Student a[], int n) 
{
	cout << "Thong tin danh sach sinh vien:\n";
	listHeader();

	for(int i = 0; i < n; i++) {
		a[i].detail();
	}
}

void searchId(Student a[], int n) 
{
	string id;
	cout << "Nhap ma sinh vien can tim: ";cin >> id;

	listHeader();
	for (int i = 0; i < n; i++) {
		if(a[i].id.find(id) != string::npos) {
			a[i].detail();
			return;
		}
	}
	cout << "Khong tim thay sinh vien co ma vua nhap !\n";
}

void listGPA(Student a[], int n) 
{
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

string chuanhoa(string name) 
{
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

bool cmp3(Student a, Student b)
{
	if(a.className != b.className) return a.className < b.className;
	string name1 = chuanhoa(a.name);
   	string name2 = chuanhoa(b.name);
   return name1 < name2;
}

bool cmp4(Student a, Student b)
{
	if(a.className != b.className) return a.className < b.className;
	return a.gpa > b.gpa;
}

void sortName(Student a[], int n) 
{
	sort(a, a + n, cmp3);
}

void sortClassName(Student a[], int n)
{
	sort(a, a + n, cmp4);
}

void delStudent(Student a[], int n)
{
	string soct;
	int res = 0;
	cout << "Nhap ma sinh vien ban can xoa: ";cin >> soct;
	for(int i = 0; i < n; i++)
	{
		if( a[i].id == soct)
		{
		   res ++;
		   for(int j = i; j < n;j++)
		   {
		   	 a[j] = a[j+1];
		   }
		   cout << "Da xoa sinh vien co ma " << soct << "\n";
		}
	}
	if (res == 0)
	cout << "Ma so sinh vien khong ton tai ! \n";
	else n--;
}

void updateStudent(Student a[], int n)
{
	string soct;
	cout << "Nhap ma so sinh vien ban can sua: ";cin >> soct;
	for(int i = 0; i < n; i++)
	{
		if(a[i].id == soct)
		{
			a[i].input();
		}
	}
}


int main() {
	Student a[1000];
	int n,id;

	while(true) {
		cout << " \n";
		cout << "--------------------------MENU-------------------------\n";
		cout << "| 1. Nhap thong tin sinh vien                         |\n";
		cout << "| 2. Hien thi toan bo danh sach sinh vien             |\n";
		cout << "| 3. Tim kiem sinh vien theo ma                       |\n";
		cout << "| 4. Liet ke sinh vien co diem GPA cao nhat           |\n";
		cout << "| 5. Sap xep sinh vien theo lop va ten theo ABC       |\n";
		cout << "| 6. Sap xep sinh vien theo lop va diem GPA giam dan  |\n";
		cout << "| 7. Xoa sinh vien theo ma sinh vien                  |\n";
		cout << "| 8. Sua thong tin sinh vien                          |\n";
		cout << "| 0. Thoat !                                          |\n";
		cout << "-------------------------------------------------------\n";
		cout << " \n";
		cout << "  <> Nhap lua chon <>:  ";
		
		int lc;
		cin >> lc;
	
        		system("cls");	
        		
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
			case 7:
				delStudent(a, n);
				listStudent(a, n);
				break;
			case 8:
			    updateStudent(a, n);  
				listStudent(a, n); 
				break;
			case 0:
			    cout << "Thoat!!!\n";
				return 0;
			default:
			    cout << "Lua chon khong hop le !" << endl;   
		}
	}
 return 0;
}
