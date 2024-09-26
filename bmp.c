#include "bmp.h"
#include <GL/glut.h>

BMPImage* readBMP(const char *filename) {
  BMPImage *image = malloc(sizeof(BMPImage));
  FILE *file = fopen(filename, "rb");

  if (!file) {
    fprintf(stderr, "No se puede abrir el archivo %s\n", filename);
    free(image);
    return NULL;
  }

  fread(image->header, sizeof(unsigned char), 54, file);
  image->width = *(int*)&image->header[18];
  image->height = *(int*)&image->header[22];

  image->data = malloc(image->width * image->height * 3); // 3 bytes por píxel
  fread(image->data, sizeof(unsigned char), image->width * image->height * 3, file);
  fclose(file);

  return image;
}

void freeBMP(BMPImage *image) {
  free(image->data);
  free(image);
}

void drawBMP(BMPImage *image) {
  glDrawPixels(image->width, image->height, GL_BGR, GL_UNSIGNED_BYTE, image->data);
}
