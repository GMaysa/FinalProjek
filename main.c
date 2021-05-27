#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//INVENTORY
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
    int i = 0, find,find2, size, get,get2,got,got2,bek;
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
    for(find=0;find<size;find++)
    {
        if(strncmp(loan[find].title,title,get)==0){
            printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
            got = 1;
        }
    }
    if(got == 1){
        printf("\nTerlalu banyak pilihan?");
        puts("ketik 1, untuk mencari author.");
        printf("\nPilih: ");scanf("%d",&bek);
        if (bek == 1)
        {
            fflush(stdin);
            gets(author);
            get2 = strlen(author);
            for (find2 = 0; find2 < size; find2++)
            {
                if (strncmp(loan[find2].author, author, get2) == 0)
                {
                    printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
                    got2 = 1;
                }
                if (got2 != 1)
                {
                    puts("Buku tidak ada!");
                }
            }
        }
        else if (bek!=1){
            puts("Terimakasih");
        }
    }
    else if (got!=1)
    {
        printf("\nBuku yang anda cari tidak ada\nCoba cari dengan nama author\nMasukan nama author:");
        fflush(stdin);
        gets(author);
        get2=strlen(author);
        for(find2=0;find2<size;find2++){
            if(strncmp(loan[find2].author,author,get2)==0){
                printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
                got2 = 1;
            }
            }
        }
        if(got2!=1){
            puts("Buku tidak ada!");
        }
    fclose(sc);
}

void book_listing()
{
    int i = 0, find,find2,size, get, get2,bek,got,got2,up,from;
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
    puts("Pendataan Buku:");
    printf("Masukan judul buku yang dicari: ");
    fflush(stdin);
    gets(title);
    get = strlen(title);
    for (find = 0; find < size; find++)
    {
        if (strncmp(loan[find].title, title, get) == 0)
        {
            printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
            got = 1;
        }
    }
    if(got == 1){
        printf("Sudah menemunkan? atau \nPiliham masih terlalu banyak?");
        puts("Ketik 1 untuk memilih buku sekarang atau 2 untuk mencari lagi?\nPilih:");
        scanf("%d",&bek);
        printf("\nIngin coba mencari dengan nama author?");
        printf("\nketik 1 untuk iya\nPilih: ");scanf("%d",&bek);
        if(bek == 1){
            printf("\nMasukkan author buku: ");
            fflush(stdin);
            gets(author);
            get2 = strlen(author);
            for (find2 = 0; find2 < size; find2++)
            {
                if (strncmp(loan[find2].title, title, get) == 0 && strncmp(loan[find2].author, author, get2) == 0)
                {
                    printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find2].title, loan[find2].author, loan[find2].code, loan[find2].stock, &loan[find2].loc);
                    up = find2;
                    from = 1;
                    got = 2;
                }
            }
            printf("Ingin update stock?\n ketik 2!\nPilih: ");scanf("%d",&bek);
            if(bek==2 && got == 2){
                update_inv(up,from);
            }
            else if(bek!=2 && got ==2){
                puts("Terimakasih");
            }
        }
        else if(bek != 1);{
            puts("Terimakasih");
        }
    }
    else if(got != 1);
    {
        printf("\nBukunya gak ada. Coba cari dengan nama author\n");
        printf("Masukkan author buku: ");
        fflush(stdin);
        gets(author);
        get2 = strlen(author);
        for (find = 0; find < size; find++)
        {
            if (strncmp(loan[find].author, author, get2)==0)
            {
                printf("\nTitle: %s\nAuthor: %s\nCode: %s\nStock: %d\nLocation: %s", loan[find].title, loan[find].author, loan[find].code, loan[find].stock, &loan[find].loc);
                got2 = 1;
            }
        }
        if(got2 !=1){
            printf("\nBukunya literaly gak ada\nSilahkan buat data baru");
            create();
        }
    }
    fclose(sc);
}

