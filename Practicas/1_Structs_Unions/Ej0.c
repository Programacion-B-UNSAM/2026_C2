#include <stdio.h>
#include <string.h>

struct personaStruct {
    char nombre[50];
    int edad;
    float altura;
};

union personaUnion {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    union personaUnion persona1;

    strcpy(persona1.nombre, "Joaquin");
    persona1.edad = 32;
    persona1.altura = 1.80;

    // Init
    struct personaStruct persona2 = {"Jorge", 21, 1.65};
    // struct personaStruct persona3 = {
    //     .nombre = "Jorge",
    //     .edad = 40,
    //     .altura = 1.9,
    // };

    printf("\n\n");

    // printf("Nombre: %s \n", persona1.nombre);
    // printf("Altura: %f \n", persona1.altura);
    // printf("Edad:   %d \n", persona1.edad);

    printf("Union:    %ld bytes\n", sizeof(persona1));
    printf("Struct:   %ld bytes\n", sizeof(persona2));

    printf("\n\n");
    return 0;
}
