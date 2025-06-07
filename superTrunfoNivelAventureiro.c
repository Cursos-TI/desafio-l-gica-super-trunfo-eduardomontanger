#include <stdio.h>

int main() {
    // declaracao das variaveis para as duas cartas
    char estado1[30], codigo1[10], nomeCidade1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    char estado2[30], codigo2[10], nomeCidade2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    float densidade1, pibPerCapita1;
    float densidade2, pibPerCapita2;

    int opcao;

    // inpyt de dados da primeira carta
    printf("Digite os dados da primeira carta:\n");
    printf("Estado: ");
    scanf("%s", estado1);
    printf("Codigo da carta: ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^"]s", nomeCidade1);
    printf("Populacao: ");
    scanf("%d", &populacao1);
    printf("Area (km2): ");
    scanf("%f", &area1);
    printf("PIB (em R$): ");
    scanf("%f", &pib1);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // input de dados da segunda carta
    printf("\nDigite os dados da segunda carta:\n");
    printf("Estado: ");
    scanf("%s", estado2);
    printf("Codigo da carta: ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^"]s", nomeCidade2);
    printf("Populacao: ");
    scanf("%d", &populacao2);
    printf("Area (km2): ");
    scanf("%f", &area2);
    printf("PIB (em R$): ");
    scanf("%f", &pib2);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // calculo de indicadores
    densidade1 = (area1 > 0) ? (populacao1 / area1) : 0;
    pibPerCapita1 = (populacao1 > 0) ? (pib1 / populacao1) : 0;

    densidade2 = (area2 > 0) ? (populacao2 / area2) : 0;
    pibPerCapita2 = (populacao2 > 0) ? (pib2 / populacao2) : 0;

    // menu
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    printf("\nComparacao de cartas:\n");
    printf("Carta 1 - %s (%s)\n", nomeCidade1, estado1);
    printf("Carta 2 - %s (%s)\n\n", nomeCidade2, estado2);

    switch (opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", nomeCidade1, populacao1);
            printf("%s: %d\n\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2) printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (populacao2 > populacao1) printf("Resultado: %s venceu!\n", nomeCidade2);
            else printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f km2\n", nomeCidade1, area1);
            printf("%s: %.2f km2\n\n", nomeCidade2, area2);
            if (area1 > area2) printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (area2 > area1) printf("Resultado: %s venceu!\n", nomeCidade2);
            else printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f\n", nomeCidade1, pib1);
            printf("%s: R$ %.2f\n\n", nomeCidade2, pib2);
            if (pib1 > pib2) printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pib2 > pib1) printf("Resultado: %s venceu!\n", nomeCidade2);
            else printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Numero de pontos turisticos\n");
            printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d\n\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1) printf("Resultado: %s venceu!\n", nomeCidade2);
            else printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade demografica\n");
            printf("%s: %.2f hab/km2\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km2\n\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2) printf("Resultado: %s venceu!\n", nomeCidade1);
            else if (densidade2 < densidade1) printf("Resultado: %s venceu!\n", nomeCidade2);
            else printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opcao invalida, tente novamente\n");
    }

    return 0;
}
