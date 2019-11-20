#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_A 30
#define TAM_B 30

//Declaracion de la estructura Complejo
typedef struct Complejo{
	int real;
	int imag;
}Complejo;



//Prototipos de funciones
void quick(Complejo [], int izq, int der);

void ordenaCombina(Complejo [], Complejo [], Complejo []);


int main(){
	
	Complejo arrayA[TAM_A], arrayB[TAM_B], arrayUnion[TAM_A+TAM_B], result[TAM_A];
	int numeroReal, numeroImag, i=0;
	char real[5], imag[5];
	
	FILE *archivo=NULL;
	char nombreArchivo [15];
	
	printf("\n\t Ingrese el nombre del archivo para guardar en el array A");
	printf("\n\nNombre de archivo: ");
	scanf("%s",&nombreArchivo);
	archivo = fopen(nombreArchivo,"r");

	while(archivo == NULL){
		printf("El archivo no pudo abrirse");
		printf("\n\nNombre de archivo: ");
		scanf("%s",&nombreArchivo);
		archivo = fopen(nombreArchivo,"r");
	}
	//Para el array A
	while(!feof(archivo)){

		fscanf(archivo,"%[^+]+%[^\n]\n",&real, &imag);
		numeroReal = atoi(real);
		numeroImag = atoi(imag);
//		printf("\nParte real: %d", numeroReal);
//		
//		printf("\nParte Imaginaria :%d", numeroImag);
		
		arrayA[i].real=numeroReal;
		arrayA[i].imag=numeroImag;
		i++;
//		printf("\n");
	 }
	 
	printf("\n\t Ingrese el nombre del archivo para guardar en el array B");
	printf("\n\nNombre de archivo: ");
	scanf("%s",&nombreArchivo);
	archivo = fopen(nombreArchivo,"r");

	while(archivo == NULL){
		printf("El archivo no pudo abrirse");
		printf("\n\nNombre de archivo: ");
		scanf("%s",&nombreArchivo);
		archivo = fopen(nombreArchivo,"r");
	}
	//Para el array B
	i=0;
	while(!feof(archivo)){

		fscanf(archivo,"%[^+]+%[^\n]\n",&real, &imag);
		numeroReal = atoi(real);
		numeroImag = atoi(imag);
//		printf("\nParte real: %d", numeroReal);
//		
//		printf("\nParte Imaginaria :%d", numeroImag);
		
		arrayB[i].real=numeroReal;
		arrayB[i].imag=numeroImag;
		i++;
//		printf("\n");

	}
	
	
	//Ordenamiento de los arreglos
	//Para A
	printf("\nArreglo A a ordenar: ");
	for(i=0; i<TAM_A; i++){
		printf("%d+%di, ", arrayA[i].real,arrayA[i].imag);
	}
	
	quick(arrayA,0,TAM_A-1);
	printf("\n");
	
	printf("\nArreglo A ordenado: ");
	for(i=0; i<TAM_A; i++){
		printf("%d+%di, ", arrayA[i].real,arrayA[i].imag);
	}
	
	printf("\n----------------------------------------------------");
	//Para B
	printf("\nArreglo B a ordenar: ");
	for(i=0; i<TAM_B; i++){
		printf("%d+%di, ", arrayB[i].real,arrayB[i].imag);
	}
	
	quick(arrayB,0,TAM_B-1);
	printf("\n");
	
	printf("\nArreglo B ordenado: ");
	for(i=0; i<TAM_B; i++){
		printf("%d+%di, ", arrayB[i].real,arrayB[i].imag);
	}
	
	printf("\n----------------------------------------------------");
	//Empieza la union de los dos arreglos----------------------------
	printf("\nArreglos a combinar: ");
	printf("\nArreglo A: ");
	for(i=0; i<TAM_A; i++){
		printf("%d+%di, ", arrayA[i].real,arrayA[i].imag);
	}
	printf("\n");
	printf("\nArreglo B: ");
	for(i=0; i<TAM_B; i++){
		printf("%d+%di, ", arrayB[i].real,arrayB[i].imag);
	}
	
	ordenaCombina(arrayA, arrayB, arrayUnion);
	printf("\n----------------------------------------------------");
	printf("\nArreglo Union ordenado: ");
	for(i=0; i<(TAM_A+TAM_B); i++){
		printf("%d+%di, ", arrayUnion[i].real,arrayUnion[i].imag);
	}
	//Termina la union de los arreglos--------------------------------
	
	
	
	fclose(archivo);

	
	
	return 0;
}

//Implementacion de funciones
void quick(Complejo *array, int izq, int der){
	int i= izq, j=der, pivote = array[(izq+der)/2].real;
	Complejo res[TAM_A], aux;
	do{
		while(array[i].real < pivote){
			i++;
		}
		while(array[j].real > pivote){
			j--;
		}
		if(i <= j){
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
			j--;
		}
	}while(i<=j);
	
	if(izq < j){
		quick(array, izq, j);
	}
	if(i < der){
		quick(array, i, der);
	}
	
}

void ordenaCombina(Complejo *a, Complejo *b, Complejo *resultado){
	resultado[TAM_A+TAM_B];
	int posA=0, posB=0, posRes=0;
	
	while(posA < TAM_A && posB < TAM_B){
		if(a[posA].real < a[posB].real){
			resultado[posRes] = a[posA];
			posRes++;
			posA++;
		}
		else{
			resultado[posRes] = a[posB];
			posRes++;
			posB++;
		}
	}
	
	while(posA < TAM_A){
		resultado[posRes] = a[posA];
		posRes++;
		posA++;
	}
	
	while(posB < TAM_B){
		resultado[posRes] = b[posB];
		posRes++;
		posB++;
	}
	
	
}

