/**
 * @file MTHM.c
 * @author David Matuszak
 * @date 15 Sep 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/**
 * @fn int max(int a, int b).
 * @brief A function that returns the maximum of \a a and \a b.
 *
 * @param a the first argument.
 * @param b the second argument.
 */
int max(int a, int b) { return (a > b)? a : b; }

/**
 * @fn int min(int a, int b).
 * @brief A function that returns the minimum of \a a and \a b.
 *
 * @param a the first argument.
 * @param b the second argument.
 */
int min(int a, int b) { return (a < b)? a : b; }
/**
 * @fn void swap(int *a, int *b).
 * @brief A function that swaps the pointers to two integers.
 *
 * @param *a the first pointer.
 * @param *b the second pointer.
 */
void swap(long long int *a, long long int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @fn void printArray(int arr[], int size).
 * @brief A function that prints an array. Function was used in the debugging stage.
 *
 * @param arr[] is the array that will be printed.
 * @param size is the arrays size.
 */
void printArray(int arr[], int size){
	int i = 0;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}
/**
 * @fn quicksort(int arr[], int l, int r)
 * @brief function sorts an array using the quicksort alorithm (http://www.algorytm.org/algorytmy-sortowania/sortowanie-szybkie-quicksort/quick-1-c.html).
 */
void quicksort(long long int arr[], int l, int r){
    if (l >= r)
    {
        return;
    }
    
    long long int pivot = arr[r];


    int cnt = l;


    int i = 0;
    for (i = l; i <= r; i++)
    {

        if (arr[i] <= pivot)
        {
            swap(&arr[cnt], &arr[i]);

            cnt++;
        }
    }
    
    quicksort(arr, l, cnt-2); 
    quicksort(arr, cnt, r);  
}
/**
 * @fn profitCounter(int Profit, int C, int CapasityFirst, int ClassOfKnapsack, int SpeedOfKnapsack)
 * @brief Function returns the profit relative to the current position of a file in a knapsack.
 *
 * @param Priofit is the initial profit of a file given to it at the beginning.
 * @param C is the current capacity of a knapsack.
 * @param CapacityFirst is the initial capacity of a knapsack.
 * @param ClassOfKnapsack is a value given to every knapsack at the beginning.
 * @param SpeedOfKnapsack is a value given at the beginning.
 */
int profitCounter(long long int Profit, long long int C, long long int CapacityFirst, int ClassOfKnapsack, int SpeedOfKnapsack){
	return (Profit * (C/CapacityFirst)+ClassOfKnapsack+SpeedOfKnapsack);
}
/**
 * @fn divideWeight(int n, int Profit[], int Weight[], int Y[], int Capasity[], int m, int CapasityFirst[])
 * @brief function devides the weights of programs so that they will fit into every knapsack.
 *
 * @param Priofit is the initial profit of a file given to it at the beginning.
 * @param Weight is the initial weight of a file given to it at the beginning.
 * @param Y is the current positioning of all files in all knapsacks.
 * @param Capacity is the current capacity of a knapsack.
 * @param m is the amount of available knapsacks.
 * @param CapacityFirst is the initial capacity of a knapsack.
 */
int divideWeight(int n, long long int Profit[], long long int Weight[], int Y[], long long int Capacity[], int m, long long int CapacityFirst[]){
	int k = 0, licznikTmp = 1;
	quicksort(Capacity, 1, m);
	for(k=1;k<=n;k++){
		if(Weight[k]>Capacity[licznikTmp]){
			Weight[k] = Weight[k] - Capacity[licznikTmp];
			Capacity[licznikTmp] = 0;
			quicksort(Capacity, 1, m);
			licznikTmp++;
			
		}
	}		
	return 0;
}
/**
 * @fn argMax(int x, int a, int y, int b)
 * @brief function returns the argument of the function that has a higher autput.
 *
 * @param x is the argument of the first function.
 * @param a is the output of the first function.
 * @param y is she argument of the second function.
 * @param b is the output of the second function 
 */
int argMax(int x, int a, int y, int b){
	if(a>=b)return x;
	else return y;
}
/**
 * @fn argMax(int x, int a, int y, int b)
 * @brief function returns the argument of the function that has a lower autput.
 *
 * @param x is the argument of the first function.
 * @param a is the output of the first function.
 * @param y is she argument of the second function.
 * @param b is the output of the second function 
 */
int argMin(int x, int a, int y, int b){
	if(a<=b)return x;

else return y;
}
/**
 * @fn minPrzedzialZero(int n, int Weight[], int Y[])
 * @brief function returns the Weight of a unallocated file .
 *
 * @param n amount of files.
 * @param Weight is the initial weight of every file given to it at the beginning.
 * @param Y is the current positioning of all files in all knapsacks.
 */   
int minPrzedzialZero(int n, long long int Weight[], int Y[]){
	int i = 1;
	int temp = 0;
	int flaga = 0;
	
	for(i = 1; i<=n;i++){
		if(Y[i] == 0){
			if(flaga = 0){
				temp = Weight[i];
				flaga = 1;
			}
			else{
				if(Weight[i] < temp) temp = Weight[i];
				
			}
			
		}
	}
return temp;	
}
/**
 * @fn minPrzedzialZeroIterator(int n, int Weight[], int Y[])
 * @brief function returns the position of a unallocated file.
 *
 * @param n amount of files.
 * @param Weight is the initial weight of every file given to it at the beginning.
 * @param Y is the current positioning of all files in all knapsacks.
 */
int minPrzedzialZeroIterator(int n, long long int Weight[], int Y[]){
	int i = 1;
	int temp = 0;
	int iterator = 0;
	int flaga = 0;
	
	for(i = 1; i<=n;i++){
		
		if(Y[i] == 0){	
			if(flaga == 0){
				temp = Weight[i];
				flaga = 1;
			}
			else{
				if(Weight[i] < temp){
					temp = Weight[i];
					iterator = i;
				} 
				
			}
			
		}
	}
return iterator;	
}
/**
 * @fn Greedys(int n, int Profit[], int Weight[], int Y[], int Capasity[], int m, int CapasityFirst[], int z, int ClassOfKnapsack[], int SpeedOfKnapsack[])
 * @brief function return the positions of files in knapsacks
 *
 * function allows eack knapsack (from largest to smallest) to choose their files according to the profit they will recive.
 * 
 * @param Priofit is the initial profit of a file given to it at the beginning.
 * @param Weight is the initial weight of a file given to it at the beginning.
 * @param Y is the current positioning of all files in all knapsacks.
 * @param Capacity is the current capacity of a knapsack.
 * @param z is the profit sum of all the files.
 * @param m is the amount of available knapsacks.
 * @param CapacityFirst is the initial capacity of a knapsack.
 * @param ClassOfKnapsack is a value given to every knapsack at the beginning.
 * @param SpeedOfKnapsack is a value given at the beginning.
 */
int * Greedys(int n, long long int Profit[], long long int Weight[], int Y[], long long int Capacity[], int m, long long int CapacityFirst[], int z, int ClassOfKnapsack[], int SpeedOfKnapsack[]){ 
	int j = 1;
	int i = 1;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(Y[j] == 0 && Weight[j] <= Capacity[i]){	
				Y[j] = i;
				Capacity[i] = Capacity[i] - Weight[j];
				z = z+ profitCounter(Profit[j], Capacity[i], CapacityFirst[i], ClassOfKnapsack[i], SpeedOfKnapsack[i]);
						
			}
		}			
	}
	return Y;	
}
/**
 *@fn MTHM(int n, int Profit[], int Weight[], int Y[], int Capasity[], int m, int CapasityFirst[], int z, int ClassOfKnapsack[], int SpeedOfKnapsack[])
 * @brief function returns the improved positioning of files in knapsacks.
 *
 * Function improves on the positioning of files in 3 steps. Firstly it rearranges the files in knapsacks. the next step compares two files in between two knapsacks and checks if there will be a improvement in the over all profit if they would change places.
 * The last step looks for unpacked files and checks if there would be a overall larger profit if these files would replace ones already packed. (This step is optional only if some files remain unpacked) 
 *
 * @param Priofit is the initial profit of a file given to it at the beginning.
 * @param Weight is the initial weight of a file given to it at the beginning.
 * @param Y is the current positioning of all files in all knapsacks.
 * @param Capacity is the current capacity of a knapsack.
 * @param z is the profit sum of all the files.
 * @param m is the amount of available knapsacks.
 * @param CapacityFirst is the initial capacity of a knapsack.
 * @param ClassOfKnapsack is a value given to every knapsack at the beginning.
 * @param SpeedOfKnapsack is a value given at the beginning.
 */
