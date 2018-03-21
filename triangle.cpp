#include<stdio.h>
#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>

double x1,x2,x3,y1,y2,y3;
static GLfloat spin = 0.0;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glOrtho(-3.0, 5.0, -5.0, 10.0, -1.0, 1.0);
}

void input()
{
	printf("Enter Co-ordinate of 3 pionts of the triangle:-\n\n");

	printf("Co-ordinate of 1st point(x1  y1): ");
	scanf("%lf %lf",&x1,&y1);

	printf("Co-ordinate of 2nd point(x2  y2): ");
	scanf("%lf %lf",&x2, &y2);
	
	printf("Co-ordinate of 3rd point(x3  y3): ");
	scanf("%lf %lf",&x3, &y3);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	
	glBegin(GL_TRIANGLES); //GL_POLYGON GL_POINTS GL_LINE_LOOP
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glEnd();
	
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON 
				&& state == GLUT_DOWN)
	{
		spin = 45;
		glutPostRedisplay();
	}
}

void main()
{	
	//freopen("rotation.txt","r",stdin);

	glutInitWindowSize (250, 250);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Rotating Triangle");
	
	init ();
	input();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}	