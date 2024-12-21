#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void sapXepVaInDanhSach(struct SinhVien sv[], int n); 

int main() {
    struct SinhVien sv[50] = {
        {1, "nguyen van b", 12, "0111111111"},
        {2, "nguyen van d", 13, "0222222222"},
        {3, "nguyen van a", 14, "0333333333"},
        {4, "nguyen van e", 15, "0444444444"},
        {5, "nguyen van c", 16, "0555555555"}
    };
    sapXepVaInDanhSach(sv, 5);
    
    return 0;
}

void sapXepVaInDanhSach(struct SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(sv[j].name, sv[j + 1].name) > 0) {
                struct SinhVien temp = sv[j + 1];
                sv[j + 1] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("\nKet qua sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d", sv[i].id);
        printf("\nTen: %s", sv[i].name);
        printf("\nTuoi: %d", sv[i].age);
        printf("\nSdt: %s\n", sv[i].phoneNumber);
    }
}


