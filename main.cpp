#include <iostream>
// #include<fstream>
#include <bits/stdc++.h>
#include <iomanip> // setw, setfill, fixed, setprecision, left.
#include <cstring> // cmp

using namespace std;

// cau truc (struct) c� t�n l� "Student" dai dien cho th�ng tin cua mot sinh vi�n
struct Student
{
	string id, name, className, birthday, gt;
	double gpa;

	void detail()
	{
		// hop nhap
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

	// Nhap th�ng tin cho sinh vi�n.
	void input()
	{
		cout << "\nNhap ma sinh vien: ";
		cin >> id;
		cout << "Nhap ten sinh vien: ";
		cin.ignore();
		getline(cin, name);
		cout << "Nhap lop: ";
		cin >> className;
		cout << "Nhap ngay sinh: ";
		cin >> birthday;
		cout << "Nhap gioi tinh: ";
		cin >> gt;
		cout << "GPA: ";
		cin >> gpa;
	}
};

// In ra ti�u de cua bang danh s�ch sinh vi�n
//  '-' de tao duong ke ngang giua c�c cot v� dau cuoi bang
// '|' de tao khung cho bang.
void listHeader()
{
	// hop o ngoai
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

// In ra th�ng tin cua danh s�ch sinh vi�n
// Neu chua co sinh vien nao duoc luu se thong bao: danh sach sinh vien trong
// In ra th�ng b�o "Thong tin danh sach sinh vien:" de d�nh dau phan in danh s�ch sinh vi�n.
// Goi h�m listHeader() de in ra ti�u de cua bang danh s�ch sinh vi�n.
// Su dung vong lap for de duyet qua tung sinh vi�n trong mang a.
// �oi voi moi sinh vi�n, goi phuong thuc detail() de in ra th�ng tin chi tiet cua sinh vi�n d�.
// Sau khi in het danh s�ch sinh vi�n, in mot dong trong de tao khoang c�ch.
void listStudent(Student a[], int n)
{
	if (n == 0)
	{
		cout << "\n\n         Danh sach sinh vien trong!" << endl;
	}
	else
	{
		cout << "Thong tin danh sach sinh vien:\n\n";
		listHeader();
		for (int i = 0; i < n; i++)
		{
			a[i].detail();
		}
	}
	cout << "\n";
}

// Tim kiem sinh vi�n theo t�n.
// Khai b�o bien name kieu du lieu string de luu t�n sinh vi�n can tim kiem.
// Y�u cau nguoi d�ng nhap t�n sinh vi�n can tim kiem.
// Su dung vong lap for de duyet qua tung sinh vi�n trong mang a.
// Su dung phuong thuc find() cua lop string de kiem tra xem t�n nhap v�o c� ton tai trong t�n cua sinh vi�n hien tai hay kh�ng.
// Neu tim thay sinh vi�n c� t�n tr�ng khop, in ra th�ng tin cua sinh vi�n d� bang c�ch goi h�m listHeader() de in ti�u de v� goi phuong thuc detail() de in th�ng tin chi tiet.
// Sau khi tim thay sinh vi�n v� in ra th�ng tin, su dung lenh return de ket th�c h�m.
// Neu kh�ng tim thay sinh vi�n n�o c� t�n tr�ng khop, in ra th�ng b�o kh�ng tim thay.
void searchName(Student a[], int n)
{
	string name;
	cout << "Nhap ten sinh vien can tim: ";
	cin >> name;
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		if (a[i].name.find(name) != string::npos)
		{
			cout << "Thong tin sinh vien tim duoc: \n\n";
			listHeader();
			a[i].detail();
			return;
		}
	}
	cout << "\nKhong tim thay sinh vien co ten vua nhap !\n\n";
}

// Tim kiem sinh vi�n theo Id.
// Khai b�o bien id kieu du lieu string de luu id sinh vi�n can tim kiem.
// Y�u cau nguoi d�ng nhap id sinh vi�n can tim kiem.
// Su dung vong lap for de duyet qua tung sinh vi�n trong mang a.
// Su dung phuong thuc find() cua lop string de kiem tra xem id nhap v�o c� ton tai trong id cua sinh vi�n hien tai hay kh�ng.
// Neu tim thay sinh vi�n c� id tr�ng khop, in ra th�ng tin cua sinh vi�n d� bang c�ch goi h�m listHeader() de in ti�u de v� goi phuong thuc detail() de in th�ng tin chi tiet.
// Sau khi tim thay sinh vi�n v� in ra th�ng tin, su dung lenh return de ket th�c h�m.
// Neu kh�ng tim thay sinh vi�n n�o c� id tr�ng khop, in ra th�ng b�o kh�ng tim thay.
void searchId(Student a[], int n)
{
	string id;
	cout << "Nhap ma sinh vien can tim: ";
	cin >> id;
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		if (a[i].id.find(id) != string::npos)
		{
			cout << "Thong tin sinh vien tim duoc: \n\n";
			listHeader();
			a[i].detail();
			return;
		}
	}
	cout << "\nKhong tim thay sinh vien co ma vua nhap !\n\n";
}

