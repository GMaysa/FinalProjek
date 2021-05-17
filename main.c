#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char title[200];
    char author[200];
    char code[200];
    int stock;
}loan[100];

void view(){
    int i = 0, j = 0, find;
    FILE *rd;
    rd = fopen("database_boak.txt", "r");
    char ch;

    if (rd == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (ch != EOF)
    {
        fscanf(rd, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        printf("%s %s %s %d\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock);
        ch = fgetc(rd);
        i++;
    }
    fclose(rd);
}

void tester(){
    int i = 0, find, size, get;
    char code[50];
    FILE *sc;
    sc = fopen("database_boak.txt","r");
    char ai;
    if(sc ==NULL){
        printf("File tidak ditemukan");
        exit(0);
    }
    while(ai != EOF){
        fscanf(sc, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        ai = fgetc(sc);
        i++;
    }
    size = i;
    gets(code);
    fflush(stdin);
    for(find = 0; find < size; find++){
        if(strcmp(loan[find].code,code) == 0){
            printf("%s %s %s %d", loan[find].title, loan[find].author, loan[find].code, loan[find].stock);
        }
    }
    fclose(sc);
}

void update(){
    int i = 0, size,find=0;
    char title[100];
    FILE *up;
    up = fopen("database_boak.txt", "w");
    char dp;
    if (up == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (dp != EOF)
    {
        fscanf(up, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        dp = fgetc(up);
        i++;
    }
    size = i;
    gets(title);
    fflush(stdin);
    for (find = 0; find < size; find++)
    {
        if (strcmp(loan[find].title, title) == 0){
            printf("Stock sekarang: %d", loan[find].stock);
            fprintf(up,"%d",loan[find].stock);
        }
    }
    fclose(up);
}
int main()
{
    int chose,ul;
    do{
        scanf("%d", &chose);
        switch(chose){
            case 1:
                view();
                break;
            
            case 2:
                tester();
                break;

            case 3:
                update();
                break;
            
            case 4:
                exit(0);
                break;
            default:
                printf("salah");
        }
        printf("Ulang? Ketik 1: ");scanf("%d", &ul);
    }while(ul == 1);
    return 0;
}