#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<pthread.h>
int a=10,b=20,c=30,x1,x2,x3;
double z1,z2,z3;


struct aaa
{
	int a, b,c;
};


void *printz1 (void* arg)
{
	struct aaa *ptr = (struct aaa *) arg;
	printf("THREAD 1 RUNNING...");
	for(x1=0;x1<100;x1++)
	{
		
		z1=ptr->a + x1;//πρώτη συνάρτηση
		printf("\n Z1 =%f ", z1);
		}
	
	return NULL;   
}

void *printz2 (void* arg)
{
	
	printf("\n THREAD 2 RUNNING...");
	for(x2=0;x2<100;x2++)
	{

		z2=a*pow(x2,2)+b*x2+c;//δευτερη συνάρτηση
		printf("\n Z2 =%f ", z2);
		}
	
	return NULL;   
}


void *printz3 (void* arg)
{   

		printf("\n THREAD 3 RUNNING...");
	for(x3=0;x3<100;x3++)
	{
	
		z3=b*pow(x3,2)+a;//τριτη συνάρτηση
		printf("\n Z3 =%f \t ", z3);
		}
	
	return NULL;   
}

int  main()
{

int x,a,b,c;
printf("this program run 3 equation and give the result for diffrent values of x.\n");

struct aaa pa;

scanf("%d %d %d", &pa.a, &pa.b, &pa.c);

pthread_t t1, t2, t3, t4;
    
	printf("\n\nCreating threads\n\n");
	pthread_create(&t1, NULL, printz1, &pa);
	pthread_create(&t2, NULL, printz2, NULL);
	pthread_create(&t3, NULL, printz3, NULL);

	
	printf("\n\nJoining Threads\n\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	printf("\nPress enter to continue ");
    getchar();
	return 0;
}




