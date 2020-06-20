#include<stdio.h>			//standart kütüphane
admin()						//Adminin döviz için kullanýlan para birimlerini dosyadan deðiþtirmesini saðlar.
{
	int password = 6789;		//Admine ait þifre
	int password_input;			//kullanýcýnýn gürdiði þifre
	int i,j,k,value;
	float chng[12];		//Yeni girilen deðerleri atadýðýmýz dizi.
	FILE *doviz;
	printf("Þifreyi giriniz:\n");
	scanf("%d",&password_input);
	if(password_input == password)		//Þifre doðruysa iþlem yapýlabiliyor.
	{
		printf("\t***HOÞGELDÝNÝZ***\n");
		doviz = fopen("para_birimleri.txt","w");	//dosyayý w komutuyla açýyoruz.
		printf("Para birimlerinin deðerlerini giriniz:T=TÜRK LÝRASI, D=DOLLAR, E=EURO, S=STERLÝN\n");
		printf("T-D:\nT-E:\nT-S:\nD-T:\nD-E:\nD-S:\nE-T:\nE-D:\nE-S:\nS-T:\nS-D:\nS-E:\n");
		for(i=0; i<12; i++)
		{
			scanf("%f",&chng[i]);		//kullanýcýdan deðerler alýnýyor.
		}
		fprintf(doviz,"%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\nT-D  T-E  T-S  D-T  D-E  D-S  E-T  E-D  E-S  S-T  S-D  S-E",
		chng[0],chng[1],chng[2],chng[3],chng[4],chng[5],chng[6],chng[7],chng[8],chng[9],chng[10],chng[11]);
		/*Girilen deðerler dosyaya yazýlýyor*/
		fclose(doviz);			//dosyamýzý kapatýyoruz.
	}
	else	//Þifre yanlýþsa iki ayrý seçenek sunar.
	{
		printf("Yanlýþ þifre girdiniz.\nTekrar denemek için 1'e basýn.\nMenü için 2'ye basýn.");
		scanf("%d",&value);
		if(value == 1)
		{
			admin();		//kullanýcý 1'i tuþlarsa tekrar þifreyi dener.
		}
		else if(value == 2)
		{
			choosing();		//kullanýcý 2'yi tuþlarsa menüye döner.
		}
		else
		{
			printf("ERROR!!!");
		}
	}
}