int * MTHM(int n, long long int Profit[], long long int Weight[], int Y[], long long int Capacity[], int m, long long int CapacityFirst[], int z, int ClassOfKnapsack[], int SpeedOfKnapsack[]){
	int j = 1;
	int i = 1;
	

	int l = 0;
	for(i=1; i<=m;i++){
		Capacity[i] = CapacityFirst[i];
	}
	
	
	i = 1;
	int temporaryIterator =  1;
	
	for(j=n;j>=1;j--){
		if(Y[j] > 0){
			temporaryIterator = 1;
			while(temporaryIterator <= m ){
								
				if(Weight[j] <= Capacity[i]){
					l = i;
					break;
				}
				i++;
				if(i>=m){
					i = i - m + 1;
				} 
				temporaryIterator++;
			}
			
			
			if(l==0){

				Y[j] = 0;
			}
			else{
				Y[j] = l;
				Capacity[l] = Capacity[l] - Weight[j];
				z = z + profitCounter(Profit[j], Capacity[l], CapacityFirst[l], ClassOfKnapsack[l], SpeedOfKnapsack[l]);
				if(l < m){
					i = l+1;
				}
				else{
					i = 1;
				}
			}
		}
	}
	int * temp = Y;
	
	int *x = Greedys(n, Profit, Weight, temp, Capacity,m,CapacityFirst,z,ClassOfKnapsack,SpeedOfKnapsack);	
	

	int k =0;
	int high = 0;
	int low = 0;
	int d = 0;
	int t = 0;

	int u = minPrzedzialZeroIterator(n, Weight, Y);

	
	for(j=1;j<=n;j++){
		for(k = j+1; k<=n;k++){
			if(Y[k] != Y[j]){
				high = argMax(j, Weight[j], k,  Weight[k]);
				low = argMin(j, Weight[j], k, Weight[k]);
				d = Weight[high] - Weight[low];
				if(d <= Capacity[Y[low]] && Capacity[Y[high]] + d >= Weight[u]){
					t = argMax(u, Profit[u],  u, Weight[u]);
					Capacity[Y[high]] = Capacity[Y[high]] + d - Weight[t];
					Capacity[Y[low]] = Capacity[Y[low]] - d;
					Y[t] = Y[high];
					Y[high] = Y[low];
					Y[low] = Y[t];
					z = z + profitCounter(Profit[t], Capacity[Y[high]], CapacityFirst[Y[high]], ClassOfKnapsack[Y[high]], SpeedOfKnapsack[Y[high]]);
 				}
			}
		}
	}


int K[n];
int CapacityTemp = 0;
int suma = 0; 

	for(j=n; j>=1;j--){
		if(Y[j] > 0){
			CapacityTemp = Capacity[Y[j]] + Weight[j];
			for(i=0;i<=n;i++){
				K[i] = 0;
			}
			for(k=1; k<=n;k++){
				if(Y[k] == 0 && Weight[k] <= CapacityTemp){
					K[k] = k;
					CapacityTemp = CapacityTemp - Weight[k];
				
				}
			}
			suma = 0;
			for(k=0;k<=n;k++){
				if(K[k] > 0){
					suma = suma + profitCounter(Profit[K[k]], Capacity[Y[j]], CapacityFirst[Y[j]], ClassOfKnapsack[Y[j]], SpeedOfKnapsack[Y[j]]);
				}
			}
			if(suma > profitCounter(Profit[j], Capacity[Y[j]], CapacityFirst[Y[j]], ClassOfKnapsack[Y[j]], SpeedOfKnapsack[Y[j]])){
				for(k=0;k<=n;k++){
				if(K[k] > 0){
					Y[k] = Y[j];
					Capacity[Y[j]] = CapacityTemp;
					Y[j] = 0;
					z = z + suma - profitCounter(Profit[j], Capacity[Y[j]], CapacityFirst[Y[j]], ClassOfKnapsack[Y[j]], SpeedOfKnapsack[Y[j]]);
				}
			}
			}
		}
	}	
	
	
	
	
	
	
	return Y;
	
}
/**
 *
 * @brief Main function reads data from files and allocates them to their asignated table spaces. Afterwards the appropriate functions are called and the result is stored in a file.  
 */	
