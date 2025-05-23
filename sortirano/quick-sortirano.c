#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000000

int niz[MAX];

void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
return;
}

void QuickSort(int l, int r){
int i,j;
if(l>=r) return;
//razvrstavaju se elementi s obzirom na stozer
i=l+1;
j=r;
while((i<=j) && (i<=r) && (j>l)){
while((niz[i]<=niz[l]) && (i<=r)) i++;
while((niz[j]>=niz[l]) && (j>l)) j--;
if(i<j)
swap(&niz[i], &niz[j]);
}
if(i>r){
//stozer je najveci u polju
swap(&niz[r],&niz[l]);
QuickSort(l,r-1);
}
else if(j<=l){
//stozer je najmanji u polju
QuickSort(l+1,r);
}
else{
//stozer se nalazi negdje u sredini
swap(&niz[j],&niz[l]);
QuickSort(l,j-1);
QuickSort(j+1,r);
}
}


//trenutno vrijeme
double vrijeme(){
    return (double)(clock())/(CLOCKS_PER_SEC/1000.0);
}

int main(void){
    int i,n;
    FILE *fp, *rezultati;
    rezultati=fopen("rezultati-quick-sort-sortirano.csv","w");
    for(n=1000;n<=30000;n+=1000){
        //ucitavanje n slucajnih brojeva
        fp=fopen("brojevi-sortirano.txt","r");
        for(i=0;i<n;i++)
            fscanf(fp,"%d",&niz[i]);


        double pocetak,kraj;
        pocetak=vrijeme();
        QuickSort(0,n-1);
        kraj=vrijeme();

        printf("n = %d\n",n);
        fprintf(rezultati,"%d, %g\n",n,(kraj-pocetak)/1000.0);
        fclose(fp);
    }
    fclose(rezultati);
    return 0;
}
