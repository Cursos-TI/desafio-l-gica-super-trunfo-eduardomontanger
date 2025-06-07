#include <stdio.h>

int main() {
    // declaração das variaveis para as duas cartas
    char estado1[30], codigo1[10], nomeCidade1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    char estado2[30], codigo2[10], nomeCidade2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    float densidade1, densidade2;
    int opcao1 = 0, opcao2 = 0;
    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;
    float soma1 = 0, soma2 = 0;

    // inpyt de dados da primeira carta
    printf("Digite os dados da primeira carta:\n");
    printf("Estado: "); scanf("%29s", estado1); while (getchar() != '\n');
    printf("Codigo da carta: "); scanf("%9s", codigo1); while (getchar() != '\n');
    printf("Nome da cidade: "); scanf(" %[^\n]", nomeCidade1); while (getchar() != '\n');
    printf("Populacao: "); scanf("%d", &populacao1); while (getchar() != '\n');
    printf("Area (km2): "); scanf("%f", &area1); while (getchar() != '\n');
    printf("PIB (em R$): "); scanf("%f", &pib1); while (getchar() != '\n');
    printf("Numero de pontos turisticos: "); scanf("%d", &pontosTuristicos1); while (getchar() != '\n');

    // input de dados da segunda carta
    printf("\nDigite os dados da segunda carta:\n");
    printf("Estado: "); scanf("%29s", estado2); while (getchar() != '\n');
    printf("Codigo da carta: "); scanf("%9s", codigo2); while (getchar() != '\n');
    printf("Nome da cidade: "); scanf(" %[^\n]", nomeCidade2); while (getchar() != '\n');
    printf("Populacao: "); scanf("%d", &populacao2); while (getchar() != '\n');
    printf("Area (km2): "); scanf("%f", &area2); while (getchar() != '\n');
    printf("PIB (em R$): "); scanf("%f", &pib2); while (getchar() != '\n');
    printf("Numero de pontos turisticos: "); scanf("%d", &pontosTuristicos2); while (getchar() != '\n');

    // calculo de densidade demográfica
    densidade1 = (area1 > 0) ? (populacao1 / area1) : 0;
    densidade2 = (area2 > 0) ? (populacao2 / area2) : 0;

    // menu
    printf("\nAtributos disponíveis:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");

    // opcao do primeiro atributo
    printf("\nEscolha o primeiro atributo (1-5): ");
    scanf("%d", &opcao1); while (getchar() != '\n');

    // opcao do segundo atributo, impedindo repeticao e entrada invalida
    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        if (scanf("%d", &opcao2) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n');
            opcao2 = 0;
            continue;
        }
        while (getchar() != '\n');
        if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5) {
            printf("Atributo invalido ou repetido. Escolha outro.\n");
        }
    } while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5);

    // comparacao dos atributos informados a acima
    for (int i = 1; i <= 2; i++) {
        int opcao = (i == 1) ? opcao1 : opcao2;
        float v1 = 0, v2 = 0;
        char nomeAttr[50];

        switch (opcao) {
            case 1:
                v1 = populacao1;
                v2 = populacao2;
                sprintf(nomeAttr, "Populacao");
                break;
            case 2:
                v1 = area1;
                v2 = area2;
                sprintf(nomeAttr, "Area");
                break;
            case 3:
                v1 = pib1;
                v2 = pib2;
                sprintf(nomeAttr, "PIB");
                break;
            case 4:
                v1 = pontosTuristicos1;
                v2 = pontosTuristicos2;
                sprintf(nomeAttr, "Pontos Turisticos");
                break;
            case 5:
                v1 = densidade1;
                v2 = densidade2;
                sprintf(nomeAttr, "Densidade Demografica");
                break;
            default:
                printf("\nOpcao invalida.\n");
                return 1;
        }

        printf("\nComparacao (%s):\n", nomeAttr);
        printf("%s: %.2f\n", nomeCidade1, v1);
        printf("%s: %.2f\n", nomeCidade2, v2);

        if (opcao == 5) {
            if (v1 < v2) printf("-> %s venceu este atributo!\n", nomeCidade1);
            else if (v2 < v1) printf("-> %s venceu este atributo!\n", nomeCidade2);
            else printf("-> Empate neste atributo.\n");
        } else {
            if (v1 > v2) printf("-> %s venceu este atributo!\n", nomeCidade1);
            else if (v2 > v1) printf("-> %s venceu este atributo!\n", nomeCidade2);
            else printf("-> Empate neste atributo.\n");
        }

        if (i == 1) { valor1_attr1 = v1; valor2_attr1 = v2; }
        else { valor1_attr2 = v1; valor2_attr2 = v2; }
    }

    // soma total dos resultados
    soma1 = valor1_attr1 + valor1_attr2;
    soma2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma total dos atributos:\n");
    printf("%s: %.2f\n", nomeCidade1, soma1);
    printf("%s: %.2f\n", nomeCidade2, soma2);

    if (soma1 > soma2) {
        printf("\nResultado final: %s venceu a rodada!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("\nResultado final: %s venceu a rodada!\n", nomeCidade2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}
