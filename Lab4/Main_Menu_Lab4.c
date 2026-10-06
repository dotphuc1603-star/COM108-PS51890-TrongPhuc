#include <stdio.h>

void chucnang1(void) {
    int min, max;
    int tong = 0;
    int biendem = 0;
    float trungbing;

    printf("Nhap so min: ");
    scanf("%d", &min);

    printf("Nhap so max: ");
    scanf("%d", &max);

    if (min > max) {
        printf("cu phap khong hop le\n");
        return;
    }

    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) {
            tong += i;
            biendem++;
        }
    }

    if (biendem == 0) {
        printf("Khong co so chia het cho 2 trong khoang nay\n");
    } else {
        trungbing = (float)tong / biendem;
        printf("Tong cac so chia het cho 2: %d\n", tong);
        printf("So luong chia het cho 2: %d\n", biendem);
        printf("Trung binh cong cac so chia het cho 2: %.2f\n", trungbing);
    }
}

void chucnang2(void) {
    int x;
    int i;
    int laNguyenTo = 1;

    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    if (x < 2) {
        laNguyenTo = 0;
    } else {
        for (i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }
    }

    if (laNguyenTo) {
        printf("%d la so nguyen to\n", x);
    } else {
        printf("%d khong phai la so nguyen to\n", x);
    }
}

void chucnang3(void) {
    int x;
    int i;
    int LaChinhPhuong = 0;

    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    if (x == 0) {
        LaChinhPhuong = 1;
    } else if (x > 0) {
        for (i = 1; i<= x; i++) {
            if (i * i == x) {
                LaChinhPhuong = 1;
                break;
            }
        }
    }

    if (LaChinhPhuong) {
        printf("%d la so chinh phuong\n", x);
    } else {
        printf("%d khong phai la so chinh phuong\n", x);
    }
}

int main(void) {
    int chon;
    do {
        printf("+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 4              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2     |\n");
        printf("| 2. Kiem tra so nguyen to                          |\n");
        printf("| 3. Kiem tra so chinh phuong                       |\n");
        printf("| 4. Thoat                                          |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                chucnang1();
                break;
            case 2:
                chucnang2();
                break;
            case 3:
                chucnang3();
                break;
            case 4:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon tu 1 den 4.\n");
                break;
        }
    } while (chon != 4);

    return 0;
}