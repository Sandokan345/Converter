#include<stdio.h>		// Standart k�t�phanemizi ekliyoruz.
computer()				//Bilgisayar birimlerinin birbirine d�n���m�n� yapar.
{
	float value;		//Kullan�c�n�n girece�i de�eri al�r.
	int unit_Nu,i;
	char a[5][10]={"TeraByte","GigaByte","MegaByte","KiloByte","Byte",'\0'};
	//Kullan�c�n�n hangi birimin de�erini direce�ini ��renmek i�in dizi i�inde birimleri tan�mlay�p kullan�c�dan se�mesini istiyoruz.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");	//Yap�lan i�lemleri kay�t alt�nda tutmak i�in dosyam�z� a��yoruz.
	/*Dosyalama i�lemlerinin di�er i�lemlerle ar��mamas� i�in bir tab bo�luk b�rakt�m.*/
	printf("\nHangi birimden de�er girecekseniz o birimin numaras�n� giriniz:\n");
	for(i=0; i<5; i++)
	{
		printf("\n%d-%s\n",i+1,a[i]);
	}
	scanf("%d",&unit_Nu);
	if(unit_Nu <=5 && unit_Nu >= 1)		//Kullan�c� 1-5 aras� de�er girerse i�lemler yap�l�r aksi takdirde hata verir.
	{
		printf("\nDe�erinizi giriniz:\n");
		scanf("%f",&value);
		//switch case yap�s� ile girilen de�eri di�er birimlere tek tek �eviriyoruz.
		switch(unit_Nu){
			case 1: 
			fprintf(dosya,"\n***Byte �evirme ��leminiz:***\n");
			/*��lemlerin hangi alana ait oldu�unu bilmek i�in o alan�n ba�l���n� her case'in ba��nda fprintf fonksiyonu ile yap�yoruz.*/
				for(i=0;i<4; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[0],value*(pow(1024,i+1)),a[i+1]); 
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[0],value*(pow(1024,i+1)),a[i+1]); 
						/*Yap�lan her i�lemi ayr�yeten dosyaya yazd�r�yoruz.*/
					/* say�y� di�erlerine �evirmek i�in 1024 ile �arp�yoruz.
					Her seferinde 1024'�n katlar�yla �arpaca��m�z i�in kare alma fonksiyonu olan pow'u kulland�m.*/ 
				}
				fclose(dosya);		//dosyay� kapat�yoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Byte �evirme ��leminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[1],value/1024,a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[1],value/1024,a[0]);
				for(i=0;i<3; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,a[1],value*(pow(1024,i+1)),a[i+2]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[1],value*(pow(1024,i+1)),a[i+2]);
				}
					fclose(dosya);		//dosyay� kapat�yoruz.
				break;
			case 3:
					fprintf(dosya,"\n***Byte �evirme ��leminiz:***\n");
				printf("\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,2)),a[0]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,2)),a[0]);
				printf("\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,1)),a[1]);
					fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,a[2],value/(pow(1024,1)),a[1]);
				for(i=0;i<2; i++)
				{
					printf("\%.2f %s = %.2f %s\n",value,a[2],value*(pow(1024,i+1)),a[i+3]);
						fprintf(dosya,"\%.2f %s = %.2f %s\n",value,a[2],value*(pow(1024,i+1)),a[i+3]);
				}
					fclose(dosya);		//dosyay� kapat�yoruz.
				break;
			case 4:
					fprintf(dosya,"\n***Byte �evirme ��leminiz:***\n");
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
					fclose(dosya);		//dosyay� kapat�yoruz.
				break;
			case 5:
					fprintf(dosya,"\n***Byte �evirme ��leminiz:***\n");
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
					fclose(dosya);		//dosyay� kapat�yoruz.
		}
	}
	else
	{
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");
		computer();
	}
}
