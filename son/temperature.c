#include<stdio.h>		// Standart kütüphanemizi ekliyoruz.
temperature()			// Sýcaklýk birimlerini birbirine dönüþtüren fonksiyondur.
{
	int i,unit_Nu;
	int boiling_Point[4]={212,373,100,80},freeze_Point[4]={32,-273,0,0};
	//kaynama ve donma noktalarýný dizi ile kaydettik.
	float value;		//kullanýcýnýn gireceði deðer.
	char unit[4][20]={"Fahrenheit","Kelvin","Santigrat","Reomür",'\0'};
	// 4 çeþit sýcaklýk birimimizi karakter dizisine aldýk.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");
	/*Her iþlem kayýt altýna alýnsýn diye dosya açýyoruz.
	dosya iþlemleri bir tab boþluklu olanlardýr.*/
	printf("\nHangi birimden deðer girecekseniz o birimin numarasýný giriniz:\n");
	for(i=0; i<4; i++)
	{
		printf("%d-%s\n\n",i+1,unit[i]);
	}	
	scanf("%d",&unit_Nu);
	if(unit_Nu <=4 && unit_Nu >= 1)		//kullanýcý 1-4 arasý deðer girmezse hata verir.
	{
		printf("Deðerinizi Giriniz:\n\n");
		scanf("%f",&value);
		/* Sýcaklýk birimlerinde çevirme iþlemlerini þu þekilde yapýyoruz:
		(x - DNx) / (KNx - DNx) * (KNy - DNy) + DNy
		x = Girdiðimiz deðere ait birim
		y = Çevirilecek deðerin birimi
		DN = Donma Noktasý Sýcaklýðý
		KN = Kaynama noktasý sýcaklýðý */
		switch(unit_Nu)
		{
			case 1:
					fprintf(dosya,"\n***Sýcaklýk Çevirme Ýþleminiz:***\n");
				for(i=0; i<3; i++)
				{
					printf("\n%.2f %s = %.3f %s\n",value,unit[0],((value-32)/180)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[0],((value-32)/180)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
				}
					fclose(dosya);		//dosyayý kapatýyoruz...
				break;
			case 2:
					fprintf(dosya,"\n***Sýcaklýk Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.3f %s\n",value,unit[1],((value+273)/646)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[1],((value+273)/646)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
				for(i=1; i<3; i++)
				{
					printf("\n%.2f %s = %.3f %s\n",value,unit[1],((value+273)/646)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[1],((value+273)/646)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
				}
					fclose(dosya);
				break;
			case 3:
					fprintf(dosya,"\n***Sýcaklýk Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
				printf("\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[1]-freeze_Point[1])+(freeze_Point[1]),unit[1]);	
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[1]-freeze_Point[1])+(freeze_Point[1]),unit[1]);	
				for(i=2; i<3; i++)
				{
					printf("\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[2],((value)/100)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
				}
					fclose(dosya);
				break;
			case 4:
					fprintf(dosya,"\n***Sýcaklýk Çevirme Ýþleminiz:***\n");
				printf("\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[0]-freeze_Point[0])+(freeze_Point[0]),unit[0]);
				printf("\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[1]-freeze_Point[1])+(freeze_Point[1]),unit[1]);
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[1]-freeze_Point[1])+(freeze_Point[1]),unit[1]);	
				printf("\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[2]-freeze_Point[2])+(freeze_Point[2]),unit[2]);
					fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[3],((value)/80)*(boiling_Point[2]-freeze_Point[2])+(freeze_Point[2]),unit[2]);	
				break;	
					fclose(dosya);
		}	
	}
	else
	{
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");
		temperature();
	}
}
