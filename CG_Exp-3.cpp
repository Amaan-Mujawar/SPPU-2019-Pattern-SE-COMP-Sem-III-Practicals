/*
Write C++ program to implement Cohen Southerland line clipping algorithm.
*/


#include<iostream>
#include <graphics.h>

using namespace std;

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin=150;
int ymin=150;
int xmax=350;
int ymax=350;

int code(int x,int y)
{
	 int outcode;
	 if(x<xmin)
		  outcode =LEFT;
	else if(x>xmax)
		  outcode =RIGHT;
	else if(y<ymin)
		  outcode =BOTTOM;
	else if(y>xmax)
		  outcode =TOP;
	 else
		  outcode=INSIDE;
 return outcode;
}
void clip(int x1,int y1,int x2,int y2)
{
	 int outcode1=code(x1,y1);
	 int outcode2=code(x2,y2);
	 bool accept=false;
	 float m=y2-y1/x2-x1;
	 while(true)
 	 {
		  if(!(outcode1 | outcode2)) 
	          {
			accept=true;
			break;
		  }
		  else if(outcode1 & outcode2)
			break;
		  else
		  {
		 	  int x,y;
			  int outcodeout;
			
			if(outcode1==0) 
				outcodeout = outcode2;
			else
				outcodeout=outcode1;
			
			if(outcodeout & TOP)
   			{
				   x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
				    y=ymax;
			 }	
			 else if(outcodeout & BOTTOM)
			   {
				    x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
				    y=ymin;
			  }	
			  else if(outcodeout & RIGHT)
			   {
				    y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
				    x=xmax;
			    }
			   else
			   {
				   y=y1+(y2-y1)*(xmin-x1)/(x2-x1);	
				   x=xmin;
			   }
			   if(outcodeout == outcode1)
			   {
				    x1=x;
				    y1=y;
				    outcode1=code(x1,y1);
			   }
			   else
			   {
				    x2=x;
				    y2=y;
				    outcode2=code(x2,y2);
			   }
	  	}
	 }
	 if(accept)
	{
		  rectangle(xmin,ymin,xmax,ymax);
	  	line(x1,y1,x2,y2);
	 }     
}
int main()
{

	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL); 
	int x1,y1,x2,y2,tx,ty;
	
	 cout<<"\n Enter the initial points of the line : ";
	 cout<<"\n X-axis : ";
	 cin>>x1;
	 cout<<" Y-axis : ";
	 cin>>y1;
	 cout<<"\n Enter the final points of the line : ";
	 cout<<"\n X-axis : ";
	 cin>>x2;
	 cout<<" Y-axis : ";
	 cin>>y2;
	 if(x1>x2)
	 {
		  tx=x1,ty=y1;
		  x1=x2,y1=y2;
		  x2=tx,y2=ty;
	}
	 cleardevice();
	 rectangle(xmin,ymin,xmax,ymax);
 	line(x1,y1,x2,y2);
	 cleardevice();
	 clip(x1,y1,x2,y2);
	delay(5000);
	 return 0;
}