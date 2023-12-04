/*Algoritmo de Cálculos Vetoriais
- Autor: Gabriel Almeida - ECAT_IFAM - CMDI - mar 2022*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "vec_funcs.h"
#include <conio.h>


void main(void){
	
	char ch[3], str[3], ch12[3]="12", ch0[3]="0";
	int i, n=3, key=1, cin;
	
	for(;;){
		puts("-------------------------------------------------\n");
		puts("-= Algoritmo de Calculos de vetores =-\n");
		puts("Este algoritmo realiza calculos com um ou mais");
		puts("vetores assumindo que os mesmos iniciam na origem.");
		puts("Caso o vetor nao inicie na origem, escreva-o como");
		puts("se o fizesse. Ate o momento o programa funciona para");	
		puts("vetores de 2 ou 3 dimensoes(Retas x, y e z) representadas");
		puts("respectivamente pelas bases i, j e k.\n");	
		puts("-------------------------------------------------\n");
		
		do{
			puts("|| MENU SELECAO - Digite a operacao deseja ||\n");
			puts("[1] - Norma do Vetor");
			puts("[2] - Vetor Versor");
			puts("[3] - Produto Escalar");
			puts("[4] - Produto Vetorial");
			puts("[5] - Projecao de Vetor");
			puts("[6] - Angulos entre vetores");
			puts("[7] - Angulos entre os Eixos");
			puts("[8] - Soma de Vetores");
			puts("[9] - Coord. Cartesianas => Polares");
			puts("[10] - Coord. Polares => Cartesianas");
			puts("[11] - Sair");
			printf("\n= Selecao: ");
			fflush(stdin);
			gets(ch);
			int key2=1;
			
			//printf("\n1.ch %s\n", ch);
			//printf("\n%d\n", strlen(ch));
			
			for(i=0;i<strlen(ch);i++){
				if(!isdigit(ch[i])){
					key2=0;
					break;
				}
			}
			//printf("\n%d\n", key2);
			//printf("\n2.ch %s\n", ch);
			//printf("\n%d\n", key2);
			cin = atoi(ch);
						
			if( key2 && cin > atoi(ch0) && cin < atoi(ch12) ){
				key = 0;
			} else{
				printf("\n\n- Valor Invalido! - Selecione um numero de 1 a 11.\n\n");
			}
		}while(key);
		
		float vet[n];
		float vet2[n];
		int x = 104;
	
		/*printf("\n%d\n", cin);*/
		switch(cin){
			case 1: /*-=| Calculo Norma |=-*/
				printf("\n=| Calculo Norma |=\n\n");
				
				n = getn();
				getVet(vet, n);
				
				printf("\n# Norma do Vetor: %.2f\n\n", normaVet(vet, n));
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			break;

			case 2: /*=| Vetor Versor |=*/
				{
					printf("\n=| Vetor Versor |=\n\n");
					float vet_ver[n];
					
					n = getn();
					getVet(vet, n);
					
					vetVer(vet_ver, vet, n);
					printf("# Vetor Versor = [%.2f]%c", vet_ver[0], ++x);
					for(i=1;i<n;i++) printf(" + [%.2f]%c ", vet_ver[i], ++x);
					//printf("# Angulos: x = %.2f ; y = %.2f ; z = %.2f");
					printf("\n\n");
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 3: /*=| Produto Escalar |=*/
				printf("\n=| Produto Escalar |=\n\n");

				n = getn();
				printf("\n= Vetor 1:\n");
				getVet(vet, n);
				printf("\n= Vetor 2:\n");
				getVet(vet2, n);
				
				printf("\n# Produto Escalar = %.2f\n\n", prodEsca(vet, vet2, n));
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			break;
			
			case 4: /*=| Produto Vetorial |=*/
				{
					printf("\n=| Produto Vetorial |=\n\n");
					float vetp1[n], vetp2[n], *vetpr;
					
					n = getn();
					
					//vetp1 = calloc(3, sizeof(float));
					//vetp2 = calloc(3, sizeof(float));
					vetpr = calloc(3, sizeof(float));
					
					printf("\n= Vetor 1:\n");
					getVet(vetp1, n);
					printf("\n= Vetor 2:\n");
					getVet(vetp2, n);
					
					prodVetOrd3(vetp1, vetp2, vetpr, n);
					
					printf("\n# Produto Vetorial = [%.2f]%c + [%.2f]%c + [%.2f]%c \n\n", *vetpr, x+1, *(vetpr+1), x+2, *(vetpr+2), x+3);
					
					//free(vetp1);
					//free(vetp2);
					free(vetpr);
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 5: /*=| Projecao de Vetor |=*/
				{
					printf("\n=| Projecao de Vetor |=\n");
					float vet3[n];
					
					n = getn();
					printf("\n= Vetor 1:\n");
					getVet(vet, n);
					printf("\n= Vetor 2:\n");
					getVet(vet2, n);
					
					projEsca(vet, vet2, vet3, n);
					printf("\n# Projecao de Vetor 1 em Vetor 2 = [%.2f]%c", vet3[0], ++x);
					for(i=1;i<n;i++) printf(" + [%.2f]%c ", vet3[i], ++x);
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 6: /*=| Angulo Entre Vetores |=*/
				{
					printf("\n=| Angulo Entre Vetores |=\n");
					double a;
					
					n = getn();
					printf("\n= Vetor 1:\n");
					getVet(vet, n);
					printf("\n= Vetor 2:\n");
					getVet(vet2, n);
					
					a = angVets(vet, vet2, n);
					printf("\n# Angulos entre os vetores =  %.4lf rads / %.2lf graus \n\n", a, ( a * (180 / M_PI) ) );	
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 7: /*-=| Angulo entre Eixos |=-*/
				{
					printf("\n=| Angulo entre Eixos |=\n\n");
					double vet_eixos[n];
					int a = 120;			
					
					n = getn();
					getVet(vet, n);
					
					angEixos(vet, vet_eixos, n);					
					printf("\n# Angulo entre os eixos: \n");
					for(i=0;i<n;i++) printf("%c -  %.4lf rads / %.2lf graus \n", a++, vet_eixos[i], ( vet_eixos[i] * (180 / M_PI) ) );
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 8: /*-=| Soma de Vetores |=-*/
				{
					printf("\n=| Soma de Vetores |=\n\n");
					int a=0, j;
					float *vet_soma, *vet_result;
					
					while( n!=2 && n!=3){
						printf("= Ordem dos Vetores [2/3]: ");
						scanf("%d", &n);
						if( n!=2 && n!=3) printf("\nValor Invalido!\n\n");
					}
					
					do{
						printf("\n= Quantidade de Vetores para somar: ");
						scanf("%d",&a);
						if(a<=0) printf("Valor Invalido!");
					}while(a<=0);
					
					vet_soma = calloc(n*a,sizeof(float));
					vet_result = calloc(n,sizeof(float));
					
					for(i=0;i<a;i++){
						int y=104;
						printf("\n= Vetor %d:\n", i+1);
						for(j=0;j<n;j++){
							printf("- cord. %c: ", ++y);
							scanf("%f", (vet_soma + (i*n) + j ));
						}
					}
					
					somaVets(n, a, vet_soma, vet_result);
					printf("\n# Soma = [%.2f]%c", *vet_result, ++x);
					for(i=1;i<n;i++) printf(" + [%.2f]%c ", *(vet_result+i), ++x);
					
					free(vet_soma);
					free(vet_result);
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

			case 9: /*-=| Coord. Cartesianas => Polares |=-*/
				{
					printf("\n=| Coord. Cartesianas => Polares |=\n\n");
					float *vet_polar;
					int a = 0;			
					
					n = getn();
					getVet(vet, n);
					
					vet_polar = calloc(n, sizeof(float));
					
					getCoordPolar(vet, vet_polar, n);
					printf("\n# Coordenadas Polares:\n - r = %.2f\n", vet_polar[0]);
					printf(" - ang. com x = %.4lf rads / %.4lf graus \n", vet_polar[1], ( vet_polar[1] * (180 / M_PI)));
					if(n==3) printf(" - ang. com z = %.4lf rads / %.2lf graus \n", vet_polar[2], ( vet_polar[2] * (180 / M_PI)));
					
					free(vet_polar);
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;
			
			case 10: /*-=| Coord. Polares => Cartesianas |=-*/
				{
					printf("\n=| Coord. Polares => Cartesianas |=\n\n");
					float *vet;
			
					n = getn();
					vet = calloc(n, sizeof(float));
					getCoordCart(vet, n);
					
					printf("\n# Coord. Cartesianas = [%.2f]%c", *vet, ++x);
					for(i=1;i<n;i++) printf(" + [%.2f]%c ", *(vet + i), ++x);
					
					free(vet);
					
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;			

			case 11: /*-=| EXIT |=-*/
				printf("Saindo.");
				exit(1);
			break;
		}
		system("cls");
	}
	
}



