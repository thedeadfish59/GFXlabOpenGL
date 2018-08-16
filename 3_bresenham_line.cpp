#include<windows.h>
#include<math.h>
#include<GL/glut.h>


void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);  //background color is white
  glColor4f(1.0f, 0.0f, 0.0f,1.0f);  //drawing color is black
  glPointSize(4.0); //a dot is 2 by 2 pixels
  
//initialize view (simple orthographic projection)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0, 1.0, -1.0, 1.0);
  
  //set the viewing coordinates
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void line(GLint p,GLint s,GLint q,GLint t)
{
GLint x1=p,x2=q,y1=s,y2=t;
 GLint x,y;
 //x1=50, x2=200, y1=100, y2=200;
  GLint dx, dy, inc1, inc2, d;

  x = x1;
  y = y1;

  dx = x2-x1;
  dy = y2-y1;

  inc1 = 2 * dy;
  inc2 = 2 * (dy-dx);

  d = inc1 - dx;

  while(x <= x2)
    {

      glBegin(GL_POINTS);
      { 
	glVertex2i(x,y); 
      }
      glEnd();
  
	  x++;
      
	  if(d < 0)
      d = d + inc1;

	  else {
		  d = d + inc2;
		  y++;
	  }
      
      }

}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
  glPointSize(2.0);
   	
line(100,50,200,50);
line(100,100,200,100);
line(100,50,110,800);
line(200,50,210,800);
//line(100,200,50,100);
//line(100,200,50,100);
	
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
