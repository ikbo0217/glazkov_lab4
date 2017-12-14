#include <stdio.h> 
#include <stdlib.h> 

/* Packet structure described in the task */
struct packet { 
   int num; 
   char line[256];
   float floatnum; 
};

int main(int argc, char *argv[]){ 
   int size = 0; 
   FILE *fp;
   struct packet p;

   if(argc > 1){
      fp = fopen(argv[1], "rb"); 

      /* Making sure we ve opened the file */
      if(!fp){
         printf("\"%s\" could not be found or opened. Make sure you ve entered correct filename, file exists and is not locked by system.", argv[1]);

         return 0;
      }

      /* Reading the file */
      while(fread(&p, sizeof(struct packet), 1, fp)){
         /* Knowing that each packet has fixed size in bytes, adding it`s size to get total file size */
         size = size + sizeof(struct packet);

         printf("%d %s %f \n", p.num, p.line, p.floatnum); 
      }

      printf("Total size %d bytes", size); 
   } else {
      printf("Please, provide a filename as the second argument\n./a.out [filename]\n");
   }

   return 0; 
}