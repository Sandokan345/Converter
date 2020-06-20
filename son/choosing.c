#include<stdio.h>
choosing()
/*Bu fonksiyonda kullanýcý, programýn hangi iþlevini kullanmak istediðini seçer.*/
{
	int unit_Nu;
	printf("Hangi birimi çevirmek istiyorsanýz o birimin numarasýný giriniz:\n\n");
	printf("1-)Uzunluk Birimi\n\n2-)Bilgisayar Birimleri\n\n3-)Açý Deðeri Bulma\n\n4-)Sýcaklýk Birimi\n\n5-)Para Birimleri\n\n6-)Adminlik Ýþlemleri\n\n");
	// Kullanýcý hangi birimde çeviri yapmak istiyorsa o birimin numarasýna girerek o fonksiyona gidiyor.
	scanf("%d",&unit_Nu);
	//if komutuyla girilen birim numarasýna ait fonksiyona geçiþ yapýlýyor.
	if(unit_Nu <= 6 && unit_Nu >= 1)	//6 adet birim olduðu için 1-6 deðer arasý deðer girerse iþleme tabii tutulur.
	{
		if(unit_Nu==1) 	
		{
			length();		//1 deðeri uzunluk fonksiyonuna gider.
			printf("\n\nYENÝ ÝÞLEM:\n\n");	//fonksiyon dönüþünde yeni iþlem için tekrar choosing fonksiyonuna gelinir.
			choosing();
		}
		if(unit_Nu==2) 	
		{
			computer();		//2 deðeri bilgisayar birimlerini çevirme fonksiyonuna gider.
			printf("\n\n\n\nYENÝ ÝÞLEM:\n\n\n\n");
			choosing();		
		}
		if(unit_Nu==3)	
		{
			radian();		//3 deðeri açý birimleri çevirme fonksiyonuna gider.
			printf("\n\n\n\nYENÝ ÝÞLEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==4)	
		{
			temperature();		//4 deðeri sýcaklýk birimleri çevirme fonksiyonuna gider.
			printf("\n\n\n\nYENÝ ÝÞLEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==5)	
		{
			exchange();			// 5 deðeri para birimi çevirme fonksiyonuna gider.
			printf("\n\n\n\nYENÝ ÝÞLEM:\n\n\n\n");
			choosing();
		}
		if(unit_Nu==6)	
		{
			admin();			// 6 deðeri adminlik iþlemleri fonksiyonuna gider.
			printf("\n\n\n\nYENÝ ÝÞLEM:\n\n\n\n");
			choosing();
		}
	}
	else
	{
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");		//1-5 arasý deðer verilmezse hata verir.
		choosing();
	}
}
