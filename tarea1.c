#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct thread_data {
   int a;
   int b;
   int sum;
   int sub;
   int mult;

} thread_data;

void *Thread(void *arg)
{
   thread_data *tdata=(thread_data *)arg;

   int a=tdata->a;
   int b=tdata->b;
   int sum=a+b;
   int sub=a-b;
   int mult=a*b;
   
   tdata->sum=sum;
   tdata->sub=sub;
   tdata->mult=mult;
   pthread_exit(NULL);
}

int main()
{
   pthread_t tid;
   thread_data tdata;
   
   printf("Introduzca el primer numero entero: ");
   scanf("%d", &tdata.a);
   
   printf("Introduzca el segundo numero entero: ");
   scanf("%d", &tdata.b);


   pthread_create(&tid, NULL, Thread, (void *)&tdata);
   pthread_join(tid, NULL);

   printf("%d + %d = %d\n", tdata.a, tdata.b, tdata.sum);
   printf("%d - %d = %d\n", tdata.a, tdata.b, tdata.sub);
   printf("%d * %d = %d\n", tdata.a, tdata.b, tdata.mult);

   int suma =  tdata.sum;
   int resta = tdata.sub;
   int multi = tdata.mult;
   int x;
   FILE *fichero;
   fichero = fopen("tarea1.txt", "w+");
  
      while (!feof(fichero))
      {
         fscanf(fichero, "%d", &x);

      }
      
    
         fprintf(fichero," \nResultado de la Suma: %d + %d = %d\n", tdata.a, tdata.b, tdata.sum);
         fprintf(fichero, "\nResultado de la Resta: %d - %d = %d\n", tdata.a, tdata.b, tdata.sub);
         fprintf(fichero,"\nResultado de la Multiplicacion: %d * %d = %d\n", tdata.a, tdata.b, tdata.mult);
       
    

   
   fflush(fichero);
   fclose(fichero);
   printf("EXITO !!");
   printf("Proceso completado");
   return 0;
}