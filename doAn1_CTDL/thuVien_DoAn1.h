#include <iostream>
using namespace std;
const int MAX = 100;
struct Student{
	int code;
	char name[30];
	float subject[3];//math, English, c++
}; 
typedef Student SV;

struct ContiguousListStudent{
	int n;
	SV list[MAX];
};
typedef ContiguousListStudent CLS;

int &size(CLS &m);
bool isFull(CLS m);
bool isEmpty(CLS m);
int init(CLS &m);
void nhapThongTin(CLS &m);
void xuatDanhSach(CLS m);
void xoaDanhSach(CLS &m);
void themSinhVien(CLS &m);
int xoaSinhVien(CLS &m, int index);
void timKiemSinhVien(CLS m, int x);
void capNhatSinhVien(CLS &m, int x);
void swap(int &x, int &y);
void sapXepDTBTang(CLS &m);
