#include<windows.h>
#include<math.h>
#include<GL/glut.h>


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


void DDALine(int x1,int y1,int x2,int y2)
{
	GLint x,y;
  GLdouble xf, m, b;
  x=x1; y=y1;
  m=(y2-y1)/(x2-x1);
  b=y1-m*x1;
  glBegin(GL_POINTS);
  { 
    glVertex2i(x,y); 
  }
  glEnd();

  while(y<y2)
    {
      y++;
      xf=(y-b)/m;
      x=floor(xf+0.5);
      glBegin(GL_POINTS);
      { 
	glVertex2i(x,y); 
      }
      glEnd();
      }
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
  glPointSize(2.0);
   	
  DDALine(36,25,240,250);
	
  glFlush(); //send all output to display
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

  //fprintf(stderr, "Hello!\n");
  return 1;

}
