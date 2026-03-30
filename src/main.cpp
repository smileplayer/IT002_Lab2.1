#include <iostream>
#include "NgayThangNam.h"

using namespace std;


int main()
{
    NgayThangNam a;
    a.Nhap();

    // tìm ngày tiếp theo của ngày vừa nhập
    NgayThangNam kq = a.TinhNgayThangNamTiepTheo();

    cout << "\nNgay ban nhap la: ";
    a.Xuat();

    cout << "Ngay hom sau la: ";
    kq.Xuat();

    return 0;
}