void listGPA(Student a[], int n)
{
	// tim diem GPA cao nhat
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].gpa > res)
			res = a[i].gpa;
	}
	// In ra danh s�ch sinh vi�n c� diem GPA cao nhat
	cout << "Danh sach sinh vien co diem gpa cao nhat :\n";
	listHeader();
	for (int i = 0; i < n; i++)
	{
		if (a[i].gpa == res)
		{
			a[i].detail(); // In chi tiet th�ng tin sinh vi�n
		};
	}
}

string chuanhoa(string name)
{
	stringstream ss(name);	// Tao mot stringstream tu chuoi dau v�o
	vector<string> v;		// Khoi tao mot vector de luu tru c�c tu trong chuoi
	string token, res = ""; // Bien token de luu tung tu, bien res de luu ket qua cuoi c�ng
	while (ss >> token)
	{
		v.push_back(token); // Th�m tu v�o vector
	}
	// X�y dung chuoi ket qua chuan hoa theo y�u cau
	res += v[v.size() - 1]; // Th�m tu cuoi c�ng v�o dau chuoi ket qua
	for (int i = 0; i < v.size() - 1; i++)
	{
		res += v[i]; // Th�m c�c tu con lai v�o sau tu cuoi c�ng
	}
	return res; // Tra ve chuoi da chuan h�a
}

// Sap xep ten
// �au ti�n, ch�ng ta kiem tra xem hai sinh vi�n a v� b c� c�ng className hay kh�ng.
// Neu hai sinh vi�n c� className kh�c nhau, ch�ng ta so s�nh v� tra ve ket qua so s�nh a.className < b.className.
// Tiep theo, ch�ng ta chuan h�a t�n cua hai sinh vi�n bang c�ch goi h�m chuanhoa voi a.name v� b.name.
// Cuoi c�ng, ch�ng ta so s�nh t�n da chuan h�a name1 v� name2 bang to�n tu '<' v� tra ve ket qua.
bool cmp1(Student a, Student b)
{
	if (a.className != b.className)
		return a.className < b.className;
	string name1 = chuanhoa(a.name);
	string name2 = chuanhoa(b.name);
	return name1 < name2;
}

// Sap xep theo lop
// �au ti�n, ch�ng ta kiem tra xem hai sinh vi�n a v� b c� c�ng className hay kh�ng.
// Neu hai sinh vi�n c� className kh�c nhau, ch�ng ta so s�nh v� tra ve ket qua so s�nh a.className < b.className.
// Neu hai sinh vi�n c� c�ng className, ch�ng ta tiep tuc kiem tra diem GPA cua hai sinh vi�n.
// Tra ve ket qua so s�nh a.gpa > b.gpa. �ieu n�y dao nguoc thu tu sap xep vi ch�ng ta muon sap xep giam dan theo diem GPA.
bool cmp2(Student a, Student b)
{
	if (a.className != b.className)
		return a.className < b.className;
	return a.gpa > b.gpa;
}

// Sap xep GPA
// �au ti�n, ch�ng ta kiem tra xem hai sinh vi�n a v� b c� c�ng className hay kh�ng.
// Neu className kh�c nhau, ch�ng ta tra ve ket qua so s�nh a.gpa > b.gpa, dao nguoc thu tu sap xep dua tr�n diem GPA.
bool cmp3(Student a, Student b)
{
	if (a.className != b.className)
		;
	return a.gpa > b.gpa;
}

// Sap xep danh sach sinh vien theo lop va ten theo ABC
void sortName(Student a[], int n)
{
	sort(a, a + n, cmp1);
}

// Sap xep danh sach sinh vien theo lop v� GPA giam dan
void sortClassName(Student a[], int n)
{
	sort(a, a + n, cmp2);
}

// Sap xep theo GPA giam dan
void sortGPA(Student a[], int n)
{
	sort(a, a + n, cmp3);
}

