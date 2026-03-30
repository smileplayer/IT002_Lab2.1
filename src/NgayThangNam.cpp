#include <iostream>
#include "NgayThangNam.h"

using namespace std;

// Hàm kiểm tra năm nhuận
// Input:int nam là năm cần kiểm tra
// Output: bool - true nếu là năm nhuận, nếu không là false
// Ý tưởng: năm nhuận chia hết cho 400 hay (chia hết cho 4 và không chia hết 100)
bool IsLeapYear(int nam)
{
    return ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0);
}

// Hàm trả về ngày tối đa của tháng
// Input: int thang, int nam - tháng và năm cần tìm ngày tối đa
// Output: int - số ngày tối đa của tháng đó
// Ý tưởng:
// - Tháng 2: năm nhuận là 29, không nhuận là 28
// - Tháng 4, 6, 9, 11: có 30 ngày
// - Còn lại trả về 31 ngày
int DayLimit(int thang, int nam)
{
    if (thang == 2)
        return IsLeapYear(nam) ? 29 : 28;

    if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        return 30;

    return 31;
}

// Phương thức nhập ngày, tháng, năm từ bàn phím (có kiểm tra lỗi nhập)
// Input: dữ liệu từ bàn phím
// Output: không có (gán giá trị cho thuộc tính)
void NgayThangNam::Nhap()
{
    while (true) // Lặp đến khi nhập hợp lệ
    {
        cout << "Nhap ngay: ";
        cin >> iNgay;

        cout << "Nhap thang: ";
        cin >> iThang;

        cout << "Nhap nam: ";
        cin >> iNam;

        // Kiểm tra lỗi nhập (nhập chữ)
        if (cin.fail())
        {
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(1000, '\n'); // Bỏ dữ liệu sai

            cout << "\n\nNgay ban nhap khong hop le, vui long nhap lai.\n";
            continue;
        }

        // Kiểm tra hợp lệ (<= 0 hay > giá trị tối đa đều không hợp lệ)
        if (iNgay <= 0 || iThang <= 0 || iNam <= 0 ||
            iThang > 12 || iNgay > DayLimit(iThang, iNam))
        {
            cout << "\nNgay ban nhap khong hop le, vui long nhap lai.\n";
            continue;
        }

        break; // Hợp lệ thì thoát
    }
}

// Phương thức xuất ngày tháng năm
// Input: không có (sử dụng thuộc tính của ngày đang gọi phương thức)
// Output: thông tin ngày tháng năm trên màn hình
void NgayThangNam::Xuat()
{
    cout << iNgay << '/' << iThang << '/' << iNam << '\n';
}

// Phương thức tìm ngày tiếp theo
// Input: không có (sử dụng thuộc tính của ngày đang gọi phương thức)
// Output: NgayThangNam - ngày tiếp theo
NgayThangNam NgayThangNam::TinhNgayThangNamTiepTheo()
{
    NgayThangNam temp = *this; // tránh thao tác trực tiếp lên dữ liệu gốc
    int maxDay = DayLimit(temp.iThang, temp.iNam);

    temp.iNgay++;
    if (temp.iNgay > maxDay) // Nếu ngày vượt quá ngày tối đa, sang tháng tiếp theo
    {
        temp.iNgay = 1;
        temp.iThang++;
    }

    if (temp.iThang > 12) // Nếu tháng vượt quá tháng tối đa, sang năm tiếp theo
    {
        temp.iThang = 1;
        temp.iNam++;
    }

    return temp;
}
