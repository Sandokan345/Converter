/* Uzunluk, sýcaklýk, bilgisayar,para birimlerinin dönüþümünü yapan; açý deðerinin sinüs-cosinüs-tanjant-cotanjant deðerlerini veren bir çevirici programýdýr.*/
#include<stdio.h>		// Standart kütüphanemizi ekliyoruz.
#include<locale.h> 		// Türkçe karakter kullanýmý için bu kütüphaneyi ekliyoruz
#include<conio.h>	
int main() {
	setlocale(LC_ALL, "Turkish"); 	// Türkçe karakter kullanýmýný aktif ediyoruz.
	printf("\t***BÝRÝM ÇEVÝRÝCÝ***\n");		// Programýn baþlýðý
	choosing();
	getch();
	return 0;
}
