# Library Simulator

## Model
    Simulasi Perpustakaan, dimana terdapat beberapa fungsi yang menangani peminjaman, system keanggotaan, dan inventaris buku.

## Breakdown
- Main menu
- Peminjaman Buku
- Inventaris buku
- System keanggotaan
- Pengembalian Buku

## Function
### ***Main Menu***
- Memuat tampilan menu mencakup 4 fungsi dibawah.
### ***Peminjaman Buku / Book Loan ***
- Mencatat data  peminjaman mencakup data buku, identitas peminjam, tgl pinjam, tenggat pengembalian.
### ***Inventaris Buku / Inventory ***
- Memeriksa ketersediaan buku yang diminta peminjam.
- Mengupdate data buku masuk dan buku keluar/dipinjam.
- Menyimpan data buku: Nama, Author, Kode, Stok, Tempat.
### ***System Keanggotaan***
- Membuat data keanggotaan baru mencakup Nama, Nomor Tlp, Alamat
- Menghapus keanggotaan
- Memperbaharui data keanggotaan seperti alamat dan nomor tlp
### ***Pengembalian Buku***
- Mencata data pengembalian buku sesuai tenggat dan tidak.

## Things Need
- Peminjaman Buku (Array, Struct, File Operasi Write). Metode: create, update;
- Inventaris Buku (Array, Struct, File Operasi Write and Read). Metode: read, update, delete;
- System Keanggotaa (Array, Struct, File Operasi Write and Read). Metode: create, update, delete, read;
- Pengembalian Buku (Array, Struct, File Operasi Write). Metode: delete, update;

## Metode:
- Peminjaman Buku: Metode: create, update;
- Inventaris Buku: Metode: read, update, delete;
- System Keanggotaa: Metode: create, update, delete, read;
- Pengembalian Buku: Metode: delete, update;

## Algoritma
### Peminjaman Buku / Book Loan
1. Staff mendata identitas peminjam, tgl pinjam, tenggat pengembalian.
2. Staff mencari buku --> invetory(kode);

### Inventaris Buku / Inventory
1. Informasi Buku
    - Informasi Spesifik --> 5
    - Semua informasi --> baca file.txt

2. Pendataan buku
    - Mengecek judul buku dan author --> 5
        - jika ada, update
        - jika tidak, buat data baru: masukan informasi nama, author, kode (baru), stok, tempat.
    
3. Mencari Buku
    - jika satu judul sama dan ada --> tampilkan informasi
    - jika tidak, masukan nama author
        - jika ada --> tampilkan informasi
        - jika tidak --> ERROR

4. Data Pinjam/Kembali
    - jika kode ada
        - tampil informasi
            - cek apakah judul & author sama
             - jika iya --> tambah/ kurang data
             - jika tidak --> masukan ulang kode (loop)
    - jika kode tidak 
        - masukan ulang yang benar(loop)

5. Data Real
    - backup file semua informasi.

### System Keanggotaan
1. Buat data baru --> create data
2. Update data 
    - cari nama
        - jika ada --> pilih
            - hapus peminjaman
            - update data baru
3. Hapus keanggotaan --> delete
4. Baca data keanggotaan

### Pengembalian Buku
1. Buku dikembalikan 
    - masukan nama peminjam --> system_keanggotaan(nama)
