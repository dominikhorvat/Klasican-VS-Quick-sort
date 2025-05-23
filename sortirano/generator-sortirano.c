#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000


//generator slucajnih brojeva u datoteku brojevi-sortirano.txt

int main(void){
    FILE *fp;
    fp=fopen("brojevi-sortirano.txt","w");
    int i;
    for(i=0;i<MAX;i++){
        fprintf(fp,"%d ",i);
        if(i%1000==0)
            printf("%d\n",i);
    }

    fclose(fp);



return 0;
}


