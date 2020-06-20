#include<stdio.h>		// Standart k�t�phanemizi ekliyoruz.
temperature()			// S�cakl�k birimlerini birbirine d�n��t�ren fonksiyondur.
{
	int i,unit_Nu;
	int boiling_Point[4]={212,373,100,80},freeze_Point[4]={32,-273,0,0};
	//kaynama ve donma noktalar�n� dizi ile kaydettik.
	float value;		//kullan�c�n�n girece�i de�er.
	char unit[4][20]={"Fahrenheit","Kelvin","Santigrat","Reom�r",'\0'};
	// 4 �e�it s�cakl�k birimimizi karakter dizisine ald�k.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");
	/*Her i�lem kay�t alt�na al�ns�n diye dosya a��yoruz.
	dosya i�lemleri bir tab bo�luklu olanlard�r.*/
	printf("\nHangi birimden de�er girecekseniz o birimin numaras�n� giriniz:\n");
	for(i=0; i<4; i++)
	{
		printf("%d-%s\n\n",i+1,unit[i]);
	}	
	scanf("%d",&unit_Nu);
	if(unit_Nu <=4 && unit_Nu >= 1)		//kullan�c� 1-4 aras� de�er girmezse hata verir.
	{
		printf("De�erinizi Giriniz:\n\n");
		scanf("%f",&value);
		/* S�cakl�k birimlerinde �evirme i�lemlerini �u �ekilde yap�yoruz:
		(x - DNx) / (KNx - DNx) * (KNy - DNy) + DNy
		x = Girdi�imiz de�ere ait birim
		y = �evirilecek de�erin birimi
		DN = Donma Noktas� S�cakl���
		KN = Kaynama noktas� s�cakl��� */
		switch(unit_Nu)
		{
			case 1:
					fprintf(dosya,"\n***S�cakl�k �evirme ��leminiz:***\n");
				for(i=0; i<3; i++)
				{
					printf("\n%.2f %s = %.3f %s\n",value,unit[0],((value-32)/180)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.3f %s\n",value,unit[0],((value-32)/180)*(boiling_Point[i+1]-freeze_Point[i+1])+(freeze_Point[i+1]),unit[i+1]);
				}
					fclose(dosya);		//dosyay� kapat�yoruz...
				break;
			case 2:
					fprintf(dosya,"\n***S�cakl�k �evirme ��leminiz:***\n");
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
					fprintf(dosya,"\n***S�cakl�k �evirme ��leminiz:***\n");
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
					fprintf(dosya,"\n***S�cakl�k �evirme ��leminiz:***\n");
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
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");
		temperature();
	}
}
