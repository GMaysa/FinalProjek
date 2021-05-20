#include <stdio.h>
#include <stdlib.h>
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

    fprintf(ptr,"%s; %s; %s; ", mem[i].nama, mem[i].noTelp, mem[i].Alamat);

    fclose(ptr);
    system("cls");
    puts("BERHASIL...");
    system("pause");
    return 0;
}
int update(){}

int display(){
    FILE *ptr;
    char ch;
    ptr = fopen("DB/dbMember.txt","r");

    int i = 0;
    while(ch != EOF){
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        // printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        ch = fgetc(ptr);
        i++;
    }
    for(int j = 0; j < i; j++){
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
    }

    fclose(ptr);
}

int delete(){}

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
            break;
            case 2:
                system("cls");
                update();
            break;
            case 3:
                system("cls");
                display();
            break;
            case 4:
                system("cls");
                delete();
            break;
        
            default:
            break;
        }

    }while(ch != 0);
}