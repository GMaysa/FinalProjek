#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data
{
    char title[500];
    char author[500];
    char isbn[500];
    int stock;
    char loc[500];
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

int getAll()
{
    int i = 0, j = 0, loop;
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
        fscanf(rd, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %d %200[^;]%*c", &loan[i].title, &loan[i].author, &loan[i].isbn, &loan[i].stock, &loan[i].loc);
        printf("[%d]\nTitle: %s\nAuthor: %s\nISBN: %s\nStock: %d\nLocation: %s\n", i + 1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, &loan[i].loc);
        ch = fgetc(rd);
        i++;
        loop = i;
    }
    return loop;
    fclose(rd);
}

int getSpec(char*find, int kind){
    int loop = getAll();
    int size = strlen(find);
    int err;
    system("cls");
    if(kind == 1){
        for(int i =0;i<loop;i++){
            if(strncmp(loan[i].title,find,size)==0){
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n",i+1,loan[i].title,loan[i].author,loan[i].isbn,loan[i].stock,loan[i].loc);
                err = 0;
            }
        }
        if (err != 0){
            puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
            return 1;
        }

    }
    else if(kind == 2){
        for (int i = 0; i < loop; i++)
        {
            if (strncmp(loan[i].author, find, size)==0)
            {
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", i+1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
                err = 0;
            }
        }
            if (err != 0)
            {
                puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
                return 1;
            }
    }
    else if(kind == 3){
        for (int i = 0; i < loop; i++)
        {
            if (strncmp(loan[i].isbn, find, size)==0)
            {
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", i+1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
                err = 0;
            }
        }
            if (err != 0)
            {
                puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
                return 1;
            }
    }
    else {
        puts("Pilihan anda tidak tersedia");
    }

}

/*char *getMore(char *more, int kind,char*find,int size1)
{
    int loop = getAll();
    int size2 = strlen(more);
    int err;
    if (kind == 1)
    {
        for (int i = 0; i < loop; i++)
        {
            if (strncmp(loan[i].title, find, size1)==0 && strncmp(loan))
            {
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", i + 1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
                err = 0;
            }
            if (err != 0)
            {
                puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
            }
        }
    }
    else if (kind == 2)
    {
        for (int i = 0; i < loop; i++)
        {
            if (strncmp(loan[i].author, find, size))
            {
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", i + 1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
                err = 0;
            }
            if (err != 0)
            {
                puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
            }
        }
    }
    else if (kind == 3)
    {
        for (int i = 0; i < loop; i++)
        {
            if (strncmp(loan[i].isbn, find, size))
            {
                printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", i + 1, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
                err = 0;
            }
            if (err != 0)
            {
                puts("Buku tidak tersedia atau periksa kembali tulisan anda.");
            }
        }
    }
    else
    {
        puts("Pilihan anda tidak tersedia");
    }
}*/

int viewBook(int num){
    int i = num -1;
    printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", num, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
}
int getBook(char *title){
    int loop = getAll(),num;
    system("cls");
    int err = getSpec(title,1);
    if (err== 1){
        printf("Buku tidak tersedia");
        return 1;
    }
    if (err != 1){
        printf("Pilih Buku");scanf("%d",&num);
        viewBook(num);
        return 0;
    }
    system("cls");
}
int main()
{
    char chose[2];
    char ul[2];
    char info[500];
    int menu, ch, pilih, sub=0;
    printf("Menu:\n");
    puts("1. Data Buku");
    puts("2. Sistem Keanggotaan");
    puts("3. Data Pinjam/Kembali");
    puts("Pilih menu: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1: 
        do
        {
            puts("Data Buku");
            puts("1.Iventaris");
            puts("2.Pendataan Buku");
            puts("3.Mencari Buku");
            puts("4.Pembukuan Pinjam/Kembali");
            puts("5.Data Real");
            fflush(stdin);
            gets(chose);
            if (strcmp("1", chose) == 0)
            {
                puts("Inventaris Buku");
                puts("1. Semua informasi");
                puts("2. Informasi Spesifik");
                puts("Anda ingin melihat yang mana? (ketik nomor untuk memilih)");
                printf("Pilihan: ");
                scanf("%d", &sub);
                if (sub == 1)
                {
                    getAll();
                }
                else if (sub == 2)
                {
                    printf("Masukan Informasi:");
                    fflush(stdin);
                    gets(info);
                    printf("Jenis Informasi\n1.Judul\n2.Author\n3.ISBN\n");scanf("%d",&pilih);
                    getSpec(info,pilih);
                }
                else
                {
                    puts("Pilihan tidak tersedia");
                }
            }
            else if (strcmp("2", chose) == 0)
            {
                puts("Pendataan Buku");
                printf("1.Buku Masuk\n2.Hapus Data\n");scanf("%d",&sub);
                if(sub == 1){
                    printf("Masukan Judul Buku: ");
                    fflush(stdin);
                    gets(info);
                    int next = getBook(info);
                    if(next == 1){
                        printf("Ui");
                        //buat baru
                    }
                    if (next == 0){
                        printf("Ai");
                        //update
                    }

                }
                else if(sub == 2){

                }
                else{
                    printf("Pilihan tidak tersedia");
                }
            }
            else if (strcmp("3", chose) == 0)
            {
                puts("Data Pinjam/Kembali");
                //belum ada tapi pakai kode tanggal maybe.
            }
            else if (strcmp("4", chose) == 0)
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
          //      insert();
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
           //     update();
                system("pause");
            }
            else if (ch == 3)
            {
                system("cls");
           //     display();
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
          //      delete ();
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

