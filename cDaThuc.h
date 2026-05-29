#pragma once
#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc {
private:
	int bac;
	float* a;

public:
	cDaThuc(int n = 0); // constructor
	~cDaThuc();         // destructor
	void Nhap();
	void Xuat();
	float TinhGiaTri(float x);
	cDaThuc Cong(const cDaThuc& dt);
	cDaThuc Tru(const cDaThuc& dt);
};

#endif
