//Roberto - Jamiro-MR (Examen tercer parcial)

//Inicio codigo arboles.c de la clase previa
#include<stdio.h>
#include<stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int dato;
};

struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);
	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
	nuevo_nodo->dato = dato;
	nuevo_nodo->hijo_izq = NULL;
	nuevo_nodo->hijo_der = NULL;

	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	if(dato > nd->dato){
		if(nd->hijo_der == NULL){
			nd->hijo_der = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd->hijo_izq == NULL){
			nd->hijo_izq = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}
//Fin codigo arboles.c

int nivel = 0; //nivel
void buscar(struct nodo* nd, int n){ //busqueda de nivel
	nivel++;
	if(n == nd->dato){
		printf("El numero '%d' se encontrado en el siguiente nivel: %d\n", n, nivel); //numero localizado
	}else if(n < nd->dato && nd->hijo_izq != NULL){
		buscar(nd->hijo_izq, n);
	}else if(n > nd->dato && nd->hijo_der != NULL){
		buscar(nd->hijo_der, n);
	}else{
		printf("El número '%d' no se se ha podido localizar\n", n); //numero no localizado
	}
}

int main(){
	int numSearch = 0; //guardar numero a localizar
	struct nodo* raiz = NULL;
	raiz = nuevoNodo(10); //Numeros cambiados para comprobar que ordena
	insertarNodo(raiz, 2); //Además que los que teniamos eran solo 3
	insertarNodo(raiz, 22);
	insertarNodo(raiz, 4);
	insertarNodo(raiz, 3);
	insertarNodo(raiz, 9);
	insertarNodo(raiz, 6); //Así que agregue más y más grandes para comprobar si los encontraba.
	insertarNodo(raiz, 14);
	insertarNodo(raiz, 7);
	insertarNodo(raiz, 99);
	insertarNodo(raiz, 200);
	insertarNodo(raiz, 45);
	insertarNodo(raiz, 32);

	printf("¿Que numero desea localizar?: \n"); //Input del usuario para especificar numero
	scanf("%d", &numSearch);
	//Función de busqueda
	buscar(raiz, numSearch);
	printf("Fin del programa. \n");

	return 0; //fin del programa
}