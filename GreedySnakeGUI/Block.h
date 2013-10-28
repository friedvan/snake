// Block.h: interface for the Block class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOCK_H__F8E5A0A5_059F_4FC6_BED1_E36612C3DCFC__INCLUDED_)
#define AFX_BLOCK_H__F8E5A0A5_059F_4FC6_BED1_E36612C3DCFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//block status 
#define EMPTY	0
#define FULL	1
//block type
#define WALL	1
#define SPACE	2
#define SNAKE	3
#define NUT		4
//side length
#define SIDELENGTH	10

class Block  
{
private:
	int x;	//position x
	int y;	//position y
//	int status;	//empty or full
	int type;	//wall,space,snake or nut
public:
//	void setStatus(int status);
	void setType(int type);
	void setPos(int xx,int yy);
	int getType();
	Block(int x,int y,int status,int type);
	virtual ~Block();

};

#endif // !defined(AFX_BLOCK_H__F8E5A0A5_059F_4FC6_BED1_E36612C3DCFC__INCLUDED_)
