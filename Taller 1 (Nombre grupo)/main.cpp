#include <windows.h>
#include <GL/glut.h>

using namespace std;

void proyeccion()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-2, 4);
}

// *letter l 
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

void A1(){
//External Shape
    glVertex2f(-11, 0); glVertex2f(-11, 3);
    glVertex2f(-11, 3); glVertex2f(-8,3);
    glVertex2f(-8,3); glVertex2f(-8,0);
    glVertex2f(-11,0); glVertex2f(-10,0);
    glVertex2f(-8,0); glVertex2f(-9,0);
    glVertex2f(-10,0); glVertex2f(-10,0.6); 
    glVertex2f(-9,0); glVertex2f(-9,0.6);
    glVertex2f(-10,0.6); glVertex2f(-9,0.6);

//Internal Shape
    glVertex2f(-10,1); glVertex2f(-10,2.6);
    glVertex2f(-9,1); glVertex2f(-9,2.6);
    glVertex2f(-10,1); glVertex2f(-9,1);
    glVertex2f(-10,2.6); glVertex2f(-9,2.6);
}

void L2(){
    glVertex2f(-7,0); glVertex2f(-7,3);
    glVertex2f(-7,0); glVertex2f(-4,0);
    glVertex2f(-4,0); glVertex2f(-4,0.6);
    glVertex2f(-4,0.6); glVertex2f(-6,0.6);
    glVertex2f(-6,0.6); glVertex2f(-6,3);
    glVertex2f(-7,3); glVertex2f(-6,3);
}

void A2(){
//External Shape
    glVertex2f(-3, 0); glVertex2f(-3, 3);
    glVertex2f(-3, 3); glVertex2f(0,3);
    glVertex2f(0,3); glVertex2f(0,0);
    glVertex2f(-3,0); glVertex2f(-2,0);
    glVertex2f(0,0); glVertex2f(-1,0);
    glVertex2f(-2,0); glVertex2f(-2,0.6); 
    glVertex2f(-1,0); glVertex2f(-1,0.6);
    glVertex2f(-2,0.6); glVertex2f(-1,0.6);

//Internal Shape
    glVertex2f(-2,1); glVertex2f(-2,2.6);
    glVertex2f(-1,1); glVertex2f(-1,2.6);
    glVertex2f(-2,1); glVertex2f(-1,1);
    glVertex2f(-2,2.6); glVertex2f(-1,2.6);
}

void L3(){
    glVertex2f(1,0); glVertex2f(1,3);
    glVertex2f(1,0); glVertex2f(4,0);
    glVertex2f(4,0); glVertex2f(4,0.6);
    glVertex2f(4,0.6); glVertex2f(2,0.6);
    glVertex2f(2,0.6); glVertex2f(2,3);
    glVertex2f(1,3); glVertex2f(2,3);
}

void Ampersand(){
    //Bottom
    glVertex2f(5.5, 0); glVertex2f(7.5,0);
    glVertex2f(5, 0.6); glVertex2f(5.5,0.6);
    glVertex2f(7.5, 0.6); glVertex2f(8,0.6);
    glVertex2f(5.5, 0.6); glVertex2f(5.5,0);
    glVertex2f(7.5, 0.6); glVertex2f(7.5,0);
    //Top
    glVertex2f(5.5, 3); glVertex2f(7.5,3);
    glVertex2f(5, 2.4); glVertex2f(5.5,2.4);
    glVertex2f(7.5, 2.4); glVertex2f(8,2.4);
    glVertex2f(5.5, 2.4); glVertex2f(5.5,3);
    glVertex2f(7.5, 2.4); glVertex2f(7.5,3);
    //Left Bottom
    glVertex2f(5, 0.6); glVertex2f(5,1.5);
    glVertex2f(5, 1.5); glVertex2f(5.5,1.5);

    //left Top
    glVertex2f(5, 2.4); glVertex2f(5,1.8);
    glVertex2f(5, 1.8); glVertex2f(5.5,1.8);
    glVertex2f(5.5, 1.8); glVertex2f(5.5,1.5);

    //Right Bottom
    glVertex2f(7.5, 1.3); glVertex2f(8,1.3);
    glVertex2f(8, 1.1); glVertex2f(8,0.8);

    //Right Top
    glVertex2f(8, 2.4); glVertex2f(8,2);
    glVertex2f(8, 2); glVertex2f(7.5,2);
    glVertex2f(7.5, 2); glVertex2f(7.5,1.3);

    //Backside Bottom
    glVertex2f(8, 0); glVertex2f(9,0);
    glVertex2f(8, 0.8); glVertex2f(9,0.8);
    glVertex2f(9, 0.8); glVertex2f(9,0);
    glVertex2f(8, 0); glVertex2f(8,0.6);

    //Backside Top
    glVertex2f(8, 1.1); glVertex2f(9,1.1);
    glVertex2f(9, 1.1); glVertex2f(9,1.8);
    glVertex2f(9, 1.8); glVertex2f(8,1.8);
    glVertex2f(8, 1.8); glVertex2f(8,1.3);
}


void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    L1();
    A1();
    L2();
    A2();
    L3();
    Ampersand();
    glEnd();
    glFlush();
}


int main (int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500,350);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("El Cuerpo Humano");
    proyeccion();
    glutDisplayFunc(dibujar);
    glutMainLoop();
}
