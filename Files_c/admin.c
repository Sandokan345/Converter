#include<stdio.h>			//standart k�t�phane
admin()						//Adminin d�viz i�in kullan�lan para birimlerini dosyadan de�i�tirmesini sa�lar.
{
	int password = 6789;		//Admine ait �ifre
	int password_input;			//kullan�c�n�n g�rdi�i �ifre
	int i,j,k,value;
	float chng[12];		//Yeni girilen de�erleri atad���m�z dizi.
	FILE *doviz;
	printf("�ifreyi giriniz:\n");
	scanf("%d",&password_input);
	if(password_input == password)		//�ifre do�ruysa i�lem yap�labiliyor.
	{
		printf("\t***HO�GELD�N�Z***\n");
		doviz = fopen("para_birimleri.txt","w");	//dosyay� w komutuyla a��yoruz.
		printf("Para birimlerinin de�erlerini giriniz:T=T�RK L�RASI, D=DOLLAR, E=EURO, S=STERL�N\n");
		printf("T-D:\nT-E:\nT-S:\nD-T:\nD-E:\nD-S:\nE-T:\nE-D:\nE-S:\nS-T:\nS-D:\nS-E:\n");
		for(i=0; i<12; i++)
		{
			scanf("%f",&chng[i]);		//kullan�c�dan de�erler al�n�yor.
		}
		fprintf(doviz,"%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\nT-D  T-E  T-S  D-T  D-E  D-S  E-T  E-D  E-S  S-T  S-D  S-E",
		chng[0],chng[1],chng[2],chng[3],chng[4],chng[5],chng[6],chng[7],chng[8],chng[9],chng[10],chng[11]);
		/*Girilen de�erler dosyaya yaz�l�yor*/
		fclose(doviz);			//dosyam�z� kapat�yoruz.
	}
	else	//�ifre yanl��sa iki ayr� se�enek sunar.
	{
		printf("Yanl�� �ifre girdiniz.\nTekrar denemek i�in 1'e bas�n.\nMen� i�in 2'ye bas�n.");
		scanf("%d",&value);
		if(value == 1)
		{
			admin();		//kullan�c� 1'i tu�larsa tekrar �ifreyi dener.
		}
		else if(value == 2)
		{
			choosing();		//kullan�c� 2'yi tu�larsa men�ye d�ner.
		}
		else
		{
			printf("ERROR!!!");
		}
	}
}
