#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP_SEC(s) Sleep((s) * 1000)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_SEC(s) sleep(s)
#define CLEAR_SCREEN() system("clear")
#endif

// Funções de Conversão

float converterComprimento(float valor, char ent, char sai) {
    // Base: Metros
    float emMetros = 0;
    if (ent == 'C') emMetros = valor / 100.0f;
    else if (ent == 'M') emMetros = valor;
    else if (ent == 'K') emMetros = valor * 1000.0f;
    else if (ent == 'J') emMetros = valor * 0.9144f;
    else if (ent == 'P') emMetros = valor * 0.0254f;

    if (sai == 'C') return emMetros * 100.0f;
    if (sai == 'M') return emMetros;
    if (sai == 'K') return emMetros / 1000.0f;
    if (sai == 'J') return emMetros / 0.9144f;
    if (sai == 'P') return emMetros / 0.0254f;
    return 0;
}

float converterMassa(float valor, char ent, char sai) {
    // Base: Gramas
    float emGramas = 0;
    if (ent == 'G') emGramas = valor;
    else if (ent == 'K') emGramas = valor * 1000.0f;
    else if (ent == 't') emGramas = valor * 1000000.0f;
    else if (ent == 'O') emGramas = valor * 28.3495f;
    else if (ent == 'L') emGramas = valor * 453.592f;

    if (sai == 'G') return emGramas;
    if (sai == 'K') return emGramas / 1000.0f;
    if (sai == 't') return emGramas / 1000000.0f;
    if (sai == 'O') return emGramas / 28.3495f;
    if (sai == 'L') return emGramas / 453.592f;
    return 0;
}

float converterTemperatura(float valor, char ent, char sai) {
    float emCelsius = 0;
    if (ent == 'C') emCelsius = valor;
    else if (ent == 'K') emCelsius = valor - 273.15f;
    else if (ent == 'F') emCelsius = (valor - 32.0f) * 5.0f / 9.0f;

    if (sai == 'C') return emCelsius;
    if (sai == 'K') return emCelsius + 273.15f;
    if (sai == 'F') return (emCelsius * 9.0f / 5.0f) + 32.0f;
    return 0;
}

float converterArea(float valor, char ent, char sai) {
    // Base: Metros quadrados (m2)
    float emM2 = 0;
    if (ent == 'M') emM2 = valor;
    else if (ent == 'K') emM2 = valor * 1000000.0f;
    else if (ent == 'A') emM2 = valor * 4046.86f;
    else if (ent == 'H') emM2 = valor * 10000.0f;

    if (sai == 'M') return emM2;
    if (sai == 'K') return emM2 / 1000000.0f;
    if (sai == 'A') return emM2 / 4046.86f;
    if (sai == 'H') return emM2 / 10000.0f;
    return 0;
}

float converterVolume(float valor, char ent, char sai) {
    // Base: Litros
    float emLitros = 0;
    if (ent == 'M') emLitros = valor / 1000.0f; // Mililitros
    else if (ent == 'L') emLitros = valor;
    else if (ent == 'C') emLitros = valor / 1000.0f; // Centimetro cubico = ml
    else if (ent == 'G') emLitros = valor * 3.78541f; // Galão US

    if (sai == 'M') return emLitros * 1000.0f;
    if (sai == 'L') return emLitros;
    if (sai == 'C') return emLitros * 1000.0f;
    if (sai == 'G') return emLitros / 3.78541f;
    return 0;
}

