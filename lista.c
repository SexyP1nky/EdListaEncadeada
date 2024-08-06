#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó
typedef struct no
 {
    int data;
    struct no
    * next;
} no
;

// Função para criar uma lista vazia
no
* createlistavazia() {
    return NULL;
}

// Função para verificar se a lista está vazia
int vazio(no
* head) {
    return (head == NULL);
}

// Função para obter o tamanho da lista
int tamanho(no
* head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

// Função para obter/modificar o valor do elemento em uma determinada posição
int elemento(no
* head, int position) {
    if (position < 1 || position > tamanho(head)) {
        printf("Posição inválida!\n");
        return -1;
    }

    int i;
    for (i = 1; i < position; i++) {
        head = head->next;
    }

    return head->data;
}

void setElemento(no
* head, int position, int value) {
    if (position < 1 || position > tamanho(head)) {
        printf("Posição inválida!\n");
        return;
    }

    int i;
    for (i = 1; i < position; i++) {
        head = head->next;
    }

    head->data = value;
}

// Função para inserir um elemento em uma determinada posição
void insertElemento(no
** head, int position, int value) {
    if (position < 1 || position > tamanho(*head) + 1) {
        printf("Posição inválida!\n");
        return;
    }

    no
    * newno
     = (no
    *)malloc(sizeof(no
    ));
    newno
    ->data = value;

    if (position == 1) {
        newno
        ->next = *head;
        *head = newno
        ;
    } else {
        no
        * temp = *head;
        int i;
        for (i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newno
        ->next = temp->next;
        temp->next = newno
        ;
    }
}

// Função para retirar um elemento de uma determinada posição
void removeElemento(no
** head, int position) {
    if (position < 1 || position > tamanho(*head)) {
        printf("Posição inválida!\n");
        return;
    }

    no
    * temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
    } else {
        no
        * prev = NULL;
        int i;
        for (i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

// Função para imprimir os elementos de toda a lista
void printLista(no
* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Função principal para testar as operações
int main() {
    no
    * list = createlistavazia();

    printf("Inserindo elementos na lista...\n");
    insertElemento(&list, 1, 10);
    insertElemento(&list, 2, 20);
    insertElemento(&list, 3, 30);
    insertElemento(&list, 2, 15); // Inserir 15 na posição 2
    printLista(list); // Esperado: 10 --> 15 --> 20 --> 30 --> NULL

    printf("Tamanho da lista: %d\n", tamanho(list)); // Esperado: 4

    printf("Elemento na posição 3: %d\n", elemento(list, 3)); // Esperado: 20

    printf("Modificando elemento na posição 2 para 25...\n");
    setElemento(list, 2, 25);
    printLista(list); // Esperado: 10 --> 25 --> 20 --> 30 --> NULL

    printf("Removendo elemento na posição 1...\n");
    removeElemento(&list, 1);
    printLista(list); // Esperado: 25 --> 20 --> 30 --> NULL

    printf("Verificando se a lista está vazia: %s\n", vazio(list) ? "Sim" : "Não"); // Esperado: Não

    return 0;
}
