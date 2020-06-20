#include<stdio.h>		//Standart k�t�phane
exchange()				// Para birimlerini birbirine �eviren fonksiyondur.
{
	int i,j,unit_Nu,k=0;
	float value;		//Kullan�c�n�n girece�i de�er.
	char unit[4][15]={"T�rk Liras�","Dollar","Euro","Sterlin",'\0'};
	// 4 farkl� para birimini dizi i�ine ald�m.
	float money[4][3];		//Para birimlerinin birbirine d�n���m� olan dizidir.��lemleri yaparken bunu kullanaca��z.
	float p[12];			// Dosyadan birimlerin birbirine �evirimini almak i�in tan�mlad���m�z dizidir.
	// her paran�n birbirine g�re durumlar�n� bir dizi i�inde tutarak g�ncelleme i�lemlerinin daha rahat yap�lmas�n� sa�lad�m.
	FILE *doviz,*dosya;		//dosya i�lemleri bir tab bo�lukla yap�lm��t�r.
	dosya=fopen("kayitlar.txt","a");	//��lemleri kay�t alt�nda tutar.
	doviz=fopen("para_birimleri.txt","r");		//Para birimlerinin d�n���m�n�n bulundu�u dosyay� a��yoruz.
		if(doviz==NULL)		//Dosya a��lmazsa uyar� verir.
		{
			printf("dosya olusmadi\n");
		}
		else
		{
			fscanf(doviz,"%f %f %f %f %f %f %f %f %f %f %f %f",
			&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6],&p[7],&p[8],&p[9],&p[10],&p[11]);
			/*fscanf ile dosyadan bilgiler p dizisine al�yoruz.*/
			fclose(doviz);	//dosyay� kapat�yoruz.
		}		
	for(i=0; i<4; i++)
		{
			for(j=0; j<3; j++)
			{
				money[i][j]=p[k];		//p dizisini money dizisine at�yoruz.
				k++;
			}
		}
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
		switch(unit_Nu){
			case 1:
					fprintf(dosya,"\n***Para �evirme ��leminiz:***\n");
				for(i=0; i<3; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,unit[0],value*money[0][i],unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,unit[0],value*money[0][i],unit[i+1]);
				}
					fclose(dosya);		//dosyay� kapat�yoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Para �evirme ��leminiz:***\n");
				j=0;
				for(i=0; i<4; i++)
				{
					if(i==1)
					{
						i++;
					}
					printf("\n%.2f %s = %.2f %s\n",value,unit[1],value*money[1][j],unit[i]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,unit[1],value*money[1][j],unit[i]);	
					j++;			
				}
					fclose(dosya);
				break;
			case 3:
					fprintf(dosya,"\n***Para �evirme ��leminiz:***\n");
				j=0;
				for(i=0; i<4; i++)
				{
					if(i==2)
					{
						i++;
					}
					printf("\n%.2f %s = %.2f %s\n",value,unit[2],value*money[2][j],unit[i]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,unit[2],value*money[2][j],unit[i]);	
					j++;			
				}
					fclose(dosya);
				break;
			case 4:
					fprintf(dosya,"\n***Para �evirme ��leminiz:***\n");
				j=0;
				for(i=0; i<3; i++)
				{
					if(i==3)
					{
						i++;
					}
					printf("\n%.2f %s = %.2f %s\n",value,unit[3],value*money[3][j],unit[i]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,unit[3],value*money[3][j],unit[i]);	
					j++;			
				}
					fclose(dosya);
				break;
		}
	}
	else
	{
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");
		exchange();
	}
}
