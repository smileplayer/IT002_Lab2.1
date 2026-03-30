#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

class NgayThangNam
{
private:
    int iNgay, iThang, iNam;

public:
    void Nhap();
    void Xuat();

    // Trả về ngày kế tiếp
    NgayThangNam TinhNgayThangNamTiepTheo();

};

#endif // NGAYTHANGNAM_H
