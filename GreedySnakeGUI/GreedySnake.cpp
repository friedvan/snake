// GreedySnake.cpp: implementation of the GreedySnake class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>

#include "GreedySnake.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GreedySnake::GreedySnake(int width,int height)
{
	//initial width&height
	this->width=width;
	this->height=height;
	//apply memoary
	block=(Block **)malloc(height*sizeof(Block *));		
	for(int j=0;j<height;j++)
	{
		block[j]=(Block *)malloc(width*sizeof(Block));
	}
	
	//initial blocks
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			//initial wall
			if(i==0||j==0||i==height-1||j==width-1)
				block[i][j]=Block(i,j,FULL,WALL);
			else
				block[i][j]=Block(i,j,EMPTY,SPACE);
		}
	}
	
	//initial direction
	direction = UP;
	//initial snake
	head=snake;
	tail=snake+INITLENGTH-1;
	for(int i=INITLENGTH-1;i>=0;i--)
	{
		snake[i].posX=width/2;
		snake[i].posY=height-INITLENGTH+i-1;

		if(i-1>=0)
			snake[i].before=&snake[i-1];
		else
			snake[i].before=tail;
	}
	//initial nut
	nextNut();
	
	//refresh game
	refresh();
}

GreedySnake::GreedySnake()
{
	//initial width&height
	this->width=30;
	this->height=30;
	//apply memoary
	block=(Block **)malloc(height*sizeof(Block *));		
	for(int j=0;j<height;j++)
	{
		block[j]=(Block *)malloc(width*sizeof(Block));
	}
	
	//initial blocks
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			//initial wall
			if(i==0||j==0||i==height-1||j==width-1)
				block[i][j]=Block(i,j,FULL,WALL);
			else
				block[i][j]=Block(i,j,EMPTY,SPACE);
		}
	}
	
	//initial direction
	direction = UP;
	//initial snake
	head=snake;
	tail=snake+INITLENGTH-1;
	for(int i=INITLENGTH-1;i>=0;i--)
	{
		snake[i].posX=width/2;
		snake[i].posY=height-INITLENGTH+i-1;
		
		if(i-1>=0)
			snake[i].before=&snake[i-1];
		else
			snake[i].before=tail;
	}
	//initial nut
	nextNut();
	
	//refresh game
	refresh();
}

GreedySnake::~GreedySnake()
{
	
}

int GreedySnake::getWidth()
{
	return width;
}

int GreedySnake::getHeight()
{
	return height;
}

void GreedySnake::refresh()
{
	block[nut.posY][nut.posX].setType(NUT);
	//	block[nut.posX][nut.posY].setType(FULL);
	Snake *ptr=tail;
	while(ptr!=head)
	{
		block[ptr->posY][ptr->posX].setType(SNAKE);
		ptr=ptr->before;
	}
	block[head->posY][head->posX].setType(SNAKE);
	ptr=NULL;
//	printSnake();
}

void GreedySnake::nextNut()
{
	srand(time(NULL)); 
	nut.posX=rand()%(width-2)+1;
	srand(time(NULL));
	nut.posY=rand()%(height-2)+1;
}

int GreedySnake::moveForward()
{
	switch(direction)
	{
	case UP:
		{
			switch(block[head->posY-1][head->posX].getType())
			{
			case SPACE:
				{
					block[tail->posY][tail->posX].setType(SPACE);
					tail->posX=head->posX;
					tail->posY=head->posY-1;
					tail=tail->before;
					head=head->before;
					return LIVE;
				}
			case SNAKE:
				return DEAD;
			case WALL:
				return DEAD;
			case NUT:
				{
					//必须动态申请，否则函数结束，内存释放
					Snake *newHead=(Snake *)malloc(sizeof(Snake));
					newHead->posX=head->posX;
					newHead->posY=head->posY-1;
					newHead->before=tail;
					head->before=newHead;
					head=head->before;
					nextNut();
					return LIVE;
				}
			}
		}
	case LEFT:
		{
			switch(block[head->posY][head->posX-1].getType())
			{
			case SPACE:
				{
					block[tail->posY][tail->posX].setType(SPACE);
					tail->posX=head->posX-1;
					tail->posY=head->posY;
					tail=tail->before;
					head=head->before;
					return LIVE;
				}
			case SNAKE:
				return DEAD;
			case WALL:
				return DEAD;
			case NUT:
				{
					Snake *newHead=(Snake *)malloc(sizeof(Snake));
					newHead->posX=head->posX-1;
					newHead->posY=head->posY;
					newHead->before=tail;
					head->before=newHead;
					head=head->before;
					nextNut();
					return LIVE;
				}
			}
		}
	case RIGHT:
		{
			switch(block[head->posY][head->posX+1].getType())
			{
			case SPACE:
				{
					block[tail->posY][tail->posX].setType(SPACE);
					tail->posX=head->posX+1;
					tail->posY=head->posY;
					tail=tail->before;
					head=head->before;
					return LIVE;
				}
			case SNAKE:
				return DEAD;
			case WALL:
				return DEAD;
			case NUT:
				{
					Snake *newHead=(Snake *)malloc(sizeof(Snake));
					newHead->posX=head->posX+1;
					newHead->posY=head->posY;
					newHead->before=tail;
					head->before=newHead;
					head=head->before;			
					nextNut();
					return LIVE;
				}
			}
		}
	case DOWN:
		{
			switch(block[head->posY+1][head->posX].getType())
			{
			case SPACE:
				{
					block[tail->posY][tail->posX].setType(SPACE);
					tail->posX=head->posX;
					tail->posY=head->posY+1;
					tail=tail->before;
					head=head->before;
					return LIVE;
				}
			case SNAKE:
				return DEAD;
			case WALL:
				return DEAD;
			case NUT:
				{
					Snake *newHead=(Snake *)malloc(sizeof(Snake));
					newHead->posX=head->posX;
					newHead->posY=head->posY+1;
					newHead->before=tail;
					head->before=newHead;
					head=head->before;
					nextNut();
					return LIVE;
				}
			}
		}
	}	
	return DEAD;
}

void GreedySnake::changeDirection(int newDirection)
{
	direction=newDirection;
}

void GreedySnake::printSnake()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if (block[i][j].getType()==SPACE)
			{
				//cout<<"0";
				printf(" ");
			} 
			else if(block[i][j].getType()==NUT)
			{
				//cout<<"7";
				printf("o");
			}
			else if(block[i][j].getType()==SNAKE)
			{
				//cout<<"1";
				printf("1");
			}
			else if(block[i][j].getType()==WALL)
				printf("w");

		}
		//cout<<endl;
		printf("\n");
	}
}

// void main()
// {
// 	GreedySnake s(20,20);
// //	cout<<"init..."<<endl;
// 
// 	printf("init...\n");
// 	s.printSnake();
// 
// 
// 	int i=0;
// 	while (	i<5&&s.moveForward())
// 	{
// 		i++;
// 		s.refresh();
// 		printf("\n");
// 		s.printSnake();
// 		Sleep(1000);
// //		cout<<endl;
// 	}
// 	s.changeDirection(LEFT);
// 	while(s.moveForward())
// 	{
// 		s.refresh();
// 		printf("\n");
// 		s.printSnake();
// 		Sleep(1000);
// 	}
// }

