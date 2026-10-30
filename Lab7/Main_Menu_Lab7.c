#include <stdio.h>
#include <string.h>
#include <conio.h> // Thư viện hỗ trợ getch() cho Windows

// --- KHAI BÁO NGUYÊN MẪU HÀM (FUNCTION PROTOTYPE) ---
void demNguyenAmPhuAm();
void dangNhapHeThong();
void sapXepMangChuoi();
void doiThapPhanSangHexa();
void daoChuoi(char s[]);

int main() {
    int choice;
    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 7              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi              |\n");
        printf("| 2. Dang nhap bang Username va Password            |\n");
        printf("| 3. Sap xep chuoi theo chu cai                     |\n");
        printf("| 4. Doi so thap phan sang thap luc phan            |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Loi nhap lieu! Vui long nhap so tu 1 den 5.\n");
            while (getchar() != '\n'); // Xóa bộ đệm
            continue;
        }
        
        // Xóa ký tự '\n' còn sót lại trong bộ đệm sau khi dùng scanf
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                dangNhapHeThong();
                break;
            case 3:
                sapXepMangChuoi();
                break;
            case 4:
                doiThapPhanSangHexa();
                break;
            case 5:
                printf("\nThoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// --- BÀI 1: ĐẾM NGUYÊN ÂM VÀ PHỤ ÂM ---
void demNguyenAmPhuAm() {
    char s[256];
    printf("\n--- BAI 1: DEM NGUYEN AM VA PHU AM ---\n");
    printf("Nhap vao mot chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Xóa ký tự xuống dòng

    int nguyenAm = 0, phuAm = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        // Kiểm tra chữ cái (cả hoa và thường)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }
    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n", s, nguyenAm, phuAm);
}

// --- BÀI 2: ĐĂNG NHẬP USERNAME & PASSWORD (ẨN DẤU *) ---
void dangNhapHeThong() {
    char userSys[] = "admin";
    char passSys[] = "12345";

    char inputUser[50];
    char inputPass[50];
    int i = 0;
    char ch;

    printf("\n--- BAI 2: DANG NHAP HE THONG ---\n");
    printf("Nhap username: ");
    fgets(inputUser, sizeof(inputUser), stdin);
    inputUser[strcspn(inputUser, "\n")] = '\0';

    printf("Nhap password: ");
    // Vòng lặp đọc từng ký tự mật khẩu và ẩn bằng dấu '*'
    while (1) {
        ch = getch();
        if (ch == 13 || ch == 10) { // Phím Enter
            inputPass[i] = '\0';
            break;
        } else if (ch == 8 || ch == 127) { // Phím Backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // Xóa dấu sao trên màn hình
            }
        } else if (i < (int)sizeof(inputPass) - 1) {
            inputPass[i++] = ch;
            printf("*");
        }
    }
    printf("\n");

    // So sánh chuỗi bằng strcmp
    if (strcmp(inputUser, userSys) == 0 && strcmp(inputPass, passSys) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

// --- BÀI 3: SẮP XẾP MẢNG CHUỖI THEO THỨ TỰ CHỮ CÁI ---
void sapXepMangChuoi() {
    char s[5][20];
    char temp[20];

    printf("\n--- BAI 3: SAP XEP MANG CHUOI ---\n");
    printf("Nhap vao 5 chuoi:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nhap chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }

    // Thuật toán Bubble Sort kết hợp strcmp và strcpy
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

// --- HÀM PHỤ TRỢ: ĐẢO NGƯỢC CHUỖI CHO BÀI 4 ---
void daoChuoi(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// --- BÀI 4: ĐỔI SỐ THẬP PHÂN SANG THẬP LỤC PHÂN (HEXA) ---
void doiThapPhanSangHexa() {
    int n;
    printf("\n--- BAI 4: DOI THAP PHAN SANG THAP LUC PHAN ---\n");
    printf("Nhap vao mot so nguyen khong am: ");
    if (scanf("%d", &n) != 1) {
        printf("So nhap vao khong hop le!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // Xóa bộ đệm

    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    if (n == 0) {
        printf("So thap luc phan cua 0 la: 0\n");
        return;
    }

    char hexChars[] = "0123456789ABCDEF";
    char hexResult[100] = "";
    int tempN = n;
    int idx = 0;

    while (tempN > 0) {
        int remainder = tempN % 16;
        hexResult[idx++] = hexChars[remainder];
        tempN /= 16;
    }
    hexResult[idx] = '\0';

    // Đảo ngược chuỗi vì các số dư lấy từ thấp đến cao
    daoChuoi(hexResult);

    printf("So thap luc phan cua %d la: %s\n", n, hexResult);
}