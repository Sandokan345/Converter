/* Uzunluk, s�cakl�k, bilgisayar,para birimlerinin d�n���m�n� yapan; a�� de�erinin sin�s-cosin�s-tanjant-cotanjant de�erlerini veren bir �evirici program�d�r.*/
#include<stdio.h>		// Standart k�t�phanemizi ekliyoruz.
#include<locale.h> 		// T�rk�e karakter kullan�m� i�in bu k�t�phaneyi ekliyoruz
#include<conio.h>	
int main() {
	setlocale(LC_ALL, "Turkish"); 	// T�rk�e karakter kullan�m�n� aktif ediyoruz.
	printf("\t***B�R�M �EV�R�C�***\n");		// Program�n ba�l���
	choosing();
	getch();
	return 0;
}
