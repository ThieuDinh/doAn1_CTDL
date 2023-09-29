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

void nhapThongTin(CLS &m)
{
	cout << "Nhap so luong sinh vien: ";
	cin >> m.n;
	cin.ignore();
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

void xuatDanhSach(CLS m)
{
	cout << "-----------------------------------------------" << endl;
	cout << "\nDanh sach sinh vien " << endl;
	for (int i = 0; i < size(m); i++)
	{
		cout << "\nSinh vien thu " << i + 1 << endl;
		cout << "ID: " << m.list[i].code << endl;
		cout << "Lop: " << m.list[i].grade << endl;
		cout << "Ho va ten: " << m.list[i].name << endl;
		cout << "Diem (Math, English, C++): " << m.list[i].subject[0] << " " << m.list[i].subject[1] << " " << m.list[i].subject[2] << endl;
	}
}

void xoaDanhSach(CLS &m)
{
	size(m) = 0;
}

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

int timKiemSinhVien(CLS m, int x)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == x)
			return i;
}

void capNhatSinhVien(CLS &m, int x)
{
	for (int i = 0; i < size(m); i++)
		if (m.list[i].code == x)
		{
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
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

float dtb(CLS m, int x)
{
	int dtb;
	return dtb = (m.list[x].subject[0] + m.list[x].subject[1] + m.list[x].subject[2]) / 3;
}

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

void ghepDanhSach(CLS m, CLS n, CLS &k)
{
	size(k) = size(m) + size(n);
	for (int i = 0; i < size(m); i++)
		k.list[i] = m.list[i];
	for (int i = 0; i < size(n); i++)
		k.list[size(m) + i] = n.list[i];
}

void svXuatSacNhat(CLS m)
{
	int viTri;
	float diemMax=dtb(m, 0);
	for (int i = 1; i < size(m); i++)
	{
		if (dtb(m, i) > diemMax)
		{
			diemMax = dtb(m, i);
			viTri = i;
		}
	}
}

void svLoaiGioi(CLS m, CLS &n)
{
	size(n) = 0;
	for (int i = 0; i < size(m); i++)
		if (dtb(m, i) >= 8.0)
			n.list[size(n)++] = m.list[i];
}

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
		cin >>code;
		
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

