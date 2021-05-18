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
    rd = fopen("database.txt", "r");
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
    sc = fopen("database.txt","r");
    char ai;
    if(sc ==NULL){
        printf("File tidak ditemukan");
        exit(0);
    }
    while(ai != EOF){
        fscanf(sc, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        printf("%s %s %s %d\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock);
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
    up = fopen("database.txt", "w");
    char dp;
    if (up == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (dp != EOF)
    {
        fscanf(up, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        printf("%s %s %s %d\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock);
        dp = fgetc(up);
        i++;
    }
    size = i;
    gets(title);
    fflush(stdin);
    for (find = 0; find < size; find++)
    {
        if (strcmp(loan[find].title,title) == 0){
            printf("\nStock sekarang: %d", loan[find].stock);
            scanf("%d",&loan[find].stock);
        }
        printf("%s %s %s %d\n", loan[find].title, loan[find].author, loan[find].code, loan[find].stock);
        fprintf(up,"%s %s %s %d", loan[find].title,loan[find].author, loan[find].code, loan[find].stock);
    }
    fclose(up);
}
int main()
{
    char chose[2];
    char ul[2];
    do{
        gets(chose);
        fflush(stdin);
            if(strcmp("1",chose)==0){
                view();
            }
            else if (strcmp("2", chose) == 0)
            {
                tester();
            }
            else if (strcmp("3", chose) == 0)
            {
                update();
            }
            else{
                printf("salah");
            }
        
        printf("\nUlang? Ketik 1: ");
        gets(ul);
        fflush(stdin);
    }while(strcmp("1",ul)==0);
    return 0;
}