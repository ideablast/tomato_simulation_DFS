#include"ALL.h"

#ifdef ACTUAL
extern Stack* top;

Stack* Add_new_node()
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->G_link = NULL;
	temp->S_link = NULL;

	return temp;
}

void Push_Link(Graph* node)
{
	Stack* temp = Add_new_node();
	temp->G_link = node;

	temp->S_link = top->S_link;
	top->S_link = temp;
}

Graph* Pop_Link()
{
	Stack* S_temp = top->S_link;
	Graph* G_temp = top->S_link->G_link;

	top->S_link = S_temp->S_link;
	free(S_temp);

	return  G_temp;
}

int IS_Empty()
{
	return top->S_link == NULL;
}

Graph** Make_Carton()
{
	int i, j;
	Graph** node;
	int size = rand() % (SIZE_END - SIZE_START + 1) + SIZE_START;
	//int size = 5;
	node = (Graph**)malloc(size * sizeof(Graph*));
	for (i = 0; i < size; i++)
	{
		node[i] = (Graph*)malloc(size * sizeof(Graph));
		for (j = 0; j < size; j++)
		{
			node[i][j].link = (Graph**)malloc(NUM_OF_LINK * sizeof(Graph*));
			node[i][j].OX = 0;
		}
	}

	return node;
}

void Input_Tomato(Graph** carton)
{
	int i, j;
	int cnt = 0;
	int size = _msize(carton) / sizeof(Graph*);
	//int ary[5][5] = { {0,0,0,1,0},{1,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0} };
	/*

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			carton[i][j].OX = rand() % 2;
			//carton[i][j].OX = ary[i][j];
		}
	}
	*/
	while (1)
	{
		carton[rand() % size][rand() % size].OX = 1;
		cnt++;

		if (cnt == NUM_OF_TOMATO)
			break;
	}

}

void Input_Link(Graph** carton)
{
	int i, j, idx;
	int link_i, link_j;
	int i_flag = 0, j_flag = 0;
	int size = _msize(carton) / sizeof(Graph*);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (idx = 0; idx < NUM_OF_LINK; idx++)
			{
				switch (idx)
				{
				case 0:
					link_i = i - 1;
					link_j = j;

					if (link_i >= 0 && link_i < size)
						i_flag = TRUE;
					else
						i_flag = FALSE;
					if (link_j >= 0 && link_j < size)
						j_flag = TRUE;
					else
						j_flag = FALSE;
					break;
				case 1:
					link_i = i;
					link_j = j + 1;
					if (link_i >= 0 && link_i < size)
						i_flag = TRUE;
					else
						i_flag = FALSE;
					if (link_j >= 0 && link_j < size)
						j_flag = TRUE;
					else
						j_flag = FALSE;
					break;
				case 2:
					link_i = i + 1;
					link_j = j;
					if (link_i >= 0 && link_i < size)
						i_flag = TRUE;
					else
						i_flag = FALSE;
					if (link_j >= 0 && link_j < size)
						j_flag = TRUE;
					else
						j_flag = FALSE;
					break;
				case 3:
					link_i = i;
					link_j = j - 1;
					if (link_i >= 0 && link_i < size)
						i_flag = TRUE;
					else
						i_flag = FALSE;
					if (link_j >= 0 && link_j < size)
						j_flag = TRUE;
					else
						j_flag = FALSE;
					break;
				}

				if (i_flag == TRUE && j_flag == TRUE)
					carton[i][j].link[idx] = &carton[link_i][link_j];
				else
					carton[i][j].link[idx] = NULL;

				i_flag = 0;
				j_flag = 0;
				link_i = 0;
				link_j = 0;
			}
		}
	}

}

void Tomato_Ripe_Simulation(Graph **carton, int **check_list)
{
	int i, j, idx;
	int day_cnt = 0, cnt = 0;
	int size = _msize(carton) / sizeof(Graph*);
	Graph* temp;
	
	while (1)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (check_list[i][j] == 1)
					cnt++;
			}
		}
		if (cnt == size * size)
			break;
		else
		{
			cnt = 0;
			day_cnt++;
		}
			
			
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (carton[i][j].OX == 1 && check_list[i][j] != 1)
				{
					Push_Link(&carton[i][j]);
					check_list[i][j] = 1;
				}
			}
		}

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (check_list[i][j])
					printf("■");
				else
					printf("□");
				//printf("%d", check_list[i][j]);
			}
			puts("");
		}
		puts("");

		while (1)
		{
			if (IS_Empty() == FALSE)
				temp = Pop_Link();
			else
				break;

			for (idx = 0; idx < NUM_OF_LINK; idx++)
			{
				if (temp->link[idx]&& temp->link[idx]->OX==0)
					temp->link[idx]->OX = 1;
			}
		}
	}
	printf("경과 일 수: %d", day_cnt-1);
	
}


#endif
/*
while (1)
		{

			if (IS_Empty() == TRUE)
				break;
			else



			for (idx = 0; idx < NUM_OF_LINK; idx++)
			{ }



		}
	for (idx = 0; idx < NUM_OF_LINK; idx++)
			{

				carton[i][j].link[idx];
			}
			
			
			for (idx = 0; idx < NUM_OF_LINK; idx++)
	{
		carton[0][size - 1];
		carton[size - 1][0];
		carton[size - 1][size - 1];
	}
	
	if((i>=0&&i<size)&&(j>=0&&j<size))
	for (i = 1; i < size - 1; i++)
	{
	}
	for (j = 1; j < size - 1; j++)
	{
	}

	for (i = 1; i < size-1; i++)
	{
		for (j = 1; j < size-1; j++)
		{
			//Link[0]: (i-1, j), Link[1]: (i, j+1), Link[2]: (i+1, j), Link[3]: (i, j-1)
			if()
		
		}
	}
		
			*/