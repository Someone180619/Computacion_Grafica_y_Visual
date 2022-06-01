#include <windows.h>
#include <stdio.h>
#include<string.h>
#include <GL/glut.h>
#include <math.h>
#define PI=3.14159265358979323846;


void draw_circle(float x, float y, float radio);
float move_cloud=0;
float move_dust=0;

void Pista(){
 glBegin(GL_QUADS);  //cesped
    glColor3ub(51, 128, 0);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glColor3ub(35, 87, 0);
    glVertex2i(1000, 300);
    glVertex2i(0, 300);
    glEnd();

    glBegin(GL_QUADS);  //pista
    glColor3ub(50, 50, 50);
    glVertex2i(0, 50);
    glVertex2i(1000, 50);
    glColor3ub(0, 0, 0);
    glVertex2i(1000, 270);
    glVertex2i(0, 270);
    glEnd();

    glBegin(GL_QUADS);  //Lineas amarillas
    glColor3ub(255, 254, 17);
    glVertex2i(10, 180);
    glVertex2i(100, 180);
    glVertex2i(100, 200);
    glVertex2i(10, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(150, 180);
    glVertex2i(240, 180);
    glVertex2i(240, 200);
    glVertex2i(150, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(380, 180);
    glVertex2i(290, 180);
    glVertex2i(290, 200);
    glVertex2i(380, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(390, 180);
    glVertex2i(340, 180);
    glVertex2i(340, 200);
    glVertex2i(390, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(530, 180);
    glVertex2i(440, 180);
    glVertex2i(440, 200);
    glVertex2i(530, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(670, 180);
    glVertex2i(580, 180);
    glVertex2i(580, 200);
    glVertex2i(670, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(810, 180);
    glVertex2i(720, 180);
    glVertex2i(720, 200);
    glVertex2i(810, 200);
    //
    glColor3ub(255, 254, 17);
    glVertex2i(950, 180);
    glVertex2i(860, 180);
    glVertex2i(860, 200);
    glVertex2i(950, 200);
    glEnd();
}

void DrawCloud(){
    ///==================================== Creacion de estrellas
    //Estrella modelo
    glColor3f(255, 251, 0); //Amarillo
    draw_circle(140+move_cloud,750,10);
    glColor3f(0.0,0.1,0.23); //Azul
    draw_circle(149+move_cloud,759,10);
    draw_circle(149+move_cloud,740,10);
    draw_circle(130+move_cloud,740,10);
    draw_circle(130+move_cloud,759,10);


}
void edificio(){

}

void DrawCity()
{
    ///================================= Creacion de la luna

    glColor3f(1.0,0.99,0.81);   //color
    draw_circle(500, 800,70);
    glColor3f(0.0,0.1,0.23);   //azul color
    draw_circle(560, 800,70);


    edificio();
    DrawCloud();
    Pista();
}

void myDisplay(void)
{
    glClearColor(0.0,0.1,0.23,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    DrawCity();
    DrawCloud();
    Pista();
    glEnd();
    glFlush ();
}

void Dibujar (void)
{
    glClearColor(0.0,0.7,1.5,0.0);  //color del cielo
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}


void draw_circle(float x, float y, float radio) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angulo = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angulo1=0.0;
    glVertex2d(radio * cos(0.0) , radio * sin(0.0));
    for (int i=0; i<circle_points; i++)
    {
        glVertex2d(radio * cos(angulo1), radio *sin(angulo1));
        angulo1 += angulo;
    }
    glEnd();
    glPopMatrix();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (10,50);
    glutCreateWindow ("Taller2 - Paisaje Libre" );
    glutDisplayFunc(myDisplay);
    Dibujar();
    glutMainLoop();
}