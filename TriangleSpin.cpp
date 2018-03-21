// TriangleSpin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float theta=0,xc,yc,angle=0;
float tri[3][3]={{10,50,30},{10,10,37},{1,1,1}};
float rotO[3][3]={0};
float rotF[3][3]={0};
float res[3][3]={0};
void triangle(float a[3][3])
{
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2f(0,0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
	glEnd();
}
void multiply(float b[3][3])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			res[i][j]=0;
			for(k=0;k<3;k++)
			{
				res[i][j]=res[i][j]+b[i][k]*tri[k][j];
			}
		}
	}
	triangle(res);
}
void display()
{
	rotO[0][0]=cos(theta);
	rotO[0][1]=-sin(theta);
	rotO[0][2]=0;
	rotO[1][0]=sin(theta);
	rotO[1][1]=cos(theta);
	rotO[1][2]=0;
	rotO[2][0]=0;
	rotO[2][1]=0;
	rotO[2][2]=1;

	rotF[0][0]=cos(theta);
	rotF[0][1]=-sin(theta);
	rotF[0][2]=-(xc*(cos(theta)-1))+(yc*sin(theta));
	rotF[1][0]=sin(theta);
	rotF[1][1]=cos(theta);
	rotF[1][2]=-(yc*(cos(theta)-1))-(xc*sin(theta));
	rotF[2][0]=0;
	rotF[2][1]=0;
	rotF[2][2]=1;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	triangle(tri);
	glColor3f(0,0,1);
	multiply(rotO);
	glColor3f(0,1,0);
	multiply(rotF);
	glFlush();
}
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(-50,50,-50,50);
}
void main()
{
	printf("Enter the angle(theta) to be rotated\n");
	scanf("%f",&theta);
	theta=(3.14*theta)/180;
	printf("Enter the Fixed point (xc,yc)\n");
	scanf("%f%f",&xc,&yc);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(800,800);
	glutCreateWindow("Triangle rotation about an origin and a fixed point");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}





