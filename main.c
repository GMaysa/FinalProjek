#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

typedef struct anggota{
    int id;
    char nama[MAX];
    char alamat[MAX];
    char no_telp[15];
}member;

void create(){
    member *u;
    FILE *ptr;
    int n;
    printf("Masukkan berapa banyak data yang akan diisi : ");
    scanf("%d", &n);

    u = (member *)calloc(n, sizeof(member));
    ptr = fopen("anggota.txt", "a");

    for(int i = 0; i < n; i++){
        u[i].id = i;
        printf("Masukkan Nama : ");
        fflush(stdin);
        scanf("%[^\n]s", &u[i].nama);
        printf("Masukkan Alamat : ");
        fflush(stdin);
        scanf("%[^\n]s", &u[i].alamat);
        fflush(stdin);
        printf("Masukkan No Telephone : ");
        scanf("%[^\n]s", &u[i].no_telp);
        
        fwrite(&u[i], sizeof(member),1,ptr);
    }
    fclose(ptr);
}

void update(){
    FILE *ptr;
    FILE *pls;
    ptr = fopen("anggota.txt", "r+");
    pls = fopen("anggota.txt", "a+");

    fclose(pls);
    fclose(ptr);
}
void display(){}
void delete(){}

int main(){
    int n;
    printf("PILIH : ");
    scanf("%d", &n);
    switch (n){
    case 1:
        create();
        break;

    case 2:
        display();
        break;

    case 3:
        update();
        break;

    case 4:
        delete();
        break;

    default:
        break;
    }
    
}