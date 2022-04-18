#include <windows.h>
#include <GL/glut.h>

using namespace std;

void proyeccion()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,15,-9,9);
}

void cabeza()
{
    glBegin (GL_LINES);
    glColor3f(0.0,0.7,0.0);

    glVertex2i(-1, 5); glVertex2i(-4, 5);
    glVertex2i(-4, 5); glVertex2i(-4, 8);
    glVertex2i(-4, 8); glVertex2i(4, 8);
    glVertex2i(4, 8); glVertex2i(4, 5);
    glVertex2i(4, 5); glVertex2i(1, 5);
}

void cuello()
{
    glVertex2i(-1, 4); glVertex2i(-1, 5);
    glVertex2i(1, 4); glVertex2i(1, 5);
}

void brazos ()
{
    //brazo izquierdo
    glVertex2i(-2, 3); glVertex2i(-12, 3);
    glVertex2i(-12, 3); glVertex2i(-12, 4);
    glVertex2i(-12, 4); glVertex2i(-1, 4);

    //brazo derecho
    glVertex2i(2, 3); glVertex2i(12, 3);
    glVertex2i(12, 3); glVertex2i(12, 4);
    glVertex2i(12, 4); glVertex2i(1, 4);
}

void torso()
{
    glVertex2i(-2, -2); glVertex2i(-2, 3);
    glVertex2i(2, -2); glVertex2i(2, 3);
}

void legs()
{
    //Left leg
    glVertex2i(-2, -2); glVertex2i(-6, -7);
    glVertex2i(0, -2); glVertex2i(-5, -8);

    //Right leg
    glVertex2i(2, -2); glVertex2i(6, -7);
    glVertex2i(0, -2); glVertex2i(5, -8);
}

void foots()
{
    //Left foot
    glVertex2i(-6, -7); glVertex2i(-9, -7);
    glVertex2i(-9, -7); glVertex2i(-9, -8);
    glVertex2i(-9, -8); glVertex2i(-5, -8);

    //Right foot
    glVertex2i(6, -7); glVertex2i(9, -7);
    glVertex2i(9, -7); glVertex2i(9, -8);
    glVertex2i(9, -8); glVertex2i(5, -8);
}

void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    cabeza();
    cuello();
    brazos();
    torso();
    legs();
    foots();
    glEnd();
    glFlush();
}


int main (int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("El Cuerpo Humano");
    proyeccion();
    glutDisplayFunc(dibujar);
    glutMainLoop();
}
