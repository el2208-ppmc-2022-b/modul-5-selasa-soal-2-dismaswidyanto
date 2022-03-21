/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursion
*Percobaan        : -
*Hari dan Tanggal : Selasa, 22 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#define true 1
#define false 0

/**
 * @brief fungsi eksekusi rekursi
 * 
 * @param prevVal elemen array pada indeks sebelum yang ditinjau
 * @param addr alamat elemen yang sedang ditinjau
 * @param idx indeks alamat yang sedang ditinjau
 * @param last_idx indeks maksimum peninjauan
 * @return int mengembalikan nilai hasil sekuens yang ditelusuri
 */
int execute(char prevVal, char* addr, int idx, int last_idx);

int main() {
	// Inisialisasi variabel string RNA
	char RNA[30];
	int last_idx = 0;

	// Input string RNA
	printf("Input RNA: ");
	scanf("%s", RNA);

	// Evaluasi validitas RNA
	int i = 0; int exitLoop = false;
	while (i < 30 && exitLoop == false) {
		if ((RNA[i] == 'A') || (RNA[i] == 'U') || (RNA[i] == 'C') || (RNA[i] == 'G')) { // Kasus karakter sesuai karakter standar
			if (i == 29) {                                                              // Jika karakter ditemukan pada indeks 29, maka batas sudah terlampaui
				printf("Pita RNA rusak");
				return 0;
			}
		}
		else if (RNA[i] == 'X') {                                                       // Jika karakter X ditemukan, evaluasi apakah karakter selanjutnya merupakan akhir dari string
			if (RNA[i+1] != '\0') {
				printf("Pita RNA rusak");
				return 0;
			}
			else {                                                                      // Jika setelah karakter X adalah end of string, maka loop diselesaikan
				last_idx = i;
				exitLoop = true;
			}
		}
		else {                                                                          // Kondisi karakter selain karakter valid
			printf("Pita RNA rusak");
			return 0;
		}
		i++;
	}

	// Penghitungan jumlah sekuens terpanjang
	int max = 0;
	i = 1;
	while (i < last_idx+1) {
		int temp = execute(RNA[i-1], &(RNA[i]), i, last_idx);
		if (temp > max) {
			max = temp;
		}
		i = i + temp;
	}

	// Output sekuens terpanjang
	printf("Panjang maximum: %d", max);
	return 0;
}

int execute(char prevVal, char* addr, int idx, int last_idx) {
	if (idx > last_idx) {
		// Jika indeks sudah mencapai indeks maksimal, nilai 0 dikeluarkan
		return 0;
	}
	else {
		// Kondisi indeks valid
		if (prevVal == *addr) {
			// Kondisi konten string masih sama
			return (1+execute(*addr, addr+1, idx+1, last_idx));
		}
		else {
			// Kondisi konten string berbeda
			return 1;
		}
	}
}
