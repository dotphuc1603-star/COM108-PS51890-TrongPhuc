#include <stdio.h>
int main() {
    float diemTB;
    int hanhKiem;
    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTB);
    printf("Nhap hanh kiem (1: Tot, 0: Khac): ");
    scanf("%d", &hanhKiem);
    int dkBiem = (diemTB >= 8.0f);
    int dkHanhKiem = (hanhKiem == 1);
    int ketQuaHocBong = dkBiem && dkHanhKiem;
    printf("Dieu kien diem trung binh >= 8: %d\n", dkBiem);
    printf("Dieu kien hanh kiem tot: %d\n", dkHanhKiem);
    printf("Ket qua xet hoc bong (1: Dat, 0: Khong dat): %d\n", ketQuaHocBong);
    return 0;
}