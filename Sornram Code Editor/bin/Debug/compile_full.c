#include <stdio.h>
#include <string.h>
char cmd[4096];
char *file;
char *fileErr;
char *fileEsym;
char ch;
int num;
char source[255];
void clearScreen();
int main(int argc, char *args[]){
	clearScreen();
    if(argc == 2){
		file = args[1];
		file[strlen(file) - 2] = 0;
		sprintf(cmd, ".\\bin\\Ccsc.exe -D -T -A -L -M -J +EA I=\"bin/Devices\" %s", args[1]);
		system(cmd);
		fileErr = file;
		fileEsym = file;
		fileErr = strcpy(fileErr,file);
		fileErr = strcat(fileErr,".err");
			printf("\n");
		FILE *fp;
		fp = fopen(fileErr, "r");
		while(!feof(fp)){
			printf("%c",fgetc(fp));
		}
		fclose(fp);
		sprintf(cmd, "del %s", fileErr);
		system(cmd);
		file[strlen(file) - 4] = 0;		
		fileEsym = strcat(fileEsym,".esym");
		sprintf(cmd, "del %s", fileEsym);
		system(cmd);
    }else{
		clearScreen();
		printf("Usage : %s <file>\n",args[0]);
		printf("=======================================\n\n");
		printf("1. Compile & Build\n");
		printf("2. Exit\n");
		scanf("%d", &num);
		switch(num){
			case 1 :
			printf("Input Source File : ");
			scanf("%s", source);
			file = source;
			file[strlen(file) - 2] = 0;
			sprintf(cmd, ".\\bin\\Ccsc.exe -D -T -A -L -M -J +EA I=\"bin/include\" %s", source);
			system(cmd);
			clearScreen();
			fileErr = file;
			fileEsym = file;
			fileErr = strcpy(fileErr,file);
			fileErr = strcat(fileErr,".err");
			printf("\n");
			FILE *fp;
			fp = fopen(fileErr, "r");
			while(!feof(fp)){
				printf("%c",fgetc(fp));
			}
			fclose(fp);
			sprintf(cmd, "del %s", fileErr);
			system(cmd);
			file[strlen(file) - 4] = 0;		
			fileEsym = strcat(fileEsym,".esym");
			sprintf(cmd, "del %s", fileEsym);
			system(cmd);
			break;
			default:
			clearScreen();
			printf("\n\t[x] Exit ...\n");
			break;
		}
	}
}
void clearScreen(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}