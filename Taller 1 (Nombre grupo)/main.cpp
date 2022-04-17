#include <windows.h>
#include <GL/glut.h>

using namespace std;
void projection()
{
    glClearColor(0.0,0.0,0.0,2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-1,4);
}

void lettersL()
{
    glBegin (GL_LINES);
    glColor3f(1.0,1.0,1.0);
    //L1
    glVertex2i(-15, 3); glVertex2i(-15, 0);
    glVertex2i(-15, 0); glVertex2i(-12, 0);
    glVertex2i(-12, 0); glVertex2f(-12, 0.6);
    glVertex2f(-12, 0.6); glVertex2f(-14, 0.6);
    glVertex2f(-14, 0.6); glVertex2i(-14, 3);
    glVertex2i(-14, 3); glVertex2i(-15, 3);

    //L2
    glVertex2f(-7,0); glVertex2f(-7,3);
    glVertex2f(-7,0); glVertex2f(-4,0);
    glVertex2f(-4,0); glVertex2f(-4,0.6);
    glVertex2f(-4,0.6); glVertex2f(-6,0.6);
    glVertex2f(-6,0.6); glVertex2f(-6,3);
    glVertex2f(-7,3); glVertex2f(-6,3);

    //L3
    glVertex2f(1,0); glVertex2f(1,3);
    glVertex2f(1,0); glVertex2f(4,0);
    glVertex2f(4,0); glVertex2f(4,0.6);
    glVertex2f(4,0.6); glVertex2f(2,0.6);
    glVertex2f(2,0.6); glVertex2f(2,3);
    glVertex2f(1,3); glVertex2f(2,3);
}

