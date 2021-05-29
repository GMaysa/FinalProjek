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
    char title[500];
    char isbn[500];
    char name[500];
    char loanTime[500];
    char backTime[500];
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
    long size = getLong(fileInv);
    if(size == 0){
        printf("File kosong");
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

void delBook(int target)
{
    int loop = getAll(), i;
    system("cls");
    FILE *db;
    for (i = target-1; i < loop; i++)
    {
        loan[i] = loan[i + 1];
    }
    i -= 1;
    db = fopen(fileInv, "w");
    for (int j = 0; j < i; j++)
    {
        if (j > 0)
        {
            fprintf(db, "\n");
        }
        fprintf(db, "%s;\n%s;\n%s;\n%d\n%s;", loan[j].title,loan[j].author,loan[j].isbn,loan[j].stock,loan[j].loc);
    }
    fclose(db);
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
                if (i > 0)
                {
                    fprintf(um, "\n");
                }
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
                if (i > 0)
                {
                    fprintf(um, "\n");
                }
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
void delMem(int target){
    int loop = getallMem(),i;
    system("cls");
    FILE *dm;
    for(i = target; i<loop;i++){
        mem[i] = mem[i+1];
    }
    i-=1;
    dm = fopen(fileInv,"w");
    for(int j = 0; j<i;j++){
        if (j > 0)
        {
            fprintf(dm, "\n");
        }
        fprintf(dm,"%s;\n%s;\n%s;",mem[j].nama,mem[j].noTelp,mem[j].Alamat);
    }
    fclose(dm);
}
//Sistem Pengembalian
char *getTime(){
    struct tm *info;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    return asctime(info);
}
int getallLoan(){
    int i = 0,loop;
    FILE *gal;
    gal = fopen(fileLoan,"r");
    char ch;
    if(gal == NULL){
        printf("File tidak ditemukan!");
    }
    long size = getLong(fileLoan);
    if(size==0){
        printf("File Kosong");
        exit(1);
    }
    while(ch!= EOF){
        fscanf(gal,"%200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c",row[i].title,row[i].isbn,row[i].name,row[i].loanTime);
        printf("[%d]\nTitle: %s\nISBN: %s\nLoan by %s\nLoan time %s\n",i+1,row[i].title,row[i].isbn,row[i].name,row[i].loanTime);
        ch = fgetc(gal);
        i++;
        loop = i;
    }
    return loop;
    fclose(gal);
}
void delLoan(char*isbn,char*namaDepan){
    int loop = getallLoan(), i,target;
    system("cls");
    FILE *dl;
    int size = strlen(namaDepan);
    for (i = 0; i < loop; i++)
    {
        if (strcmp(row[i].isbn, isbn) == 0 && strncmp(row[i].name, namaDepan, size) == 0)
        {
            target = i;
        }
    }
    for (i = target; i < loop; i++)
    {
        row[i] = row[i + 1];
    }
    i -= 1;
    dl = fopen(fileLoan, "w");
    for (int j = 0; j < i; j++)
    {
        if (j > 0)
        {
            fprintf(dl, "\n");
        }
        fprintf(dl, "%s;\n%s;\n%s;\n%s;", row[j].title, row[j].isbn, row[j].name,row[j].loanTime);
    }
    fclose(dl);
}
char*getspecLoan(char*isbn){
    int loop = getAll();
    system("cls");
    for(int i = 0; i<loop; i++){
        if(strcmp(loan[i].isbn,isbn)==0){
            return loan[i].title;
        }
    }
}
char*getDate(char*isbn,char*namaDepan){
    int loop = getallLoan(),i=0;
    system("cls");
    int size = strlen(namaDepan);
    for(int i = 0; i<loop;i++){
        if(strcmp(row[i].isbn,isbn)==0 && strncmp(row[i].name,namaDepan,size)==0){
            return row[i].loanTime;
        }
    }
}
void minusStock(char*isbn){
    int loop = getAll();
    system("cls");
    FILE *ms;
    ms = fopen(fileInv,"w");
    char ch;
    if(ms == NULL){
        printf("File tidak ditemukan");
        exit(1);
    }
    for(int i = 0; i <loop; i++){
        if(strcmp(isbn,loan[i].isbn)==0){
            loan[i].stock -= 1;
        }
    }
    for(int i = 0; i<loop;i++){
        if(i>0){
            fprintf(ms,"\n");
        }
        fprintf(ms,"%s;\n%s;\n%s;\n%d\n%s; ",loan[i].title,loan[i].author,loan[i].isbn,loan[i].stock,loan[i].loc);
    }
    fclose(ms);
}
int getallBack()
{
    int i = 0, j = 0, loop;
    FILE *gab;
    gab = fopen(fileBack, "r");
    char ch;
    if (gab == NULL)
    {
        printf("File tidak ditemukan!");
    }
    long size = getLong(fileBack);
    if (size == 0)
    {
        printf("File Kosong");
        exit(1);
    }
    do{
        fscanf(gab, "%200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c %200[^;]%*c", row[i].title, row[i].isbn, row[i].name, row[i].loanTime, row[i].backTime);
        printf("[%d]\nTitle: %s\nISBN: %s\nLoan by %s\nLoan time at %s\nBack time at %s ",i+1,row[i].title, row[i].isbn, row[i].name, row[i].loanTime,row[i].backTime);
        ch = fgetc(gab);
        i++;
        loop = i;
    }while (ch != EOF);
    return loop;
    fclose(gab);
}
void plusStock(char *isbn)
{
    int loop = getAll();
    system("cls");
    FILE *ms;
    ms = fopen(fileInv, "w");
    char ch;
    if (ms == NULL)
    {
        printf("File tidak ditemukan");
        exit(1);
    }
    for (int i = 0; i < loop; i++)
    {
        if (strcmp(isbn, loan[i].isbn) == 0)
        {
            loan[i].stock += 1;
        }
    }
    for (int i = 0; i < loop-1; i++)
    {
        if (i > 0)
        {
            fprintf(ms, "\n");
        }
        fprintf(ms, "%s;\n%s;\n%s;\n%d\n%s; ", loan[i].title, loan[i].author, loan[i].isbn, loan[i].stock, loan[i].loc);
    }
    fclose(ms);
}
int checkStock(char*isbn){
    int loop = getAll(), i = 0;
    system("cls");
    for (int i = 0; i < loop; i++)
    {
        if (strcmp(loan[i].isbn, isbn) == 0)
        {
            return loan[i].stock;
        }
    }
}
void createLoan(char*isbn,char*name,char*loanTime){
    FILE *cl;
    cl = fopen(fileLoan,"a");
    int size = getLong(fileLoan);
    char*title = strdup(getspecLoan(isbn));
    int stock = checkStock(isbn);
    if (stock == 0){
        printf("Stock Kosong");
        exit(1);
    }
    if(size > 0){
        fprintf(cl,"\n");
    }
    fprintf(cl,"%s;\n%s;\n%s;\n%s; ",title,isbn,name,loanTime);
    minusStock(isbn);
    fclose(cl);
}
void createBack(char*isbn,char*name,char*backTime){
    FILE *cb;
    cb = fopen(fileBack, "a");
    int size = getLong(fileBack);
    char *title = strdup(getspecLoan(isbn));
    char *loanTime = strdup(getDate(isbn,name));
    if (size > 0)
    {
        fprintf(cb, "\n");
    }
    fprintf(cb, "%s;\n%s;\n%s;\n%s;\n%s; ", title, isbn, name, loanTime, backTime);
    plusStock(isbn);
    delLoan(isbn,name);
    fclose(cb);
}

int main(){
    char chose[2];
    char ul[2];
    char info[500],info1[500],info2[500],info3[500],info4[500];
    int menu, ch, pilih, sub=0,stock;
    menu :
    system("cls");
    printf("Menu:\n");
    puts("1. Data Buku");
    puts("2. Sistem Keanggotaan");
    puts("3. Data Pinjam/Kembali");
    puts("0. Exit");
    printf("PILIH: ");
    scanf("%d", &menu);
    switch (menu)
    {
        case 1: 
            do
            {
                dataBuku :  
                system("cls");
                puts("Data Buku");
                puts("1. Iventaris");
                puts("2. Pendataan Buku");
                puts("3. Pembukuan Pinjam/Kembali");
                puts("4. Kembali");
                printf("PILIH: ");
                fflush(stdin);
                gets(chose);
                if (strcmp("1", chose) == 0){
                    int nil;
                    system("cls");
                    puts("Inventaris Buku");
                    puts("1. Semua informasi");
                    puts("2. Informasi Spesifik");
                    puts("3. Kembali");
                    printf("Pilihan: ");
                    scanf("%d", &sub);
                    if (sub == 1){
                        system("cls");
                        getAll();
                    }
                    else if (sub == 2){
                        system("cls");
                        printf("Masukan Informasi:");
                        fflush(stdin);
                        gets(info);
                        printf("Jenis Informasi\n1.Judul\n2.Author\n3.ISBN\n");scanf("%d",&pilih);
                        getSpec(info,pilih);
                    }
                    else if (sub == 3){
                        goto dataBuku;
                    }
                    else{
                        puts("Pilihan tidak tersedia");
                    }
                }
                else if (strcmp("2", chose) == 0){
                    system("cls");
                    puts("Pendataan Buku");
                    printf("1. Buku Masuk\n2. Hapus Data\n3. Kembali\n");
                    scanf("%d", &sub);
                    if(sub == 1){
                        printf("Masukan Judul Buku: ");
                        fflush(stdin);
                        gets(info);
                        int next = getBook(info);
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
                        printf("Masukan Judul Buku: ");
                        fflush(stdin);
                        gets(info);
                        int next = getBook(info);
                        if (next == 0)
                        {
                            puts("Buku tidak tersedia");
                        }
                        if (next != 0){
                            printf("Input nomor buku yang ingin kamu hapus!");
                            printf("Input");scanf("%d",&pilih);
                            delBook(pilih);
                        }
                    }
                    else if(sub == 3){
                        goto dataBuku;
                    }
                    else{
                        printf("Pilihan tidak tersedia");
                    }
                }
                else if (strcmp("3", chose) == 0)
                {
                    puts("Data Pinjam/Kembali");
                    printf("1.Data Peminjaman\n2.Data Pengembalian\n3.Tampilkan Semua\n4.Kembali\n");
                    printf("Pilih: ");scanf("%d",&pilih);
                    if(pilih == 1){
                        printf("Data Peminjaman\n");
                        getallLoan();
                    }
                    else if (pilih == 2){
                        printf("Data Pengembalian\n");
                        getallBack();

                    }
                    else if(pilih == 3){
                        printf("Semua Mobilitas Buku");
                        getallLoan();
                        getallBack();
                    }
                    else if(pilih == 4){
                        goto dataBuku;
                    }
                    else{
                        puts("Pilihan tidak tersedia!");
                        exit(1);
                    }
                }
                else if (strcmp("4", chose) == 0){
                    goto menu;
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
                puts("5. Kembali");

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
                        printf("Apa yang ingin kamu edit?\n1. Name\n2. Phone Number\n3. Address");
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
                else if (ch == 4)
                {
                    system("cls");
                    printf("Masukan Nama Depan");
                    fflush(stdin);
                    gets(info);
                    int next = getMember(info);
                    if(next == 0){
                        puts("Anggota tidak ditemukan");
                    }
                    if (next!=0){
                        printf("Input nomor anggota yang ingin kamu hapus!");
                        printf("Input: ");scanf("%d",&pilih);
                        delMem(pilih);
                    }
                    system("pause");
                }
                else if (ch == 5){
                    goto menu;
                }
            } while (ch != 0);
        case 3:
            do{
                system("cls");
                puts("Data Pinjam/Kembali");
                puts("1.Create Peminjaman\n2.Create Pengembalian\n3.Kembali");
                printf("Pilih: ");
                scanf("%d", &pilih);
                if (pilih == 1)
                {
                    printf("Data Peminjaman\nMasukan Data\n");
                    printf("ISBN: ");
                    fflush(stdin);
                    gets(info);
                    printf("Peminjam: ");
                    fflush(stdin);
                    gets(info1);
                    printf("Tanggal Peminjaman");
                    char *dup = strdup(getTime());
                    createLoan(info, info1, dup);
                }
                else if (pilih == 2)
                {
                    printf("Data Pengembalian\nMasukan Data\n");
                    printf("ISBN: ");
                    fflush(stdin);
                    gets(info);
                    printf("Nama Depan: ");
                    fflush(stdin);
                    gets(info1);
                    printf("Tanggal Pengembalian");
                    strcpy(info2, getTime());
                    createBack(info, info1, info2);
                }
                else if (pilih == 3){
                    goto menu;
                }
                else{
                    printf("Pilihan tidak tersedia");
                    exit(1);
                }
            }while (pilih != 0);
            break;
        case 0:
            system("cls");
            exit(0);
        default:
            printf("Menu tidak tersedia tolong lah ya...FUCEK");
    }
    return 0;
}