int main(){
	
	clock_t begin = clock();
	double time_spent = 0.0;
	int flaga = 0;
	int n = 0;
	int m = 0;
	int z = 0;

    
	FILE* file = fopen("conf.txt", "r"); 
	FILE * file1 = fopen("filesTmp.txt", "r");
	FILE * file2 = fopen("carriersTmp.txt", "r");
	FILE * filespeed = fopen("speedTmp.txt", "r");
	if(file==NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	if(file1==NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	if(file2==NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   if(filespeed==NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if(flaga == 0){
        	n = atoi(line);
        	flaga = 1;
		}
		else{
			m = atoi(line);
		}
		 
    }
   
	long long int Weight[n+1];
	long long int Profit[n+1];
	long long int Capacity[m+1];
	long long int CapacityFirst[m+1];
	int Y[n+1];
	int ClassOfKnapsack[m+1];
	int SpeedOfKnapsack[m+1];
	
	
	 
	Weight[0] = 0;
	Profit[0] = 0;
	Capacity[0] =0;
	CapacityFirst[0] = 0;
    int licznik =1;
    while (fgets(line, sizeof(line), file2)) {
        
        Capacity[licznik] = atoi(line);
        CapacityFirst[licznik] = atoi(line);
        licznik++;
		 
    }
  
    licznik = 1;
     while (fgets(line, sizeof(line), file1)) {
        
        Weight[licznik] = atoi(line);
        Profit[licznik] = Weight[licznik];
        licznik++;
		 
    }
	int i;	
	for(i=0;i<=n;i++){		
		Y[i]=0;		
	}
	for(i=0;i<=m;i++){		
		ClassOfKnapsack[i]=1;	
		SpeedOfKnapsack[i]=1;	
	}
	licznik = 1;
	while (fgets(line, sizeof(line), file1)) {
        
        SpeedOfKnapsack[licznik] = atoi(line);
        licznik++;
		 
    }
    FILE *f = fopen("result.txt", "wb");
	if(f==NULL){
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	
	int k = 1, licznikTmp = 1, temporaryCapacity=0;
	while(k<=n){
		if(Weight[k]>Capacity[licznikTmp]){

			Weight[k] = Weight[k] - Capacity[licznikTmp];
			temporaryCapacity = CapacityFirst[licznikTmp];
			Capacity[licznikTmp] = 0;
			CapacityFirst[licznikTmp] = 0;
			int x = 0;
    		for (x = 1; x <= m; x++){

    		}
			fprintf(f,"%d/%d(%d) ", k,licznikTmp,temporaryCapacity);
			licznikTmp++;
			k=0;

		}
		k++;
	}
	
	
	int j = 0;
	int *t = MTHM(n, Profit, Weight, Y, Capacity,  m, CapacityFirst, z,ClassOfKnapsack,SpeedOfKnapsack);
	
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
	
	//fprintf(f,"Time elpased is %f seconds | ", time_spent);
	//fprintf(f,"\n");
	for(j=1; j<=n;j++){
			fprintf(f,"%d ", t[j]);
	}

	fclose(f);

	
	fclose(file);
	fclose(file2);
	fclose(file1);
	
	
	return 0;
}
