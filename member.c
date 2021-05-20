#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct member{
    char nama[50];
    char noTelp[15];
    char Alamat[100];
}mem[250];

int insert(){
    FILE *ptr;
    int i = 0;
    ptr = fopen("DB/dbMember.txt","a");

    puts("Masukkan data member baru...");
    printf("Nama: ");
    fflush(stdin);
    gets(mem[i].nama);
    printf("No Telp: ");
    fflush(stdin);
    gets(mem[i].noTelp);
    printf("Alamat: ");
    fflush(stdin);
    gets(mem[i].Alamat); 

    fprintf(ptr," %s; %s; %s;", mem[i].nama, mem[i].noTelp, mem[i].Alamat);

    fclose(ptr);
    system("cls");
    puts("BERHASIL...");
    return 0;
}
int update(){
    FILE *ptr, *w;
    char ch, nama[100];
    ptr = fopen("DB/dbMember.txt", "r");

    int i = 0;
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        ch = fgetc(ptr);
        i++;
    }
    printf("Masukkan nama member: ");
    fflush(stdin);
    gets(nama);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(mem[j].nama, nama) == 0)
        {
            puts("Masukkan data dengan benar...");
            printf("Nama: ");
            fflush(stdin);
            gets(mem[j].nama);
            printf("No Telp: ");
            fflush(stdin);
            gets(mem[j].noTelp);
            printf("Alamat: ");
            fflush(stdin);
            gets(mem[j].Alamat);
        }
        system("cls");
    }
    system("cls");
    w = fopen("DB/dbMember.txt", "w");
    for (int j = 0; j < i; j++)
    {
        if(j == 0){
            fprintf(w, "%s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        }else{
            fprintf(w, " %s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        }
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
    }
    fclose(w);
    fclose(ptr);
}

int display(){
    FILE *ptr;
    char ch;
    ptr = fopen("DB/dbMember.txt","r");

    if (ptr == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    int i = 0;
    while(ch != EOF){
        printf("%d\n", i);
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        i++;
        ch = fgetc(ptr);
    }
    fclose(ptr);
}

void delete(){
    FILE *ptr, *w;
    char ch, nama[100];
    ptr = fopen("DB/dbMember.txt", "r");

    int i = 0, target;
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        ch = fgetc(ptr);
        i++;
    }
    printf("Masukkan nama member: ");
    fflush(stdin);
    gets(nama);
    for (int j = 0; j < i; j++)
    {
        if(strcmp(mem[j].nama, nama) == 0){
            target = j;
        }
        system("cls");
    }
    for (int k = target; k < i; k++){
        mem[k] = mem[k + 1];
    }
    system("cls");
    puts("BERHASIL...");
    system("pause");
    i -= 1;
    w = fopen("DB/dbMember.txt", "w");
    for (int j = 0; j < i; j++){
        fprintf(w, " %s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
    }
    fclose(w);
    fclose(ptr);
}

int main(){
    int ch;
    do{
        system("cls");
        puts("Sistem Member");
        puts("1. Member baru");
        puts("2. Edit data");
        puts("3. Tampil data");
        puts("4. Delete data");
        puts("0. exit");
        
        puts("Anda ingin melihat yang mana? (ketik nomor untuk memilih)");
        printf("Pilihan: ");
        scanf("%d", &ch);

        switch (ch){
            case 1:
                system("cls");
                insert();
                system("pause");
            break;
            case 2:
                system("cls");
                update();
                system("pause");
            break;
            case 3:
                system("cls");
                display();
                system("pause");
            break;
            case 4:
                system("cls");
                delete();
                system("pause");
            break;
        
            default:
            break;
        }

    }while(ch != 0);
}