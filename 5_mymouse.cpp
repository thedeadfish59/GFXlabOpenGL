#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>


const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A,B,C,D; // values for scaling and shifting

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);  //background color is white
  glColor3f(0.0f, 0.0f, 0.0f);  //drawing color is black
  glPointSize(4.0); //a dot is 2 by 2 pixels
  //glLineWidth(4.0); //a line is 4 times thicker
  

//initialize view (simple orthographic projection)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0, 1.0, -1.0, 1.0);

  A = screenWidth/4.0; //Set values for scaling and shifting
  B= 0.0;
  C=D=screenHeight/2.0;

  //set the viewing coordinates
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



void myMouse(int button, int state, int x ,int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      glColor4f(0.0,1.0,0.0,1.0);
      glRecti(200,150,500,330);  // create a rectangle 
      glFlush();
    }

  else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
	    //glPointSize(2.0);

      glColor3f(1.0,0.0,0.0);
     
	  GLint h = 350,k = 240, x, y, r, d;
  
  y = r = 60;
  d = 3 - 2*r;
  	
  for(x=0; x<=y; x++)
    {
	  glBegin(GL_POINTS);
      {
		  
	glVertex2i(x+h,y+k);
	glVertex2i(x+h,k-y);
	glVertex2i(y+h,x+k);
	glVertex2i(y+h,k-x);
	glVertex2i(-y+h,x+k);
	glVertex2i(-y+h,k-x);
	glVertex2i(-x+h,y+k);
	glVertex2i(-x+h,k-y);

      }
      glEnd();

	  if(d<0)

		  d = d + 4*x + 6;
	  else{

		  d = d + 4*(x-y) + 10;
		  y--;
	  }
	}
  glFlush();
  } //elseif

}


void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush(); //send all output to display
}



int  main(int argc, char** argv)
{
  glutInit(&argc, argv);  //initialize the toolkit
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
  glutInitWindowSize(640,480);  //set window size
  //set window position on screen
  glutInitWindowPosition(100,150);  
  //open the screen window and set the name
  glutCreateWindow("My First Window");  

  //register the callback functions
  glutDisplayFunc(myDisplay);
  glutMouseFunc(myMouse);

  myInit();
  glutMainLoop();  //go into a perpetual loop

  //fprintf(stderr, "Hello!\n");
  return 1;

}
