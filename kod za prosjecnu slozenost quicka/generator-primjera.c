#include <stdio.h>
#include <stdlib.h>

#define BR_BROJEVA   1000000
#define BR_DATOTEKA  1000

/* ovim kodom ce se generirati 1000 .txt datoteka u kojima
 ce biti 1 000 000 nasumicnih brojeva. Bitno je napomenuti kako je
 prije pokretanja ovog programa u istom direktoriju (mapi gdje je ovaj kod)
 napraviti mapu pod nazivom "primjeri" */

int main(void) {
    int br, i;
    FILE* datoteka;
    char naziv_datoteke[50];
    for(br = 1; br <= BR_DATOTEKA; ++br) {
        sprintf(naziv_datoteke,"primjeri/%d.txt",br);
        datoteka = fopen(naziv_datoteke,"w");
        for(i = 0; i < BR_BROJEVA; ++i)
            fprintf(datoteka,"%d ", rand());
        fclose(datoteka);
        printf("Generirana datoteka %s.\n",
               naziv_datoteke);
    }

    return 0;
}
