#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

int opt=1;

void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20,20, -20,20, -1,1);
}

void triangle(){
    glBegin(GL_POLYGON);
    glVertex2f(5,5);
    glVertex2f(10,5);
    glVertex2f(7.5,10);
    glEnd();
    glFlush();
}

void display(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(opt==1){
        triangle();
        glRotatef(45,0,0,1);
        glColor3f(1,0,0);
        triangle();
    }
    else{
        triangle();
        glTranslated(5,5,0);
        glRotatef(45,0,0,1);
        glTranslated(-5,-5,0);
        glColor3f(1,0,0);
        triangle();
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("triangle");

    printf("enter choice \n 1. rotate abt origin \n 2. rotate about fixed point\n");
    scanf("%d",&opt);
    init();
    glutDisplayFunc(display);
    glutMainLoop();


}

