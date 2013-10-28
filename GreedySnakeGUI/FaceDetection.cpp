// FaceDetection.cpp: implementation of the FaceDetection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
/*#include "FaceMFC.h"*/
#include "FaceDetection.h"

#include "cv.h"
#include "cvaux.h"
#include "highgui.h"
#include "cxcore.h"

#pragma comment(lib,"cv210.lib")
#pragma comment(lib,"highgui210.lib")
#pragma comment(lib,"cxcore210.lib")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FaceDetection::FaceDetection()
{

}

FaceDetection::~FaceDetection()
{

}

void FaceDetection::detection()
{
	static CvMemStorage* storage = 0;
	static CvHaarClassifierCascade* cascade = 0;
	const char* cascade_name ="haarcascade_frontalface_alt.xml";
	
    CvCapture* capture = NULL;
    IplImage *frame, *frame_copy = 0;

	//

	
	static CvScalar colors[] = 
    {
        {{0,0,255}},
        {{0,128,255}},
        {{0,255,255}},
        {{0,255,0}},
        {{255,128,0}},
        {{255,255,0}},
        {{255,0,0}},
        {{255,0,255}}
    };	
	
	
	cascade_name = "haarcascade_frontalface_alt2.xml";	
    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );	
    storage = cvCreateMemStorage(0);	
//	capture = cvCaptureFromAVI( "f://[¹úÍõµÄÑÝ½²].The.Kings.Speech.2010.DVDSCR.XViD-iLG.CD1.avi" ); 	
  
//	capture = cvCaptureFromAVI("f://test.avi");
	capture = cvCaptureFromCAM(-1);
	cvNamedWindow( "result", 1 );  
	cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES,10);
	IplImage* img=cvQueryFrame(capture);
	double scale = 1.3;
    IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
    IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
		cvRound (img->height/scale)),
		8, 1 );
    int i;	
	
    if( capture )
    {

        for(;;)
        {	
			cvGrabFrame( capture );
            frame = cvRetrieveFrame( capture );
            if( !frame )
                break;
            if( !img )
                img = cvCreateImage( cvSize(frame->width,frame->height),IPL_DEPTH_8U, frame->nChannels );
            if( frame->origin != IPL_ORIGIN_TL )
                cvCopy( frame, img, 0 );
            else
                cvFlip( frame, img, 0 );
			
			cvCvtColor( img, gray, CV_BGR2GRAY );
			cvResize( gray, small_img, CV_INTER_LINEAR );
			cvEqualizeHist( small_img, small_img );
			cvClearMemStorage( storage );
			
			if( cascade )
			{
				double t = (double)cvGetTickCount();
				CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage,
					1.1, 2, 0/*CV_HAAR_DO_CANNY_PRUNING*/,
					cvSize(30, 30) );
				t = (double)cvGetTickCount() - t;
				printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
				for( i = 0; i < (faces ? faces->total : 0); i++ )
				{
					CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
					CvPoint center;
					int radius;
					center.x = cvRound((r->x + r->width*0.5)*scale);
					center.y = cvRound((r->y + r->height*0.5)*scale);

					//
					lastPoint = point;

					point.x=center.x;
					point.y=center.y;

					radius = cvRound((r->width + r->height)*0.25*scale);
					cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
					cvCircle( img, center, 1, colors[i%8], 3, 8, 0 );
				}
			}
			
			cvFlip( img, img, 0 );
			cvShowImage( "result", img );
			
            if( cvWaitKey( 1 ) >= 0 )
                break;
        }
		
        cvReleaseImage( &frame_copy );
        cvReleaseCapture( &capture );
    }
	
    cvDestroyWindow("result");
}

int FaceDetection::getDirection()
{
	int direction;

	int dirX;
	int dirY;
	
	if(point.x-lastPoint.x>10)
		dirX=RIGHT;
	else if(lastPoint.x-point.x>10)
		dirX=LEFT;	
	else
		dirX=0;

	if(point.y-lastPoint.y>10)
		dirY=DOWN;
	else if(lastPoint.x-point.x>10)
		dirY=UP;	
	else
		dirY=0;

	direction=dirX>dirY?dirX:dirY;
	return direction;
}