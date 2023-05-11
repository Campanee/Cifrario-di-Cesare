#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {

  FILE * fin;
  FILE * fout;
  char rigo[500], fris[500]; //vettori
  int contatore, kc;
  if (argc !=3) {
    printf("Parametri errati\n");
    return 1;
  }

  kc = atoi(argv[2]);
  fin = fopen(argv[1], "r");
  if (fin == NULL){
    printf("Processo non riuscito\n");
    return 2;
  }

  strcpy(fris, "c_"); 
  strcat(fris, argv[1]);

  fout = fopen(fris, "w"); // fris = nome del file, w = metodo di scrittura
 
  fgets(rigo /*destinazione*/, 500 /*buffer*/, fin); // funzione di #string.h, legge riga per riga
  while(feof(fin) == 0) { //fin --> parametro
    for(contatore = 0; contatore < strlen(rigo)/*prende la lunghezza di rigo e la trasforma in int*/; contatore++) {
      if(rigo[contatore] >= 65 && rigo[contatore] <= 90) { //65 = A , 90 = Z
        rigo[contatore] = rigo[contatore] + kc;
      }else{
        if(rigo[contatore] >= 97 && rigo[contatore] <= 122) { //97 = a , 122 = z
        rigo[contatore] = rigo[contatore] + kc;
      }
    }
  }

  fprintf(fout, "%s", rigo); // %s = rigo
  fgets(rigo, 500, fin); //fgets punta alla riga successiva

  }
  fclose(fin);
  fclose(fout);
  return 0;
}