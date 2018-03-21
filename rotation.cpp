#include<stdio.h>
#include<conio.h>

#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>

double x1,x2,x3,y1,y2,y3,px,py, m[4][4], m1[4][4],
		r[4][4]={{0},{0, 0.70710678, -0.70710678, 0},	// |
					 {0, 0.70710678, 0.70710678, 0},	// | rotation matrix - 45°
					 {0, 0, 0, 1}},						// |
			 p[4][4]={{0},{1,0},		// | matrix for
					{0,1},{0,0,1}};		// | the point

void input()
{
	printf("Enter Co-ordinate of 3 pionts of the triangle:-\n");

	printf("Co-ordinate of 1st piont(x1 y1): ");
	scanf("%lf %lf",&x1,&y1);
	m[1][1]=x1; m[2][1]=y1;

	printf("Co-ordinate of 2nd piont(x2, y2): ");
	scanf("%lf %lf",&x2, &y2);
	m[1][2]=x2; m[2][2]=y2;
	
	printf("Co-ordinate of 3rd piont(x3, y3): ");
	scanf("%lf %lf",&x3, &y3);
	m[1][3]=x3; m[2][3]=y3;

	m[3][1]=1; m[3][2]=1; m[3][3]=1;

	printf("Enter a point as origin for rotation: ");
	scanf("%lf %lf",&px,&py);
}


void MultMatrix(double c[4][4], double a[4][4], double b[4][4])
{
	int i,j,k;

	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{	c[i][j]=0;
			for(k=1;k<=3;k++)
			{
				c[i][j]=c[i][j] + a[i][k]*b[k][j];
			}
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(x1,y1, 0.0);
	glVertex3f(x2,y2, 0.0);
	glVertex3f(x3,y3, 0.0);
	glEnd();
	
	glColor3f(0.5, 3.5, 3.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(m1[1][1], m1[2][1], 0.0);
	glVertex3f(m1[1][2], m1[2][2], 0.0);
	glVertex3f(m1[1][3], m1[2][3], 0.0);
	glEnd();
	
	glFlush();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	freopen("rotation.txt","r",stdin);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);

	input();
	MultMatrix(m1, r, m);

	glutCreateWindow("Graphics Design");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}