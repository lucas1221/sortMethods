//Programa: metodos_ordenacao.c
//Programadores: Lucas Gonzalez de Queiroz
//Diálogo:Este algoritmos verifica um vetor com números aleatorios, imprime ordenadamente em cada método respectivo de ordenacao, assim como também imprime
// o numero de comparacoes e trocas do respectivo método de ordenacao.
//Métodos de seleção para ordenação de vetores

//Bibliotecas
#include <stdio.h>
//declaracao das constantes
#define MAX 10000
//variáveis globais
int contamerge = 0;
int contad = 0;
int compar;
int numtrocamerg;
int numtrocaquick;
int trocarecmerge;
int trocarecquick;
//Prototipos das Funcoes Utilizadas no programa
void selection_sort(int vselec[MAX], int tamanho);//Funcao selection sort
void bubble_sort(int vbub[MAX], int tamanho);//Funcao bubble sort
void insertion_sort(int veins[MAX], int tamanho);//Funcao insertion sort
void merge_sort(int p , int tam , int vmerg[MAX], int *compar, int *numtrocamerg);//Funcao Merge Sort
void intercala(int p, int q , int tam , int vmerge[MAX],int *comp, int *trocamerg);//Funcao auxiliar da Merge Sort
void quicksort(int p, int tam, int vquick[MAX], int *comparaquick, int *numtrocaquick);//Funcao Quick Sort
int separa(int p, int r, int vquick[MAX],int *comparador, int *trocaquick);//Funcao auxiliar do QuickSort


//Inicio da Funcao Principal
int main()
{
    //declaracao variaveis locais
	int vbub[MAX],tamanho,i,n,j,p=0;
	int vins[MAX], vmerge[MAX], vselec[MAX], vquick[MAX];
    
    int comparaquick;
    

	//num casos teste
	scanf("%d", &n);
	for(i = 0; i < n; i++)
        {
        //tamanho do vetor
		scanf("%d", &tamanho);
		//leitura do vetor
		for(j = 0; j < tamanho; j++)
			{
                scanf("%d", &vbub[j]);
                vselec[j] = vbub[j];
                vins[j] = vbub[j];
                vmerge[j] = vbub[j];
                vquick[j] = vbub[j];

			}
		//Ordene o vetor com a funcao SelectionSort
		selection_sort(vselec, tamanho);

		//Ordene o vetor com a funcao InsertionSort
		insertion_sort(vins, tamanho);

		//Ordene o vetor com a funcao BubbleSort
		bubble_sort(vbub, tamanho);

		//Ordene o vetor com a funcao MergeSort
		merge_sort(p , tamanho , vmerge, &compar, &numtrocamerg);
	//impressao resultado apos Merge
	int k;
        printf("MergeSort: \n");
	printf("Vetor ordenado: ");
	    for(k = 0; k < tamanho; k++)
		    printf("%d ", vmerge[k]);
      printf("\n");
      printf("%d comparacoes e ", compar);
      printf("%d trocas\n\n", numtrocamerg);
      contamerge = 0;
      trocarecmerge = 0;
      

	int tamquick;
	tamquick = tamanho -1;
	//Ordene o vetor com a funcao QuickSort
        quicksort(p, tamquick, vquick, &comparaquick, &numtrocaquick);

        //Imprima Quick Sort
	int l;
        printf("QuickSort: \n");
	printf("Vetor ordenado: ");
	    for(l = 0; l < tamanho; l++)
		printf("%d ", vquick[l]);
        printf("\n");
        printf("%d comparacoes e ", comparaquick);
        printf("%d trocas\n\n", numtrocaquick);
        contad = 0;
        trocarecquick=0;
	printf("-----------------------------------------------------------------------");
	printf("\n");


	}//fim for
	return 0;//fim programa
}//fim maincomp++;

//Funcao: selection_sort

//Diálogo: Método de seleção para ordenação de vetores
void selection_sort(int vselec[MAX], int tamanho)
{
    //declaracao variaveis locais
	int temp,n,i,menor,comp = 0, trocas_selection=0, verifica = 0;
	for(i = 0; i < tamanho-1; i++)
        {
            menor = i;
            verifica = 0;
		for(n = i+1; n < tamanho; n++)
		{
			comp++;
			if(vselec[n] < vselec[menor])
			{
				menor = n;
				verifica = 1;


			}
		}//fim for
        if(verifica == 1) {
		temp = vselec[menor];
		vselec[menor] = vselec[i];
		vselec[i] = temp;
        trocas_selection++;
        }
	}//fim for
	//Imprima o resultado
	int k;
	printf("SelectionSort:\n ");
	printf("Vetor ordenado: ");
	for(k = 0; k < tamanho; k++)
        printf("%d ", vselec[k]);
        printf("\n");
        printf("%d comparacoes e " , comp);
        printf("%d trocas\n\n", trocas_selection);

}//fim selection

//Funcao: insertion_sort.c

