#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

/*TOMATO*/
Graph** Make_Carton();
void Input_Tomato(Graph** carton);
void Input_Link(Graph** carton);
void Tomato_Ripe_Simulation(Graph** carton, int** check_list);

/*STACK*/
Stack* Add_new_node();
void Push_Link(Graph* node);
Graph* Pop_Link();
int IS_Empty();

#endif
