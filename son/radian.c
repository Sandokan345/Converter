#include<stdio.h>		// Standart kütüphanemizi ekliyoruz.
#include<math.h>		// Matematiksel iþlemler için..
#define pi 3.14159265	// pi deðerini belirledim
radian()
{
	/*math.h kütüphanesi bize sinüs-cosinüs-tanjant deðerlerini bulmamýzý saðlýyor 
	Girilen açýyý radyana çevirip son halini almamýz yetiyor.*/
	float value;
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");		//Ýþlemleri kayýt altýnda tutmak için dosya açýyoruz.
	/*Her dosya iþlemini bir tab boþluk býrakarak yaptým. Bu sayede normal iþlemlerle karýþmayacak kodun okumasý kolaylaþacaktýr.*/
	printf("\nAçýnýzý giriniz:\n\n");
	scanf("%f",&value);
	if(value >= 0)		//Girilen açý 0'dan büyük deðilse hata verir.
	{
			fprintf(dosya,"\n***Açý Çevirme Ýþleminiz:***\n");
		value*=pi/180;
		printf("\nsinüsü=%.3f\n\n",sin(value));
			fprintf(dosya,"\nsinüsü=%.3f\n\n",sin(value));		//Her iþlem dosyaya yazýlýyor.
		printf("cosinüsü=%.3f\n\n",cos(value));
			fprintf(dosya,"cosinüsü=%.3f\n\n",cos(value));
		printf("tanjantý=%.3f\n\n",tan(value));
			fprintf(dosya,"tanjantý=%.3f\n\n",tan(value));
		printf("cotanjantý=%.3f\n\n",1/tan(value));
			fprintf(dosya,"cotanjantý=%.3f\n\n",1/tan(value));
			fclose(dosya);
	}
	else
	{
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");
		radian();
	}
}
