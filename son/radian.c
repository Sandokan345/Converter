#include<stdio.h>		// Standart k�t�phanemizi ekliyoruz.
#include<math.h>		// Matematiksel i�lemler i�in..
#define pi 3.14159265	// pi de�erini belirledim
radian()
{
	/*math.h k�t�phanesi bize sin�s-cosin�s-tanjant de�erlerini bulmam�z� sa�l�yor 
	Girilen a��y� radyana �evirip son halini almam�z yetiyor.*/
	float value;
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");		//��lemleri kay�t alt�nda tutmak i�in dosya a��yoruz.
	/*Her dosya i�lemini bir tab bo�luk b�rakarak yapt�m. Bu sayede normal i�lemlerle kar��mayacak kodun okumas� kolayla�acakt�r.*/
	printf("\nA��n�z� giriniz:\n\n");
	scanf("%f",&value);
	if(value >= 0)		//Girilen a�� 0'dan b�y�k de�ilse hata verir.
	{
			fprintf(dosya,"\n***A�� �evirme ��leminiz:***\n");
		value*=pi/180;
		printf("\nsin�s�=%.3f\n\n",sin(value));
			fprintf(dosya,"\nsin�s�=%.3f\n\n",sin(value));		//Her i�lem dosyaya yaz�l�yor.
		printf("cosin�s�=%.3f\n\n",cos(value));
			fprintf(dosya,"cosin�s�=%.3f\n\n",cos(value));
		printf("tanjant�=%.3f\n\n",tan(value));
			fprintf(dosya,"tanjant�=%.3f\n\n",tan(value));
		printf("cotanjant�=%.3f\n\n",1/tan(value));
			fprintf(dosya,"cotanjant�=%.3f\n\n",1/tan(value));
			fclose(dosya);
	}
	else
	{
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");
		radian();
	}
}
