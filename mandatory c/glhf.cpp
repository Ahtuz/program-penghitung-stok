#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int pilih;
	char nabar[100][100];
	int index = 0;
	int jubar[1000];
	int nobar[1000];
	int nobartemp;
	char tamkur[100][100];
	int jubartemp = 0;
	int tambahkurang[100];
	int index1 = 0;
	char nabartemp[100][100];
	char nabartemp1[100][100];
	char nabarcari[100];
	int found=0;
	int cektambah[100];
	char nabarcount[50];
	int boom=0;
	char nambarcount[100][100];
	char load;
	
		FILE *pFile;
		pFile = fopen("lihat barang temp.txt","r");
		while(fscanf(pFile, "%d.  %s %d\n", &nobar[index], nabar[index], &jubar[index])!=EOF) index++;
		fclose(pFile);
	
	do{
		system("cls");
		printf(" ______________________________________ \n");
		printf("|                                      |\n");
		printf("|    PROGRAM PENGHITUNG STOK BARANG    |\n");
		printf("|______________________________________|\n");
		printf("|                                      |\n");
		printf("|                MENU:                 |\n");
		printf("|         1. Tambah Barang             |\n");
		printf("|         2. Lihat Barang              |\n");
		printf("|         3. Penghitung Barang         |\n");
		printf("|         4. Ubah Nama Barang          |\n");
		printf("|         5. Riwayat Barang            |\n");
		printf("|         6. Cari Barang               |\n");
		printf("|         7. Keluar                    |\n");
		printf("|______________________________________|\n\n");

		do{
			printf("Masukkan Pilihan Menu:");
			scanf("%d",&pilih); fflush stdin;
		}while(pilih>7 || pilih<1);

		switch(pilih){
		case 1:
			system("cls");
			printf("MENU 1. TAMBAH BARANG\n\n");

			do{
				boom=0;
				printf("Masukkan nama barang:");
				scanf("%[^\n]s",&nabar[index]); fflush stdin;
				strcpy(nabarcount,nabar[index]);
				for(int i=0;i<index;i++){
					if(strcmp(nabarcount,nabar[index])==1){
						printf("Nama barang tersebut sudah ada.");
						boom=1;
					}
				}
			}while(strlen(nabar[index])<1 || strlen(nabar[index])>100 || boom==1);

			do{
				printf("Masukkan jumlah \"%s\":", nabar[index]);
				scanf("%d",&jubar[index]); fflush stdin;
			}while(jubar[index]<1);

			nobar[index]=index+1;
			strcpy(nambarcount[index],nabar[index]);
			cektambah[index]=1;
			index1++;
			index++;
			break;

		case 2:
			system("cls");
			printf("MENU 2. LIHAT BARANG\n\n");

			if(index==0){
				printf("Tidak ada barang...");

				FILE *pFile;

				pFile = fopen("lihat barang.txt", "w");
				fprintf(pFile, "Tidak ada barang...");

				fclose(pFile);
			}

			else{
				printf(" _____________________________________ \n");
				printf("|                  |                  |\n");
				printf("|   Nama Barang    |   Jumlah Barang  |\n");
				printf("|__________________|__________________|\n");
				printf("|                  |                  |\n");
				for(int i=0;i<index;i++){
					printf("|    %-14s|    %-14d|\n",nabar[i],jubar[i]);
				}
				printf("|__________________|__________________|\n");

				FILE *pFile;

				pFile = fopen("lihat barang.txt", "w");
					fprintf(pFile, " _____________________________________ \n");
					fprintf(pFile, "|                  |                  |\n");
					fprintf(pFile, "|   Nama Barang    |   Jumlah Barang  |\n");
					fprintf(pFile, "|__________________|__________________|\n");
					fprintf(pFile, "|                  |                  |\n");
				for(int i=0;i<index;i++){
					fprintf(pFile, "|    %-14s|    %-14d|\n", nabar[i], jubar[i]);
				}
					fprintf(pFile, "|__________________|__________________|\n");

				fclose(pFile);
			}

				printf("\n\n");
				printf("File telah disave di \"lihat barang.txt\".\n");
				printf("Tekan Enter untuk melanjutkan...");

				getchar();
				break;

		case 3:
				system("cls");
				printf("MENU 3. PENGHITUNG BARANG\n\n");

				if(index==0){
					printf("Tidak ada barang...");
				}

				else{
					printf(" ___________________________________________ \n");
					printf("|     |                  |                  |\n");
					printf("| No. |   Nama Barang    |   Jumlah Barang  |\n");
					printf("|_____|__________________|__________________|\n");
					printf("|     |                  |                  |\n");
					for(int i=0;i<index;i++){
						printf("|  %-3d|    %-14s|    %-14d|\n",nobar[i],nabar[i],jubar[i]);
					}
					printf("|_____|__________________|__________________|\n");

					printf("\n\n");

					do{
						printf("Nomor barang yang akan dikurangi atau ditambah stoknya:");
						scanf("%d",&nobartemp); fflush stdin;
					}while(nobartemp>index);

					printf("\n");

					for(int i=0;i<index;i++){
						if(nobartemp==nobar[i]){
							do{
								printf("Ditambah atau dikurang? [tambah/kurang]: ");
								scanf("%s",&tamkur[index1]); fflush stdin;
							}while(strcmp(tamkur[index1],"tambah")!=0 && strcmp(tamkur[index1],"kurang")!=0);

							printf("\n");
							jubartemp = jubar[i];
						
							if(strcmp(tamkur[index1],"tambah")==0){
								printf("Ingin ditambah berapa banyak? ");
								scanf("%d",&tambahkurang[index1]); fflush stdin;
								jubartemp=jubartemp+tambahkurang[index1];
								jubar[i] = jubartemp;
								strcpy(nabartemp[index1],nabar[i]);
								index1++;
							}

							else{
								printf("Ingin dikurang berapa banyak? ");
								scanf("%d",&tambahkurang[index1]); fflush stdin;
								jubartemp=jubartemp-tambahkurang[index1];
								jubar[i] = jubartemp;
								strcpy(nabartemp[index1],nabar[i]);

								if(jubar[i]==0){
									strcpy(nabartemp[index1],nabar[i]);
									printf("\n\"%s\" telah dihapus karena sudah habis.", nabartemp[index1]);
									strcpy(nabar[i],nabar[i+1]);
									nobar[i]=nobar[i+1]-1;
									index--;

								}
								index1++;
							}
						}
					}
				}

				printf("\n\n");
				printf("Silakan ke menu 2 untuk lihat dan save file barang.\n");
				printf("Tekan Enter untuk melanjutkan...");

				getchar();
				break;

		case 4:
				system("cls");
				printf("MENU 4. UBAH NAMA BARANG\n\n");

				if(index==0){
					printf("Tidak ada barang...");
				}

				else{
					printf(" ___________________________________________ \n");
					printf("|     |                  |                  |\n");
					printf("| No. |   Nama Barang    |   Jumlah Barang  |\n");
					printf("|_____|__________________|__________________|\n");
					printf("|     |                  |                  |\n");
					for(int i=0;i<index;i++){
						printf("|  %-3d|    %-14s|    %-14d|\n",nobar[i],nabar[i],jubar[i]);
					}
					printf("|_____|__________________|__________________|\n");

					printf("\n\n");

					do{
						printf("Nomor barang yang akan diubah namanya:");
						scanf("%d",&nobartemp); fflush stdin;
					}while(nobartemp>index);

					printf("\n");

					for(int i=0;i<index;i++){
						if(nobartemp==nobar[i]){
							printf("Barang \"%s\" akan diubah menjadi: ", nabar[i]);
							scanf("%[^\n]s", nabartemp[index1]); fflush stdin;
							strcpy(nabartemp1[index1], nabar[i]);
							strcpy(nabar[i], nabartemp[index1]);
							index1++;
						}
					}
				}

				printf("\n\n");
				printf("Silakan ke menu 2 untuk lihat dan save file barang.\n");
				printf("Tekan Enter untuk melanjutkan...");

				getchar();
				break;

		case 5:
			system("cls");

			printf("MENU 4. RIWAYAT BARANG\n\n");

			if(index1==0){
				printf("Tidak ada riwayat barang...");

				FILE *pFile;

				pFile = fopen("riwayat barang.txt", "w");
				fprintf(pFile, "Tidak ada riwayat barang...");

				fclose(pFile);
			}

			else{
				for(int i=0;i<index1;i++){
					if(strcmp(tamkur[i],"tambah")==0 || strcmp(tamkur[i],"kurang")==0){
						printf("%d. %s telah di%s sebanyak %d.\n", i+1, nabartemp[i], tamkur[i], tambahkurang[i]);
					}
					else if(cektambah[i]==1){
						printf("%d. Barang dengan nama \"%s\" telah didaftarkan.\n", i+1, nambarcount[i]);
					}
					else{
						printf("%d. %s telah diubah namanya menjadi %s. \n", i+1, nabartemp1[i], nabartemp[i]);
					}
				}
			}

			printf("\n\nRiwayat barang telah disave di \"riwayat barang.txt\".\n");
			printf("Tekan Enter untuk melanjutkan...\n");

			getchar();
			break;

		case 6:
			system("cls");
			printf("MENU 6. CARI BARANG\n\n");

			if(index==0){
				printf("Tidak ada barang...");
			}

			else{
				printf("Silakan masukkan nama barang yang ingin dicari: ");
				scanf("%[^\n]s", &nabarcari); fflush stdin;
				printf("\n\n");
				found=0;

				for(int i=0;i<index;i++){
					if(strstr(nabar[i],nabarcari)){
						printf("%d. Ditemukan \"%s\" dengan jumlah %d berada di nomor %d\n", i+1, nabar[i], jubar[i], nobar[i]);
						found=1;
					}
				}

				if(found==0){
					printf("Tak ditemukan barang dengan nama \"%s\"", nabarcari);
				}
			}
			
			printf("\n\nTekan Enter untuk melanjutkan...\n");

			getchar();
			break;
		}

	}while(pilih != 7);

	FILE *pF;
	pF = fopen("lihat barang temp.txt","w");
	for(int i=0;i<index;i++){
		fprintf(pF, "%d. %s %d\n", nobar[i], nabar[i], jubar[i]);
	}
	fclose(pF);

	FILE *pFile;

	pFile = fopen("riwayat barang.txt", "a");

	for(int i=0;i<index1;i++){
		if(strcmp(tamkur[i],"tambah")==0 || strcmp(tamkur[i],"kurang")==0){
			fprintf(pFile, "%d. %s telah di%s sebanyak %d.\n", i+1, nabartemp[i], tamkur[i], tambahkurang[i]);
		}
		else if(cektambah[i]==1){
			fprintf(pFile, "%d. Barang dengan nama \"%s\" telah didaftarkan.\n", i+1, nambarcount[i]);
		}
		else{
			fprintf(pFile, "%d. %s telah diubah namanya menjadi %s. \n", i+1, nabartemp1[i], nabartemp[i]);
		}
	}

	fclose(pFile);


	printf("\nTerima kasih.\nTekan Enter untuk keluar.");

	getchar();
	return 0;
}