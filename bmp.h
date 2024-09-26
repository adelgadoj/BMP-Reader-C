#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned char header[54]; // Encabezado del BMP
  unsigned int width;       // Ancho de la imagen
  unsigned int height;      // Altura de la imagen
  unsigned char *data;      // Datos de la imagen
} BMPImage;

BMPImage* readBMP(const char *filename);
void freeBMP(BMPImage *image);
void drawBMP(BMPImage *image);

#endif // BMP_H
