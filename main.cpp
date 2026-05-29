#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {
	cDaThuc p, q;

	cout << "Nhap da thuc P:\n";
	p.Nhap();

	cout << "Nhap da thuc Q:\n";
	q.Nhap();

	cout << "\nP(x) = ";
	p.Xuat();

	cout << "Q(x) = ";
	q.Xuat();

	float x;
	cout << "\nNhap x: ";
	cin >> x;

	cout << "P(" << x << ") = " << p.TinhGiaTri(x) << endl;
	cout << "Q(" << x << ") = " << q.TinhGiaTri(x) << endl;

	cDaThuc tong = p.Cong(q);
	cDaThuc hieu = p.Tru(q);

	cout << "\nP + Q = ";
	tong.Xuat();

	cout << "P - Q = ";
	hieu.Xuat();

	return 0;
}
