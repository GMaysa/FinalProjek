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
} lo[500],lo2[500];

struct borrowback
{
    char title[100];
    char code[100];
    char id_borrow[100];
    char date[100];
} row[500];

int borrow(){
    FILE *br;
    FILE *br2;
    FILE *db;
    FILE *db2;
    int i =0 ,r=0,k,temp,size;
    char t[] = "YYY";
    char ch,dh;
    puts(t);
    db = fopen("DB/database.txt","r");
    if (db == NULL){
        printf("File tidak ditemukan");
        exit(0);
    }
    while(dh != EOF){
        fscanf(db, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %s",lo[r].title,lo[r].author,lo[r].code,lo[r].stock,lo[r].loc);
        dh = getc(db);
        r++;
    }
    puts(t);
    size = r;
    br = fopen("DB/dbLoan.txt","r");
    if(br == NULL){
        printf("FILE tidak ditemukan");
        exit(0);
    }
    while(ch !=EOF){
       fscanf(br, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c", row[i].title,row[i].code,row[i].id_borrow, row[i].date);
       ch=getc(br);
       i++;
    }
    puts(t);
    temp = i;
    printf("%d",size);
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
    strcpy(row[temp].date,asctime(info));
    for(k = 0; k<size;k++){
        if(strcmp(lo[k].code,row[temp].code)==0){
            lo[k].stock -= 1;
        }
    }
    db2 = fopen("DB/database.c","w");
    for(int j = 0; j<=size;j++){
        printf("[%d]\nTilte: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", lo[j].title, lo[j].author, lo[j].code, lo[j].stock, lo[j].loc);
        fprintf(db2,"%s; %s; %s; %d %s\n",lo[j].title,lo[j].author,lo[j].code,lo[j].stock,lo[j].loc);
    }
    br2 = fopen("DB/dbLoan.txt","w");
        for (int j = 0; j <= temp; j++)
    {
        fprintf(br2, "%s; %s; %s; %s\n", row[j].title,row[j].code, row[j].id_borrow, row[j].date);
        printf("Title: %s\nCode: %s\nNama: %s\nTanggal Pinjam: %s\n", row[j].title,row[j].code, row[j].id_borrow, row[j].date);
    }
    
    fclose(br2);
    fclose(db2);
    fclose(db);
    fclose(br);
}
int main(){
    borrow();
    return 0;
}