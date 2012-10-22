#include <stdio.h>

#define MAX_NUMBER 50

/*struct Edge{
	struct Edge *next;
	int item;
};*/

int globalCountFirst = 0;
int globalCountSecond = 0;

void Input(int*, int*);
void Output(int*, int*);
void Remove(int*, int*);
void Add(int*, int*);
void AddPosition(int*, int*);
void AddEdge(int (&chEdges)[MAX_NUMBER][MAX_NUMBER]);

int main(void)
{
	
	int first[MAX_NUMBER];
	int second[MAX_NUMBER];
	
	//struct Edge *firstEdges[MAX_NUMBER];
	
	int edges[MAX_NUMBER][MAX_NUMBER];
		
	int answ;
	
	while(1)
	{
		printf("\n\n0: Input first set\n\
1: Input second set\n\
2: Add one more item into first set\n\
3: Add one more item into second set\n\
4: Remove item from first set\n\
5: Remove item from second set\n\
6: Output sets\n\
7: Add one more item on position of first set\n\
8: Add one more item on position of second set\n\
9: Add edges\n\
\nChoose your destiny! : ");

		scanf("%d", &answ);
		switch(answ)
		{
			case 0: Input(first, &globalCountFirst);          break;
			case 1: Input(second, &globalCountSecond);        break;
			case 2: Add(first, &globalCountFirst);            break;
			case 3: Add(second, &globalCountSecond);          break;
			case 4: Remove(first, &globalCountFirst);         break;
			case 5: Remove(second, &globalCountSecond);       break;
			case 6: Output(first, second);                    break;
			case 7: AddPosition(first, &globalCountFirst);    break;
			case 8: AddPosition(second, &globalCountSecond);  break;
			case 9: AddEdge(edges);                          break;
		}
	}
	
	return 0;
}


	
void Input(int *set, int *globalCount)
{
	int answ = 1;
	int tmp;
	
	while(1)
	{
		printf("\nType new set item: ");
		scanf("%d", &tmp);
		set[*globalCount] = tmp;
		
		if(*globalCount > MAX_NUMBER - 1)
		{
			printf("\nEnd of set");
			break;
		}
		
		printf("\nDo you type one more? [1/0]");
		scanf("%d", &answ);
		if(answ == 0) break;
		
		(*globalCount)++;
	}
}

void Output(int *setFirst, int *setSecond)
{
	
	int count;
	
	printf("\nFirst set:\n");
	for(count = 0; count <= globalCountFirst; count++) printf("%d ", setFirst[count]);
	printf("\nSecond set:\n");
	for(count = 0; count <= globalCountSecond; count++) printf("%d ", setSecond[count]);
}

void Remove(int *set, int *globalCount)
{
	int index;
	
	printf("\nType set index to remove: ");
	scanf("%d", &index);
	
	for(index; index < MAX_NUMBER -1; index++) set[index] = set[index + 1];
	
	(*globalCount)--;
}

void Add(int *set, int *globalCount)
{
	printf("\nType one more set item: ");
	scanf("%d", &set[++(*globalCount)]);
}

void AddPosition(int *set, int *globalCount)
{
	int count, position;
	
	printf("\nType position index of new item: ");
	scanf("%d", &position);
	
	for(count = *globalCount; count >= position; count--)
		set[count + 1] = set[count];
		
	printf("\nType one more set item: ");
	scanf("%d", &set[position]);
	
	(*globalCount)++;
}

/*void AddEdge(struct Edge **edges)
{
	int index;
	
	printf("Type item index for setting edges: ");
	scanf("%d", &index);
	printf("%d", index);
	struct Edge *current;
	edges[index] = current;
	current -> next = (struct Edge*)malloc(sizeof(struct Edge));
	
	int answ = 1;
	int tmp;
	
	while(1)
	{
		printf("\nType new edged item: ");
		scanf("%d", &tmp);
		current -> next -> item = tmp;
		current -> next = (struct Edge*)malloc(sizeof(struct Edge));
		
		printf("\nDo you type one more? [1/0]");
		scanf("%d", &answ);
		if(answ == 0) break;
	}
}
*/

void AddEdge(int (&chEdges)[MAX_NUMBER][MAX_NUMBER])
{
	int firstIndex, secondIndex;
	
	printf("\nType first item index: ");
	scanf("%d", &firstIndex);
	
	printf("\nType second item index: ");
	scanf("%d", &secondIndex);
	
	chEdges[firstIndex][secondIndex] = 1;
	
	printf("\nEdge complited");
}