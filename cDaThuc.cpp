#include <iostream>
#include <cmath>
#include "cDaThuc.h"

using namespace std;

/* constructor */
cDaThuc::cDaThuc(int n) {
	bac = n;
	a = new float[bac + 1];

	for (int i = 0; i <= bac; i++)
		a[i] = 0;
}

/* destructor */
cDaThuc::~cDaThuc() {
	delete[] a;
}

/* nhập đa thức */
void cDaThuc::Nhap() {
	cout << "Nhap bac da thuc: ";
	cin >> bac;

	delete[] a;
	a = new float[bac + 1];

	for (int i = bac; i >= 0; i--) {
		cout << "Nhap he so bac " << i << ": ";
		cin >> a[i];
	}
}

/* xuất đa thức */
void cDaThuc::Xuat() {
	bool first = true; // kiểm tra phần tử đầu tiên
	bool allZero = true; // kiểm tra toàn bộ = 0

	for (int i = bac; i >= 0; i--) {
		if (a[i] != 0) {
			allZero = false;

			// xử lý dấu
			if (first) {
				if (a[i] < 0) cout << "-";
			}
			else {
				if (a[i] > 0) cout << " + ";
				else cout << " - ";
			}

			// in giá trị tuyệt đối
			float value = abs(a[i]);

			// xử lý hệ số
			if (value != 1 || i == 0)
				cout << value;

			// xử lý x
			if (i > 0) {
				cout << "x";
				if (i > 1) cout << "^" << i;
			}

			first = false;
		}
	}

	// nếu toàn bộ hệ số = 0
	if (allZero) cout << "0";

	cout << endl;
}

/* tính giá trị tại x */
float cDaThuc::TinhGiaTri(float x) {
	float s = 0;

	for (int i = 0; i <= bac; i++) {
		s += a[i] * pow(x, i);
	}

	return s;
}

/* cộng đa thức */
cDaThuc cDaThuc::Cong(const cDaThuc& dt) {
	int maxBac = (bac > dt.bac) ? bac : dt.bac;

	cDaThuc kq(maxBac);

	for (int i = 0; i <= maxBac; i++) {
		float h1 = (i <= bac) ? a[i] : 0;
		float h2 = (i <= dt.bac) ? dt.a[i] : 0;

		kq.a[i] = h1 + h2;
	}

	return kq;
}

/* trừ đa thức */
cDaThuc cDaThuc::Tru(const cDaThuc& dt) {
	int maxBac = (bac > dt.bac) ? bac : dt.bac;

	cDaThuc kq(maxBac);

	for (int i = 0; i <= maxBac; i++) {
		float h1 = (i <= bac) ? a[i] : 0;
		float h2 = (i <= dt.bac) ? dt.a[i] : 0;

		kq.a[i] = h1 - h2;
	}

	return kq;
}
