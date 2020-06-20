#include<stdio.h>		// Standart kütüphanemizi ekliyoruz.
computer()				//Bilgisayar birimlerinin birbirine dönüþümünü yapar.
{
	float value;		//Kullanýcýnýn gireceði deðeri alýr.
	int unit_Nu,i;
	char a[5][10]={"TeraByte","GigaByte","MegaByte","KiloByte","Byte",'\0'};
	//Kullanýcýnýn hangi birimin deðerini direceðini öðrenmek için dizi içinde birimleri tanýmlayýp kullanýcýdan seçmesini istiyoruz.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");	//Yapýlan iþlemleri kayýt altýnda tutmak için dosyamýzý açýyoruz.
	/*Dosyalama iþlemlerinin diðer iþlemlerle arýþmamasý için bir tab boþluk býraktým.*/
	printf("\nHangi birimden deðer girecekseniz o birimin numarasýný giriniz:\n");
	for(i=0; i<5; i++)
	{
		printf("\n%d-%s\n",i+1,a[i]);
	}
	scanf("%d",&unit_Nu);
	if(unit_Nu <=5 && unit_Nu >= 1)		//Kullanýcý 1-5 arasý deðer girerse iþlemler yapýlýr aksi takdirde hata verir.
	{
		printf("\nDeðerinizi giriniz:\n");
		scanf("%f",&value);
		//switch case yapýsý ile girilen deðeri diðer birimlere tek tek çeviriyoruz.
		switch(unit_Nu){
			case 1: 
			fprintf(dosya,"\n***Byte Çevirme Ýþleminiz:***\n");
			/*Ýþlemlerin hangi alana ait olduðunu bilmek için o alanýn baþlýðýný her case'in baþýnda fprintf fonksiyonu ile yapýyoruz.*/
				for(i=0;i<4; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[0],value*(pow(1024,i+1)),a[i+1]); 
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[0],value*(pow(1024,i+1)),a[i+1]); 
						/*Yapýlan her iþlemi ayrýyeten dosyaya yazdýrýyoruz.*/
					/* sayýyý diðerlerine çevirmek için 1024 ile çarpýyoruz.
					Her seferinde 1024'ün katlarýyla çarpacaðýmýz için kare alma fonksiyonu olan pow'u kullandým.*/ 
				}
				fclose(dosya);		//dosyayý kapatýyoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Byte Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[1],value/1024,a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[1],value/1024,a[0]);
				for(i=0;i<3; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[1],value*(pow(1024,i+1)),a[i+2]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[1],value*(pow(1024,i+1)),a[i+2]);
				}
					fclose(dosya);		//dosyayý kapatýyoruz.
				break;
			case 3:
					fprintf(dosya,"\n***Byte Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,2)),a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,2)),a[0]);
				printf("\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,1)),a[1]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,1)),a[1]);
				for(i=0;i<2; i++)
				{
					printf("\%.2f %s = %.2f %s\n",value,a[2],value*(pow(1024,i+1)),a[i+3]);
						fprintf(dosya,"\%.2f %s = %.2f %s\n",value,a[2],value*(pow(1024,i+1)),a[i+3]);
				}
					fclose(dosya);		//dosyayý kapatýyoruz.
				break;
			case 4:
					fprintf(dosya,"\n***Byte Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,3)),a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,3)),a[0]);
				printf("\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,2)),a[1]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,2)),a[1]);
				printf("\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,1)),a[2]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[3],value/(pow(1024,1)),a[2]);
				for(i=0;i<1; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[3],value*(pow(1024,i+1)),a[i+4]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[3],value*(pow(1024,i+1)),a[i+4]);
				}
					fclose(dosya);		//dosyayý kapatýyoruz.
				break;
			case 5:
					fprintf(dosya,"\n***Byte Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,4)),a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,4)),a[0]);
				printf("\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,3)),a[1]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,3)),a[1]);
				printf("\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,2)),a[2]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,2)),a[2]);
				printf("\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,1)),a[3]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[4],value/(pow(1024,1)),a[3]);
				for(i=0;i<1; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[4],value*(pow(1024,i)),a[i+4]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[4],value*(pow(1024,i)),a[i+4]);
				}
				break;
					fclose(dosya);		//dosyayý kapatýyoruz.
		}
	}
	else
	{
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");
		computer();
	}
}
