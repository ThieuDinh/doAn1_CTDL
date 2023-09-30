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
bool kiemTraTonTai(CLS m, int x);
void nhapThongTin(CLS &m);
void xuatDanhSach(CLS m);
void xoaDanhSach(CLS &m);
void themSinhVien(CLS &m);
int xoaSinhVien(CLS &m, int index);
int timKiemSinhVien(CLS m, int x);
int capNhatSinhVien(CLS &m, int x);
void swap(int &x, int &y);
float dtb(CLS m, int x);
void sapXepDTBTang(CLS &m);
void sapXepCodeTang(CLS &m);
void xoaCodeTrung(CLS &m);
void sapXepMathTang(CLS &m);
void ghepDanhSach(CLS m, CLS n, CLS &k);
int timKiemNhiPhan(CLS m, int x);
int svXuatSacNhat(CLS m);
void tachsvLoaiGioi(CLS m, CLS &n);
void themSVCheckCode(CLS &m);
bool kiemTraCode(CLS m, int code);
bool kiemTraSoSVGioi(CLS m);
void tim2SVDiemToanNhoHon5(CLS m, CLS &n);
void tachDanhSachSVTotNhat(CLS m, CLS &n);
bool kiemTraDiemTang(CLS m);
bool kiemTraDiemGiam(CLS m);

void hienthi();
void menu(CLS &m, CLS &c, CLS &k, int &n);