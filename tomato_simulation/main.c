#include "ALL.h"

Stack* top;
int main()
{
	Graph** carton;
	int** check_list;
	int size;
	int i;

	srand((unsigned int)time(NULL));
	top = Add_new_node();
	
	carton = Make_Carton();
	size = _msize(carton) / sizeof(Graph*);
	check_list = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
		check_list[i] = (int*)calloc(size, sizeof(int));

	Input_Tomato(carton);
	Input_Link(carton);
	Tomato_Ripe_Simulation(carton, check_list);

}