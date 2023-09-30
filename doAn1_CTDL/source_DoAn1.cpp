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
	float dtb;
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
	return -1;
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
//9
void sapXepCodeTang(CLS &m)
{
	for (int i = 0; i < size(m) - 1; i++)
	{
		for (int j = i + 1; j < size(m); j++)
		{
			if (m.list[i].code > m.list[j].code)
				swap(m.list[i], m.list[j]);
		}
	}
}
void xoaCodeTrung(CLS &m)
{
	int newSize = 0;
	for (int i = 0; i < size(m); i++) {
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
	return -1;
}
//12
bool kiemTraDiemTang(CLS m)
{
	for (int i = 0; i < size(m) - 1; i++)
		for (int j = i + 1; j < size(m); j++)
			if (dtb(m, i) > dtb(m, j))
				return false;
	return true;
}

//13
bool kiemTraDiemGiam(CLS m)
{
	for (int i = 0; i < size(m) - 1; i++)
		for (int j = i + 1; j < size(m); j++)
			if (dtb(m, i) < dtb(m, j))
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
	//cout << "Danh sach sinh vien " << endl;
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
int svXuatSacNhat(CLS m)
{
	int viTri,i;
	float diemMax = dtb(m, 0);
	if (size(m) == 1)
		return i=0;
	for (i = 1; i < size(m); i++)
		if (dtb(m, i) > diemMax)
		{
			diemMax = dtb(m, i);
			viTri = i;
		}
	return viTri;
}


void hienthi()
{
	cout << "**********************************************************************************************" << endl;
	cout << "   \t\t\t\t\t Cac chuc nang\n " << endl;
	cout << "    1. Tao danh sach sinh vien rong" << endl;
	cout << "    2. Nhap danh sach sinh vien" << endl;
	cout << "    3. Xuat danh sach sinh vien" << endl;
	cout << "    4. Xoa danh sach sinh vien" << endl;
	cout << "    5. Xoa mot sinh vien " << endl;
	cout << "    6. Them mot sinh vien vao danh sach khong kiem tra code trung" << endl;
	cout << "    7. Cap nhat thong tin mot sinh vien co trong danh sach" << endl;
	cout << "    8. Sap xep danh sach tang dan theo diem trung binh 3 mon hoc" << endl;
	cout << "    9. Xoa tat ca cac sinh vien co ma code trung nhau " << endl;
	cout << "   10. Tron hai danh sach va sap xep tang dan theo diem toan " << endl;
	cout << "   11. Tim kiem tren danh sach da sap xep trong cau 10" << endl;
	cout << "   12. Kiem tra mot danh sach la danh sach tang dan" << endl;
	cout << "   13. Kiem tra mot danh sach la danh sach giam dan" << endl;
	cout << "   14. Kiem tra nua danh sach dau co tong so sinh vien gioi lon hon mot nua sau hay khong " << endl;
	cout << "   15. Tim cap sinh vien co tong diem toan nho hon 5 dau tien " << endl;
	cout << "   16. Them sinh vien vao danh sach co kiem tra ma code trung " << endl;
	cout << "   17. Tach tat ca cac sinh vien xep loai gioi ra thanh mot danh sach khac " << endl;
	cout << "   18. Tach danh sach sinh vien co thanh tich hoc tap 3 mon hoc tot nhat " << endl;
	cout << "   19. Xuat sinh vien xuat sac nhat trong danh sach " << endl;
	cout << "    5. Xoa mot sinh vien " << endl;
	cout << "    0. Thoat chuong trinh" << endl;
	cout << "**********************************************************************************************" << endl;
}


void menu(CLS &m, CLS &n,CLS &k, int &a)
{
	init(m);
	int chon;
	do {
		cout << "\n\n\033[1;34mChon 1 so de chon chuc nang: \033[0m";
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
		case 6:
			themSinhVien(m);
			break;
		case 7:
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
		case 8:
			sapXepDTBTang(m);
			cout << "Da sap xep tang dan theo diem trung binh " << endl;
			xuatDanhSach(m);
			break;
		case 9:
			cout << "Da xoa tat ca cac sinh vien co code trung " << endl;
			sapXepCodeTang(m);
			xoaCodeTrung(m);
			xuatDanhSach(m);
			break;
		case 10:
			cout << "Nhap danh sach sinh vien thu nhat " << endl;
			do {
				cout << "Nhap so luong sinh vien: ";
				cin >> m.n;
				cin.ignore();
				if (m.n < 0 || m.n>100)
					cout << "\nSo luong khong hop le! Vui long nhap lai." << endl;
			} while (m.n < 0 || m.n>100);
			nhapThongTin(m);
			cout << "\nNhap danh sach sinh vien thu hai " << endl;
			do {
				cout << "Nhap so luong sinh vien: ";
				cin >> n.n;
				cin.ignore();
				if (n.n < 0 || n.n>100)
					cout << "\nSo luong khong hop le! Vui long nhap lai." << endl;
			} while (n.n < 0 || n.n>100);
			nhapThongTin(n);
			ghepDanhSach(m, n,k);
			sapXepMathTang(k);
			cout << "\nDa sap xep tang dan theo diem toan" << endl;
			xuatDanhSach(k);
			break;
		case 11:
			int i;
			cout << "Nhap ID sinh vien can tim ";
			cin >> x;
			if (timKiemNhiPhan(m, x) != -1)
			{
				i = timKiemNhiPhan(m, x);
				cout << "Sinh vien can tim " << endl;
				cout << "ID: " << m.list[i].code << endl;
				cout << "Ho va ten: " << m.list[i].name << endl;
				cout << "Lop: " << m.list[i].grade << endl;
				cout << "Diem (Math, English, C++): " << m.list[i].subject[0] << " " << m.list[i].subject[1] << " " << m.list[i].subject[2] << endl;
			}
			else
				cout << "Khong tim thay sinh vien " << endl;
			break;
		case 12:
			if (kiemTraDiemTang(m))
				cout << "Danh sach tang dan theo diem trung binh " << endl;
			else
				cout << "Danh sach khong tang dan theo diem trung binh " << endl;
			break;
		case 13:
			if (kiemTraDiemGiam(m))
				cout << "Danh sach giam dan theo diem trung binh " << endl;
			else
				cout << "Danh sach khong giam dan theo diem trung binh " << endl;
			break;
		case 14:
			if (kiemTraSoSVGioi(m))
				cout << "So sinh vien gioi trong nua dau danh sach nhieu hon nua sau " << endl;
			else 	cout << "So sinh vien gioi trong nua dau danh sach khong nhieu hon nua sau " << endl;
			break;
		case 15:
			cout << "Hai sinh vien dau tien co tong diem toan nho hon 5 " << endl;
			tim2SVDiemToanNhoHon5(m,n);
			xuatDanhSach(n);
			break;
		case 16:
			themSVCheckCode(m);
			xuatDanhSach(m);
			break;
		case 17:
			cout << "Danh sach sinh vien xep loai gioi " << endl;
			tachsvLoaiGioi(m, n);
			xuatDanhSach(n);
			break;
		case 18:
			cout << "Danh sach sinh vien co thanh tich tot nhat " << endl;
			tachDanhSachSVTotNhat(m,n);
			xuatDanhSach(n);
			break;
		case 19:
			cout << "Sinh vien xuat sac nhat " << endl;
			i=svXuatSacNhat(m);
			cout << "ID: " << m.list[i].code << endl;
			cout << "Ho va ten: " << m.list[i].name << endl;
			cout << "Lop: " << m.list[i].grade << endl;
			cout << "Diem (Math, English, C++): " << m.list[i].subject[0] << " " << m.list[i].subject[1] << " " << m.list[i].subject[2] << endl;
			cout << "Diem trung binh: " << static_cast<int>(dtb(m, i) * 100 + 0.5) / 100.0;
			//static_cast<int>(dtb(m,i) * 100 + 0.5) / 100.0;
		default:
			break;
		}
	} while (chon != 0);
}