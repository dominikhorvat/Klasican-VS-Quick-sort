#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BROJ_DATOTEKA 1000

int niz[1000000];

void swap(int *a, int *b){
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
        if(i<j) swap(&niz[i], &niz[j]);
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



double vrijeme(){
    return (double)(clock())/(CLOCKS_PER_SEC/1000.0);
}

int main(void){

FILE *rezultati, *ulaz;
rezultati=fopen("rezultati.csv","w");

char naziv[50];
int n,d,i;
for(n=10000;n<=100000;n+=10000){
    double prosjecno=0;
    for(d=1;d<=BROJ_DATOTEKA;d++){
        sprintf(naziv,"primjeri/%d.txt",d);
        ulaz=fopen(naziv,"r");
        for(i=0;i<n;i++){
            fscanf(ulaz,"%d",&niz[i]);
        }
        double pocetak=vrijeme();
        QuickSort(0,n-1);
        double kraj=vrijeme();
        prosjecno+=kraj-pocetak;
        fclose(ulaz);
    }
    prosjecno/=BROJ_DATOTEKA;
    fprintf(rezultati,"%d %g\n",n,prosjecno);
    printf("Odredili za %d.\n",n);
}



fclose(rezultati);

return 0;
}
