#include <stdio.h>
int main() {
    float luongmotngay;
    int songaycong;
    printf("Nhap luong mot ngay: ");
    scanf("%f", &luongmotngay);
    printf("Nhap so ngay cong: ");
    scanf("%d", &songaycong);
    float luongthang = luongmotngay * songaycong;
    float phucapantrua = luongthang * 0.2;
    float luongthucnhan = luongthang + phucapantrua;
printf("luong thang: %.2f\n", luongthang);
printf("phu cap an trua: %.2f\n", phucapantrua);
printf("luong thuc nhan: %.2f\n", luongthucnhan);
return 0;
}