

#include<iostream>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
 GLfloat xRotated, yRotated, zRotated,Xspeed=0.01,Yspeed=0.02;
void init(void)
{ glClearColor(0.0,0.5,0.8,0);}


void DrawCube(void)
{
     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-10.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    glBegin(GL_QUADS);
     glColor3f(0.0f,1.0f,0.0f);
     glVertex3f( 1.0f, 1.0f,-1.0f);
     glVertex3f(-1.0f, 1.0f,-1.0f);
     glVertex3f(-1.0f, 1.0f, 1.0f);
     glVertex3f( 1.0f, 1.0f, 1.0f);
     glColor3f(1.0f,0.5f,0.0f);
     glVertex3f( 1.0f,-1.0f, 1.0f);
     glVertex3f(-1.0f,-1.0f, 1.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
     glVertex3f( 1.0f,-1.0f,-1.0f);
     glColor3f(1.0f,0.0f,0.0f);
     glVertex3f( 1.0f, 1.0f, 1.0f);
     glVertex3f(-1.0f, 1.0f, 1.0f);
     glVertex3f(-1.0f,-1.0f, 1.0f);
     glVertex3f( 1.0f,-1.0f, 1.0f);
     glColor3f(1.0f,1.0f,0.0f);
     glVertex3f( 1.0f,-1.0f,-1.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
     glVertex3f(-1.0f, 1.0f,-1.0f);
     glVertex3f( 1.0f, 1.0f,-1.0f);
     glColor3f(0.0f,0.0f,1.0f);
     glVertex3f(-1.0f, 1.0f, 1.0f);
     glVertex3f(-1.0f, 1.0f,-1.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
     glVertex3f(-1.0f,-1.0f, 1.0f);
     glColor3f(1.0f,0.0f,1.0f);
     glVertex3f( 1.0f, 1.0f,-1.0f);
     glVertex3f( 1.0f, 1.0f, 1.0f);
     glVertex3f( 1.0f,-1.0f, 1.0f);
     glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();
  glFlush();
}


void animation(void)
{

     yRotated += Yspeed;
     xRotated += Xspeed;
     DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
  //cout<<"enter the values for the background color";
  //cin>>c1>>c2>>c3;
init();
glutDisplayFunc(DrawCube);
glutReshapeFunc(reshape);
glutIdleFunc(animation);
glutMainLoop();
return 0;
}
