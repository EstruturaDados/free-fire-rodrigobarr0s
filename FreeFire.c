#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
typedef struct
{
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

// Vetor estático para armazenar os itens
Item mochila[MAX_ITENS];
int numItens = 0;

// Função para adicionar um item
void adicionarItem()
{
    if (numItens >= MAX_ITENS)
    {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);
    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[numItens] = novo;
    numItens++;

    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item pelo nome
void removerItem()
{
    char nome[50];
    printf("Digite o nome do item a remover: ");
    scanf("%s", nome);

    int encontrado = -1;
    for (int i = 0; i < numItens; i++)
    {
        if (strcmp(mochila[i].nome, nome) == 0)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("Item não encontrado.\n");
        return;
    }

    // Reorganiza o vetor para preencher a lacuna
    for (int i = encontrado; i < numItens - 1; i++)
    {
        mochila[i] = mochila[i + 1];
    }
    numItens--;

    printf("Item removido com sucesso!\n");
}

// Função para listar todos os itens
void listarItens()
{
    if (numItens == 0)
    {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n===== Itens na Mochila =====\n");
    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numItens; i++)
    {
        printf("%-20s %-15s %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
    printf("---------------------------------------------\n\n");
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItemPorNome()
{
    if (numItens == 0)
    {
        printf("Mochila vazia. Nenhum item para buscar.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do item que deseja buscar: ");
    scanf("%s", nome);

    int encontrado = 0;
    for (int i = 0; i < numItens; i++)
    {
        if (strcmp(mochila[i].nome, nome) == 0)
        {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Item '%s' não encontrado na mochila.\n", nome);
    }
}

// Função principal com menu interativo
int main()
{
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.
    
    int opcao;

    do {
        printf("===== MENU =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItemPorNome(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
