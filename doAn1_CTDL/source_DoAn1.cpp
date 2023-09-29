#include "thuVien_DoAn1.h"

int &size(CLS &m)
{
	return m.n;
}
bool isEmpty(CLS m)
{
	return size(m) == 0;
}
bool isFull(CLS m)
{
	return size(m) >= MAX;
}

int init(CLS &m)
{
	return m.n = 0;
}
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
bool kiemTraTonTai(CLS m, int x)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == x)
			return true;
	return false;
}

float dtb(CLS m, int x)
{
	int dtb;
	return dtb = (m.list[x].subject[0] + m.list[x].subject[1] + m.list[x].subject[2]) / 3;
}
void nhapThongTin(CLS &m)
{
	for (int i = 0; i < m.n; i++)
	{
		cout << "\nThong tin cua sinh vien thu [" << i + 1 << "] ";
		cout << "\nNhap ID cua sinh vien: ";
		cin >> m.list[i].code;
		cin.ignore();
		cout << "Nhap ten sinh vien: ";
		cin.getline(m.list[i].name, 30);
		cout << "Nhap lop: ";
		cin >> m.list[i].grade;
		cout << "Nhap diem cua sinh vien (Math, English, C++): ";
		cin >> m.list[i].subject[0];
		cin >> m.list[i].subject[1];
		cin >> m.list[i].subject[2];
	}
}
//2
void xoaDanhSach(CLS &m)
{
	size(m) = 0;
}
//3
void themSinhVien(CLS &m)
{
	size(m)++;
	cout << "\nThong tin cua sinh vien moi " << endl;
	cout << "\nNhap ID cua sinh vien: ";
	cin >> m.list[size(m) - 1].code;
	cin.ignore();
	cout << "Nhap ten sinh vien: ";
	cin.getline(m.list[size(m) - 1].name, 30);
	cout << "Nhap lop: ";
	cin >> m.list[size(m) - 1].grade;
	cout << "Nhap diem cua sinh vien (Math, English, C++): ";
	cin >> m.list[size(m) - 1].subject[0];
	cin >> m.list[size(m) - 1].subject[1];
	cin >> m.list[size(m) - 1].subject[2];
}
//4
int xoaSinhVien(CLS &m, int x)
{
	if (isEmpty(m))
		return -1;
	for (int i = 0; i < size(m); i++)
	{
		if (m.list[i].code == x)
		{
			for (int j = i; j < size(m) - 1; j++)
				m.list[j] = m.list[j + 1];
			size(m)--;
		}
	}
	return 1;
}
//5
int timKiemSinhVien(CLS m, int x)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == x)
			return i;
}

//6
int capNhatSinhVien(CLS &m, int x)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == x)
		{
			cout << "Nhap ID cua sinh vien: ";
			cin >> m.list[i].code;
			cin.ignore();
			cout << "Nhap ten sinh vien: ";
			cin.getline(m.list[i].name, 30);
			cout << "Nhap lop: ";
			cin >> m.list[i].grade;
			cout << "Nhap diem cua sinh vien (Math, English, C++): ";
			cin >> m.list[i].subject[0];
			cin >> m.list[i].subject[1];
			cin >> m.list[i].subject[2];
			return 1;
		}
	return -1;
}

//7
void sapXepDTBTang(CLS &m)
{
	for (int i = 0; i < size(m) - 1; i++)
	{
		for (int j = i + 1; j < size(m); j++)
		{
			if (dtb(m,i) > dtb(m,j))
				swap(m.list[i], m.list[j]);
		}
	}
}

void xoaPhanTuTrung(CLS &m)
{
	int newSize = 0;
	for (int i = 1; i < size(m); i++) {
		if (i == 0 || m.list[i].code != m.list[i - 1].code) {
			m.list[newSize++] = m.list[i];
		}
	}
	size(m) = newSize;
}
//10
void ghepDanhSach(CLS m, CLS n, CLS &k)
{
	size(k) = size(m) + size(n);
	for (int i = 0; i < size(m); i++)
		k.list[i] = m.list[i];
	for (int i = 0; i < size(n); i++)
		k.list[size(m) + i] = n.list[i];
}

void sapXepMathTang(CLS &m)
{
	float math1;
	float math2;
	for (int i = 0; i < size(m) - 1; i++)
	{
		for (int j = i + 1; j < size(m); j++)
		{
			math1 = (m.list[i].subject[0]);
			math2 = (m.list[j].subject[0]);
			if (math1 > math2)
				swap(m.list[i], m.list[j]);
		}
	}
}
//11
int timKiemNhiPhan(CLS m, int x)
{
	int left = 0;
	int right = size(m) - 1;
	while (left <= right)
	{
		int mid = size(m) / 2;
		if (m.list[mid].code == x)
			return mid;
		if (m.list[mid].code > x)
			right = mid - 1;
		if (m.list[mid].code < x)
			left = mid + 1;
	}
}
//12
bool kiemTraDiemTang(CLS m)
{
	for (int i = 0; i < size(m) - 1; i++)
		for (int j = i + 1; j < size(m); j++)
			if (dtb(m, i) < dtb(m, j))
				return false;
	return true;
}

//13
bool kiemTraDiemGiam(CLS m)
{
	for (int i = 0; i < size(m) - 1; i++)
		for (int j = i + 1; j < size(m); j++)
			if (dtb(m, i) > dtb(m, j))
				return false;
	return true;
}

