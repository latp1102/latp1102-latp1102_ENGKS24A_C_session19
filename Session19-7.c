#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;                
    char name[50];
    int age;
    char phoneNumber[50];
};

void printSinhVien(struct SinhVien sinhvien[], int n);

void inSinhVien(struct SinhVien sinhvien[], int *n, int id);

int main() {
    int id, n = 5;
    struct SinhVien sv[50] = {
        {1, "nguyen van a", 12, "0111111111"},
        {2, "nguyen van b", 13, "0222222222"},
        {3, "nguyen van c", 14, "0333333333"},
        {4, "nguyen van d", 15, "0444444444"},
        {5, "nguyen van e", 16, "0555555555"}
    };

    printf("\nDanh sach sinh vien ban dau:\n");
    printSinhVien(sv, n);
    printf("\n\nNhap id can xoa: ");
    scanf("%d", &id);
    inSinhVien(sv, &n, id);

    return 0;
}

void printSinhVien(struct SinhVien sinhvien[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n\nID: %d", sinhvien[i].id);
        printf("\nTen: %s", sinhvien[i].name);
        printf("\nTuoi: %d", sinhvien[i].age);
        printf("\nSdt: %s", sinhvien[i].phoneNumber);
    }
}

void inSinhVien(struct SinhVien sinhvien[], int *n, int id) {
    int count = 0, index;
    for (int i = 0; i < *n; i++) {
        if (sinhvien[i].id == id) {
            count = 1;
            index = i;
            break;
        }
    }

    if (count == 0) {
        printf("\nKhong ton tai id can xoa");
    } else {
        for (int i = index; i < (*n) - 1; i++) {
            sinhvien[i] = sinhvien[i + 1];
        }
        (*n)--;
        printf("\nKet qua sau khi xoa: \n");
        printSinhVien(sinhvien, *n);
    }
}

