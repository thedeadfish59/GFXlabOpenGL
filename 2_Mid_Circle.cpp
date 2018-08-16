#include<windows.h>
#include<math.h>
#include<GL/glut.h>
#include<iostream.h>

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);  //background color is white
  glColor3f(0.0f, 0.0f, 0.0f);  //drawing color is black
  glPointSize(4.0); //a dot is 2 by 2 pixels
  
//initialize view (simple orthographic projection)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0, 1.0, -1.0, 1.0);
  
  //set the viewing coordinates
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void Draw(int x,int y,int xC,int yC)
{

	glBegin(GL_POINTS);
      {
		  
	glVertex2i(xC + x,yC + y);
	glVertex2i(xC + x,yC - y);
	glVertex2i(xC - x,yC + y);
	glVertex2i(xC - x,yC - y);
	glVertex2i(xC + y,yC + x);
	glVertex2i(xC - y,yC + x);
	glVertex2i(xC + y,yC - x);
	glVertex2i(xC - y,yC - x);;

      }
      glEnd();
	
}


void Circle(int Radius,int xC,int yC)
{
	int P;
	int x,y;
	
	P = 1 - Radius;
	x = 0;
	y = Radius;
	
	while (x<=y)
	{
		x++;
		if (P<0)
		{
			P += 2 * x + 3;
		}
		else
		{
			P += 2 * (x - y) + 5;
			y--;
		}
		Draw(x,y,xC,yC);
	}

}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
	glPointSize(2.0);
   	
	Circle(150,320,240);
	glFlush();
 //send all output to display
}


int  main(int argc, char** argv)
{
  glutInit(&argc, argv);  //initialize the toolkit
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
  glutInitWindowSize(640,480);  //set window size
  //set window position on screen
  glutInitWindowPosition(10,15);  
  //open the screen window and set the name
  glutCreateWindow("My First Window");  
 
  glutDisplayFunc(myDisplay);

  myInit();
 
  glutMainLoop();  //go into a perpetual loop

  return 1;

}
