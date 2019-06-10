#include <windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void blda(GLint x0,GLint y0,GLint xe,GLint ye);

void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,300,0,300);

}

void setPixel(GLint xc,GLint yc){
    glBegin(GL_POINTS);
    glVertex2i(xc,yc);
    glEnd();
    glFlush();

}

void drawMyLine(){
    glPointSize(4);
    GLint x0=100;
    GLint y0=100;
    GLint xe=200;
    GLint ye=200;

    blda(x0,y0,xe,ye);
}

void blda(GLint x0,GLint y0,GLint xe,GLint ye){
    GLint dx=xe-x0;
    GLint dy=ye-y0;
    GLint twody=2*dy;
    GLint G=2*dy-dx;
    GLint twodymdx=2*(dy-dx);
    GLint x,y;

    if(x0>xe){
        x=xe;
        y=ye;
        xe=x;
    }
    else{
        x=x0;
        y=y0;
    }
    setPixel(x,y);

    while(x<xe){
        x++;
        if(G<0){
            G=G+twody;
        }
        else{
            y++;
            G=G+twodymdx;
        }
        setPixel(x,y);
    }
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("blda");
    init();
    glutDisplayFunc(drawMyLine);
    glutMainLoop();
}
