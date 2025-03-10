#include <GL/glut.h>

// Fungsi untuk menggambar berbagai bentuk dengan primitif OpenGL
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. GL_LINE_STRIP (Garis bersambung)
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-0.5f, 0.8f);
        glVertex2f(-0.3f, 0.6f);
    glEnd();

    // 2. GL_LINE_LOOP (Garis membentuk poligon tertutup)
    glColor3f(0.0f, 1.0f, 0.0f); // Hijau
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.5f, 0.8f);
        glVertex2f(0.7f, 0.6f);
        glVertex2f(0.5f, 0.4f);
    glEnd();

    // 3. GL_TRIANGLE_FAN (Kipas segitiga)
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.5f, 0.0f); // Pusat kipas
        glVertex2f(-0.7f, -0.2f);
        glVertex2f(-0.5f, -0.4f);
        glVertex2f(-0.3f, -0.2f);
    glEnd();

    // 4. GL_TRIANGLE_STRIP (Strip segitiga)
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.7f, -0.2f);
    glEnd();

    // 5. GL_QUADS (Persegi)
    glColor3f(1.0f, 0.5f, 0.0f); // Jingga
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, -0.8f);
        glVertex2f(-0.8f, -0.6f);
        glVertex2f(-0.6f, -0.6f);
        glVertex2f(-0.6f, -0.8f);
    glEnd();

    // 6. GL_QUAD_STRIP (Strip Persegi)
    glColor3f(0.5f, 0.0f, 0.5f); // Ungu
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.2f, -0.8f);
        glVertex2f(0.2f, -0.6f);
        glVertex2f(0.4f, -0.8f);
        glVertex2f(0.4f, -0.6f);
        glVertex2f(0.6f, -0.8f);
        glVertex2f(0.6f, -0.6f);
    glEnd();

    glFlush();
}

// Fungsi inisialisasi
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Primitif OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

