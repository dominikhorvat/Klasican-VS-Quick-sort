#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000

//generiramo datoteku brojevi.txt gdje �e biti nasumi�ni brojevi
//printf u for petlji nam ispisuje do kojeg broja je generirano
//npr. u ispisu 1000 ozna�ava da je generirano u datoteci 1000 nasumi�nih brojeva

int main(void){
    FILE *fp;
    fp=fopen("brojevi.txt","w");
    int i;
    for(i=0;i<MAX;i++){
        fprintf(fp,"%d ",rand());
        if(i%1000==0)
            printf("%d\n",i);
    }

    fclose(fp);

    return 0;
}
