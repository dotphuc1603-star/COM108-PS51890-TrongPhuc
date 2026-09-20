#include <stdio.h>
int main() {
char mssv[] = "12345678";
char hoTen[] = "Nguyen Van A";
float toan = 8.5;
float ly = 7.5;
float  hoa  = 8.0;
float diemtrungbinh = (toan * 2 + ly + hoa) / (float)4;
printf("Ma so sinh vien: %s\n", mssv);
printf("Ho Va Ten: %s\n", hoTen);
printf("Diem TRung Binh: %.2f\n", diemtrungbinh);
return 0;
}

