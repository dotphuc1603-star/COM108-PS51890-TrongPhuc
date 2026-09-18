#include <stdio.h>

int main() {
    char mssv[] = "12345678";
    char hoTen[] = "Nguyen Van A";
    int namSinh = 2005;
    float diemTrungBinh = 8.25;

    int tuoi = 2026 - namSinh;

    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh);

    return 0;
}
