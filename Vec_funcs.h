/*Funções*/

/*Função de Obtenção do vetor*/
void getVet(float vetor[], int x){
	int i, a=104;
	for(i=0;i<x;i++){
		printf("- cord. %c: ", ++a);
		scanf("%f", &vetor[i]);
	}
}

/*Função de obtenção da ordem do Vetor*/
int getn(){
	int n=0;
	while(n!=2 && n!=3){
		fflush(stdin);
		printf("= Ordem do Vetor [2/3]: ");
		scanf("%d", &n);
		if( n!=2 && n!=3) printf("\nValor Invalido!\n\n");
	}
	return n;
}

/*Retorna a norma do vetor*/
float normaVet(float vetor[], int n){
	int i;
	float norma, ACM=0;
	
	for(i=0;i<n;i++) ACM += pow(vetor[i],2); 
	norma = sqrt(ACM);
	return norma;
}

/*Retorna o Vetor versor de um outro vetor, dar o vetor unitario como argumento*/
void vetVer(float vetor_versor[], float vetor[], int n){
	int i;
	float norma;
	norma = normaVet(vetor, n);
	
	for(i=0;i<n;i++) vetor_versor[i] =  vetor[i] / norma; 
}

/*Produto Escalar*/
float prodEsca(float vetor[], float vetor2[], int n){
	int i;
	float produto=0;
	
	for(i=0;i<n;i++) produto += vetor[i] * vetor2[i];
	return produto;
}

/*Retorna o arco-cosseno do angulo. Utilizar a função 'acos' para obter
o valor em radiano e multiplicar por '(180 / M_PI)' para o valor em graus.*/
double angVets(float vetor[], float vetor2[], int n){
	double a;
	
	a = prodEsca(vetor, vetor2, n) / ( normaVet(vetor,n) * normaVet(vetor2, n) );
	/*printf("\na = %lf", a);*/
	return acos(a);
}

/*Projeção de um vetor A em outro vetor B*/
void projEsca(float vetor[], float vetor2[], float vetor3[], int n){
	float x;
	int i;
	
	x = prodEsca(vetor, vetor2, n) / pow(normaVet(vetor2,n),2);
	for(i=0;i<n;i++) vetor3[i] = x * vetor2[i];
}

/*Cálculo dos angulos que o vetor forma entre os eixos*/
void angEixos(float vetor[], double vetor_eixos[], int n){
	int i;
	double x;
	
	for(i=0;i<n;i++){
		x = vetor[i] / normaVet(vetor,n);
		x = acos(x);
		vetor_eixos[i] = x;
	}
}

/*Soma de vetores*/
void somaVets(int n, int a, float *vetores_soma, float *vetor_resultado){
	int i, j;
		
	for(j=0;j<n;j++){
		for(i=0;i<a;i++){
			//*(vetor_resultado+j) += *((vetores_soma + i) + j ); ta errado, pq eu tentei isso?
			//*(vetor_resultado+j) += vetores_soma[i][j]; Não funciona
			*(vetor_resultado+j) += *(vetores_soma + ( i * n ) + j);
		}
	}
}

/*Conversão vetor cartesiano => vetor polar*/
void getCoordPolar(float vetor[], float *vet_polar, int n){
	float r, xy, xz, x;
	
	r = normaVet(vetor, n);
	/*xz = phi*/
	x = vetor[2]/r;
	xz = acos(x);
	
	/*xy = teta*/
	x = vetor[1] / (r*sin(xz));
	xy = asin(x);
	
	vet_polar[0] = r;
	vet_polar[1] = xy;
	vet_polar[2] = xz;
}

/*Conversão coordenadas esféricas => coordenadas cartesianas*/
void getCoordCart(float *vet, int n){
	int i, a=104;
	float *vetor_polar;
	char *list[3] = {"r", "xy", "xz"};
	
	puts("\nr = norma do vetor.\nxy = angulo entre vetor e eixo x[teta]\nxz = angulo entre vetor e eixo z[Fi]\n[Entre os angulos em graus]\n");
	for(i=0;i<n;i++){
		printf("- %s: ", list[i]);
		scanf("%f", vetor_polar+i);
	}
	
	if(n==3){
		*(vetor_polar + 1) = (M_PI * vetor_polar[1])/180;
		*(vetor_polar + 2) = (M_PI * vetor_polar[2])/180;
		
		*(vet+0) = vetor_polar[0] * sin(vetor_polar[2]) * cos(vetor_polar[1]);
		*(vet+1) = vetor_polar[0] * sin(vetor_polar[2]) * sin(vetor_polar[1]);
		*(vet+2) = vetor_polar[0] * cos(vetor_polar[2]);	
	}
	else if(n==2){
		*(vetor_polar + 1) = (M_PI * vetor_polar[1])/180;
		*(vet+0) = vetor_polar[0] * cos(vetor_polar[1]);
		*(vet+1) = vetor_polar[0] * sin(vetor_polar[1]);
	}
}

/*Eu devia ter criado isso daqui antes de ter feito as outras funções - */
float rads2Degree(float rad){
	return rad * (180 / M_PI);
}

float degree2Rads(float deg){
	return (deg *  M_PI)/180;
}

void prodVetOrd3(float vet[], float vet2[], float *vetRes, int ord){
	if(ord==2){
		vet[2]=0;
		vet2[2]=0;
	}
	int x=104;
	
	*vetRes = ( (*(vet + 1)) * (*(vet2 + 2)) ) - ( (*(vet + 2)) * (*(vet2 + 1)) );
	*(vetRes + 1) = (-1) * ( ( (*vet) * (*(vet2 + 2)) ) - ( (*(vet + 2)) * (*vet2) ) );
	*(vetRes + 2) = ( (*vet) * (*(vet2 + 1)) ) - ( (*(vet + 1)) * (*vet2) );
}


