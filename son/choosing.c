#include<stdio.h>
choosing()
/*Bu fonksiyonda kullan�c�, program�n hangi i�levini kullanmak istedi�ini se�er.*/
{
	int unit_Nu;
	printf("Hangi birimi �evirmek istiyorsan�z o birimin numaras�n� giriniz:\n\n");
	printf("1-)Uzunluk Birimi\n\n2-)Bilgisayar Birimleri\n\n3-)A�� De�eri Bulma\n\n4-)S�cakl�k Birimi\n\n5-)Para Birimleri\n\n6-)Adminlik ��lemleri\n\n");
	// Kullan�c� hangi birimde �eviri yapmak istiyorsa o birimin numaras�na girerek o fonksiyona gidiyor.
	scanf("%d",&unit_Nu);
	//if komutuyla girilen birim numaras�na ait fonksiyona ge�i� yap�l�yor.
	if(unit_Nu <= 6 && unit_Nu >= 1)	//6 adet birim oldu�u i�in 1-6 de�er aras� de�er girerse i�leme tabii tutulur.
	{
		if(unit_Nu==1) 	
		{
			length();		//1 de�eri uzunluk fonksiyonuna gider.
			printf("\n\nYEN� ��LEM:\n\n");	//fonksiyon d�n���nde yeni i�lem i�in tekrar choosing fonksiyonuna gelinir.
			choosing();
		}
		if(unit_Nu==2) 	
		{
			computer();		//2 de�eri bilgisayar birimlerini �evirme fonksiyonuna gider.
			printf("\n\n\n\nYEN� ��LEM:\n\n\n\n");
			choosing();		
		}
		if(unit_Nu==3)	
		{
			radian();		//3 de�eri a�� birimleri �evirme fonksiyonuna gider.
			printf("\n\n\n\nYEN� ��LEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==4)	
		{
			temperature();		//4 de�eri s�cakl�k birimleri �evirme fonksiyonuna gider.
			printf("\n\n\n\nYEN� ��LEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==5)	
		{
			exchange();			// 5 de�eri para birimi �evirme fonksiyonuna gider.
			printf("\n\n\n\nYEN� ��LEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==6)	
		{
			admin();			// 6 de�eri adminlik i�lemleri fonksiyonuna gider.
			printf("\n\n\n\nYEN� ��LEM:\n\n\n\n");
			choosing();
		}
	}
	else
	{
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");		//1-5 aras� de�er verilmezse hata verir.
		choosing();
	}
}
