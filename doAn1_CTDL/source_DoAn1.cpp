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
		cout << "\nThong tin cua sinh vien thu [" << i+1 << "] ";
		cout << "\nNhap ID cua sinh vien: ";
		cin >> m.list[i].code;
		cin.ignore();
		cout << "Nhap ten sinh vien: ";
		cin.getline(m.list[i].name,30);
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
	cout << "Nhap diem cua sinh vien (Math, English, C++): ";
	cin >> m.list[size(m) - 1].subject[0];
	cin >> m.list[size(m) - 1].subject[1];
	cin >> m.list[size(m) - 1].subject[2];
}

int xoaSinhVien(CLS &m, int index)
{
	if (isEmpty(m) || index < 0 || index >= size(m))
		return -1;
	for (int i = index; i < size(m)-1 ; i++)
		m.list[i] = m.list[i + 1];
	size(m)--;
	return 1;
}

void timKiemSinhVien(CLS m, int x)
{
	for(int i=0;i<size(m);i++)
		if (m.list[i].code == x)
		{
			cout << "\nSinh vien can tim " << endl;
			cout << "ID: " << m.list[i].code << endl;
			cout << "Ho va ten: " << m.list[i].name << endl;
			cout << "Diem (Math, English, C++): " << m.list[i].subject[0] << " " << m.list[i].subject[1] << " " << m.list[i].subject[2] << endl;
		}
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

void sapXepDTBTang(CLS &m)
{
	float dtb1;
	float dtb2;
	for (int i = 0; i < size(m) - 1; i++)
	{
		dtb1 = (m.list[i].subject[0] + m.list[i].subject[1] + m.list[i].subject[2]) / 3;
		dtb2 = (m.list[i + 1].subject[0] + m.list[i + 1].subject[1] + m.list[i + 1].subject[2]) / 3;
		if (dtb1 > dtb2)
			swap(m.list[i], m.list[i + 1]);
	}
}