// Xoa sinh vien theo Id
// y�u cau nguoi d�ng nhap m� sinh vi�n can x�a
// Sau d�, n� duyet qua mang a de tim sinh vi�n c� m� tuong ung
// Neu tim thay, h�m se x�a sinh vi�n d� bang c�ch dich chuyen c�c phan tu ph�a sau v� giam gi� tri cua n di 1
// N�u kh�ng tim thay sinh vi�n, h�m se in th�ng b�o kh�ng tim thay.
void delStudent(Student a[], int &n)
{
	string soct; // Bien luu tru m� sinh vi�n can x�a
	int res = 0; // Bien dem so luong sinh vi�n d� x�a
	cout << "Nhap ma sinh vien ban can xoa: ";
	cin >> soct;
	for (int i = 0; i < n; i++)
	{
		if (a[i].id == soct)
		{
			res++;
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			cout << "\n * Da xoa sinh vien co ma " << soct << " khoi danh sach ! * \n\n";
		}
	}
	if (res == 0)
		cout << "\n * Ma so sinh vien khong ton tai ! * \n\n";
	else
		n--;
}

// Sua thong tin sinh vien theo Id
// y�u cau nguoi d�ng nhap m� sinh vi�n can sua
// Sau d�, n� duyet qua mang a de tim sinh vi�n c� m� tuong ung
// Neu tim thay, h�m se cho ph�p nguoi d�ng cap nhat th�ng tin cua sinh vi�n d� bang c�ch goi phuong thuc input() tr�n doi tuong sinh vi�n tai vi tr� i
//  Sau khi cap nhat xong, h�m se in th�ng b�o th�nh c�ng
// Neu kh�ng tim thay sinh vi�n, h�m se in th�ng b�o kh�ng tim thay.
void updateStudent(Student a[], int n)
{
	string soct; // Bien luu tru m� sinh vi�n can sua
	int res = 0; // Bien dem so luong sinh vi�n d� sua
	cout << "Nhap ma so sinh vien ban can sua: ";
	cin >> soct;
	for (int i = 0; i < n; i++)
	{
		if (a[i].id == soct)
		{
			res++;
			a[i].input();
			cout << "\nDa sua sinh vien co ma " << soct << " thanh cong ! \n\n";
		}
	}
	if (res == 0)
		cout << "\n * Ma so sinh vien khong ton tai ! * \n\n";
	else
		n--;
}

// Lay thong tin sinh vien tu mot tep tin (dang phat trien nhung khong hoan tat)
// void checkFile()
//{
//     char c,tenfile[20];
//
//               cout<<"Nhap ten file: ";
//               cin>>tenfile;
//               ifstream in(tenfile);
//               if(!in)
//               {
//                             cout<<"File khong ton tai";
//                             getch();
//                             return;
//               }
//               cout<<"\n\n";
//               while(in.eof()==0)
//               {
//                             in.get(c);
//                             cout<<c;
//               }
//     return;
// }

// Luu ban ghi vao mot tep tin
// y�u cau nguoi d�ng nhap t�n tep tin de luu th�ng tin sinh vi�n
// Sau d�, n� mo tep tin trong che do ghi ( "w") v� su dung con tro tep tin ( FILE *fp) de tro den tep tin vua mo
// H�m sau d� lap qua mang a v� su dung fprintf de ghi th�ng tin cua moi sinh vi�n v�o tep tin theo dinh dang cu the.
// Cuoi c�ng, h�m d�ng tep tin bang c�ch su dung fclose(fp).
void SaveFile(Student a[], int n)
{
	getchar();
	char fileName[50]; // Bien luu tru t�n tep tin
	printf("Nhap ten file: ");
	gets(fileName);
	FILE *fp;				   // khai b�o con tro co kieu file
	fp = fopen(fileName, "w"); // mo file o che do w
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s|%s|%s|%s|%1.2f|%s\n",
				a[i].id.c_str(), a[i].name.c_str(), a[i].className.c_str(), a[i].birthday.c_str(), a[i].gpa, a[i].gt.c_str());
	}
	fclose(fp); // ��ng tep tin sau khi ghi xong
}

void Thoat(char c)
{
	while (c != 'Y' && c != 'N')
	{
		cout << "Vui long chon lai ! \n"
			 << endl;
		cout << "Nhap [Y] / [N] : ";
		cin >> c;
		system("cls");
		cout << "\n";
	}
	if (c == 'Y')
	{
		cout << "Thank you ! \n\n";
		cout << "Nice to see you again ! \n";
		exit(0);
	}
	else
		(c == 'N');
	{
		cout << "Ban da huy thoat khoi chuong trinh ! \n"
			 << endl;
		cout << "Nhap [N] de quay lai MENU: ";
		cin >> c;
		cout << "\n";
		system("cls");
		cout << "Da quay lai MENU !! \n";
	}
}

