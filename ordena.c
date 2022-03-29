//Programa: metodos_ordenacao.c
//Programadores: Lucas Gonzalez de Queiroz e Weber Veloso Mourao
//Data:
//Diálogo:Este algoritmos verifica diversos
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
	int vbub[MAX],tamanho,i,n,j,p=0,k,l;
	int vins[MAX], vmerge[MAX], vselec[MAX], vquick[MAX];
    int compara;
    int comparaquick;
    int trocas;

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
        printf("MergeSort: ");
	    //for(k = 0; k < tamanho; k++)
		    //printf("%d ", vmerge[k]);
      //printf("\n");
      printf("%d comparacoes ", compar);
      printf("%d trocas\n", numtrocamerg);
      contamerge = 0;
      trocarecmerge = 0;

    int tamquick;
    tamquick = tamanho -1;
		//Ordene o vetor com a funcao QuickSort
        quicksort(p, tamquick, vquick, &comparaquick, &numtrocaquick);

        //Imprima Quick Sort
        printf("QuickSort: ");
	    for(l = 0; l < tamanho; l++)
		printf("%d ", vquick[l]);
        printf("\n");
        printf("%d comparacoes ", comparaquick);
        printf("%d trocas\n\n", numtrocaquick);
        contad = 0;
        trocarecquick=0;


	}//fim for
	return 0;//fim programa
}//fim main

//Programa: selection_sort.c
//Programador: Lucas Gonzalez de Queiroz
//Data: 26/03/2014
//Diálogo: Método de seleção para ordenação de vetores
void selection_sort(int vselec[MAX], int tamanho)
{
    //declaracao variaveis locais
	int temp,n,i,k,menor,comp = 0, trocas_selection=0;
	for(i = 0; i < tamanho-1; i++)
        {
            menor = i;
		for(n = i+1; n < tamanho; n++)
		{

			if(vselec[n] < vselec[menor])
            {
				menor = n;
				comp++;
        
            }
		}//fim for

		temp = vselec[menor];
		vselec[menor] = vselec[i];
		vselec[i] = temp;
    trocas_selection++;
	}//fim for
	//Imprima o resultado
	printf("SelectionSort: ");
	//for(k = 0; k < tamanho; k++)
    //    printf("%d ", vselec[k]);
      //  printf("\n");
        printf("%d comparacoes " , comp);
        printf("%d trocas\n", trocas_selection);

}//fim selection

//Programa: insertion_sort.c
//Programador: Lucas Gonzalez de Queiroz
//Data: 26/03/2014
//Diálogo: Método da inserção para ordenação de vetores
void insertion_sort(int vins[MAX], int tamanho)
{
	//variaveis locais
	int j,w,x,g,comp = 0, trocas_insertion=0;

	for(j = 1; j < tamanho; j++)
        {
		x = vins[j];

		for(w = j-1; w >= 0 && vins[w] > x; w--)
        {
            vins[w+1] = vins[w];
            comp++;

        }

		vins[w+1] = x;
    trocas_insertion++;
	}//fim for
	//impressao do resultado
	printf("InsertionSort: ");
//	for(g = 0; g < tamanho; g++)
	//	printf("%d ", vins[g]);
	//printf("\n");
	printf("%d comparacoes " , comp);
  printf("%d trocas\n", trocas_insertion);
  
}//fim insertion

//Programa: bubble_sort.c
//Programador: Lucas Gonzalez de Queiroz
//Data: 26/03/2014
//Diálogo: Método de seleção para ordenação de vetores
void bubble_sort(int vbub[MAX], int tamanho)
{
    //variaveis locais
	int temp,i,j,k,compbub = 0, trocas_bubble=0;
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
	//for(k = 0; k < tamanho; k++)
    //{
		//printf("%d ", vbub[k]);
    //}
	//printf("\n");
	printf("%d comparacoes ", compbub);
  printf("%d trocas\n", trocas_bubble);
}//fim funcao Bubble


//Programa: merge_sort.c
//Programador: Lucas Gonzalez de Queiroz
//Data:
//variáveis globais


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


//Programa: intercala.c
//Programador: Lucas Gonzalez de Queiroz
//Data:
//Diálogo: Método de seleção para ordenação de vetores
void intercala(int p, int q , int tam , int vmerge[MAX], int *comp, int *trocamerg)
{
    //variaveis locais:
    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;
    int t=0;
    int z = 0;
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
   trocainter++;
   
  }//fim while
 while (j < tam)
 {
     w[k] = vmerge[j];
       j++;
       k++;
      
 }//fim while2



for (i = p; i < tam; i++){
vmerge[i] = w[i-p];

}
*trocamerg = trocainter;

}//Fim da funcao intercala



//Programa: quick_Sort.c
//Programador: Lucas Gonzalez de Queiroz
//Data:
//Diálogo: Método de seleção para ordenação de vetores

void quicksort(int p, int r, int vquick[MAX], int *comparaquick, int *numtrocaquick)
{
   //Declaracao das variaveis locais
    int j;
    int comparador;
    int trocaquick;
    //int comparaquick;
  // while (p < r) {
    //  j = separa( p, r, vquick, &comparador, &trocaquick);
      
      
      // printf("%d ", trocaquick);
      //if (j - p < r - j) {
        // quicksort( p, j-1 , vquick, comparaquick, numtrocaquick);
         //p = j + 1;
      //}//fim if
       //else {
         //quicksort( j+1, r, vquick, comparaquick, numtrocaquick);
        // r = j - 1;
      //}//fim else
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

   }//fim while
   

//Fim da Funcao Quick_Sort

//Programa: separa.c
//Programador: Lucas Gonzalez de Queiroz
//Data:
//Diálogo: Método de seleção para ordenação de vetores
int separa(int p, int r, int vquick[MAX], int *comparador, int *trocaquick)
{
    //variaveis locais
    int c = vquick[p], i = p - 1, j = r + 1, t;
    int compara = 0;
    int trocador = 0;
   while (1) {
      do { j--; compara++;} while (vquick[j] > c);
      do { i++; compara++;} while (vquick[i] < c);

      if(i < j) {
      t = vquick[i]; vquick[i] = vquick[j]; vquick[j] = t;
      trocador++;
      }
else {
  *comparador  = compara - 2;
   *trocaquick = trocador;
  return j;
}
} 
}

    //fim while
   // agora i == j+1vquick[p] = vquick[j], vquick[j] = c;
  
   
   
   
   //return j;

//Fim Funcao separa






