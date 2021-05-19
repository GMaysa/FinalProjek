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
        printf("[%d]\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", i+1, loan[i].title, loan[i].author, loan[i].code, loan[i].stock, &loan[i].loc);
        ch = fgetc(rd);
        i++;
    }
    fclose(rd);
}

void search()
{
    int i = 0, find=0, size, get;
    char title[200];
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
        fscanf(sc, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %s", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, &loan[i].loc);
        ai = fgetc(sc);
        i++;
    }
    size = i;
    printf("Masukan judul buku: ");
    fflush(stdin);
    gets(title);
    printf("%s", title);
    while (strncmp(strlwr(loan[find].title), strlwr(title),find)){
        printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
        find++;
    }
    if (!find){
        printf("\nBuku yang anda cari tidak ada atau judul yang anda tulis salah.");
    }
/*        for (find = 0; find < size; find++)
        {
            if (strcmp(loan[find].title, title) == 0)
            {
                printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
            }
            else
            {
                printf("Bukunay GAK ADA BOSQUE");
            }
        }*/
    fclose(sc);
}

void book_listing()
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
        printf("%s %s %s %d %s\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock);
        ai = fgetc(sc);
        i++;
    }
    size = i;
    printf("Masukan judul buku (tanpa spasi):");
    fflush(stdin);
    gets(title);
    printf("Masukkan author buku(tanpa spasi:");
    for (find = 0; find < size; find++)
    {
        if (strcmp(strlwr(loan[find].title), strlwr(title)) == 0)
        {
            printf("%s %s %s %d %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, loan[find].loc);
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
        fscanf(up, "%s %s %s %d", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, loan[i].loc);
        printf("%s %s %s %d\n", loan[i].title, loan[i].author, loan[i].code, loan[i].stock, loan[i].loc);
        dp = fgetc(up);
        i++;
    }
    io = fopen("database.txt", "w");
    size = i;
    gets(title);
    fflush(stdin);
    for (find = 0; find < size; find++)
    {
        if (strcmp(strlwr(loan[find].title), strlwr(title)) == 0)
        {
            printf("\nStock sekarang: %d", loan[find].stock);
            printf("\nUpdate stock: ");
            scanf("%d", &loan[find].stock);
        }
    }
    for (int j = 0; j < size; j++)
    {
        fprintf(io, "%s %s %s %d\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
        printf("%s %s %s %d\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
    }
    fclose(io);
    fclose(up);
}

int main()
{
    char chose[2];
    char ul[2];
    int menu;
    printf("Menu:");
    puts("1. Data Buku");
    printf("Pilih menu: "); scanf("%d", &menu);
    switch(menu){
        case 1:
            do
            {
                puts("Data Buku");
                puts("1.Iventaris");
                puts("2.Mobilitas Buku");
                puts("3.Mencari Buku");
                puts("4.Pembukuan Pinjam/Kembali");
                puts("5.Data Real");
                fflush(stdin);
                gets(chose);
                if (strcmp("1", chose) == 0)
                {
                    int inv;
                    puts("inventaris Buku");
                    puts("1. Semua informasi");
                    puts("2. Informasi Spesifik");
                    puts("Anda ingin melihat yang mana? (ketik nomor untuk memilih)");
                    printf("Pilihan: "); scanf("%d",&inv);
                    if(inv == 1){
                        view();
                    }
                    else if (inv == 2){
                        search();
                    }
                    else{
                        puts("Pilihan tidak tersedia");
                    }
                }
                else if (strcmp("2", chose) == 0)
                {
                    search();
                }
                else if (strcmp("3", chose) == 0)
                {
                    update();
                }
                else if (strcmp("4", chose) == 0)
                {
                    update();
                }
                else if (strcmp("5", chose) == 0)
                {
                    update();
                }
                else
                {
                    printf("Pilihan tidak tersedia goblok");
                }

                printf("\nUlang? Ketik 1: ");
                fflush(stdin);
                gets(ul);
            } while (strcmp("1", ul) == 0);            
            break;
        case 2:
            puts("BELOM ADA BANKS");
            break;
        default:
            printf("Menu tidak tersedia tolong lah ya...FUCEK");
    }
    return 0;
}
