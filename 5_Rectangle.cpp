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

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
  // glRecti(10,10,150,60); //draw a rectangle with background color

	glColor3f(0.4,0.0,0.0);
  glRecti(200,150,500,330);
  

 /*	glBegin(GL_LINES); //draw lines
  {
  glVertex2i(200,150);
  glVertex2i(200,330);
  
  glVertex2i(500,330);
  glVertex2i(500,150);

  glVertex2i(500,330);
  glVertex2i(500,150);

  glVertex2i(200,150);
  glVertex2i(500,150);

  glVertex2i(200,330);
  glVertex2i(500,330);
  }

  glEnd();*/
  
	

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
  //glutMouseFunc(myMouse);

  myInit();
  glutMainLoop();  //go into a perpetual loop

  //fprintf(stderr, "Hello!\n");
  return 1;

}
