#include <stdio.h>
#include <math.h>

void bai1() {
    float d;
    printf("Nhap diem: "); scanf("%f", &d);
    if (d < 0 || d > 10) printf("Diem so nhap vao khong hop le\n");
    else printf("Hoc Luc: %s\n", d>=9?"Xuat sac":d>=8?"Gioi":d>=6.5?"Kha":d>=5?"Trung Binh":d>=3.5?"Yeu":"Kem");
}

void bai2() {
    float a, b, c, d;
    printf("Nhap a, b, c: "); scanf("%f%f%f", &a, &b, &c);
    if (!a) {
        if (!b) printf(c ? "Phuong trinh vo nghiem.\n" : "Phuong trinh vo so nghiem.\n");
        else printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", -c / b);
    } else {
        d = b * b - 4 * a * c;
        if (d < 0) printf("Phuong trinh vo nghiem\n");
        else if (!d) printf("Phuong trinh nghiem kep: x = %.2f\n", -b / (2 * a));
        else printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2f, x2 = %.2f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
    }
}

void bai3() {
    float k, t = 0;
    printf("Nhap so kwh tieu thu: "); scanf("%f", &k);
    if (k <= 0) { printf("So kwh khong hop le\n"); return; }
    
    if (k <= 50) t = k * 1678;
    else if (k <= 100) t = 50 * 1678 + (k - 50) * 1734;
    else if (k <= 200) t = 50 * 1678 + 50 * 1734 + (k - 100) * 2014;
    else if (k <= 300) t = 50 * 1678 + 50 * 1734 + 100 * 2014 + (k - 200) * 2536;
    else if (k <= 400) t = 50 * 1678 + 50 * 1734 + 100 * 2014 + 200 * 2536 + (k - 300) * 2834;
    else t = 50 * 1678 + 50 * 1734 + 100 * 2014 + 200 * 2536 + 300 * 2834 + (k - 400) * 2927;

    printf("Tien dien: %.0f VND\n", t);
}

int main() {
    int c;
    do {
        printf("\n=====MENU CHUONG TRINH LAB3=====\n1. Tinh hoc luc sinh vien\n2. Giai phuong trinh bac 2\n3. Tinh tien tieu thu\n0. Thoat Chuong Trinh\n==================================\nNhap lua chon cua ban: ");
        scanf("%d", &c);
        switch (c) {
            case 1: bai1(); break;
            case 2: bai2(); break;
            case 3: bai3(); break;
            case 0: printf("Thoat Chuong Trinh\n"); break;
            default: printf("Lua chon ko hop le\n");
        }
    } while (c != 0);
    return 0;
}