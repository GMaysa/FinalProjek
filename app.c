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

struct member
{
    char nama[50];
    char noTelp[15];
    char Alamat[100];
} mem[250];

struct borrowback
{
    char code[100];
    char title[100];
    char id_borrow[100];
    char date[100];
} row[500];

int main()
{
    struct tm *info;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    char chose[2];
    char ul[2];
    int menu, ch;
    printf("Menu:\n");
    puts("1. Data Buku");
    puts("2. Sistem Keanggotaan");
    puts("3.Data Pinjam/Kembali");
    puts("Pilih menu: ");
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
                puts("Anda ingin melihat yang mana? (ketik nomor untuk memilih)");
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
                puts("ZONK"); //database real belum.
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
        do
        {
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
            if (ch == 1)
            {
                system("cls");
                insert();
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
                update();
                system("pause");
            }
            else if (ch == 3)
            {
                system("cls");
                display();
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
                delete ();
                system("pause");
            }
            else
            {
                exit(1);
            }

        } while (ch != 0);
    default:
        printf("Menu tidak tersedia tolong lah ya...FUCEK");
    }
    return 0;
}

