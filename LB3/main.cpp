#include <windows.h>
#include <GL/glut.h>

/* Variables de uso general */ 
static int window;
static int submenu_shapes;
static int submenu_colors;
static int valueShapes = 0; 
static float n1 = 1.0, n2 = 1.0, n3 = 1.0;


void geometricMenu(int num){
    int valueColors;
    if (num > 0 && num < 9){ // Aloja el valor de la figura se proyectar.
        valueShapes = num;
    }else{ // Determina el valor de color que ocupará la figura geométrica.
        valueColors = num;
        switch (valueColors)
        {
            case 9:
            n1=1.0;n2=0.84;n3=0.0;
            break;

            case 10:
            n1=1.0;n2=0.0;n3=0.0;
            break;

            case 11:
            n1=0.0;n2=1.0;n3=0.0;
            break;

            case 12:
            n1=0.0;n2=0.0;n3=7.0;
            break;

            case 13:
            n1=0.20;n2=0.0;n3=0.40;
            break;

            case 14:
            n1=0.20;n2=0.10;n3=0.0;
            break;

            case 15:
            n1=1.0;n2=1.0;n3=1.0;
            break;

            case 16:
            n1=0.67;n2=0.0;n3=1.00;
            break;
        } 
    }
    glutPostRedisplay();
} 

void exit(){
    glutDestroyWindow(window); // Cierra la ventana.
    exit(0);
}

void createMenu(void){  
    int e; 
    submenu_shapes = glutCreateMenu(geometricMenu); //Opciones para el submenú "Figuras".
    glutAddMenuEntry("Cuadrado", 1);
    glutAddMenuEntry("Rectangulo", 2);
    glutAddMenuEntry("Triangulo", 3);
    glutAddMenuEntry("Cirulo", 4); 
    glutAddMenuEntry("Hexagono", 5); 
    glutAddMenuEntry("Anillo", 6); 
    glutAddMenuEntry("Flecha", 7); 
    glutAddMenuEntry("Cruz", 8);

    submenu_colors = glutCreateMenu(geometricMenu); // Opciones para el submenú "Colores".
    glutAddMenuEntry("Amarillo", 9);
    glutAddMenuEntry("Rojo", 10);
    glutAddMenuEntry("verde", 11);
    glutAddMenuEntry("Azul", 12); 
    glutAddMenuEntry("Morado", 13);
    glutAddMenuEntry("Marron", 14);
    glutAddMenuEntry("Blanco", 15);
    glutAddMenuEntry("Violeta", 16);

    glutCreateMenu(geometricMenu); // Se Crea el menú de opciones.
    e = glutCreateMenu(exit); // Cierre de ventana.

    // Opciones principales
    glutAddSubMenu("Figuras", submenu_shapes);
    glutAddSubMenu("Colores", submenu_colors);
    glutAddMenuEntry("Salida", e);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 


void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glColor3f(n1,n2,n3);
    switch (valueShapes) // Proyecta la figura dependiendo del valor asignado en la función geometricMenu.
    {
        case 1:
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.6); glVertex2f(-0.6, -0.6);
            glVertex2f(0.6, -0.6); glVertex2f(0.6, 0.6);
            glEnd();
        break;

        case 2:
            glBegin(GL_QUADS);
            glVertex2f(-0.8, 0.4); glVertex2f(-0.8, -0.4);
            glVertex2f(0.8, -0.4); glVertex2f(0.8, 0.4);
            glEnd();
        break;

        case 3:
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.6,-0.6);
            glVertex2f(0.6,-0.6);
            glVertex2f(0.0,0.6);
            glEnd();
        break;

        case 4:
            glPushMatrix();
            glutSolidSphere(0.6, 100, 100);
            glPopMatrix();
        break;

        case 5:
            glBegin(GL_POLYGON);
            glVertex2f(-0.7,0.0); glVertex2f(-0.3,0.6);
            glVertex2f(-0.3,0.6);glVertex2f(0.3,0.6);
            glVertex2f(0.3,0.6);glVertex2f(0.7,0.0);
            glVertex2f(0.7,0.0);glVertex2f(0.3,-0.6);
            glVertex2f(0.3,-0.6);glVertex2f(-0.3,-0.6);
            glEnd();
        break;

        case 6:
            glPushMatrix();
            glutSolidTorus(0.2, 0.5, 10, 50);
            glPopMatrix();
        break;

        case 7:
            glBegin(GL_TRIANGLES);
            glVertex2f(0.0,-0.4);
            glVertex2f(0.7,0.0);
            glVertex2f(0.0,0.4);
            glEnd();
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.2); glVertex2f(-0.6, -0.2);
            glVertex2f(0.0, -0.2); glVertex2f(0.0, 0.2);
            glEnd();
        break;

        case 8:
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.2); glVertex2f(-0.6, -0.2);
            glVertex2f(0.6, -0.2); glVertex2f(0.6, 0.2);
            glEnd();
            glBegin(GL_QUADS);
            glVertex2f(-0.2, 0.6); glVertex2f(-0.2, -0.6);
            glVertex2f(0.2, -0.6); glVertex2f(0.2, 0.6);
            glEnd();
        break;
    }
    glFlush(); // Termina los procesos de las funciones existentes.
} 

int main(int argc, char **argv){     
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Figuras Geometricas");
    glEnable(GL_DEPTH_TEST);
    createMenu();  
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);     
    glutMainLoop();
    return EXIT_SUCCESS;
}