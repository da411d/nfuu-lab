#include "windows.h"
#include "math.h"
#include "./glut.h"

#define _W 600
#define _H 600

float animate = 1.0f;
float camera = 5.0f;

float aToFloatSin(){
    return (sin(animate) + 1) / 2;
}
float aToFloatCos(){
    return (cos(animate) + 1) / 2;
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(aToFloatSin(), aToFloatCos(), 1 - (aToFloatSin() + aToFloatCos()) / 2.0f);
    glLoadIdentity();
    //Видова трансформація (камера)
    gluLookAt(
            0.0, 0.0, camera,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);
    //Модельна трансформація
    glScalef(1.0, 1.0, 1.0);
    glRotatef(cos(animate)*100, 1, 1, 1);
    glTranslatef(sin(animate), sin(animate), 0);
    glLineWidth(4);
    glutWireCube(1.0);
    glFlush();
}

// Зміна розмірів вікна
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
//    exit((int)key);
    switch(key){
        // CAMERA
        case 45: // -
            camera -= 0.1;
            break;

        case 61: // +
            camera += 0.1;
            break;

        // ANIMATION
        case 91: // [
            animate -= 0.05;
            break;

        case 93: // ]
            animate += 0.05;
            break;

        // EXIT
        case 27:
            exit(0);
            break;
    }

    display();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(_W, _H);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
