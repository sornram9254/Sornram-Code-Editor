#include <stdio.h>
#include <string.h>
char cmd[4096];
char *file;
char *fileErr;
char *fileEsym;
int main(int argc, char *args[]){
    if(argc == 2){
		file = args[1];
		file[strlen(file) - 2] = 0;
		sprintf(cmd, ".\\bin\\Ccsc.exe -D -T -A -L -M -J +EA I=\"bin/include\" \"%s\"", args[1]);
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
		printf("Usage : ccs.exe <file.c>\n");
	}
}