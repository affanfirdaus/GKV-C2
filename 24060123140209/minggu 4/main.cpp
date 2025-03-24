#include <GL/glut.h>

static int shoulder = 0, elbow = 0, hand = 0, finger = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Lengan atas
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Lengan bawah
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Telapak tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1.0, 0.4, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari-jari (satu blok mewakili jari-jari)
    glTranslatef(0.5, 0.2, 0.0);
    glRotatef((GLfloat)finger, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': shoulder = (shoulder + 5) % 360; break;
        case 'W': shoulder = (shoulder - 5) % 360; break;
        case 's': elbow = (elbow + 5) % 360; break;
        case 'S': elbow = (elbow - 5) % 360; break;
        case 'd': hand = (hand + 5) % 360; break;
        case 'D': hand = (hand - 5) % 360; break;
        case 'a': finger = (finger + 5) % 360; break;
        case 'A': finger = (finger - 5) % 360; break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan dengan Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