int main() {
    char escolhaUnidade, unidadeEntrada, unidadeSaida, continuar;
    float valor, resultado;

    // Apresentação inicial
    printf("Programa de Conversão do Domingos Cunha\n");
    SLEEP_SEC(2);
    CLEAR_SCREEN();

    do {
        printf("Com que unidades vamos trabalhar?\n");
        printf("Comprimento (C) Massa (M) Temperatura (T) Area (A) Volume (V)\n");
        scanf(" %c", &escolhaUnidade);
        escolhaUnidade = toupper(escolhaUnidade);

        switch (escolhaUnidade) {
            case 'C':
                do {
                    printf("Unidade de entrada: Centimetro (C) Metro (M) Quilometro (K) Jarda (J) Polegada (P)?\n");
                    scanf(" %c", &unidadeEntrada);
                    unidadeEntrada = toupper(unidadeEntrada);
                    
                    printf("Quantas unidades?\n");
                    scanf("%f", &valor);

                    printf("Unidade de saida: Centimetro (C) Metro (M) Quilometro (K) Jarda (J) Polegada (P)?\n");
                    scanf(" %c", &unidadeSaida);
                    unidadeSaida = toupper(unidadeSaida);

                    if (unidadeEntrada == unidadeSaida) {
                        printf("As unidades sao iguais escolha outra unidade de saida\n");
                    }
                } while (unidadeEntrada == unidadeSaida);

                resultado = converterComprimento(valor, unidadeEntrada, unidadeSaida);
                printf("Resultado da conversao: %.4f\n", resultado);
                break;

            case 'M':
                do {
                    printf("Unidade de entrada: Grama (G) Quilograma (K) Tonelada (t) Onca (O) Libra (L)?\n");
                    scanf(" %c", &unidadeEntrada);
                    unidadeEntrada = toupper(unidadeEntrada);
                    
                    printf("Quantas unidades?\n");
                    scanf("%f", &valor);

                    printf("Unidade de saida: Grama (G) Quilograma (K) Tonelada (t) Onca (O) Libra (L)?\n");
                    scanf(" %c", &unidadeSaida);
                    unidadeSaida = toupper(unidadeSaida);

                    if (unidadeEntrada == unidadeSaida) {
                        printf("As unidades sao iguais escolha outra unidade de saida\n");
                    }
                } while (unidadeEntrada == unidadeSaida);

                resultado = converterMassa(valor, unidadeEntrada, unidadeSaida);
                printf("Resultado da conversao: %.4f\n", resultado);
                break;

            case 'T':
                do {
                    printf("Unidade de entrada: Celsius (C) Kelvin (K) Fahrenheit (F)?\n");
                    scanf(" %c", &unidadeEntrada);
                    unidadeEntrada = toupper(unidadeEntrada);
                    
                    printf("Quantas unidades?\n");
                    scanf("%f", &valor);

                    printf("Unidade de saida: Celsius (C) Kelvin (K) Fahrenheit (F)?\n");
                    scanf(" %c", &unidadeSaida);
                    unidadeSaida = toupper(unidadeSaida);

                    if (unidadeEntrada == unidadeSaida) {
                        printf("As unidades sao iguais escolha outra unidade de saida\n");
                    }
                } while (unidadeEntrada == unidadeSaida);

                resultado = converterTemperatura(valor, unidadeEntrada, unidadeSaida);
                printf("Resultado da conversao: %.4f\n", resultado);
                break;

            case 'A':
                do {
                    printf("Unidade de entrada: Metro2 (M) Quilometro2 (K) Acre (A) Hectare (H)?\n");
                    scanf(" %c", &unidadeEntrada);
                    unidadeEntrada = toupper(unidadeEntrada);
                    
                    printf("Quantas unidades?\n");
                    scanf("%f", &valor);

                    printf("Unidade de saida: Metro2 (M) Quilometro2 (K) Acre (A) Hectare (H)?\n");
                    scanf(" %c", &unidadeSaida);
                    unidadeSaida = toupper(unidadeSaida);

                    if (unidadeEntrada == unidadeSaida) {
                        printf("As unidades sao iguais escolha outra unidade de saida\n");
                    }
                } while (unidadeEntrada == unidadeSaida);

                resultado = converterArea(valor, unidadeEntrada, unidadeSaida);
                printf("Resultado da conversao: %.4f\n", resultado);
                break;

            case 'V':
                do {
                    printf("Unidade de entrada: Mililitro (M) Litro (L) Centimetro3 (C) Galao (G)?\n");
                    scanf(" %c", &unidadeEntrada);
                    unidadeEntrada = toupper(unidadeEntrada);
                    
                    printf("Quantas unidades?\n");
                    scanf("%f", &valor);

                    printf("Unidade de saida: Mililitro (M) Litro (L) Centimetro3 (C) Galao (G)?\n");
                    scanf(" %c", &unidadeSaida);
                    unidadeSaida = toupper(unidadeSaida);

                    if (unidadeEntrada == unidadeSaida) {
                        printf("As unidades sao iguais escolha outra unidade de saida\n");
                    }
                } while (unidadeEntrada == unidadeSaida);

                resultado = converterVolume(valor, unidadeEntrada, unidadeSaida);
                printf("Resultado da conversao: %.4f\n", resultado);
                break;

            default:
                printf("Opcao invalida.\n");
        }

        printf("Deseja converter mais unidades (S/N)?\n");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);

    } while (continuar == 'S');

    printf("Adeus\n");
    SLEEP_SEC(2);
    CLEAR_SCREEN();

    return 0;
}
