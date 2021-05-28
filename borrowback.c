#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data
{
    char title[200];
    char author[200];
    char code[200];
    int stock;
    char loc[200];
} loan[500];

struct borrow
{
    char title[100];
    char code[100];
    char id_borrow[100];
    char date[500];
} row[500];

struct back{
    char title[100];
    char code[100];
    char id_borrow[100];
    char dateloan[100];
    char dateback[100];
}back[500];
struct member
{
    char nama[50];
    char noTelp[15];
    char Alamat[100];
} mem[250];
char* borrow(char *comp)
{
    FILE *br;
    FILE *br2;
    int i = 0, r = 0, k, temp, size;
    char ch, dh;
    br = fopen("DB/dbLoan.txt", "r");
    if (br == NULL)
    {
        printf("FILE tidak ditemukan");
        exit(0);
    }
    while (ch != EOF)
    {
        fscanf(br, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c", row[i].title, row[i].code, row[i].id_borrow, row[i].date);
        ch = getc(br);
        i++;
    }
    temp = i;
    printf("%d", size);
    printf("Title:");
    fflush(stdin);
    gets(row[temp].title);
    printf("Code:");
    fflush(stdin);
    gets(row[temp].code);
    printf("Nama:");
    fflush(stdin);
    gets(row[temp].id_borrow);
    struct tm *info;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    strcpy(row[temp].date, asctime(info));
    br2 = fopen("DB/dbLoan.txt", "w");
    for (int j = 0; j <= temp; j++)
    {
        fprintf(br2, "%s; %s; %s; %s;", row[j].title, row[j].code, row[j].id_borrow, row[j].date);
        printf("Title: %s\nCode: %s\nNama: %s\nTanggal Pinjam: %s\n", row[j].title, row[j].code, row[j].id_borrow, row[j].date);
    }
    fclose(br2);
    fclose(br);
    strcpy(comp,row[temp].code);
    return comp;
}

void minusstck(char*str){
    FILE *db;
    FILE *io;
    char dp;
    int i = 0, size;
    db = fopen("DB/database.txt","r");
    if (db == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (dp != EOF)
    {
        fscanf(db, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %200[^;]%*c", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, &loan[i].loc);
        dp = fgetc(db);
        i++;
    }
    size = i;
    io = fopen("DB/database.txt", "w");
    for(int j = 0; j <= size; j++){
        if(strcmp(str,loan[j].code)==0){
            loan[j].stock -= 1;
        }
    }
    for(int j = 0; j<size;j++){
        fprintf(io, "%s;%s; %s; %d %s;", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
        
    }
    fclose(io);
    fclose(db);

}

int display()
{
    FILE *ptr;
    char ch;
    ptr = fopen("DB/dbMember.txt", "r");

    if (ptr == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    int i = 0;
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        printf("[%d]\n", i + 1);
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        i++;
        ch = fgetc(ptr);
    }
    fclose(ptr);
}
int getBack(){
    int save,i = 0,pilih;
    FILE *ptr;
    char ch;
    char nama[50];
    ptr = fopen("DB/dbLoan.txt","r");

    printf("Data Pinjaman");
    if (ptr == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c", row[i].title, row[i].code, row[i].id_borrow, row[i].date);
        printf("[%d]\n", i + 1);
        printf("Peminjam:%s\nJudul Buku:%s\nCode:%s\nTanggal Pinjam:%s\n",row[i].id_borrow,row[i].title,row[i].code,row[i].date);
        ch = getc(ptr);
        i++;
    }
    printf("1.Pilih Data Pengembalian");
    printf("2. Cari data lagi");
    scanf("%d",&pilih);
    if (pilih == 1){
        for (int j = 0; j<i;j++){
            printf("Peminjam:%s\nJudul Buku:%s\nCode:%s\nTanggal Pinjam:%s\n", row[j].id_borrow, row[j].title, row[j].code, row[j].date);
        }
        printf("Pilih Data Masukan Nomor: ");scanf("%d",&pilih);
        dataBack(row[pilih].id_borrow,row[pilih].title,row[i].code,row[i].date);
        delete(pilih);
    }
    else if(pilih ==2 ){
        printf("Masukan Nama:");
        fflush(stdin);
        gets(nama);
        pilih = searchBorrow(nama);
        dataBack(row[pilih].id_borrow, row[pilih].title, row[i].code, row[i].date);
        delete(pilih);
    }
    else{
        printf("Pilihan tak tersedia");
    }
    return 0;
}
int searchBorrow(char*nama){
    printf("zonk");
    return 5;
}
void delete(int target){
    FILE *w;
    int i;

    for (int k = target; k < i; k++)
    {
        row[k] = row[k + 1];
    }
    system("cls");
    puts("BERHASIL...");
    system("pause");
    i -= 1;
    w = fopen("DB/dbLoan.txt", "w");
    for (int j = 0; j < i; j++)
    {
        fprintf(w, " %s; %s; %s; %s;", row[j].title,row[j].code,row[j].id_borrow,row[j].date);
    }
    fclose(w);
}

char* getTime(){
    struct tm *info;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    return asctime(info);
}

void dataBack(char*user,char*title,char*code,char*date){
    int save, i = 0,j = 0,k=0;
    FILE *ptr;
    char ch;
    ptr = fopen("DB/dbBack.txt", "a");

    printf("Data Pengembalian");
    if (ptr == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    fprintf(ptr,"%s;%s;%s;%s;%s;",user,title,code,date,getTime());
    fclose(ptr);
}

int main(int argc, char* argv)
{
    char s[50];
 //   borrow(s);
   // printf("%s",s);
    //minusstck(s);
    getBack();


    return 0;
}