#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char title[200];
    char author[200];
    char code[200];
    int stock;
    char loc[200];
} loan[100];

void view()
{
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
        fscanf(rd, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %s", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, &loan[i].loc);
        printf("Title: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock, &loan[i].loc);
        ch = fgetc(rd);
        i++;
    }
    fclose(rd);
}

void search()
{
    int i = 0, find, size, get;
    char title[50];
    FILE *sc;
    sc = fopen("database.txt", "r");
    char ai;
    if (sc == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (ai != EOF)
    {
        fscanf(sc, "%s %s %s %d %s", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock);
        ai = fgetc(sc);
        i++;
    }
    size = i;
    gets(title);
    fflush(stdin);
    for (find = 0; find < size; find++)
    {
        if (strcmp(strlwr(loan[find].title), strlwr(title)) == 0)
        {
            printf("Title: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock, &loan[i].loc);
        }
        else
        {
            printf("Bukunay GAK ADA BOSQUE");
        }
    }
    fclose(sc);
}

void update()
{
    int i = 0, size, find = 0;
    char title[100];
    FILE *up;
    FILE *io;
    up = fopen("database.txt", "r");
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
    io = fopen("database.txt", "w");
    size = i;
    gets(title);
    fflush(stdin);
    for (find = 0; find < size; find++)
    {
        if (strcmp(loan[find].title, title) == 0)
        {
            printf("\nStock sekarang: %d", loan[find].stock);
            printf("\nUpdate stock: ");
            scanf("%d", &loan[find].stock);
        }
    }
    for (int j = 0; j < size; j++)
    {
        fprintf(io, "%s %s %s %d\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock);
        printf("%s %s %s %d\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock);
    }
    fclose(io);
    fclose(up);
}
int main()
{
    char chose[2];
    char ul[2];
    do
    {
        gets(chose);
        fflush(stdin);
        if (strcmp("1", chose) == 0)
        {
            view();
        }
        else if (strcmp("2", chose) == 0)
        {
            search();
        }
        else if (strcmp("3", chose) == 0)
        {
            update();
        }
        else
        {
            printf("salah");
        }

        printf("\nUlang? Ketik 1: ");
        fflush(stdin);
        gets(ul);
    } while (strcmp("1", ul) == 0);
    return 0;
}