void Menuchinh() // swith case
{
	Student a[10000];
	int n;
	char c;
menu:
	while (true)
	{
		cout << " \n";
		cout << "          -------------------------MENU--------------------------\n";
		cout << "          |                                                     |\n";
		cout << "          | 1. Nhap thong tin sinh vien                         |\n";
		cout << "          | 2. Hien thi toan bo danh sach sinh vien             |\n";
		cout << "          | 3. Tim kiem thong tin sinh vien                     |\n";
		cout << "          | 4. Liet ke sinh vien co diem GPA cao nhat           |\n";
		cout << "          | 5. Sap xep danh sach sinh vien                      |\n";
		cout << "          | 6. Xoa sinh vien theo ma sinh vien                  |\n";
		cout << "          | 7. Sua thong tin sinh vien                          |\n";
		cout << "          | 8. Luu file                                         |\n";
		cout << "          | 0. Thoat !                                          |\n";
		cout << "          |                                                     |\n";
		cout << "          -----------------NguyenVyTruong-TH27.36----------------\n";
		cout << " \n";
		cout << "          <> Nhap lua chon <>:  ";

		int lc;
		cin >> lc;

		system("cls");

		switch (lc)
		{
		case 1:
			cout << "Nhap thong tin: " << endl;
			a[n].input();
			++n;
			cout << "\nNhap thong tin sinh vien thu: " << n << " thanh cong !\n";
			break;
		case 2:
			listStudent(a, n);
			break;
		case 3:
			while (true)
			{
				cout << " \n";
				cout << "---------------------MENU TIM KIEM---------------------\n";
				cout << "| 1. Tim kiem thong tin sinh vien theo ten            |\n";
				cout << "| 2. Tim kiem thong tin sinh vien theo MSV            |\n";
				cout << "| 0. Quay lai menu                                    |\n";
				cout << "-------------------------------------------------------\n";
				cout << " \n";
				cout << "  <> Nhap lua chon <>:  ";

				int lc;
				cin >> lc;
				system("cls");

				switch (lc)
				{
				case 1:
					searchName(a, n);
					break;
				case 2:
					searchId(a, n);
					break;
				case 0:
					cout << "\nDa quay lai MENU !!\n";
					goto menu;
					break;
				default:
					cout << "Lua chon khong hop le moi nhap lai !" << endl;
				}
			}
		case 4:
			listGPA(a, n);
			break;
		case 5:
			while (true)
			{
				cout << " \n";
				cout << "---------------------MENU SAP XEP----------------------\n";
				cout << "| 1. Sap xep sinh vien theo lop va ten theo ABC       |\n";
				cout << "| 2. Sap xep sinh vien theo lop va diem GPA giam dan  |\n";
				cout << "| 3. Sap xep sinh vien theo diem GPA giam dan         |\n";
				cout << "| 0. Quay lai menu                                    |\n";
				cout << "-------------------------------------------------------\n";
				cout << " \n";
				cout << "  <> Nhap lua chon <>:  ";

				int lc;
				cin >> lc;
				system("cls");

				switch (lc)
				{
				case 1:
					sortName(a, n);
					listStudent(a, n);
					cout << "\nSap xep sinh vien theo lop va ten theo ABC";
					break;
				case 2:
					sortClassName(a, n);
					listStudent(a, n);
					cout << "\nSap xep sinh vien theo lop va diem GPA giam dan";
					break;
				case 3:
					sortGPA(a, n);
					listStudent(a, n);
					cout << "\nSap xep sinh vien theo diem GPA giam dan";
					break;
				case 0:
					cout << "\nDa quay lai MENU !!\n";
					goto menu;
					break;
				default:
					cout << "Lua chon khong hop le moi nhap lai !" << endl;
				}
			}
		case 6:
			delStudent(a, n);
			break;
		case 7:
			updateStudent(a, n);
			break;
		case 8:
			if (n > 0)
			{
				SaveFile(a, n);
				cout << "\nGhi danh sach sinh vien vao file thanh cong ! \n";
			}
			else
			{
				cout << "\nSanh sach sinh vien trong !\n";
			}
			break;
			//			case 9:
			//				checkFile();
			//				break;
		case 0:
			cout << "Ban xac nhan thoat ? \n"
				 << endl;
			cout << "Nhap [Y] / [N] : ";
			cin >> c;
			cout << "\n";
			Thoat(c);
			break;
		default:
			cout << "Lua chon khong hop le !" << endl;
			cout << "Hay lua chon chuc nang phu hop trong MENU !" << endl;
		}
	}
}

