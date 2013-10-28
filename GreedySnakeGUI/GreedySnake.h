// GreedySnake.h: interface for the GreedySnake class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GREEDYSNAKE_H__12441445_E0EA_4D97_BB08_A3569D88E0D0__INCLUDED_)
#define AFX_GREEDYSNAKE_H__12441445_E0EA_4D97_BB08_A3569D88E0D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Block.h"

#define UP		1
#define LEFT	2
#define DOWN	3
#define RIGHT   4

#define INITLENGTH 4

#define LIVE 1
#define DEAD 0

typedef struct _snake 
{
	int posX;
	int posY;
	struct _snake *before;
}Snake;

typedef struct _nut 
{
	int posX;
	int posY;
}Nut;

class GreedySnake  
{
private:
	int width;
	int height;
	int direction;
//	int lastDirection;

	Snake snake[INITLENGTH]; 
	Snake *head;
	Snake *tail;
	Nut nut;
public:	

	Block **block;
	GreedySnake(int width,int height);
	GreedySnake();
	virtual ~GreedySnake();
	int getWidth();
	int getHeight();
	void refresh();
	void nextNut();
	int moveForward();
	void changeDirection(int newDirection);
	void printSnake();

};

#endif // !defined(AFX_GREEDYSNAKE_H__12441445_E0EA_4D97_BB08_A3569D88E0D0__INCLUDED_)
