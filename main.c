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
} loan[500];

void view()
{
    int i = 0, j = 0, find;
    FILE *rd;
    rd = fopen("DB/database.txt", "r");
    char ch;
    if (rd == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (ch != EOF)
    {
        fscanf(rd, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %s", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, &loan[i].loc);
        printf("[%d]\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s\n", i + 1, loan[i].title, loan[i].author, loan[i].code, loan[i].stock, &loan[i].loc);
        ch = fgetc(rd);
        i++;
    }
    fclose(rd);
}

void search()
{
    int i = 0, find, size, get;
    char title[200];
    FILE *sc;
    sc = fopen("DB/database.txt", "r");
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
    get = strlen(title);
    for(find=0;find<size;find++)
    {
        if(strncmp(loan[find].title,title,get)==0){
            printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
        }
    }
    if (!find)
    {
        printf("\nBuku yang anda cari tidak ada atau judul yang anda tulis salah.");
    }
    fclose(sc);
}

void book_listing()
{
    int i = 0, find, size, get, get2;
    char title[200];
    char author[200];
    FILE *sc;
    sc = fopen("DB/database.txt", "r");
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
    get = strlen(title);
    for (find = 0; find < size; find++)
    {
        if (strncmp(loan[find].title, title, get) == 0)
        {
            printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
        }
    }
    if(!find)
    {
        printf("Bukunya gak ada. Coba cari dengan nama author");
    }
    printf("Masukkan author buku: ");
    fflush(stdin);
    gets(author);
    get2 = strlen(author);
    for (find = 0; find < size; find++)
    {
        if (strncmp(loan[find].title, title, get) == 0 && strncmp(loan[find].author, author, get2)==0)
        {
            printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
        }
    }
    if(!find){
        printf("Bukunya literaly gak ada");
    }
    fclose(sc);
}

void update()
{
    int i = 0, size, find = 0;
    char title[100];
    FILE *up;
    FILE *io;
    up = fopen("DB/database.txt", "r");
    char dp;
    if (up == NULL)
    {
        printf("File tidak ditemukan");
        exit(0);
    }
    while (dp != EOF)
    {
        fscanf(up, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %s", &loan[i].title, &loan[i].author, &loan[i].code, &loan[i].stock, &loan[i].loc);
        dp = fgetc(up);
        i++;
    }
    size = i;
    io = fopen("DB/database.txt", "w");
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
    printf("Pilih menu: ");
    scanf("%d", &menu);
    switch (menu)
    {
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
                w
                printf("Pilihan: ");
                scanf("%d", &inv);
                if (inv == 1)
                {
                    view();
                }
                else if (inv == 2)
                {
                    search();
                }
                else
                {
                    puts("Pilihan tidak tersedia");
                }
            }
            else if (strcmp("2", chose) == 0)
            {
                puts("Pendataan Buku");
                //jika ada
                book_listing();
                //jika tidak create
            }
            else if (strcmp("3", chose) == 0)
            {
                puts("Mencari Buku");
                search();
            }
            else if (strcmp("4", chose) == 0)
            {
                puts("Data Pinjam/Kembali");
                //belum ada tapi pakai kode tanggal maybe.
            }
            else if (strcmp("5", chose) == 0)
            {
                //database real belum.
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