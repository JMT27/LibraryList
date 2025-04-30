#include <stdio.h>
#include <string.h>

typedef struct bookInformation {
	int bookId;
	char bookTitle[50];
	char authorName[50];
	int year;
} info;

int main(){
	info buku[100];
	int menu, i = 0 , j, h, key;
	FILE *fp = fopen("Library.txt","w");
		do
		{
			printf("Pilih Menu :\n");
			printf("1. Input book record\n");
			printf("2. Display book record\n");
			printf("3. Update book record\n");
			printf("4. Erase book record\n");
			printf("5. Save and exit\n");
			scanf("%d", &menu);
					
			switch(menu){
				case 1 :
					printf("Masukkan book id : ");
					scanf("%d", &buku[i].bookId); getchar();
					printf("Masukkan judul buku : ");
					scanf("%[^\n]", buku[i].bookTitle); getchar();
					printf("Masukkan author name : ");
					scanf("%[^\n]", buku[i].authorName); getchar();
					printf("Masukkan year published : ");
					scanf("%d", &buku[i].year); getchar();
					i++;
					break;
											
				case 2 :
					for(j=0;j<i;j++){
						info temp;
						for(h=0;h<i-j-1;h++){
							if(strcmp(buku[h].bookTitle, buku[h+1].bookTitle)>0){
								temp = buku[h];
								buku[h]=buku[h+1];
								buku[h+1]= temp;
							}
						}
					}
					for(j=0; j<i;j++){
					printf("ID : %d\n", buku[j].bookId);
					printf("Judul buku : %s\n", buku[j].bookTitle);
					printf("Author name : %s\n", buku[j].authorName);
					printf("Year published : %d\n\n", buku[j].year);
					}
					break;
		
				case 3 :
					for(j=0; j<i;j++){
					printf("ID : %d\n", buku[j].bookId);
					printf("Judul buku : %s\n", buku[j].bookTitle);
					printf("Author name : %s\n", buku[j].authorName);
					printf("Year published : %d\n\n", buku[j].year);
					}
					
					scanf("%d", &key);
					int z = 0;
					for(j=0;j<i;j++){
						if(key == buku[j].bookId){
							printf("Masukkan book ID : ");
							scanf("%d", &buku[j].bookId); getchar();
							printf("Masukkan judul buku : ");
							scanf("%[^\n]", buku[j].bookTitle); getchar();
							printf("Masukkan author name : ");
							scanf("%[^\n]", buku[j].authorName); getchar();
							printf("Masukkan year published : ");
							scanf("%d", &buku[j].year); getchar();
							z = 1;
							break;
						}
					}
					if(z==0) printf("ID salah\n"); break;
			
				case 4 :
					z=0;
					for(j=0; j<i;j++){
						printf("ID : %d\n", buku[j].bookId);
						printf("Judul buku : %s\n", buku[j].bookTitle);
						printf("Author name : %s\n", buku[j].authorName);
						printf("Year published : %d\n\n", buku[j].year);
					}
					printf("Tulis ID buku yang ingin dihapus :");
					scanf("%d", &key);
					int deleteID;
					for(j=0;j<i;j++){
						if(key == buku[j].bookId){
							deleteID=j;
							z=-1;
							break;
						}
						if(z==0) printf("ID salah\n"); break;
					}
					for(j=deleteID;j<i-1;j++){
						buku[j]=buku[j+1];
					}
					i--;
					
				case 5 :
					for(j=0;j<i;j++){
						fprintf(fp,"%d#%s#%s#%d\n",buku[j].bookId,buku[j].bookTitle,buku[j].authorName,buku[j].year);
					}
					fclose(fp);
					
			}
		}
	while (menu != 5);
}

