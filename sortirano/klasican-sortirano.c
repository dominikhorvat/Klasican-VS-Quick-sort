#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000000

int niz[MAX];


//trenutno vrijeme
double vrijeme(){
    return (double)(clock())/(CLOCKS_PER_SEC/1000.0);
}

double sortiraj_klasicno(int n){
    double pocetak, kraj;
    pocetak=vrijeme();
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(niz[i]>niz[j]){
                temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
            }
        }
    }

    kraj=vrijeme();
    //vratimo vrijeme potroseno za sortiranje proizvoljnog niza duljine n
    return kraj-pocetak;

}

int main(void){
    int i,n;
    FILE *fp, *rezultati;
    rezultati=fopen("rezultati-klasican-sort-sortirano.csv","w");
    for(n=1000;n<=30000;n+=1000){
        //ucitavanje n slucajnih brojeva
        fp=fopen("brojevi-sortirano.txt","r");
        for(i=0;i<n;i++)
            fscanf(fp,"%d",&niz[i]);

        printf("n = %d\n",n);
        fprintf(rezultati,"%d, %g\n",n,sortiraj_klasicno(n)/1000.0);
        fclose(fp);
    }
    fclose(rezultati);
    return 0;
}

