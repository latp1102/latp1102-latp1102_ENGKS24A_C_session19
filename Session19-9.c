#include <stdio.h>
#include <string.h>

struct SinhVien {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

void inSV(struct SinhVien sv[], int n);
void themSV(struct SinhVien sv[], int *n);
void suaSV(struct SinhVien sv[], int n);
void xoaSV(struct SinhVien sv[], int *n);
void timKiemSV(struct SinhVien sv[], int n);
void sapXepSV(struct SinhVien sv[], int n);

int main(){
	struct SinhVien sv[100] = {
        { 1, "nguyen van a", 30, "0111111111" },	
        { 2, "nguyen van d", 40, "0222222222" },	
        { 3, "nguyen van e", 35, "0333333333" },
        { 4, "nguyen van c", 60, "0444444444" },
        { 5, "nguyen van b", 55, "0555555555" },
    };
    
    int chose;
	int n = 5;
    do {
    	printf("--------Menu--------\n");
    	printf(" 1. Hien thi danh sach sinh vien\n ");
    	printf("2. Them sinh vien\n ");
    	printf("3. Sua thong tin sinh vien\n ");
    	printf("4. Xoa sinh vien\n ");
    	printf("5. Tim kiem sinh vien\n ");
    	printf("6. Sap xep danh sach sinh vien\n ");
    	printf("7. Thoat\n ");
    	printf("Lua chon cua ban: ");
    	scanf("%d",&chose);
    	fflush(stdin);
    	switch( chose){
    		case 1:{
    			inSV(sv, n);
				break;
			}
			case 2:{
				themSV(sv, &n);
				break;
			}
			case 3:{
				suaSV(sv, n);
				break;
			}
			case 4:{
				xoaSV(sv, &n);
				break;
			}
			case 5:{
				timKiemSV(sv, n);
				break;
			}
			case 6:{
				sapXepSV(sv, n); 
				break;
			}
			case 7:{
				printf("\nBan chon thoat");
				break;
			}
		}
	}while( chose != 7 );

	return 0;
}

void inSV( struct SinhVien sv[], int n){
	printf("Phan tu trong mang:\n ");
	for ( int i = 0; i< n; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}	
}

void themSV( struct SinhVien sv[], int *n){
	int index;
	printf("Vi tri them(1 - %d): ",*n+1);
	scanf("%d",&index);
	
	while ( index < 1 || index > (*n)+1 ){
		printf("Vui long nhap dung\n");
		printf("Vi tri them(1 - %d): ", (*n)+1);
		scanf("%d", &index);
	}
	fflush(stdin);
	for ( int i = *n; i>= index ; i--){
		sv[i].id = sv[i-1].id +1;
		strcpy( sv[i].name, sv[i-1].name);
		sv[i].age = sv[i-1].age;
		strcpy( sv[i].phoneNumber, sv[i-1].phoneNumber);
	}
	
	sv[index-1].id = index ;
	printf("Nhap ten sv: ");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int size = strlen(sv[index-1].name);
	sv[index-1].name[size-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("\nNhap sdt: ");
	fgets( sv[index-1].phoneNumber,sizeof( sv[index-1].phoneNumber),stdin);
	
	(*n)++;
	printf("\nKet qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void suaSV( struct SinhVien sv[], int n){
	int index;
	printf("Vi tri sua(1 - %d): ", n);
	scanf("%d", &index);
	
	while ( index < 1 || index > n ){
		printf("Vui long nhap dung\n");
		printf("Vi tri sua(1 - %d): ", n);
		scanf("%d", &index);
	}
	fflush(stdin);
	sv[index-1].id = index ;
	printf("Nhap ten sv:");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int len = strlen(sv[index-1].name);
	sv[index-1].name[len-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("Nhap sdt: ");
	fgets( sv[index-1].phoneNumber, sizeof( sv[index-1].phoneNumber), stdin);
	
	printf("Ket qua: \n");
	for ( int i = 0; i< n; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void xoaSV( struct SinhVien sv[], int *n){
	int index;
	printf("Vi tri xoa(1 - %d): ", *n);
	scanf("%d", &index);
	
	while( index < 1 || index > *n ){
		printf("Vui long nhap dung\n");
		printf("Vi tri them(1 - %d):\n ", *n );
		scanf("%d", &index);
	}
	fflush(stdin);
	for( int i = index-1 ; i < (*n)-1  ; i++){
		sv[i].id = sv[i+1].id ;
		strcpy( sv[i].name, sv[i+1].name);
		sv[i].age = sv[i+1].age;
		strcpy( sv[i].phoneNumber, sv[i+1].phoneNumber);
	}
	
	(*n)--;
	printf("Ket qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void sapXepSV( struct SinhVien sv[], int n){
	for( int i = 0; i< n; i++){
		for ( int j = 0; j< n-1-i; j++){
			if ( strcmp(sv[j].name, sv[j+1].name ) > 0 ){
				struct SinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
			}
		}
	}
	printf("Ket qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("ID: %d\n", sv[i].id);
		printf("Ten: %s\n", sv[i].name);
		printf("Tuoi: %d\n", sv[i].age);
		printf("Sdt: %s\n ", sv[i].phoneNumber);
	}
}

void timKiemSV( struct SinhVien sv[], int n){
	char input[50];
	int count = 0;
	
	printf("Nhap ten can tim: ");
	fgets( input, 50, stdin);
	int size = strlen(input);
	input[size-1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strcmp(sv[i].name, input) == 0 ){
			count = 1;
			printf("SV can tim: \n");
			printf("ID: %d\n", sv[i].id);
			printf("Ten: %s\n", sv[i].name);
			printf("Tuoi: %d\n", sv[i].age);
			printf("Sdt: %s\n ", sv[i].phoneNumber);
			break;
		}
	}
	if ( count == 0 ) printf(" Khong tim thay sv\n");
}

