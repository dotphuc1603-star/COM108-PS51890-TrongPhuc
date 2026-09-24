#include <stdio.h>
#define PI 3.14159
int main() {
    float chieuDai, chieuRong, banKinh;
    float chuViHCN, dienTichHCN, chuViHT, dienTichHT;
    printf("Nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieuRong);
    printf("Nhap ban kinh: ");
    scanf("%f", &banKinh);
    chuViHCN = (chieuDai + chieuRong) * 2;
    dienTichHCN = chieuDai * chieuRong;
    chuViHT = 2 * PI * banKinh;
    dienTichHT = PI * banKinh * banKinh;
    printf("Chu vi hinh chu nhat: %.2f\n", chuViHCN);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTichHCN);
    printf("Chu vi hinh tron: %.2f\n", chuViHT);
    printf("Dien tich hinh tron: %.2f\n", dienTichHT);
    return 0;
}