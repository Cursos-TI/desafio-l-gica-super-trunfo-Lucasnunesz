#include <stdio.h>

int main() {
    // Estrutura da carta com ataque e defesa
    struct {
        char nome[50];
        unsigned long int populacao;
        float area;
        float pib;
        int pontos_turisticos;
        float densidade;
        float pib_per_capita;
        int ataque;    // Novo atributo: Ataque
        int defesa;    // Novo atributo: Defesa
    } carta1, carta2;

    // Inicialização da Carta 1 - Brasil
    carta1.nome[0] = 'B';
    carta1.nome[1] = 'r';
    carta1.nome[2] = 'a';
    carta1.nome[3] = 's';
    carta1.nome[4] = 'i';
    carta1.nome[5] = 'l';
    carta1.nome[6] = '\0';
    carta1.populacao = 203000000;
    carta1.area = 8516000;
    carta1.pib = 1800;
    carta1.pontos_turisticos = 45;
    carta1.ataque = 70;       // Valor de ataque (exemplo)
    carta1.defesa = 60;       // Valor de defesa (exemplo)
    if (carta1.area > 0) {
        carta1.densidade = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidade = 0;
    }
    if (carta1.populacao > 0) {
        carta1.pib_per_capita = (carta1.pib * 1000000000) / (float)carta1.populacao;
    } else {
        carta1.pib_per_capita = 0;
    }

    // Inicialização da Carta 2 - Japão
    carta2.nome[0] = 'J';
    carta2.nome[1] = 'a';
    carta2.nome[2] = 'p';
    carta2.nome[3] = 'a';
    carta2.nome[4] = 'o';
    carta2.nome[5] = '\0';
    carta2.populacao = 125000000;
    carta2.area = 377975;
    carta2.pib = 4900;
    carta2.pontos_turisticos = 38;
    carta2.ataque = 85;       // Valor de ataque (exemplo)
    carta2.defesa = 50;       // Valor de defesa (exemplo)
    if (carta2.area > 0) {
        carta2.densidade = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidade = 0;
    }
    if (carta2.populacao > 0) {
        carta2.pib_per_capita = (carta2.pib * 1000000000) / (float)carta2.populacao;
    } else {
        carta2.pib_per_capita = 0;
    }

    int opcao1, opcao2;
    int entrada_valida = 0;

    // Menu para primeiro atributo
    do {
        printf("\nEscolha o PRIMEIRO atributo:\n");
        printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade\n6. PIB per Capita\n7. Ataque\n8. Defesa\n");
        printf("Digite (1-8): ");
        scanf("%d", &opcao1);
        while (getchar() != '\n'); // Limpa buffer

        if (opcao1 >= 1 && opcao1 <= 8) {
            entrada_valida = 1;
        } else {
            printf("Erro: Escolha entre 1 e 8!\n");
        }
    } while (entrada_valida == 0);

    // Menu para segundo atributo
    entrada_valida = 0;
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        int num = 1;
        if (opcao1 != 1) printf("%d. Populacao\n", num++);
        if (opcao1 != 2) printf("%d. Area\n", num++);
        if (opcao1 != 3) printf("%d. PIB\n", num++);
        if (opcao1 != 4) printf("%d. Pontos Turisticos\n", num++);
        if (opcao1 != 5) printf("%d. Densidade\n", num++);
        if (opcao1 != 6) printf("%d. PIB per Capita\n", num++);
        if (opcao1 != 7) printf("%d. Ataque\n", num++);
        if (opcao1 != 8) printf("%d. Defesa\n", num++);
        printf("Digite (1-%d): ", num-1);
        scanf("%d", &opcao2);
        while (getchar() != '\n'); // Limpa buffer

        // Mapeamento do opcao2
        int opcao2_real = 0;
        int contador = 0;
        if (opcao1 != 1) { contador++; if (contador == opcao2) opcao2_real = 1; }
        if (opcao1 != 2 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 2; }
        if (opcao1 != 3 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 3; }
        if (opcao1 != 4 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 4; }
        if (opcao1 != 5 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 5; }
        if (opcao1 != 6 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 6; }
        if (opcao1 != 7 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 7; }
        if (opcao1 != 8 && opcao2_real == 0) { contador++; if (contador == opcao2) opcao2_real = 8; }

        if (opcao2 >= 1 && opcao2 <= 7 && opcao2_real != opcao1) {
            opcao2 = opcao2_real;
            entrada_valida = 1;
        } else {
            printf("Erro: Escolha valida e diferente do primeiro!\n");
        }
    } while (entrada_valida == 0);

    // Variáveis para atributos
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    // Primeiro atributo com switch
    switch (opcao1) {
        case 1: 
            valor1_carta1 = carta1.populacao; 
            valor1_carta2 = carta2.populacao; 
            break;
        case 2: 
            valor1_carta1 = carta1.area; 
            valor1_carta2 = carta2.area; 
            break;
        case 3: 
            valor1_carta1 = carta1.pib; 
            valor1_carta2 = carta2.pib; 
            break;
        case 4: 
            valor1_carta1 = carta1.pontos_turisticos; 
            valor1_carta2 = carta2.pontos_turisticos; 
            break;
        case 5: 
            valor1_carta1 = carta1.densidade; 
            valor1_carta2 = carta2.densidade; 
            break;
        case 6: 
            valor1_carta1 = carta1.pib_per_capita; 
            valor1_carta2 = carta2.pib_per_capita; 
            break;
        case 7: 
            valor1_carta1 = carta1.ataque; 
            valor1_carta2 = carta2.ataque; 
            break;
        case 8: 
            valor1_carta1 = carta1.defesa; 
            valor1_carta2 = carta2.defesa; 
            break;
    }

    // Segundo atributo com switch
    switch (opcao2) {
        case 1: 
            valor2_carta1 = carta1.populacao; 
            valor2_carta2 = carta2.populacao; 
            break;
        case 2: 
            valor2_carta1 = carta1.area; 
            valor2_carta2 = carta2.area; 
            break;
        case 3: 
            valor2_carta1 = carta1.pib; 
            valor2_carta2 = carta2.pib; 
            break;
        case 4: 
            valor2_carta1 = carta1.pontos_turisticos; 
            valor2_carta2 = carta2.pontos_turisticos; 
            break;
        case 5: 
            valor2_carta1 = carta1.densidade; 
            valor2_carta2 = carta2.densidade; 
            break;
        case 6: 
            valor2_carta1 = carta1.pib_per_capita; 
            valor2_carta2 = carta2.pib_per_capita; 
            break;
        case 7: 
            valor2_carta1 = carta1.ataque; 
            valor2_carta2 = carta2.ataque; 
            break;
        case 8: 
            valor2_carta1 = carta1.defesa; 
            valor2_carta2 = carta2.defesa; 
            break;
    }

    // Comparação individual
    int vitoria1_attr1;
    if (opcao1 == 5) { // Densidade: menor vence
        if (valor1_carta1 < valor1_carta2) vitoria1_attr1 = 1;
        else vitoria1_attr1 = 0;
    } else { // Outros atributos: maior vence
        if (valor1_carta1 > valor1_carta2) vitoria1_attr1 = 1;
        else vitoria1_attr1 = 0;
    }

    int vitoria1_attr2;
    if (opcao2 == 5) { // Densidade: menor vence
        if (valor2_carta1 < valor2_carta2) vitoria1_attr2 = 1;
        else vitoria1_attr2 = 0;
    } else { // Outros atributos: maior vence
        if (valor2_carta1 > valor2_carta2) vitoria1_attr2 = 1;
        else vitoria1_attr2 = 0;
    }

    // Soma dos atributos escolhidos
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Lógica de ataque e defesa
    int resultado_ataque_defesa1 = carta1.ataque - carta2.defesa; // Carta 1 ataca Carta 2
    int resultado_ataque_defesa2 = carta2.ataque - carta1.defesa; // Carta 2 ataca Carta 1

    // Resultado
    printf("\n=== Resultado ===\n");
    printf("Paises: %s vs %s\n", carta1.nome, carta2.nome);
    printf("\nAtributo 1:\n%s: %.2f\n%s: %.2f\n", carta1.nome, valor1_carta1, carta2.nome, valor1_carta2);
    if (vitoria1_attr1) printf("Vencedor: %s\n", carta1.nome);
    else printf("Vencedor: %s\n", carta2.nome);

    printf("\nAtributo 2:\n%s: %.2f\n%s: %.2f\n", carta1.nome, valor2_carta1, carta2.nome, valor2_carta2);
    if (vitoria1_attr2) printf("Vencedor: %s\n", carta1.nome);
    else printf("Vencedor: %s\n", carta2.nome);

    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", carta1.nome, soma_carta1, carta2.nome, soma_carta2);

    printf("\nAtaque vs Defesa:\n");
    printf("%s ataca %s: %d\n", carta1.nome, carta2.nome, resultado_ataque_defesa1);
    printf("%s ataca %s: %d\n", carta2.nome, carta1.nome, resultado_ataque_defesa2);

    printf("\nResultado Final: ");
    if (soma_carta1 == soma_carta2) {
        printf("Empate nos atributos! ");
        if (resultado_ataque_defesa1 == resultado_ataque_defesa2) {
            printf("Empate total!\n");
        } else if (resultado_ataque_defesa1 > resultado_ataque_defesa2) {
            printf("Vencedor por ataque/defesa: %s\n", carta1.nome);
        } else {
            printf("Vencedor por ataque/defesa: %s\n", carta2.nome);
        }
    } else if (soma_carta1 > soma_carta2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else {
        printf("Vencedor: %s\n", carta2.nome);
    }

    return 0;
}