#include<stdio.h>		//Standart kütüphane
exchange()				// Para birimlerini birbirine çeviren fonksiyondur.
{
	int i,j,unit_Nu,k=0;
	float value;		//Kullanýcýnýn gireceði deðer.
	char unit[4][15]={"Türk Lirasý","Dollar","Euro","Sterlin",'\0'};
	// 4 farklý para birimini dizi içine aldým.
	float money[4][3];		//Para birimlerinin birbirine dönüþümü olan dizidir.Ýþlemleri yaparken bunu kullanacaðýz.
	float p[12];			// Dosyadan birimlerin birbirine çevirimini almak için tanýmladýðýmýz dizidir.
	// her paranýn birbirine göre durumlarýný bir dizi içinde tutarak güncelleme iþlemlerinin daha rahat yapýlmasýný saðladým.
	FILE *doviz,*dosya;		//dosya iþlemleri bir tab boþlukla yapýlmýþtýr.
	dosya=fopen("kayitlar.txt","a");	//Ýþlemleri kayýt altýnda tutar.
	doviz=fopen("para_birimleri.txt","r");		//Para birimlerinin dönüþümünün bulunduðu dosyayý açýyoruz.
		if(doviz==NULL)		//Dosya açýlmazsa uyarý verir.
		{
			printf("dosya olusmadi\n");
		}
		else
		{
			fscanf(doviz,"%f %f %f %f %f %f %f %f %f %f %f %f",
			&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6],&p[7],&p[8],&p[9],&p[10],&p[11]);
			/*fscanf ile dosyadan bilgiler p dizisine alýyoruz.*/
			fclose(doviz);	//dosyayý kapatýyoruz.
		}		
	for(i=0; i<4; i++)
		{
			for(j=0; j<3; j++)
			{
				money[i][j]=p[k];		//p dizisini money dizisine atýyoruz.
				k++;
			}
		}
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
		switch(unit_Nu){
			case 1:
					fprintf(dosya,"\n***Para Çevirme Ýþleminiz:***\n");
				for(i=0; i<3; i++)
				{
					printf("\n%.2f %s = %.2f %s\n",value,unit[0],value*money[0][i],unit[i+1]);
						fprintf(dosya,"\n%.2f %s = %.2f %s\n",value,unit[0],value*money[0][i],unit[i+1]);
				}
					fclose(dosya);		//dosyayý kapatýyoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Para Çevirme Ýþleminiz:***\n");
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
					fprintf(dosya,"\n***Para Çevirme Ýþleminiz:***\n");
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
					fprintf(dosya,"\n***Para Çevirme Ýþleminiz:***\n");
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
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");
		exchange();
	}
}
