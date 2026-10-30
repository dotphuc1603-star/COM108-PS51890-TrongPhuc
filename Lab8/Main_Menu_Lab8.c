#include <stdio.h>
#include <string.h>

// --- ĐỊNH NGHĨA CẤU TRÚC SINH VIÊN ---
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// --- KHAI BÁO NGUYÊN MẪU HÀM (FUNCTION PROTOTYPE) ---
void nhapXuatDanhSach(struct SinhVien ds[], int *n);
void sapXepTheoDiem(struct SinhVien ds[], int n);
void timKiemTheoMSSV(struct SinhVien ds[], int n);
void xuatHocBongTheoNganh(struct SinhVien ds[], int n);

int main() {
    struct SinhVien ds[50];
    int n = 0; // Biến đếm số lượng sinh viên hiện có
    int choice;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 8              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien               |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan           |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV                   |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh        |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Loi nhap lieu! Vui long nhap so tu 1 den 5.\n");
            while (getchar() != '\n'); // Xóa bộ đệm
            continue;
        }
        while (getchar() != '\n'); // Xóa ký tự '\n' sót lại sau scanf

        switch (choice) {
            case 1:
                nhapXuatDanhSach(ds, &n);
                break;
            case 2:
                if (n == 0) {
                    printf("\nDanh sach rong! Vui long chon chuc nang 1 de nhap danh sach truoc.\n");
                } else {
                    sapXepTheoDiem(ds, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nDanh sach rong! Vui long chon chuc nang 1 de nhap danh sach truoc.\n");
                } else {
                    timKiemTheoMSSV(ds, n);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nDanh sach rong! Vui long chon chuc nang 1 de nhap danh sach truoc.\n");
                } else {
                    xuatHocBongTheoNganh(ds, n);
                }
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

// --- BÀI 1: NHẬP VÀ XUẤT DANH SÁCH SINH VIÊN ---
void nhapXuatDanhSach(struct SinhVien ds[], int *n) {
    printf("\n--- BAI 1: NHAP VA XUAT DANH SACH SINH VIEN ---\n");
    do {
        printf("Nhap so luong sinh vien (toi da 50): ");
        if (scanf("%d", n) != 1) {
            printf("Gia tri khong hop le!\n");
            while (getchar() != '\n');
            *n = 0;
        }
    } while (*n <= 0 || *n > 50);
    while (getchar() != '\n');

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        
        printf("MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = '\0';

        printf("Ten SV: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        ds[i].tenSV[strcspn(ds[i].tenSV, "\n")] = '\0';

        printf("Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        ds[i].nganhHoc[strcspn(ds[i].nganhHoc, "\n")] = '\0';

        do {
            printf("Diem TB (0.0 - 10.0): ");
            if (scanf("%f", &ds[i].diemTB) != 1) {
                printf("Diem khong hop le. Vui long nhap lai!\n");
                while (getchar() != '\n');
                ds[i].diemTB = -1;
            } else {
                while (getchar() != '\n');
            }
        } while (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0);
    }

    printf("\n--- DANH SACH SINH VIEN VUA NHAP ---\n");
    for (int i = 0; i < *n; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n", ds[i].diemTB);
    }
}

// --- BÀI 2: SẮP XẾP SINH VIÊN THEO ĐIỂM TĂNG DẦN ---
void sapXepTheoDiem(struct SinhVien ds[], int n) {
    printf("\n--- BAI 2: SAP XEP SINH VIÊN THEO DIEM TANG DAN ---\n");
    struct SinhVien svTemp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTB > ds[j].diemTB) {
                svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("Danh sach sinh vien sau khi sap xep tang dan theo diem TB:\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n", ds[i].diemTB);
    }
}

// --- BÀI 3: TÌM KIẾM SINH VIÊN THEO MÃ SỐ ---
void timKiemTheoMSSV(struct SinhVien ds[], int n) {
    printf("\n--- BAI 3: TIM KIEM SINH VIEN THEO MSSV ---\n");
    char searchMSSV[50];
    printf("Nhap MSSV can tim: ");
    fgets(searchMSSV, sizeof(searchMSSV), stdin);
    searchMSSV[strcspn(searchMSSV, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, searchMSSV) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", ds[i].mssv);
            printf("Ten SV: %s\n", ds[i].tenSV);
            printf("Nganh hoc: %s\n", ds[i].nganhHoc);
            printf("Diem TB: %.2f\n", ds[i].diemTB);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien co MSSV: %s\n", searchMSSV);
    }
}

// --- BÀI 4: XUẤT DANH SÁCH HỌC BỔNG THEO NGÀNH ---
void xuatHocBongTheoNganh(struct SinhVien ds[], int n) {
    printf("\n--- BAI 4: HOC BONG THEO NGANH (Diem TB >= 8.0) ---\n");
    int coNguoiDat = 0;

    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            coNguoiDat = 1;
            break;
        }
    }

    if (!coNguoiDat) {
        printf("Khong co sinh vien nao dat hoc bong.\n");
        return;
    }

    // Duyệt qua từng sinh viên để nhóm theo ngành
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            // Kiểm tra xem tên ngành này đã được in ở các bước trước đó chưa
            int daIn = 0;
            for (int k = 0; k < i; k++) {
                if (strcmp(ds[k].nganhHoc, ds[i].nganhHoc) == 0) {
                    daIn = 1;
                    break;
                }
            }

            // Nếu ngành chưa được in, tiến hành in tên ngành và liệt kê tất cả sinh viên đạt học bổng thuộc ngành đó
            if (!daIn) {
                printf("Nganh: %s\n", ds[i].nganhHoc);
                for (int j = 0; j < n; j++) {
                    if (strcmp(ds[j].nganhHoc, ds[i].nganhHoc) == 0 && ds[j].diemTB >= 8.0) {
                        printf("- %s - %s - Diem TB: %.2f\n", ds[j].mssv, ds[j].tenSV, ds[j].diemTB);
                    }
                }
            }
        }
    }
}