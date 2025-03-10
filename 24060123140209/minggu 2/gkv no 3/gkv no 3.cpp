#include <GL/glut.h>

// Fungsi untuk menggambar satu kubus pada posisi tertentu
void drawCube(float x, float y, float z, float size) {
    glBegin(GL_QUADS);

    // Sisi Depan
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glVertex3f(x, y, z);
    glVertex3f(x + size, y, z);
    glVertex3f(x + size, y + size, z);
    glVertex3f(x, y + size, z);

    // Sisi Belakang
    glColor3f(0.0f, 1.0f, 0.0f); // Hijau
    glVertex3f(x, y, z - size);
    glVertex3f(x + size, y, z - size);
    glVertex3f(x + size, y + size, z - size);
    glVertex3f(x, y + size, z - size);

    // Sisi Kiri
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glVertex3f(x, y, z);
    glVertex3f(x, y, z - size);
    glVertex3f(x, y + size, z - size);
    glVertex3f(x, y + size, z);

    // Sisi Kanan
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glVertex3f(x + size, y, z);
    glVertex3f(x + size, y, z - size);
    glVertex3f(x + size, y + size, z - size);
    glVertex3f(x + size, y + size, z);

    // Sisi Atas
    glColor3f(1.0f, 0.0f, 1.0f); // Ungu
    glVertex3f(x, y + size, z);
    glVertex3f(x + size, y + size, z);
    glVertex3f(x + size, y + size, z - size);
    glVertex3f(x, y + size, z - size);

    // Sisi Bawah
    glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
    glVertex3f(x, y, z);
    glVertex3f(x + size, y, z);
    glVertex3f(x + size, y, z - size);
    glVertex3f(x, y, z - size);

    glEnd();
}

// Fungsi untuk menampilkan beberapa kubus bertingkat
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-0.5f, -1.0f, -5.0f); // Geser posisi tampilan

    // Gambar 5 kubus bertingkat
    for (int i = 0; i < 5; i++) {
        drawCube(0.0f, i * 0.6f, 0.0f, 0.5f); // Menaikkan posisi setiap kubus
    }

    glutSwapBuffers();
}

// Inisialisasi OpenGL
void init() {
    glEnable(GL_DEPTH_TEST); // Aktifkan depth buffer untuk tampilan 3D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 10.0f); // Perspektif kamera
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kubus Bertingkat OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