//Diálogo: Método da inserção para ordenação de vetores
void insertion_sort(int vins[MAX], int tamanho)
{
	//variaveis locais
	int j,w,x,comp = 0, trocas_insertion=0;

	for(j = 1; j < tamanho; j++)
        {
		x = vins[j];

		for(w = j-1; w >= 0 && vins[w] > x; comp++, w--)
		{
		      vins[w+1] = vins[w];



		}

        if(w+1 != j){
		vins[w+1] = x;
		trocas_insertion++;
        }
        else
		comp++;
	}//fim for
	//impressao do resultado
	int g;
	printf("InsertionSort: \n");
	printf("Vetor ordenado: ");
	for(g = 0; g < tamanho; g++)
		printf("%d ", vins[g]);
	printf("\n");
	printf("%d comparacoes e " , comp);
        printf("%d trocas\n\n", trocas_insertion);

}//fim insertion

//Funcao: bubble_sort.c

//Diálogo: Método de seleção para ordenação de vetores
void bubble_sort(int vbub[MAX], int tamanho)
{
    //variaveis locais
	int temp,i,j,compbub = 0, trocas_bubble=0;
	int trocou=1;

	for(i = tamanho-1; i > 0 && trocou == 1; i--)
        {
		trocou = 0;
		for(j = 0; j < i; j++)
		{
			compbub++;
			if(vbub[j] > vbub[j+1])
			{
				temp      = vbub[j];
				vbub[j]   = vbub[j+1];
				vbub[j+1] = temp;
				trocas_bubble++;
				trocou = 1;
			}//fim if

		}//fim for
	}//fim for
	//impressao resultado
	printf("BubbleSort: ");
	
	printf("Vetor ordenado: ");
	int k;
	for(k = 0; k < tamanho; k++)
	{
	printf("%d ", vbub[k]);
	}
	printf("\n");
	printf("%d comparacoes e ", compbub);
	printf("%d trocas\n\n", trocas_bubble);
}//fim funcao Bubble


//Funcao: merge_sort.c

//Diálogo: Método de seleção para ordenação de vetores
void merge_sort(int p, int tam, int vmerge[MAX], int *compar, int *numtrocamerg)
{
 //variaveis locais
 int q;
int comp;
int trocamerg;
//int numtrocamerg;
 //int *comp;

 //Se 0 < tamanho do vetor - 1
   if (p < tam - 1)
   {
	//q = meio
	q = (p + tam) / 2;
	merge_sort(p , q , vmerge, compar, numtrocamerg);
	merge_sort(q, tam, vmerge, compar, numtrocamerg);
	intercala(p, q, tam , vmerge, &comp, &trocamerg);
	contamerge = contamerge + comp;
	trocarecmerge = trocarecmerge + trocamerg;
   }//fim if
   
   *compar = contamerge;
   *numtrocamerg = trocarecmerge;

}//fim da funcao MergeSort


//Funcao: intercala.c

//Diálogo: Método de seleção para ordenação de vetores
void intercala(int p, int q , int tam , int vmerge[MAX], int *comp, int *trocamerg)
{
    //variaveis locais:
    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;
    int t=0;
    int trocainter = 0;
	while (i < q && j < tam)
	{
    
		if (vmerge[i] < vmerge[j])
		{
			w[k] = vmerge[i];
			i++;

		}//fim if

		else
		{
			 w[k] = vmerge[j];
			 j++;
			 trocainter++;

		}//fim else

		k++;
		t++;

	}//fim while1

	*comp = t;

	while (i < q)
	{
		w[k] = vmerge[i];
		i++;
		k++;
  

	}//fim while
	while (j < tam)
	{
		w[k] = vmerge[j];
		j++;
		k++;
  
	}//fim while2



	for (i = p; i < tam; i++)
	{
		vmerge[i] = w[i-p];

	}
	
	*trocamerg = trocainter;

}//Fim da funcao intercala



//Funcao: quick_Sort.c

//Diálogo: Método de seleção para ordenação de vetores

void quicksort(int p, int r, int vquick[MAX], int *comparaquick, int *numtrocaquick)
{
	//Declaracao das variaveis locais
	int j;
	int comparador;
	int trocaquick;
    
	if (p < r)
	{
		j = separa (p, r, vquick, &comparador ,&trocaquick);
		contad = contad + comparador;
		trocarecquick = trocarecquick + trocaquick;
		quicksort(p, j, vquick,comparaquick ,numtrocaquick);
		quicksort(j+1,r,vquick,comparaquick ,numtrocaquick);
	}


	*comparaquick = contad;
	*numtrocaquick = trocarecquick;

}//fim quicksort


//Funcao: separa.c

//Diálogo: Método de seleção para ordenação de vetores
int separa(int p, int r, int vquick[MAX], int *comparador, int *trocaquick)
{
	//variaveis locais
	int c = vquick[p], i = p - 1, j = r + 1, t;
	int compara = 0;
	int trocador = 0;
	
	while (1) 
	{
		do { j--; compara++;} while (vquick[j] > c);
		do { i++; compara++;} while (vquick[i] < c);

		if(i < j) {
			t = vquick[i]; vquick[i] = vquick[j]; vquick[j] = t;
			trocador++;
	}
		else
		{
		*comparador  = compara - 2;
		*trocaquick = trocador;
  return j;
		}
	}
}//fim separa