void create(){
    int i = 0, size;
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
    printf("\nData Baru");
    printf("Title:");
    fflush(stdin);
    gets(loan[size].title);
    printf("Author:");
    fflush(stdin);
    gets(loan[size].author);
    printf("Code:");
    fflush(stdin);
    gets(loan[size].code);
    printf("Stock:");
    scanf("%d",&loan[size].stock);
    printf("Location:");
    fflush(stdin);
    gets(loan[size].loc);
    for (int j = 0; j <= size; j++)
    {
        fprintf(io, "%s; %s; %s; %d %s\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
        printf("Title: %s\nAuthor: %s\nCode: %s\nStock: %d\n Location: %s\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
    }
    fclose(io);
    fclose(up);
}


void update_inv(int find,int from)
{
    int i = 0, size,save;
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
    printf("\nStock sekarang: %d", loan[find].stock);
    printf("\nUpdate stock: ");
    scanf("%d", &loan[find].stock);
    for (int j = 0; j < size; j++)
    {
        fprintf(io, "%s;%s;%s;%d%s\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
        printf("Title: %s\nAuthor: %s\nCode: %s\nStock: %d\n Location: %s\n", loan[j].title, loan[j].author, loan[j].code, loan[j].stock, loan[j].loc);
    }
    
    fclose(io);
    fclose(up);
}
//MEMBER SYSTEM
struct member
{
    char nama[50];
    char noTelp[15];
    char Alamat[100];
} mem[250];

int insert()
{
    FILE *ptr;
    int i = 0;
    ptr = fopen("DB/dbMember.txt", "a");

    puts("Masukkan data member baru...");
    printf("Nama: ");
    fflush(stdin);
    gets(mem[i].nama);
    printf("No Telp: ");
    fflush(stdin);
    gets(mem[i].noTelp);
    printf("Alamat: ");
    fflush(stdin);
    gets(mem[i].Alamat);

    fprintf(ptr, " %s; %s; %s;", mem[i].nama, mem[i].noTelp, mem[i].Alamat);

    fclose(ptr);
    system("cls");
    puts("BERHASIL...");
    return 0;
}
int update()
{
    FILE *ptr, *w;
    char ch, nama[100];
    ptr = fopen("DB/dbMember.txt", "r");

    int i = 0;
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        ch = fgetc(ptr);
        i++;
    }
    printf("Masukkan nama member: ");
    fflush(stdin);
    gets(nama);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(mem[j].nama, nama) == 0)
        {
            puts("Masukkan data dengan benar...");
            printf("Nama: ");
            fflush(stdin);
            gets(mem[j].nama);
            printf("No Telp: ");
            fflush(stdin);
            gets(mem[j].noTelp);
            printf("Alamat: ");
            fflush(stdin);
            gets(mem[j].Alamat);
        }
        system("cls");
    }
    system("cls");
    w = fopen("DB/dbMember.txt", "w");
    for (int j = 0; j < i; j++)
    {
        if (j == 0)
        {
            fprintf(w, "%s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        }
        else
        {
            fprintf(w, " %s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        }
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
    }
    fclose(w);
    fclose(ptr);
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
        printf("[%d]\n", i+1);
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        i++;
        ch = fgetc(ptr);
    }
    fclose(ptr);
}

void delete ()
{
    FILE *ptr, *w;
    char ch, nama[100];
    ptr = fopen("DB/dbMember.txt", "r");

    int i = 0, target;
    while (ch != EOF)
    {
        fscanf(ptr, "%200[^;]%*c %200[^;]%*c %200[^;]%*c", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
        ch = fgetc(ptr);
        i++;
    }
    printf("Masukkan nama member: ");
    fflush(stdin);
    gets(nama);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(mem[j].nama, nama) == 0)
        {
            target = j;
        }
        system("cls");
    }
    for (int k = target; k < i; k++)
    {
        mem[k] = mem[k + 1];
    }
    system("cls");
    puts("BERHASIL...");
    system("pause");
    i -= 1;
    w = fopen("DB/dbMember.txt", "w");
    for (int j = 0; j < i; j++)
    {
        fprintf(w, " %s; %s; %s;", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
        printf("Nama: %s\nNo Telp: %s\nAlamat: %s\n\n", mem[j].nama, mem[j].noTelp, mem[j].Alamat);
    }
    fclose(w);
    fclose(ptr);
}
//DATA PINJAM KEMBALI
struct borrowback
{
    char code[100];
    char title[100];
    char id_borrow[100];
    char date[100];
} row[500];

//INTERFACE MAIN MENU//
int main(){
    struct tm *info;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    char chose[2];
    char ul[2];
    int menu,ch;
    printf("Menu:\n");
    puts("1. Data Buku");puts("2. Sistem Keanggotaan");puts("3.Data Pinjam/Kembali");
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
                    puts("ZONK");//database real belum.
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
                if(ch == 1){
                    system("cls");
                    insert();
                    system("pause");
                }
                else if(ch == 2){
                    system("cls");
                    update();
                    system("pause");
                }
                else if (ch == 3){
                    system("cls");
                    display();
                    system("pause");
                }
                else if (ch == 2){
                    system("cls");
                    delete ();
                    system("pause");
                }
                else{
                    exit(1);
                }

            } while (ch != 0);
        default:
            printf("Menu tidak tersedia tolong lah ya...FUCEK");
    }
    return 0;
}