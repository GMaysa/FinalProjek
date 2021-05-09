#include <stdio.h>
#include <string.h>

struct data
{
    char book_title[200];
    char identy[200];
    char date_loan[200];
    char date_back[200];
}loan[100];

struct info
{
    char title[100];
    char author[100];
    int code;
    int stock;
}in[100];

void book_loan()
{
    FILE *bl;//pointer untuk menyimpan data peminjaman
    int i = 0;
    bl = fopen("database_boak_loan.txt","w");
    fprintf(bl,"\n-------------------------------------\nIdentitas Nama: ");
    fgets(loan->identy,sizeof(loan->identy),stdin);
    fputs(loan->identy,bl);
    fprintf(bl,"Judul Buku: ");
    fgets(loan->book_title, sizeof(loan->book_title), stdin);
    fputs(loan->book_title, bl);
    fprintf(bl,"Tanggal Peminjaman: ");
    fgets(loan->date_loan, sizeof(loan->date_loan), stdin);
    fputs(loan->date_loan, bl);
    fprintf(bl,"Tengat Pengembalian: ");
    fgets(loan->identy, sizeof(loan->identy), stdin);
    fputs(loan->identy, bl);
    fclose(bl);
}

void search_book()
{
    int i = 0, j = 0, find;
    char tit[100];
    FILE *sb;//pointer untuk menyimpan data yang dibuka
    FILE *sbc;
    sb = fopen("database_boak.txt","r");
    char ch;
    while(ch != EOF)
    {
        fscanf(sb,"\n%s\n%s\n%d\n%d", &in[i].title, &in[i].author,&in[i].code,&in[i].stock);
        printf("\n%s\n%s\n%d\n%d", in[i].title, in[i].author, in[i].code, in[i].stock);
        ch = fgetc(sb);
        i++;
    }
    gets(tit);
    fflush(stdin);
    while(strcmp(tit,in[j].title)!=0)
    {
        j++;
    }
    find = j;
    sbc = fopen("database_boak.txt", "a");
    in[find].stock = in[j].stock - 1;
    fprintf(sbc, in[find].stock);
    fclose(sbc);
    fclose(sb);
}

int main(){
    //Peminjaman Buku
    FILE *fp;
    int n;
    fp = fopen("database_boak_loan.txt", "a");
    fprintf(fp,"Data Peminjaman",n);
    fclose(fp);
    book_loan();
    search_book();
}