// void Menuchinh() // if else
//{
//	Student a[10000];
//	int n;
//	char c;
//    menu:while(true)
//    {
//		cout << " \n";
//		cout << "-------------------------MENU--------------------------\n";
//		cout << "|                                                     |\n";
//		cout << "| 1. Nhap thong tin sinh vien                         |\n";
//		cout << "| 2. Hien thi toan bo danh sach sinh vien             |\n";
//		cout << "| 3. Tim kiem thong tin sinh vien                     |\n";
//		cout << "| 4. Liet ke sinh vien co diem GPA cao nhat           |\n";
//		cout << "| 5. Sap xep danh sach sinh vien                      |\n";
//		cout << "| 6. Xoa sinh vien theo ma sinh vien                  |\n";
//		cout << "| 7. Sua thong tin sinh vien                          |\n";
//		cout << "| 8. Ghi file                                         |\n";
//		cout << "| 0. Thoat !                                          |\n";
//		cout << "|                                                     |\n";
//		cout << "-------------------------------------------------------\n";
//		cout << " \n";
//		cout << "  <> Nhap lua chon <>:  ";
//
//		int lc;
//		cin >> lc;
//
//		system("cls");
//
//		       if (lc == 1)
//		       {
//				cout << "Nhap thong tin: " << endl;
//				a[n].input();
//				++n;
//				cout << "\nNhap thong tin sinh vien thu: " << n << " thanh cong !\n";
//			   }
//
//			   if (lc == 2)
//			   {
//				listStudent(a, n);
//			   }
//
//			   if (lc == 3)
//			   {
//				 while(true)
//				 {
//					cout << " \n";
//					cout << "---------------------MENU TIM KIEM---------------------\n";
//					cout << "| 1. Tim kiem thong tin sinh vien theo ten            |\n";
//					cout << "| 2. Tim kiem thong tin sinh vien theo MSV            |\n";
//					cout << "| 0. Quay lai menu                                    |\n";
//					cout << "-------------------------------------------------------\n";
//                     cout << " \n";
//		            cout << "  <> Nhap lua chon <>:  ";
//
//					int lc;
//					cin >> lc;
//					system("cls");
//
//					switch(lc)
//					{
//						case 1:
//			                searchName(a, n);
//				            break;
//						case 2:
//							searchId(a ,n);
//							break;
//						case 0:
//							cout << "\nDa quay lai MENU !!\n";
//							goto menu;
//							break;
//						default:
//							cout << "Lua chon khong hop le moi nhap lai !" << endl;
//					}
//				 }
//				}
//
//			    if (lc == 4)
//			    {
//				 listGPA(a, n);
//				}
//
//			    if (lc == 5)
//			    {
//				 while(true)
//				 {
//					cout << " \n";
//					cout << "---------------------MENU SAP XEP----------------------\n";
//					cout << "| 1. Sap xep sinh vien theo lop va ten theo ABC       |\n";
//					cout << "| 2. Sap xep sinh vien theo lop va diem GPA giam dan  |\n";
//					cout << "| 3. Sap xep sinh vien theo diem GPA giam dan         |\n";
//					cout << "| 0. Quay lai menu                                    |\n";
//					cout << "-------------------------------------------------------\n";
//                     cout << " \n";
//		            cout << "  <> Nhap lua chon <>:  ";
//
//					int lc;
//					cin >> lc;
//					system("cls");
//
//					switch(lc)
//					{
//						case 1:
//							sortName(a, n);
//							listStudent(a, n);
//							break;
//						case 2:
//							sortClassName(a ,n);
//							listStudent(a, n);
//							break;
//						case 3:
//							sortGPA(a ,n);
//							listStudent(a, n);
//							break;
//						case 0:
//							cout << "\nDa quay lai MENU !!\n";
//							goto menu;
//							break;
//						default:
//							cout << "Lua chon khong hop le moi nhap lai !" << endl;
//					}
//				 }
//				}
//			    if (lc == 6)
//			    {
//				 delStudent(a, n);
//				}
//
//			    if (lc == 7)
//			    {
//			 	 updateStudent(a, n);
//				}
//
//			    if (lc == 8)
//			    {
//				  if (n>0)
//				  {
//				    SaveFile(a, n);
//				    cout << "\nGhi danh sach sinh vien vao file thanh cong ! \n";
//			    }else{
//			    	cout << "\nSanh sach sinh vien trong !\n";
//				}
//				}
////			if (lc == 9)
////          {
////				checkFile();
////			}
//
//			if (lc == 0)
//			{
//				Thoat(c);
//			}
//
//			else
//			{
//				cout << "Lua chon khong hop le !" << endl;
//				cout << "Hay lua chon chuc nang phu hop trong MENU !" << endl;
//			}
//	}
//}

int main()
{
	Menuchinh();
}
