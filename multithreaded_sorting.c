
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMThreads 3
#define SIZE 10
int list[SIZE] = {77,12,19,43,18,24,21,62,15,18};
int answer[SIZE];
void *sorting(void *param);
void *merging(void *param);

/*Parameter Data structure to pass in the from and to index.*/
typedef struct
{
	int from_index;
	int to_index;
	
} parameters;

int main(int argc, const char *argv[])
{
	int i;
    
	pthread_t workers[NUMThreads];
	
	/* establish the first sorting thread */
	parameters *data = (parameters *) malloc (sizeof(parameters));
	data->from_index = 0;
	data->to_index = (SIZE/2) - 1;
	pthread_create(&workers[0], 0, sorting, data);
	
	/* establish the second sorting thread */
	parameters *data1 = (parameters *) malloc (sizeof(parameters));
	data1->from_index = (SIZE/2);
	data1->to_index = SIZE - 1;
	pthread_create(&workers[1], 0, sorting, data1);
	/* now wait for the 2 sorting threads to finish */
	for (i = 0; i < NUMThreads - 1; i++)
		pthread_join(workers[i], NULL);


	parameters *data2 = (parameters *) malloc (sizeof(parameters));
	data2->from_index = 0;
	data2->to_index = (SIZE/2);
	pthread_create(&workers[2], 0, merging, data2);
	pthread_join(workers[2], NULL);
    	return 0;
}

/**
 * sorting thread.
 *
 */

void *sorting(void *params)
{
	
	parameters* pa = (parameters *)params;
	int begin = pa->from_index;
	int end = pa->to_index;
	

	int a, temp, b;
   	for (a = begin+1; a < end; a++)
   	{
       		temp = list[a];
       		b = a-1;
 
       
       		while (b >= 0 && list[b] > temp)
       		{
           		list[b+1] = list[b];
           		b = b-1;
       		}
       		list[b+1] = temp;
	}

	
	int c;
	for(c=begin; c<end; c++)
    	{
            	answer[c] = list[c];
    	}
   	

	pthread_exit(NULL);
	
}


void *merging(void *params)
{
    parameters* p = (parameters *)params;

    int begin = p->from_index;
    int end = p->to_index+1;

    int temp;
	int i,j,d;
	for( i=begin; i< SIZE; i++)
	{
		for( j=begin; j< SIZE-1; j++)
		{

			if(answer[j] > answer[j+1])
			{
				temp= answer[j];
				answer[j] = answer[j+1];
				answer[j+1] = temp;

			}
		}
	}

	for( d=begin; d<SIZE; d++)
	{
		printf("%d  ", answer[d]);
	}
	printf("\n");
    pthread_exit(NULL);
}


