#include <bits/stdc++.h>
using namespace std;

struct sv {
	string ma, ten, lop, ns;
	double gpa;

	void in() {
		cout << ".....................\n";
		cout << "Ma sinh vien :" << ma << endl;
		cout << "Ten sinh vien :" << ten << endl;
		cout << "Lop :" << lop << endl;
		cout << "Ngay sinh :" << ns << endl;
		cout << "GPA :" << fixed << setprecision(2) << gpa << endl;
		cout << ".....................\n";
	}

	void nhap() {
		cout << "Nhap ma sinh vien :";
		cin >> ma;
		cout << "Nhap ten sinh vien :";
		cin.ignore();
		getline(cin, ten);
		cout << "Nhap lop:"; cin >> lop;
		cout << "Nhap ngay sinh :";
		cin >> ns;
		cout << "Gpa :";
		cin >> gpa;
	}
};

void inds(sv a[], int n) {
	cout << " thong tin danh sach sinh vien:\n";
	for(int i = 0; i < n; i++) {
		a[i].in();
	}
}

void tkma( sv a[], int n) {
	string ma;
	cout << "Nhap ma sinh vien can tim :";
	cin >> ma;
	bool found = false;
	for (int i = 0; i < n; i++) {
		if(a[i].ma.find(ma) !=string::npos) {
			a[i].in();
			found = true;
		}
	}
	if(!found)
		cout << "Khong tim thay sinh vien co ma vua nhap !\n";
}

void lkgpa(sv a[], int n) {
	double res = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].gpa > res) res = a[i].gpa;
	}
	cout << "Danh sach sinh vien co diem gpa cao nhat :\n";
	for(int i = 0; i <n; i++) {
		if(res == a[i].gpa) {
			a[i].in();
		}
	}
}

bool cmp1(sv a, sv b) {
	return a.gpa > b.gpa;
}
void lkgpa2(sv a[], int n) {
	vector<sv> v;
	for(int i = 0; i< n; i++) {
		if(a[i].gpa >= 2.5) v.push_back(a[i]);
	}
	sort(v.begin(), v.end(), cmp1);
	cout << "Danh sach sinh vien co diem gpa >= 2.5:\n";
	for(sv x : v) {
		x.in();
	}
}

string chuanhoa(string name){
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
bool cmp2(sv a, sv b) {
   string ten1 = chuanhoa(a.ten);
   string ten2 = chuanhoa(b.ten);
   return ten1 < ten2;
}

bool cmp3(sv a, sv b){
	if(a.lop != b.lop) return a.lop < b.lop;
	string ten1 = chuanhoa(a.ten);
   string ten2 = chuanhoa(b.ten);
   return ten1 < ten2;
}

bool cmp4(sv a, sv b){
	if(a.lop != b.lop) return a.lop < b.lop;
	return a.gpa > b.gpa;
}

void sxten(sv a[], int n) {
	sort(a, a + n, cmp2);
}

void sxlop(sv a[], int n){
	sort(a, a + n, cmp3);
}

void sxlop2(sv a[], int n){
	sort(a, a + n, cmp4);
}

int main() {
	sv a[1000];
	int n;
	while(1) {
		cout << "-------------MENU-----------\n";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. Hien thi toan bo danh sach sinh vien\n";
		cout << "3. tim kiem sinh vien theo ma\n";
		cout << "4. Liet ke sinh vien co diem gpa cao nhat\n";
		cout << "5. Liet ke cac sinh vien co diem gpa >= 2.5\n";
		cout << "6. Sap xep sinh vien theo ten\n";
		cout << "7. Sap xep sinh vien theo lop, cac ban cung lop sap xep ten theo thu tu abc\n";
		cout << "8. sap xem sinh vien theo lop, cac ban cung lop duoc sap xep theo diem gpa giam dan\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------\n";
		cout << "Nhap lua chon : \n";
		int lc;
		cin >> lc;
		if(lc == 1) {
			a[n].nhap();
			++n;
		} else if(lc == 2) {
			inds(a, n);
		} else if(lc == 3) {
			tkma(a ,n);
		} else if(lc == 4) {
			lkgpa(a, n);
		} else if(lc == 5) {
			lkgpa2(a, n);
		} else if(lc == 6) {
			sxten(a ,n);
		} else if(lc == 7) {
			sxlop(a, n);
		} else if(lc == 8) {
			sxlop2(a, n);
		} else if(lc == 0) {
			break;
		}
	}
	return 0;
}
