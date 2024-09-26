#include "bmp.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

BMPImage *image;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (image)
    {
        drawBMP(image);
    }
    glFlush();
}

int main(int argc, char **argv)
{
    // Verificar si se ha pasado un argumento (nombre del archivo)
    if (argc < 3)
    {
        printf("Uso: %s <nombre_archivo_bmp>\n", argv[0]);
        return 1;
    }
    // Intentar cargar el archivo BMP
    const char *filename = argv[1];
    image = readBMP(filename);
    if (!image)
    {
        printf("Error: No se pudo cargar el archivo BMP o el archivo no es válido.\n");
        return 1;
    }
    int opcionFiltro = atoi(argv[2]);
    // Menú para seleccionar el filtro a aplicar
    /*printf("Ingrese el filtro a aplicar:\n");
    printf("1) Imagen en NORMAL\n");
    printf("2) Imagen en ESCALA DE GRISES\n");
    printf("3) Imagen en NEGATIVO\n");*/
    //scanf("%d", &opcionFiltro);

    // Aplicar el filtro seleccionado
    switch (opcionFiltro)
    {
    case 1:
        // No hacer nada, mantener la imagen original
        break;
    case 2:
        // Convertir a escala de grises
        for (int i = 0; i < image->width * image->height * 3; i += 3)
        {
            unsigned char r = image->data[i];
            unsigned char g = image->data[i + 1];
            unsigned char b = image->data[i + 2];
            unsigned char gray = (r + g + b) / 3;
            image->data[i] = gray;
            image->data[i + 1] = gray;
            image->data[i + 2] = gray;
        }
        break;
    case 3:
        // Convertir a negativo
        for (int i = 0; i < image->width * image->height * 3; i += 3)
        {
            image->data[i] = 255 - image->data[i];
            image->data[i + 1] = 255 - image->data[i + 1];
            image->data[i + 2] = 255 - image->data[i + 2];
        }
        break;
    default:
        printf("Opción no válida, mostrando imagen original.\n");
        break;
    }

    // Inicializar GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(image->width, image->height);
    glutCreateWindow("Visualizador de BMP");

    // Configurar proyección ortográfica
    glLoadIdentity();
    glOrtho(0, image->width, image->height, 0, -1, 1);

    // Establecer función de display
    glutDisplayFunc(display);
    glutMainLoop();

    // Liberar memoria de la imagen BMP
    freeBMP(image);

    return 0;
}
