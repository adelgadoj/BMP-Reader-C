# Visualizador de Imágenes BMP: Usando Structs para Formatear Bytes

## Objetivo

Este proyecto tiene como objetivo demostrar cómo utilizar `structs` en C para dar formato a un grupo de bytes y facilitar la interpretación de archivos BMP. A través de este ejercicio, se muestra cómo los `structs` pueden organizar datos binarios de manera efectiva. La visualización de la imagen mediante OpenGL es una herramienta adicional para motivar y facilitar la comprensión de cómo funcionan los `structs`.

## Requisitos

Antes de compilar y ejecutar el proyecto, asegúrate de tener instaladas las siguientes bibliotecas:

1. **OpenGL**
2. **GLUT** (o GLFW, según tu preferencia)

Para instalar las bibliotecas necesarias en un sistema basado en Debian/Ubuntu, puedes usar los siguientes comandos:

```bash
sudo apt-get update
sudo apt-get install freeglut3 freeglut3-dev
sudo apt-get install libglfw3-dev
```

## Estructura del Proyecto

El proyecto consta de los siguientes archivos:

- **`bmp.h`**: Contiene las declaraciones de las estructuras y funciones para manejar archivos BMP.
- **`bmp.c`**: Implementa las funciones para leer archivos BMP y gestionar los datos de la imagen.
- **`main.c`**: Punto de entrada del programa que inicializa la ventana OpenGL y dibuja la imagen.
- **`Makefile`**: Archivo de construcción que facilita la compilación del proyecto.
- **`Lenna.bmp`**: Ejemplo de imagen bmp de 24 bits.

## Compilación

Para compilar el proyecto, simplemente ejecuta el siguiente comando en la terminal dentro del directorio del proyecto:

```bash
make
```

Esto generará un ejecutable llamado `bmpReader`.

## Ejecución

Una vez compilado, puedes ejecutar el programa con el siguiente comando, proporcionando el nombre del archivo BMP como argumento:

```bash
./bmpReader nombre_imagen.bmp
```

Asegúrate de que el archivo `nombre_imagen.bmp` esté en el mismo directorio que el ejecutable para que el programa pueda cargarlo.

## Funcionamiento

Al ejecutar el programa, se abrirá una ventana que muestra la imagen BMP cargada. Cada píxel de la imagen se dibuja como un cuadrado en la ventana, lo que permite observar cómo se utilizan los `structs` para organizar y dar formato a los datos de la imagen.

## Ejercicios

1. **Extensión del Proyecto**: Modifica el código para que el nombre del archivo BMP sea recibido como un argumento en la línea de comandos. Asegúrate de manejar correctamente los errores en caso de que el archivo no se encuentre o no sea un BMP válido.
   
2. **Blanco y Negro `promedio de colores`**: Modifica el código para que se muestra la imagen en sólo blanco y negro, si se le da una opción especial al momento de llamar al programa en la línea de comandos.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.
