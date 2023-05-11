#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

 double sommatore = 0;
 double med=0, dll;
 char riga [200];
 FILE * f;
 f = fopen("file.txt","r");

 if(f == NULL){
   printf("errore\n");
   return 1;
 }

 fgets(riga, 200, f);
 med = med + atof(riga);
 printf("Prezzo al litro in euro >> ""%s", riga);
 fgets(riga, 200, f);
while(!feof(f)){
sommatore = sommatore + atof(riga);
fgets(riga,200,f);
}

fclose(f);

printf("I litri totali che sono stati erogati sono >> " "%1.f\n", sommatore);

dll = sommatore * med;

printf("Prezzo totale in euro >> " "%1f\n", dll);

return 0;
}
