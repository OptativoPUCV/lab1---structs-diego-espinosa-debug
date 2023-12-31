#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int mayor = arr[0];

  for(int i = 0; i < size; i++) 
  {
    if(mayor < arr[i]){
      mayor = arr[i];
    }
  }
  
  return mayor; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int aux[size];
  int cont = 0;

  for(int i = size - 1; i >= 0; i--)
  {
    aux[cont] = arr[i];
    cont++;
  }

  for(int i = 0; i < size; i++)
  {
    arr[i] = aux[i];  
  }

  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/




int *filterEvenNumbers(int arr[], int size, int *newSize) { 

  int cantidadPares = 0;

  for(int i = 0; i < size; i++)
  {
    if(arr[i]%2 == 0)
    {
      cantidadPares++;
    }
  }

  int *nuevoArr =(int *) malloc(cantidadPares * sizeof(int));
  if(nuevoArr == NULL)
  {
    return NULL;
  }

  cantidadPares = 0;

  for(int i = 0; i < size; i++)
  {
    if(arr[i]%2 == 0)
    {
      nuevoArr[cantidadPares] = arr[i];
      cantidadPares++;
    }  
  }

  *newSize = cantidadPares;
  
return nuevoArr; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  
  int sizeFinal = size1 + size2;

  for(int i = 0; i < size1; i++)
  {
    result[i] = arr1[i];  
  }

  int contador = 0;
  
  for(int i = size1; i < sizeFinal; i++)
  {
    result[i] = arr2[contador];
    contador++;
  }

  for(int i = 0; i < sizeFinal - 1; i++)
  {
    for(int f = 0; f < sizeFinal - 1; f++)
    {
      if(result[f] > result[f + 1])
      {
        int aux = result[f];
        result[f] = result[f + 1];
        result[f + 1] = aux;
      }
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 

  int ascendente = 0;
  int descendente = 0;

  for(int i = 0; i < size - 1; i++)
  {
    if(arr[i] > arr[i + 1])
    {
      descendente = 1;
    }else if(arr[i] < arr[i + 1])
    {
      ascendente = 1;
    }
  }
  

  if(ascendente == 0)
  {
    return -1;
  }else if(descendente == 0)
  {
    return 1;
  }else
  {
    return 0;
  }
  
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion) 
{
  strcpy(libro->titulo,titulo);
  strcpy(libro->autor.nombre,nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
  
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  
  Nodo *primerNodo = (Nodo *) malloc(sizeof(Nodo));
  if (primerNodo == NULL)
  {
    return NULL;
  }

  primerNodo->numero = arr[0];
  primerNodo->siguiente = NULL;

  Nodo *nodoActual = primerNodo;

  for(int i = 1; i < size; i++)
  {
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevoNodo == NULL)
    {
      return NULL;
    }

    nuevoNodo->numero = arr[i];
    nuevoNodo->siguiente = NULL;

    nodoActual->siguiente = nuevoNodo;
    nodoActual = nuevoNodo;
  }
  
  
  
  
  
  return primerNodo; 
}
