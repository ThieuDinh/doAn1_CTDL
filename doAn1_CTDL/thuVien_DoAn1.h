#include <iostream>
using namespace std;
const int MAX = 100;
struct Student{
	int code;
	char name[30];
	char grade[10];
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
int timKiemSinhVien(CLS m, int x);
void capNhatSinhVien(CLS &m, int x);
void swap(int &x, int &y);
float dtb(CLS m, int x);
void sapXepDTBTang(CLS &m);
void xoaPhanTuTrung(CLS &m);
void sapXepMathTang(CLS &m);
void ghepDanhSach(CLS m, CLS n, CLS &k);
void svXuatSacNhat(CLS m);
void svLoaiGioi(CLS m, CLS &n);
void themSVCheckCode(CLS &m);
bool kiemTraCode(CLS m, int code);