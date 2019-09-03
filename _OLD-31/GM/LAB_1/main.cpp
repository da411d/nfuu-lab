#include "windows.h"
#include "./glut.h"
#define _W 600
#define _H 600

float _x(float x){
    return (x / _W) * 2 - 1;
}
float _y(float y){
    return (-y / _H) * 2 + 1;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_POLYGON_SMOOTH);

    glLineWidth(4);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f (_x(10), _y(10));
    glVertex2f (_x(10), _y(40));
    glVertex2f (_x(40), _y(40));
    glVertex2f (_x(40), _y(10));
    glEnd();
    glFlush();

    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);
    for(int i = 0; i<20; i++){
        glVertex2f(_x(50 + i), _y(10+i));
        glVertex2f(_x(50 + i*2), _y(10+i));
    }
    glEnd();
    glFlush();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(_x(100), _y(20));
    glVertex2f(_x(140), _y(20));
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(_x(160), _y(40));
    glVertex2f(_x(180), _y(10));
    glVertex2f(_x(200), _y(40));
    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(_x(210), _y(10));
    glVertex2f(_x(230), _y(40));
    glVertex2f(_x(250), _y(10));
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(_x(260), _y(10));
    glVertex2f(_x(280), _y(40));
    glVertex2f(_x(300), _y(10));
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(_x(160), _y(40));
    glVertex2f(_x(180), _y(10));
    glVertex2f(_x(200), _y(40));
    glEnd();
    glFlush();




    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(_x(150), _y(60));
    glVertex2f(_x(550), _y(60));
    glVertex2f(_x(480), _y(180));
    glVertex2f(_x(80), _y(180));
    glVertex2f(_x(150), _y(60));
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(_x(80), _y(180));
    glVertex2f(_x(20), _y(540));
    glVertex2f(_x(430), _y(540));
    glVertex2f(_x(500), _y(430));
    glVertex2f(_x(550), _y(60));
    glVertex2f(_x(480), _y(180));
    glVertex2f(_x(430), _y(540));
    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    glLineWidth(GLfloat(6));
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(_W, _H);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
