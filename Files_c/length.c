#include<stdio.h>		// Standart kütüphanemizi ekliyoruz.
length()				//Uzunluk birimlerini birbirine çeviren fonksiyondur.
{
	int i,unit_Nu;
	float value;		//kullanýcýnýn gireceði deðer.
	char a[8][20]={"Kilometre","Hektametre","Dekametre","Metre","Desimetre","Santimetre","Milimetre","Mil",'\0'};
	// Uzunluk birimlerinden birini kullanýcýnýn seçmesi için diziye atama yaptýk.
	FILE *dosya;
	dosya=fopen("kayitlar.txt","a");
	/*Dosyalama iþlemlerinin diðer iþlemlerle arýþmamasý için bir tab boþluk býraktým.*/		
	/*Yapýlan iþlemleri kayýt altýnda tutmak için kayitlar adýnda bir txt dosyasý açýyoruz. */
	printf("\nHangi birimden deðer girecekseniz o birimin numarasýný giriniz:\n");
	/*Girilecek deðerin hangi birime ait olduðunu kullanýcýdan alýyoruz.*/
	for(i=0; i<8; i++)
	{
		printf("\n%d-%s\n",i+1,a[i]);
	}
	scanf("%d",&unit_Nu);
	if(unit_Nu <=8 && unit_Nu >= 1)	//Kullanýcý 1-8 arasý sayý girerse iþlemler yapýlýr. Aksi takdirde hata verir.
	{
		printf("\nDeðerinizi giriniz:\n");
		scanf("%f",&value); 				//deðer alýmý..
		switch(unit_Nu){
			/*Girilemn deðeri 10'un katlarýyla çarparak ya da bölerek diðer birimlere çevirme iþlemi yapýyoruz.
			bu yüzden pow komutunu kullanma gereði duydum.
			Mil kullanýmý için ekstra bir deðer giriþi yaptýk*/ 
			case 1:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
					/*Kayýt edilen iþlemin hangi alana ait olduðunu belirtmek için her case'in baþýna fprintf ile alanýný yazýyoruz.
					Bu uygulamayý diðer fonksiyonlarda da yaparak iþlemlerin karýþmamasýný saðlayacaðýz.*/
				for(i=0; i<6; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[0],value*(pow(10,i+1)),a[i+1]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[0],value*(pow(10,i+1)),a[i+1]);
						/*Yapýlan her iþlemi ekstra olarak dosyamýza kaydediyoruz.*/
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[0],value*(0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[0],value*(0.621),a[7]);
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 2:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
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
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 3:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
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
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 4:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
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
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 5:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
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
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 6:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
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
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 7:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
				for(i=0; i<6; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[6],value*(pow(10,i-6)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[6],value*(pow(10,i-6)),a[i]);
				}
				printf("\n%.1f %s = %.3f %s\n",value,a[6],value*(1000000*0.621),a[7]);
					fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[6],value*(1000000*0.621),a[7]);
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
			case 8:
					fprintf(dosya,"\n***Uzunluk Çevirme Ýþleminiz:***\n");
				for(i=0; i<7; i++)
				{
					printf("\n%.1f %s = %.3f %s\n",value,a[7],value*1.6*(pow(10,i)),a[i]);
						fprintf(dosya,"\n%.1f %s = %.3f %s\n",value,a[7],value*1.6*(pow(10,i)),a[i]);
				}
					fclose(dosya);	//dosyayý kapatýyoruz.
				break;
		}
	}
	else
	{
		printf("\nYanlýþ sayý girdiniz.\nLütfen tekrar deneyiniz..\n\n");
		length();
	}
}
