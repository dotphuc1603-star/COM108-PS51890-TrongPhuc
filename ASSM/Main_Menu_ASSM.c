#include <stdio.h>
void chucnang1() {}
void chucnang2() {}
void chucnang3() {}
void chucnang4() {}
void chucnang5() {}
void chucnang6() {}
void chucnang7() {}
void chucnang8() {}
void chucnang9() {}
void chucnang10() {}

int main() {
    int luaChon = 0;

    do {
        printf("\n=================== MENU CHUC NANG ===================\n");
        printf("1. Kiem tra so nguyen, nguyen to, chinh phuong\n");
        printf("2. Tim Uoc so chung va Boi so chung cua 2 so\n");
        printf("3. Chuong trinh tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien hang thang\n");
        printf("5. Chuc nang doi tien \n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Chuong trinh vay tien mua xe\n");
        printf("8. Sap xep thong tin hoc luc sinh vien\n");
        printf("9. Xay dung game FPOLY-LOTT (2/15)\n");
        printf("10. Chuong trinh tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("======================================================\n");
        printf("Vui long chon chuc nang (0-10): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
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
                chucnang4();
                break;
            case 5:
                chucnang5();
                break;
            case 6:
                chucnang6();
                break;
            case 7:
                chucnang7();
                break;
            case 8:
                chucnang8();
                break;
            case 9:
                chucnang9();
                break;
            case 10:
                chucnang10();
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai tu 0 den 10.\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}