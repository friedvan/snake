// Block.cpp: implementation of the Block class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Block.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Block::Block(int y,int x,int status,int type)
{
	this->x=x;
	this->y=y;
//	this->status=status;
	this->type=type;
}

Block::~Block()
{

}

int Block::getType()
{
	return type;
}

void Block::setPos(int yy,int xx)
{
	x=xx;
	y=yy;
}

void Block::setType(int type)
{
	this->type=type;
}
