# SoalShift_Modul3_F08
Semoga ilmunya berkah dan berhasil mengerjakan soal praktikum Sistem Operasi sampai selesai

1. Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan
Contoh:
-  ./faktorial 5 3 4
-  3! = 6
-  4! = 24
-  5! = 120

<h3>Jawaban :</h3>

```
void *proses(void *args)
{
	unsigned long long faktor=1;
	struct Faktorial*extract=(struct Faktorial*)args;	//mengubah nilai array menjadi variabel dan nilainya 
	for(int a=1; a<=extract->nilai; ++a)
	{
		faktor=a*faktor;	//pengkalian faktorial
	}
	printf("%d! = %llu \n", extract->nilai, faktor);
}
```
- Langkah awal membuat fungsi void untuk proses menghitung faktorialnya

```
do
	{
		scanf("%d%c", &array[a], &space);
		a++;
	}while(space != '\n');
```
- Langkah kedua kita membuat mainnya, dengan awalnya kita masukkan nilai yang mau kita faktorialkan saat tidak mengandung enter atau "\n" maka lanjut proses bawahnya

```
if(array[a] > array[b])
			{
				x=array[a];
				array[a]=array[b];
				array[b]=x;
			}
```
- Langkah ketiga, pada mainnya kita beri program untuk mengurutkan nilai yang mau difaktorialkan

```
while(array[a]!='\0')			//untuk mengfaktorialkan
	{
		dipanggil.nilai=array[a];
		urut=array[a];
		pthread_create(&tid[urut], NULL, &proses, (void *)&dipanggil);
		pthread_join(tid[urut], NULL);
		a++;
	}
```
- Langkah terakhir, saat array tidak mengandung nilai kosong maka menjalakan proses faktorial untuk setiap nilai

2. Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:
- Terdapat 2 server: server penjual dan server pembeli
- 1 server hanya bisa terkoneksi dengan 1 client
- Server penjual dan server pembeli memiliki stok barang yang selalu sama
- Client yang terkoneksi ke server penjual hanya bisa menambah stok
- Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
- Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok
- Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
- Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok
- Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
- Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
- Server penjual akan mencetak stok saat ini setiap 5 detik sekali
- Menggunakan thread, socket, shared memory

<h3>Jawaban :</h3>
	
3. Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:

a)  Terdapat 2 karakter Agmal dan Iraj

b)  Kedua karakter memiliki status yang unik

()  Agmal mempunyai WakeUp_Status, di awal program memiliki status 0

()  Iraj memiliki Spirit_Status, di awal program memiliki status 100

()  Terdapat 3 Fitur utama
-	All Status, yaitu menampilkan status kedua sahabat
-	Ex: Agmal WakeUp_Status = 75 
      	Iraj Spirit_Status = 30
-	“Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
-	“Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point

()  Terdapat Kasus yang unik dimana:
-	Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
-	Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)

()  Program akan berhenti jika Salah Satu :
-	WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
-	Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)

-	Syarat Menggunakan Lebih dari 1 Thread

<h3>Jawaban :</h3>

```
if(hitungsleep==3){
		sleep(10);
		tanda=0;
		hitungsleep=0;
		printf("Wes Tangi\n");
	  }
```
- Pertama kita membuat fungsi untuk Agmal, yang isinya pertama untuk nge-sleep selama 10 detik

```
 else{
		if(tanda==1){
			hitungbangun++;
			bangun+=15;
```
- Kedua, menambahkan nilai 15 setiap memanggil "Agmal Ayo Bangun"

```
if(hitungbangun==3){
				printf("Fitur Iraj Tidur disabled 10 s\n");
		}
```
- Ketiga, jika sudah dijalankan selama 3 kali maka print "Fitur Iraj Tidur disabled 10 s"

- Langkah diatas dilakukan juga pada fungsi status_iraj

```
	memset(pesan,0,30);
	gets(pesan);
		
	fitur_agmal=strcmp(pesan, "Agmal Ayo Bangun");
	fitur_iraj=strcmp(pesan, "Iraj Ayo Tidur");
	fitur_allstatus=strcmp(pesan, "All Status");
```
- Pada fungsi mainnya pertama kita masukkan kalimat dengan syntax "gets", lalu bandingkan kalimat yang kita masukkan dengan kalimat yang disyaratkan dengan "strcmp"

```
if(fitur_allstatus==0){
			printf("Agmal->WakeUp_Status = %d\n", bangun);
			printf("Iraj->Spirit_Status = %d\n", ayo_semangat);
		}
```
- Kondisi dimana all status dikerjakan

```
if(fitur_agmal==0){
			tanda=1;
	}
```
- Kondisi dimana fitur_agmal dijalankan

```
if(fitur_iraj==0){
			tandai=1;
		}
```
- Kondisi dimana fitur_iraj dijalankan

4. Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 
Dengan Syarat : 
- Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
- Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
- Ketika Mengekstrak file .zip juga harus secara bersama-sama
- Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
- Wajib Menggunakan Multithreading
- Boleh menggunakan system

<h3>Jawaban :</h3>

5. Angga, adik Jiwang akan berulang tahun yang ke sembilan pada tanggal 6 April besok. Karena lupa menabung, Jiwang tidak mempunyai uang sepeserpun untuk membelikan Angga kado. Kamu sebagai sahabat Jiwang ingin membantu Jiwang membahagiakan adiknya sehingga kamu menawarkan bantuan membuatkan permainan komputer sederhana menggunakan program C. Jiwang sangat menyukai idemu tersebut. Berikut permainan yang Jiwang minta.

a)	Pemain memelihara seekor monster lucu dalam permainan. Pemain dapat  memberi nama pada monsternya.

b)	Monster pemain memiliki hunger status yang berawal dengan nilai 200 (maksimalnya) dan nanti akan berkurang 5 tiap 10 detik.Ketika hunger status mencapai angka nol, pemain akan kalah. Hunger status dapat bertambah 15 apabila pemain memberi makan kepada monster, tetapi banyak makanan terbatas dan harus beli di Market.

c)	Monster pemain memiliki hygiene status yang berawal dari 100 dan nanti berkurang 10 tiap 30 detik. Ketika hygiene status mencapai angka nol, pemain akan kalah. Hygiene status' dapat bertambah 30 hanya dengan memandikan monster. Pemain dapat memandikannya setiap 20 detik(cooldownnya 20 detik).

d)	Monster pemain memiliki health status yang berawal dengan nilai 300. Variabel ini bertambah (regenerasi)daa 5 setiap 10 detik ketika monster dalam keadaan standby.
Monster pemain dapat memasuki keadaan battle. Dalam keadaan ini, food status(fitur b), hygiene status'(fitur c), dan ‘regenerasi’(fitur d) tidak akan berjalan. Health status dari monster dimulai dari darah saat monster pemain memasuki battle.

e)	Monster pemain akan bertarung dengan monster NPC yang memiliki darah 100. Baik monster pemain maupun NPC memiliki serangan sebesar 20. Monster pemain dengan monster musuh akan menyerang secara bergantian.

f)	Fitur shop, pemain dapat membeli makanan sepuas-puasnya selama stok di toko masih tersedia.

()  Pembeli (terintegrasi dengan game)
-	Dapat mengecek stok makanan yang ada di toko.
-	Jika stok ada, pembeli dapat membeli makanan.

()  Penjual (terpisah)
-	Bisa mengecek stok makanan yang ada di toko
-	Penjual dapat menambah stok makanan.

<h3>Jawaban :</h3>