void lettersA(){

//A1

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

//A2

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

void ampersands(){
    glColor3f(1.0,1.0,0.0);
//Ampersand 1

//Bottom
    glVertex2f(5, 0); glVertex2f(7,0);
    glVertex2f(4.5, 0.6); glVertex2f(5,0.6);
    glVertex2f(7, 0.6); glVertex2f(7.5,0.6);
    glVertex2f(5, 0.6); glVertex2f(5,0);
    glVertex2f(7, 0.6); glVertex2f(7,0);

//Top
    glVertex2f(5, 3); glVertex2f(7,3);
    glVertex2f(4.5, 2.4); glVertex2f(5,2.4);
    glVertex2f(7, 2.4); glVertex2f(7.5,2.4);
    glVertex2f(5, 2.4); glVertex2f(5,3);
    glVertex2f(7, 2.4); glVertex2f(7,3);

//Left Bottom
    glVertex2f(4.5, 0.6); glVertex2f(4.5,1.5);
    glVertex2f(4.5, 1.5); glVertex2f(5,1.5);

//Right Top
    glVertex2f(4.5, 2.4); glVertex2f(4.5,1.8);
    glVertex2f(4.5, 1.8); glVertex2f(5,1.8);
    glVertex2f(5, 1.8); glVertex2f(5,1.5);

//Right Bottom
    glVertex2f(7, 1.3); glVertex2f(7.5,1.3);
    glVertex2f(7.5, 1.1); glVertex2f(7.5,0.8);

//Right Top
    glVertex2f(7.5, 2.4); glVertex2f(7.5,2);
    glVertex2f(7.5, 2); glVertex2f(7,2);
    glVertex2f(7, 2); glVertex2f(7,1.3);

//Backside Bottom
    glVertex2f(7.5, 0); glVertex2f(8,0);
    glVertex2f(7.5, 0.8); glVertex2f(8,0.8);
    glVertex2f(8, 0.8); glVertex2f(8,0);
    glVertex2f(7.5, 0); glVertex2f(7.5,0.6);

//Backside Top
    glVertex2f(7.5, 1.1); glVertex2f(8,1.1);
    glVertex2f(8, 1.1); glVertex2f(8,1.8);
    glVertex2f(8, 1.8); glVertex2f(7.5,1.8);
    glVertex2f(7.5, 1.8); glVertex2f(7.5,1.3);

//Bottom Square
    glVertex2f(5.4, 0.7); glVertex2f(6.7,0.7);
    glVertex2f(5.4, 1.4); glVertex2f(6.7,1.4);
    glVertex2f(5.4, 0.7); glVertex2f(5.4,1.4);
    glVertex2f(6.7, 0.7); glVertex2f(6.7,1.4);

//Top Square
    glVertex2f(5.5, 2.4); glVertex2f(6.5,2.4);
    glVertex2f(5.5, 1.8); glVertex2f(6.5,1.8);
    glVertex2f(5.5, 2.4); glVertex2f(5.5,1.8);
    glVertex2f(6.5, 2.4); glVertex2f(6.5,1.8);

//Ampersand 2

//Bottom
    glVertex2f(8.5, 0); glVertex2f(10.5,0);
    glVertex2f(8, 0.6); glVertex2f(8.5,0.6);
    glVertex2f(10.5, 0.6); glVertex2f(11,0.6);
    glVertex2f(8.5, 0.6); glVertex2f(8.5,0);
    glVertex2f(10.5, 0.6); glVertex2f(10.5,0);

//Top
    glVertex2f(8.5, 3); glVertex2f(10.5,3);
    glVertex2f(8, 2.4); glVertex2f(8.5,2.4);
    glVertex2f(10.5, 2.4); glVertex2f(11,2.4);
    glVertex2f(8.5, 2.4); glVertex2f(8.5,3);
    glVertex2f(10.5, 2.4); glVertex2f(10.5,3);

//Left Bottom
    glVertex2f(8, 0.6); glVertex2f(8,1.5);
    glVertex2f(8, 1.5); glVertex2f(8.5,1.5);

//Right Top
    glVertex2f(8, 2.4); glVertex2f(8,1.8);
    glVertex2f(8, 1.8); glVertex2f(8.5,1.8);
    glVertex2f(8.5, 1.8); glVertex2f(8.5,1.5);

//Right Bottom
    glVertex2f(10.5, 1.3); glVertex2f(11,1.3);
    glVertex2f(11, 1.1); glVertex2f(11,0.8);

//Right Top
    glVertex2f(11, 2.4); glVertex2f(11,2);
    glVertex2f(11, 2); glVertex2f(10.5,2);
    glVertex2f(10.5, 2); glVertex2f(10.5,1.3);

//Backside Bottom
    glVertex2f(11, 0); glVertex2f(11.5,0);
    glVertex2f(11, 0.8); glVertex2f(11.5,0.8);
    glVertex2f(11.5, 0.8); glVertex2f(11.5,0);
    glVertex2f(11, 0); glVertex2f(11,0.6);

//Backside Top
    glVertex2f(11, 1.1); glVertex2f(11.5,1.1);
    glVertex2f(11.5, 1.1); glVertex2f(11.5,1.8);
    glVertex2f(11.5, 1.8); glVertex2f(11,1.8);
    glVertex2f(11, 1.8); glVertex2f(11,1.3);

//Bottom Square
    glVertex2f(8.9, 0.7); glVertex2f(10.2,0.7);
    glVertex2f(8.9, 1.4); glVertex2f(10.2,1.4);
    glVertex2f(8.9, 0.7); glVertex2f(8.9,1.4);
    glVertex2f(10.2, 0.7); glVertex2f(10.2,1.4);

//Top Square
    glVertex2f(9, 2.4); glVertex2f(10,2.4);
    glVertex2f(9, 1.8); glVertex2f(10,1.8);
    glVertex2f(9, 2.4); glVertex2f(9,1.8);
    glVertex2f(10, 2.4); glVertex2f(10,1.8);
}

void letterS(){
    glColor3f(1.0,1.0,1.0);
//Bottom
    glVertex2f(12, 0); glVertex2f(14.8,0);
    glVertex2f(12, 0.6); glVertex2f(12.8,0.6);
    glVertex2f(12, 0); glVertex2f(12,0.6);
    glVertex2f(12.8, 0.4); glVertex2f(12.8,0.6);
    glVertex2f(12.8, 0.4); glVertex2f(14,0.4);

//Right Bottom
    glVertex2f(14, 0.4); glVertex2f(14,1.4);
    glVertex2f(14.8, 0); glVertex2f(14.8,1.8);

//Top
    glVertex2f(12, 3); glVertex2f(14.8,3);
    glVertex2f(12.8, 2.6); glVertex2f(14,2.6);
    glVertex2f(14, 2.6); glVertex2f(14,2.4);
    glVertex2f(14.8, 3); glVertex2f(14.8,2.4);
    glVertex2f(14, 2.4); glVertex2f(14.8,2.4);

//Left Top
    glVertex2f(12.8, 1.8); glVertex2f(12.8,2.6);
    glVertex2f(12, 1.4); glVertex2f(12,3);

//Center
    glVertex2f(12, 1.4); glVertex2f(14,1.4);
    glVertex2f(14.8, 1.8); glVertex2f(12.8,1.8);
}

void lines(){
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-15.6, -0.5); glVertex2f(15.6,-0.5);
    glVertex2f(-15.6, 3.5); glVertex2f(15.6,3.5);
    glVertex2f(-15.6, 3.5); glVertex2f(-15.6,-0.5);
    glVertex2f(15.6, 3.5); glVertex2f(15.6,-0.5);
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  
    glLineWidth(4.0);
    lettersL();
    lettersA();
    ampersands();
    letterS();
    lines();
    glEnd();
    glFlush();
}


int main (int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,350);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Group Name");
    projection();
    glutDisplayFunc(draw);
    glutMainLoop();
}
