/*
 *  model.c
 *  This program demonstrates modeling transformations
 */
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>


void init(void) 
{
glClearColor (0.0, 0.0, 0.0, 0.0);
   //glShadeModel (GL_FLAT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void draw_triangle(void)
{
   glBegin (GL_LINE_LOOP);
   glVertex2f(0.0, 25.0);
   glVertex2f(25.0, -25.0);
   glVertex2f(-25.0, -25.0);
   glEnd();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glLoadIdentity ();
   glColor3f (1.0, 1.0, 1.0);
   draw_triangle ();

   glEnable (GL_LINE_STIPPLE);
   glLineStipple (1, 0xF0F0);
   glLoadIdentity ();
   glTranslatef (-20.0, 0.0, 0.0);
   draw_triangle ();

   glLineStipple (1, 0xF00F);
   glLoadIdentity ();
   glScalef (1.5, 0.5, 1.0);
   draw_triangle ();

   glLineStipple (1, 0x8888);
   glLoadIdentity ();
   glRotatef (90.0, 0.0, 0.0, 1.0);
   draw_triangle ();
   glDisable (GL_LINE_STIPPLE);

   glFlush ();
}

/*void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}*/


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   //glutReshapeFunc(reshape);
  // glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
