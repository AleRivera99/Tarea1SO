#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct thread_data
{
   int numero1;
   int numero2;
   int suma;
   int resta;
   int multiplicacion;

} thread_data;

void *Thread(void *arg)
{
   thread_data *tdata = (thread_data *)arg;

   int numero1 = tdata->numero1;
   int numero2 = tdata->numero2;
   int suma = numero1 + numero2;
   int resta = numero1 - numero2;
   int multiplicacion = numero1 * numero2;

   tdata->suma = suma;
   tdata->resta = resta;
   tdata->multiplicacion = multiplicacion;
   pthread_exit(NULL);
}

int main()
{
   pthread_t tid;
   thread_data tdata;

   printf("Introduzca el primer numero entero: ");
   scanf("%d", &tdata.numero1);

   printf("Introduzca el segundo numero entero: ");
   scanf("%d", &tdata.numero2);

   pthread_create(&tid, NULL, Thread, (void *)&tdata);
   pthread_join(tid, NULL);

   printf("%d + %d = %d\n", tdata.numero1, tdata.numero2, tdata.suma);
   printf("%d - %d = %d\n", tdata.numero1, tdata.numero2, tdata.resta);
   printf("%d * %d = %d\n", tdata.numero1, tdata.numero2, tdata.multiplicacion);

   int suma = tdata.suma;
   int resta = tdata.resta;
   int multi = tdata.multiplicacion;
   FILE *puntero;
   puntero = fopen("tarea1.txt", "w+");
   fprintf(puntero, " \nResultado de la Suma: %d + %d = %d\n", tdata.numero1, tdata.numero2, tdata.suma);
   fprintf(puntero, "\nResultado de la Resta: %d - %d = %d\n", tdata.numero1, tdata.numero2, tdata.resta);
   fprintf(puntero, "\nResultado de la Multiplicacion: %d * %d = %d\n", tdata.numero1, tdata.numero2, tdata.multiplicacion);

   printf("El archivo de Texto txt fue creado");
   return 0;
}