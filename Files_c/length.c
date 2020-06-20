#include<stdio.h>		// Standart k�t�phanemizi ekliyoruz.
length()				//Uzunluk birimlerini birbirine �eviren fonksiyondur.
{
	int i,unit_Nu;
	float value;		//kullan�c�n�n girece�i de�er.
	char a[8][20]={"Kilometre","Hektametre","Dekametre","Metre","Desimetre","Santimetre","Milimetre","Mil",'\0'};
	// Uzunluk birimlerinden birini kullan�c�n�n se�mesi i�in diziye atama yapt�k.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");
	/*Dosyalama i�lemlerinin di�er i�lemlerle ar��mamas� i�in bir tab bo�luk b�rakt�m.*/		
	/*Yap�lan i�lemleri kay�t alt�nda tutmak i�in kayitlar ad�nda bir txt dosyas� a��yoruz. */
	printf("\nHangi birimden de�er girecekseniz o birimin numaras�n� giriniz:\n");
	/*Girilecek de�erin hangi birime ait oldu�unu kullan�c�dan al�yoruz.*/
	for(i=0; i<8; i++)
	{
		printf("\n%d-%s\n",i+1,a[i]);
	}
	scanf("%d",&unit_Nu);
	if(unit_Nu <=8 && unit_Nu >= 1)	//Kullan�c� 1-8 aras� say� girerse i�lemler yap�l�r. Aksi takdirde hata verir.
	{
		printf("\nDe�erinizi giriniz:\n");
		scanf("%f",&value); 				//de�er al�m�..
		switch(unit_Nu){
			/*Girilemn de�eri 10'un katlar�yla �arparak ya da b�lerek di�er birimlere �evirme i�lemi yap�yoruz.
			bu y�zden pow komutunu kullanma gere�i duydum.
			Mil kullan�m� i�in ekstra bir de�er giri�i yapt�k*/ 
			case 1:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
					/*Kay�t edilen i�lemin hangi alana ait oldu�unu belirtmek i�in her case'in ba��na fprintf ile alan�n� yaz�yoruz.
					Bu uygulamay� di�er fonksiyonlarda da yaparak i�lemlerin kar��mamas�n� sa�layaca��z.*/
				for(i=0; i<6; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[0],value*(pow(10,i+1)),a[i+1]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[0],value*(pow(10,i+1)),a[i+1]);
						/*Yap�lan her i�lemi ekstra olarak dosyam�za kaydediyoruz.*/
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[0],value*(0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[0],value*(0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<1; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[1],value*(pow(10,i-1)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[1],value*(pow(10,i-1)),a[i]);
				}
				for(i=0; i<5; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[1],value*(pow(10,i+1)),a[i+2]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[1],value*(pow(10,i+1)),a[i+2]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[1],value*(10*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[1],value*(10*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 3:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<2; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[2],value*(pow(10,i-2)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[2],value*(pow(10,i-2)),a[i]);
				}
				for(i=0; i<4; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[2],value*(pow(10,i+1)),a[i+3]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[2],value*(pow(10,i+1)),a[i+3]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[2],value*(100*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[2],value*(100*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 4:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<3; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[3],value*(pow(10,i-3)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[3],value*(pow(10,i-3)),a[i]);
				}
				for(i=0; i<3; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[3],value*(pow(10,i+1)),a[i+4]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[3],value*(pow(10,i+1)),a[i+4]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[3],value*(1000*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[3],value*(1000*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 5:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<4; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[4],value*(pow(10,i-4)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[4],value*(pow(10,i-4)),a[i]);
				}
				for(i=0; i<2; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[4],value*(pow(10,i+1)),a[i+5]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[4],value*(pow(10,i+1)),a[i+5]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[4],value*(10000*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[4],value*(10000*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 6:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<5; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[5],value*(pow(10,i-5)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[5],value*(pow(10,i-5)),a[i]);
				}
				for(i=0; i<1; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[5],value*(pow(10,i+1)),a[i+6]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[5],value*(pow(10,i+1)),a[i+6]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[5],value*(100000*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[5],value*(100000*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 7:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<6; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[6],value*(pow(10,i-6)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[6],value*(pow(10,i-6)),a[i]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[6],value*(1000000*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[6],value*(1000000*0.621),a[7]);
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
			case 8:
					fprintf(dosya,"\n***Uzunluk �evirme ��leminiz:***\n");
				for(i=0; i<7; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[7],value*1.6*(pow(10,i)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[7],value*1.6*(pow(10,i)),a[i]);
				}
					fclose(dosya);	//dosyay� kapat�yoruz.
				break;
		}
	}
	else
	{
		printf("\nYanl�� say� girdiniz.\nL�tfen tekrar deneyiniz..\n\n");
		length();
	}
}
