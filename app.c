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
    char nama[500];
    char noTelp[500];
    char Alamat[500];
} mem[500];

struct borrowback
{
    char code[100];
    char title[100];
    char id_borrow[100];
    char date[100];
} row[500];
char fileInv[] = "DB/dataBook.txt";
char fileMem[] = "DB/dbMember.txt";
char fileLoan[] = "DB/dbLoan.txt";
char fileBack[] = "DB/dbBack.txt";

long getLong(char*fileName)
{
    FILE *fp = NULL;
    long off;

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("failed to fopen %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, 0, SEEK_END) == -1)
    {
        printf("failed to fseek %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    off = ftell(fp);
    if (off == -1)
    {
        printf("failed to ftell %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return off;

    if (fclose(fp) != 0)
    {
        printf("failed to fclose %s\n", fileName);
        exit(EXIT_FAILURE);
    }
}
int getAll()
{
    int i = 0, j = 0, loop;
    FILE *rd;
    rd = fopen(fileInv, "r");
    char ch;
    if (rd == NULL)
    {
        printf("File tidak ditemukan");
        exit(1);
    }
    while (ch != EOF)
    {
        fscanf(rd, " %200[^;]%*c %200[^;]%*c %200[^;]%*c %d %200[^;]%*c", &loan[i].title, &loan[i].author, &loan[i].isbn, &loan[i].stock, &loan[i].loc);
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
            if (strncmp(loan[i].title,find,size) == 0)
            {
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
    int i = num - 1;
    printf("[%d]\nTitle:%s\nAuthor:%s\nISBN:%s\nStock:%d\nLocation:%s\n", num, loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
}

int getBook(char *title){
    int loop = getAll(),num;
    system("cls");
    int err = getSpec(title,1);
    if (err== 1){
        printf("Buku tidak tersedia");
        return 0;
    }
    if (err != 1){
        printf("Pilih Buku");scanf("%d",&num);
        viewBook(num);
        return num;
    }
    system("cls");
}
void createBook(char*title,char*author,char*isbn,int stock,char*loc){
    FILE *cb;
    char ch;
    cb = fopen(fileInv,"a");
    if(cb == NULL){
        printf("File tidak ditemukan");
    }
    fprintf(cb,"\n%s;\n%s;\n%s;\n%d\n%s;",title,author,isbn,stock,loc);
    fclose(cb);
}
void updateBook(int next,int stock){
    int loop = getAll();
    system("cls");
    FILE *ub;
    char ch;
    ub = fopen(fileInv,"w");
    if(ub == NULL){
        printf("File tidak ditemukan");
    }
    for(int i = 0; i<loop;i++){
        if(i == next-1){
            fprintf(ub,"%s;\n%s;\n%s;\n%d\n%s;", loan[i].title, loan[i].author, loan[i].isbn, stock, loan[i].loc);
        }
        else{
            fprintf(ub,"%s;\n%s;\n%s;\n%d\n%s;",loan[i].title,loan[i].author,loan[i].isbn,loan[i].stock,loan[i].loc);
        }
    }
    fclose(ub);
}
//Member System
void createMem(char*name,char*phone,char*address){
    FILE *cm;
    cm = fopen(fileMem,"a");
    int buff = getLong(fileMem);
    if(buff > 0){
        fprintf(cm,"\n");
    }
    fprintf(cm,"%s;\n%s;\n%s;",name,phone,address);
    fclose(cm);
}
int getallMem(){
    FILE *gm;
    char ch;
    int size,loop, i = 0;
    gm = fopen(fileMem,"r");
    if(gm == NULL){
        printf("File tidak ditemukan");
        exit(EXIT_FAILURE);
    }
    while(ch!=EOF){
        fscanf(gm," %200[^;]%*c %200[^;]%*c %200[^;]%*c",mem[i].nama,mem[i].noTelp,mem[i].Alamat);
        printf("[%d]\nName: %s\nPhone Number: %s\nAddress: %s\n",i+1,mem[i].nama,mem[i].noTelp,mem[i].Alamat);
        ch = fgetc(gm);
        i++;
        loop = i;
    }
    return loop;
    fclose(gm);
}
void viewMem(int num){
    int i = num - 1;
    printf("[%d]\nName: %s\nPhone Number: %s\nAddress: %s\n",num,mem[i].nama,mem[i].noTelp,mem[i].Alamat);
}
int getspecMem(char*info,int kind){
    int loop = getallMem(),err;
    int size = strlen(info);
    if(kind == 1){
        for(int i = 0;i<loop;i++){
            if(strncmp(mem[i].nama,info,size)==0){
                printf("[%d]\nName: %s\nPhone Number: %s\nAddress: %s\n",i+1,mem[i].nama,mem[i].noTelp,mem[i].Alamat);
                err = 0;
            }
        }
        if(err != 0){
            printf("Anggota tidak ditemukan!");
            return 1;
        }
    }
    else{
        printf("Pilihan tidak tersedia");
    }
}
int getMember(char*name){
    int loop = getallMem(), num;
    system("cls");
    int err = getspecMem(name, 1);
    if (err == 1)
    {
        printf("Buku tidak tersedia");
        return 0;
    }
    if (err != 1)
    {
        printf("Pilih Member");
        scanf("%d", &num);
        viewMem(num);
        return num;
    }
    system("cls");
}
void updateMem(int next,char*info,int kind){
    int loop = getallMem();
    system("cls");
    FILE *um;
    char ch;
    um = fopen(fileMem, "w");
    if (um == NULL)
    {
        printf("File tidak ditemukan");
    }
    if(kind == 1){
        for (int i = 0; i < loop; i++)
        {
            if (i == next - 1)
            {
                if(i>0){
                    fprintf(um,"\n");
                }
                fprintf(um,"%s;\n%s;\n%s;",info,mem[i].noTelp,mem[i].Alamat);
            }
            else{
                fprintf(um, "%s;\n%s;\n%s;",mem[i].nama,mem[i].noTelp,mem[i].Alamat);
            }
        }
    }
    else if(kind ==2){
        for (int i = 0; i < loop; i++)
        {
            if (i == next - 1)
            {
                fprintf(um, "%s;\n%s;\n%s;", mem[i].nama, info, mem[i].Alamat);
            }
            else if (i != next -1)
            {
                fprintf(um, "%s;\n%s;\n%s;", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
            }
        }
    }
    else if(kind == 3){
        for (int i = 0; i < loop; i++)
        {
            if (i == next - 1)
            {
                fprintf(um, "%s;\n%s;\n%s;", mem[i].nama, mem[i].noTelp, info);
            }
            if( i!= next -1)
            {
                fprintf(um, "%s;\n%s;\n%s;", mem[i].nama, mem[i].noTelp, mem[i].Alamat);
            }
        }
    }
    else{
        printf("Pilihan tidak tersedia");        
    }
    fclose(um);
}
int main()
{
    char chose[2];
    char ul[2];
    char info[500],info1[500],info2[500],info3[500],info4[500];
    int menu, ch, pilih, sub=0,stock;
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
            puts("3.Pembukuan Pinjam/Kembali");
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
                    printf ("%d",next);
                    if(next == 0){
                        printf("Buku tida terseida");
                        printf("Masukan Judul: ");
                        fflush(stdin);
                        gets(info1);
                        printf("Masukan Nama Penulis: ");
                        fflush(stdin);
                        gets(info2);
                        printf("Masukan ISBN: ");
                        fflush(stdin);
                        gets(info3);
                        printf("Masukan Stock: ");
                        scanf("%d",&stock);
                        printf("Masukan Lokasi: ");
                        fflush(stdin);
                        gets(info4);
                        createBook(info1,info2,info3,stock,info4);
                        //buat baru
                    }
                    if (next != 0){
                        printf("Buku tersedia");
                        printf("Update Stock: ");scanf("%d",&stock);
                        updateBook(next,stock);
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
                printf("Name Depan: ");
                fflush(stdin);
                gets(info);
                printf("Nama Belakang");
                fflush(stdin);
                gets(info1);
                strcat(info,info1);
                printf("Phone Number: ");
                fflush(stdin);
                gets(info2);
                printf("Address: ");
                fflush(stdin);
                gets(info3);
                createMem(info,info2,info3);
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
                printf("Masukan Nama Depan");
                fflush(stdin);
                gets(info);
                int next = getMember(info);
                if(next == 0 ){
                    puts("Anggota tidak ditemukan");
                }
                if(next != 0){
                    printf("Apa yang ingin kamu edit?\n1.Name\n2.Phone Number\n3.Address");
                    printf("Pilih:");scanf("%d",&pilih);
                    printf("Masukan Informasi (yang ingin diedit)");
                    fflush(stdin);
                    gets(info);
                    updateMem(next,info,pilih);
                }
                system("pause");
            }
            else if (ch == 3)
            {
                getallMem();
                system("pause");
            }
            else if (ch == 2)
            {
                system("cls");
            //    delMem ();
            // belom
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

