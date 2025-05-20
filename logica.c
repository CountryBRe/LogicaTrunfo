#include <stdio.h>

int main() {
    struct Carta {
        char estado[30];
        char codigo[10];
        char nome_cidade[30];
        unsigned long int populacao; // População
        float area; // Área em km²
        float pib; // PIB em bilhões
        int pontos_turisticos; // Pontos turisticos
        float densidade_populacional; // Densidade populacional
        float pib_pc; // Pib per capita
    };

    struct Carta carta1 = {"Santa Catarina", "SC01", "Florianópolis", 7600000, 95730.0, 446.6, 300};
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_pc = (carta1.pib * 1000000000) / carta1.populacao;

    struct Carta carta2 = {"Paraná", "PR01", "Curitiba", 11824665, 199307.0, 564.2, 200};
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_pc = (carta2.pib * 1000000000) / carta2.populacao;

    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    int atributo1 = -1, atributo2 = -1;

    printf("=== STATUS DAS CARTAS ===\n\n");
    printf("[Carta 1] %s (%s)\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\nDensidade: %.2f hab/km²\nPIB per capita: %.2f\n\n",
        carta1.nome_cidade, carta1.estado, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos, carta1.densidade_populacional, carta1.pib_pc);

    printf("[Carta 2] %s (%s)\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos turísticos: %d\nDensidade: %.2f hab/km²\nPIB per capita: %.2f\n\n",
        carta2.nome_cidade, carta2.estado, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos, carta2.densidade_populacional, carta2.pib_pc);

    // Primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n6 - PIB per capita\n> ");
    scanf("%d", &atributo1);

    // Segundo atributo (exclui o anterior)
    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1) {
                switch(i) {
                    case 1: printf("%d - População\n", i); break;
                    case 2: printf("%d - Área\n", i); break;
                    case 3: printf("%d - PIB\n", i); break;
                    case 4: printf("%d - Pontos turísticos\n", i); break;
                    case 5: printf("%d - Densidade populacional\n", i); break;
                    case 6: printf("%d - PIB per capita\n", i); break;
                }
            }
        }
        printf("> ");
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 6);

    // Função auxiliar para pegar valores
    float get_valor(struct Carta c, int atributo) {
        switch (atributo) {
            case 1: return (float)c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return (float)c.pontos_turisticos;
            case 5: return c.densidade_populacional;
            case 6: return c.pib_pc;
            default: return 0;
        }
    }

    // Atribuir valores dos atributos
    valor1_carta1 = get_valor(carta1, atributo1);
    valor1_carta2 = get_valor(carta2, atributo1);
    valor2_carta1 = get_valor(carta1, atributo2);
    valor2_carta2 = get_valor(carta2, atributo2);

    // Mostrar os atributos escolhidos
    char* nomes_atributos[] = {
        "", "População", "Área", "PIB", "Pontos turísticos", "Densidade populacional", "PIB per capita"
    };

    printf("\n=== COMPARAÇÃO ===\n\n");
    printf("Atributo 1: %s\n", nomes_atributos[atributo1]);
    printf("%s: %.2f\n", carta1.nome_cidade, valor1_carta1);
    printf("%s: %.2f\n\n", carta2.nome_cidade, valor1_carta2);

    printf("Atributo 2: %s\n", nomes_atributos[atributo2]);
    printf("%s: %.2f\n", carta1.nome_cidade, valor2_carta1);
    printf("%s: %.2f\n\n", carta2.nome_cidade, valor2_carta2);

    // Comparações individuais
    int pontos_carta1 = 0, pontos_carta2 = 0;

    // Regras para o primeiro atributo
    if (atributo1 == 5) { // densidade - menor vence
        pontos_carta1 += valor1_carta1 < valor1_carta2 ? 1 : 0;
        pontos_carta2 += valor1_carta2 < valor1_carta1 ? 1 : 0;
    } else {
        pontos_carta1 += valor1_carta1 > valor1_carta2 ? 1 : 0;
        pontos_carta2 += valor1_carta2 > valor1_carta1 ? 1 : 0;
    }

    // Segundo atributo
    if (atributo2 == 5) { // densidade - menor vence
        pontos_carta1 += valor2_carta1 < valor2_carta2 ? 1 : 0;
        pontos_carta2 += valor2_carta2 < valor2_carta1 ? 1 : 0;
    } else {
        pontos_carta1 += valor2_carta1 > valor2_carta2 ? 1 : 0;
        pontos_carta2 += valor2_carta2 > valor2_carta1 ? 1 : 0;
    }

    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome_cidade, soma1);
    printf("%s: %.2f\n\n", carta2.nome_cidade, soma2);

    printf("Resultado final:\n");
    if (soma1 > soma2) {
        printf("\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
    } else if (soma2 > soma1) {
        printf("\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
    } else {
        printf("\033[1;33mEmpate!\033[0m\n");
    }

    return 0;
}
