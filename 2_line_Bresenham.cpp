#include<windows.h>

#include<GL/glut.h>




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

  
  //set the viewing coordinates
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
  // glRecti(10,10,150,60); //draw a rectangle with background color

  //Line drawing algorithm
  glPointSize(2.0);
  
  GLint x,y, x1=50, x2=100, y1=100, y2=200;
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

  glutDisplayFunc(myDisplay);
  
  myInit();
  glutMainLoop();  //go into a perpetual loop

  //fprintf(stderr, "Hello!\n");
  return 1;

}
