/*
Write C++ program to draw 2-D object and perform following basic transformations, a) Scaling 
b) Translation c) Rotation. Apply the concept of operator overloading.
*/


#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int object[4][3]={{100,100,1},{200,100,1},{200,200,1},{100,200,1}};

class Transformation 
{
	public:
	   	 void drawPolygon(int [4][3]);
	  	 void operator ! ();	//scaling
	   	 void operator - ();	//translation
		 void operator + ();    //Clockwise
		 void operator * ();    //Anti Clockwise
	//	    ~Transformation();
};


void Transformation::drawPolygon(int poly[4][3])
{
    int i;
     	
    for (i=0;i<3;i++)
    {
	   line(poly[i][0],poly[i][1],poly[i+1][0],poly[i+1][1]);
    }
	   line(poly[i][0],poly[i][1],poly[0][0],poly[0][1]);
}

//scaling

void Transformation :: operator ! ()
{
    int result[4][3];
    int sx=2, sy=2;

    for(int i=0;i<=3;i++)
    {
            result[i][0]=object[i][0]*sx;
           result[i][1]=object[i][1]*sy;
    }
    drawPolygon(result);
}

// translation

void Transformation :: operator - ()
{
   int result[4][3];
   int tx=80, ty=80;
    for(int i=0;i<=3;i++)
    {
            result[i][0]=object[i][0]+tx;
           result[i][1]=object[i][1]+ty;
    }
    drawPolygon(result);
}

// rotation anticlockwise

void Transformation :: operator * ()
{
    int result[4][3];
    int ang=10;
    double angle=(ang * (3.14/180));

    for(int i=0;i<=3;i++)
    {
            result[i][0]=object[i][0]*cos(angle)+object[i][1]*sin(angle);
            result[i][1]=-object[i][0]*sin(angle)+object[i][1]*cos(angle);
    }
    drawPolygon(result);
}

// rotation clockwise

void Transformation :: operator + ()
{
    int result[4][3];
    int ang=10;
    double angle=(ang * (3.14/180));

    for(int i=0;i<=3;i++)
    {
            result[i][0]=object[i][0]*cos(angle)-object[i][1]*sin(angle);
            result[i][1]=object[i][0]*sin(angle)+object[i][1]*cos(angle);
    }
    drawPolygon(result);
}

int main()
{
	int gd = DETECT, gm,choice;
	initgraph(&gd, &gm, NULL);
	
	Transformation t;
	t.drawPolygon(object);
	delay(5000);
	do{
		cleardevice();

		cout<<"\n1) Scaling";
		cout<<"\n2) Translation";
		cout<<"\n3) Clockwise Rotation";
		cout<<"\n4) Anti Clockwise Rotation";
		cout<<"\n5) Exit";
		cout<<"\n Enter  your choice :: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				setcolor(WHITE);
				t.drawPolygon(object);
				setcolor(MAGENTA);
				!t;
				delay(5000);
				cleardevice();
				break;

			case 2:
				setcolor(WHITE);
				t.drawPolygon(object);
				setcolor(GREEN);
				-t;
				delay(5000);
				cleardevice();
				break;
			case 3:
				setcolor(WHITE);
				t.drawPolygon(object);
				setcolor(YELLOW);
				*t;
				delay(5000);
				cleardevice();
				break;
			case 4:
				setcolor(WHITE);
				t.drawPolygon(object);
				setcolor(CYAN);
				+t;
				delay(5000);
				cleardevice();
				break;
			case 5:
				break;
			default :
				cout<<"\nEnter correct choice.....";
	}
	}while(choice!=5);
}