//14
bool kiemTraSoSVGioi(CLS m)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < size(m) / 2; i++)
		if (dtb(m, i) >= 8.0)
			count1++;
	for (int i = size(m) - 2; i < size(m); i++)
		if (dtb(m, i) >= 8.0)
			count2++;
	if (count1 > count2)
		return true;
	return false;
}

//15
void tim2SVDiemToanNhoHon5(CLS m, CLS &n)
{
	size(n) = 0;
	for (int i = 0; i < size(m) - 1; i++)
		for (int j = i + 1; j < size(m); j++)
			if (m.list[i].subject[0] + m.list[j].subject[0] < 5)
			{
				n.list[size(n)++] = m.list[i];
				n.list[size(n)++] = m.list[j];
			}
}


//16
bool kiemTraCode(CLS m, int code)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == code)
			return true;
	return false;
}

void themSVCheckCode(CLS &m)
{
	int code;
	size(m)++;
	cout << "\nThong tin cua sinh vien moi " << endl;
	do {
		cout << "Nhap ID cua sinh vien: ";
		cin >> code;

		if (kiemTraCode(m, code))
			cout << "\nMa code da ton tai. Vui long nhap lai." << endl;
	} while (kiemTraCode(m, code));
	m.list[size(m) - 1].code = code;
	cin.ignore();
	cout << "Nhap ten sinh vien: ";
	cin.getline(m.list[size(m) - 1].name, 30);
	cout << "Nhap lop: ";
	cin >> m.list[size(m) - 1].grade;
	cout << "Nhap diem cua sinh vien (Math, English, C++): ";
	cin >> m.list[size(m) - 1].subject[0];
	cin >> m.list[size(m) - 1].subject[1];
	cin >> m.list[size(m) - 1].subject[2];
}

//17
void tachsvLoaiGioi(CLS m, CLS &n)
{
	size(n) = 0;
	for (int i = 0; i < size(m); i++)
		if (dtb(m, i) >= 8.0)
			n.list[size(n)++] = m.list[i];
}

//18
void xuatDanhSach(CLS m) 
{
	cout << "Danh sach sinh vien " << endl;
	for (int i = 0; i < size(m); i++)
	{
		cout << "\nSinh vien thu " << i + 1 << endl;
		cout << "ID: " << m.list[i].code << endl;
		cout << "Ho va ten: " << m.list[i].name << endl;
		cout << "Lop: " << m.list[i].grade << endl;
		cout << "Diem (Math, English, C++): " << m.list[i].subject[0] << " " << m.list[i].subject[1] << " " << m.list[i].subject[2] << endl;
	}
}

//19
void tachDanhSachSVTotNhat(CLS m, CLS &n)
{
	size(n) = 0;
	for (int i = 0; i < size(m); i++)
		if (dtb(m, i) > 6.5)
			n.list[size(n)++] = m.list[i];
}
//20
void svXuatSacNhat(CLS m)
{
	int viTri;
	float diemMax = dtb(m, 0);
	for (int i = 1; i < size(m); i++)
	{
		if (dtb(m, i) > diemMax)
		{
			diemMax = dtb(m, i);
			viTri = i;
		}
	}
}


void hienthi()
{
	cout << "***************************************************************************" << endl;
	cout << " \t\t\t\t Cac chuc nang " << endl;
	cout << "  1. Tao danh sach sinh vien rong" << endl;
	cout << "  2. Nhap danh sach sinh vien" << endl;
	cout << "  3. Xuat danh sach sinh vien" << endl;
	cout << "  4. Xoa danh sach sinh vien" << endl;
	cout << "  5. Them mot sinh vien vao danh sach khong kiem tra code trung" << endl;
	cout << "  6. Cap nhat thong tin mot sinh vien co trong danh sach" << endl;
	cout << "  7. Kiem tra mang nhap vao co phai la mang doi xung hay khong?" << endl;
	cout << "  8. Tim vi tri la so nguyen to lon nhat" << endl;
	cout << "  9. Kiem tra mang nhap vao co phai la mang tang" << endl;
	cout << " 10. Kiem tra nua dau mang ben trai co tinh giam dan" << endl;
	cout << "  0. Thoat chuong trinh" << endl;
	cout << "***************************************************************************" << endl;
}


void menu(CLS m, int &n)
{
	init(m);
	int chon;
	do {
		cout << "\n\n\ \033[1;34mChon 1 so de chon chuc nang: \033[0m";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init(m);
			cout << "Da tao danh sach sinh vien rong! " << endl;
			break;
		case 2:
			do {
				cout << "Nhap so luong sinh vien: ";
				cin >> m.n;
				cin.ignore();
				if (m.n < 0 || m.n>100)
					cout << "\nSo luong khong hop le! Vui long nhap lai." << endl;
			} while (m.n < 0 || m.n>100);
			nhapThongTin(m);
			break;
		case 3:
			xuatDanhSach(m);
			break;
		case 4:
			xoaDanhSach(m);
			cout << "Da xoa danh sach sinh vien " << endl;
			break;
		case 5:
			themSinhVien(m);
			break;
		case 6:
			int x;
			cout << "Nhap ID sinh vien can cap nhat thong tin: ";
			cin >> x;
			while (!kiemTraTonTai(m, x))
			{
				cout << "ID vua nhap khong ton tai! Xin nhap lai ";
				cin >> x;
			} 
			cout << "\nCap nhat thong tin sinh vien " << endl;
			capNhatSinhVien(m, x);
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
		
			break;
		case 10:
			
			break;
		default:
			break;
		}
	} while (chon != 0);
}