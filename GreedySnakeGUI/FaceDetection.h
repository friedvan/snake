// FaceDetection.h: interface for the FaceDetection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACEDETECTION_H__62A92FBF_EF99_4AA4_8CAD_E90241698487__INCLUDED_)
#define AFX_FACEDETECTION_H__62A92FBF_EF99_4AA4_8CAD_E90241698487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>


#define UP		1
#define LEFT	2
#define RIGHT	3
#define DOWN	4



class FaceDetection  
{
private:

public:
	POINT point;
	POINT lastPoint;
	FaceDetection();
	virtual ~FaceDetection();
	void detection();
	int getDirection();
};

#endif // !defined(AFX_FACEDETECTION_H__62A92FBF_EF99_4AA4_8CAD_E90241698487__INCLUDED_)
