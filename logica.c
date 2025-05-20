#include <stdio.h>

int main() {
    // Estrutura representando uma carta do Super Trunfo
    struct Carta {
        char estado[30];
        char codigo[10];
        char nome_cidade[30];
        unsigned long int populacao;
        float area; // Em km²
        float pib;  // Em bilhões
        int pontos_turisticos; // Pontos turisticos
        float densidade_populacional; // Densidade populacional
        float pib_pc; // Pib per capita
    };

    // Carta 1 - Santa Catarina
    struct Carta carta1;
    sprintf(carta1.estado, "Santa Catarina");
    sprintf(carta1.codigo, "SC01");
    sprintf(carta1.nome_cidade, "Florianópolis");
    carta1.populacao = 7600000;
    carta1.area = 95730.0;
    carta1.pib = 446.6;
    carta1.pontos_turisticos = 300;
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_pc = (carta1.pib * 1000000000) / carta1.populacao;

    // Carta 2 - Paraná
    struct Carta carta2;
    sprintf(carta2.estado, "Paraná");
    sprintf(carta2.codigo, "PR01");
    sprintf(carta2.nome_cidade, "Curitiba");
    carta2.populacao = 11824665;
    carta2.area = 199307.0;
    carta2.pib = 564.2;
    carta2.pontos_turisticos = 200;
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_pc = (carta2.pib * 1000000000) / carta2.populacao;

    // Exibir status das cartas
    printf("=== STATUS DAS CARTAS ===\n\n");

    printf("[Carta 1] %s (%s)\n", carta1.nome_cidade, carta1.estado);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per capita: %.2f\n\n", carta1.pib_pc);

    printf("[Carta 2] %s (%s)\n", carta2.nome_cidade, carta2.estado);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per capita: %.2f\n\n", carta2.pib_pc);

    // Menu para escolhas de atributos
    int opcao;
    printf("=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha algum atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional\n");
    printf("6 - PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n=== COMPARAÇÃO ENTRE CARTAS ===\n");

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %lu\n", carta1.nome_cidade, carta1.populacao);
            printf("%s: %lu\n", carta2.nome_cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome_cidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome_cidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.area > carta1.area) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nome_cidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nome_cidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d\n", carta1.nome_cidade, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.nome_cidade, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade populacional\n");
            printf("%s: %.2f hab/km²\n", carta1.nome_cidade, carta1.densidade_populacional);
            printf("%s: %.2f hab/km²\n", carta2.nome_cidade, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("\n\033[0;32m%s venceu!\033[0m (menor densidade)\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("\n\033[0;32m%s venceu!\033[0m (menor densidade)\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 6:
            printf("Atributo: PIB per capita\n");
            printf("%s: %.2f\n", carta1.nome_cidade, carta1.pib_pc);
            printf("%s: %.2f\n", carta2.nome_cidade, carta2.pib_pc);
            if (carta1.pib_pc > carta2.pib_pc) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta1.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta2.nome_cidade);
            } else if (carta2.pib_pc > carta1.pib_pc) {
                printf("\n\033[0;32m%s venceu!\033[0m\n", carta2.nome_cidade);
                printf("\033[0;31m%s perdeu.\033[0m\n", carta1.nome_cidade);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        default:
            printf("\n\033[0;31mOpção inválida! Por favor, escolha entre 1 e 6.\033[0m\n");
    }

    return 0;
}