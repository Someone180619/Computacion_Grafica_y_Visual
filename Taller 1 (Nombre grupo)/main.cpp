#include <windows.h>
#include <GL/glut.h>

using namespace std;

void proyeccion()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-2, 4);
}

void L1()
{
    glBegin (GL_LINES);
    glColor3f(0.0,0.7,0.0);

    glVertex2i(-15, 3); glVertex2i(-15, 0);
    glVertex2i(-15, 0); glVertex2i(-12, 0);
    glVertex2i(-12, 0); glVertex2f(-12, 0.6);
    glVertex2f(-12, 0.6); glVertex2f(-14, 0.6);
    glVertex2f(-14, 0.6); glVertex2i(-14, 3);
    glVertex2i(-14, 3); glVertex2i(-15, 3);
}

void A1()
{
    //Figura exterior
    glVertex2f(-10, 3); glVertex2f(-11.5, 0);
    glVertex2f(-11.5, 0); glVertex2f(-10.5, 0);
    glVertex2f(-10.5, 0); glVertex2f(-10.5, 0.5);
    glVertex2f(-10.5, 0.5); glVertex2f(-9.5, 0.5);
    glVertex2f(-9.5, 0.5); glVertex2f(-9.5, 0);
    glVertex2f(-9.5, 0); glVertex2f(-8.5, 0);
    glVertex2f(-8.5, 0); glVertex2f(-10, 3);

    //Figura interna
    glVertex2f(-10, 2); glVertex2f(-10.5, 0.8);
    glVertex2f(-10.5, 0.8); glVertex2f(-9.5, 0.8);
    glVertex2f(-9.5, 0.8); glVertex2f(-10, 2);
}

void L2()
{
    glVertex2f(-7.5, 3); glVertex2f(-7.5, 0);
    glVertex2f(-7.5, 0); glVertex2f(-4.5, 0);
    glVertex2f(-4.5, 0); glVertex2f(-4.5, 0.6);
    glVertex2f(-4.5, 0.6); glVertex2f(-6.5, 0.6);
    glVertex2f(-6.5, 0.6); glVertex2f(-6.5, 3);
    glVertex2f(-6.5, 3); glVertex2f(-7.5, 3);
}

void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    L1();
    A1();
    L2();

    glEnd();
    glFlush();
}


int main (int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,350);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("El Cuerpo Humano");
    proyeccion();
    glutDisplayFunc(dibujar);
    glutMainLoop();
}
