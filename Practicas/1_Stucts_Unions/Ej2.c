#include <stdint.h>
#include <stdio.h>

/*
1- Piense una estructura para guardar los datos bancarios de una persona, estos son:
    - Nombre (max 20 caracteres)
    - nroCuenta  (4 numeros)
    - En caso de ser Argentino D.N.I. (10 digitos)
    - En caso de no ser Argentino Pasaporte (12 digitos alfanumericos) 
Utilize la menor cantidad de memoria posible

2- Inicalize los datos e imprima los valores

3-  a. Guarde datos de 4 personas en un archivo y 
    b. lealos

4- Idem 3 pero pida al usuario los datos (fgets)

*/

typedef struct {
    char nombre[20];
    short nroCuenta;
    short esArg;

    union id {
        char pasaporte[12];
        int dni;
    } id;
} datos_bancarios_t;

void printData(datos_bancarios_t persona1);
void writeFile(FILE* file, datos_bancarios_t persona);
void readFile(FILE* file);

int main() {
    FILE* file;
    file = fopen("nombres.bin", "wb+");
    if (file == NULL) {
        perror("Error, no exisiste el archivo");
        return 0;
    }

    datos_bancarios_t persona1 = {
        .nombre = "Juan",
        .nroCuenta = 1230,
        .esArg = 1,
        .id.dni = 40085741,
    };

    datos_bancarios_t persona2 = readUserInput();
    // printData(persona1);

    writeFile(file, persona1);
    writeFile(file, persona2);

    readFile(file);
    return 0;
}

void printData(datos_bancarios_t persona) {
    printf("Nombre:           %s\n", persona.nombre);
    printf("Numero de Cuenta: %d\n", persona.nroCuenta);
    if (persona.esArg) {
        printf("DNI:              %d\n\n", persona.id.dni);
    } else {
        printf("Pasaporte:        %s \n\n", persona.id.pasaporte);
    }
}

void writeFile(FILE* file, datos_bancarios_t persona) {
    fwrite(&persona, sizeof(persona), 1, file);
    return;
}

void readFile(FILE* file) {
    datos_bancarios_t persona;
    rewind(file);
    while (fread(&persona, sizeof(persona), 1, file) != 0) {
        printData(persona);
    }
}

datos_bancarios_t readUserInput() {
    datos_bancarios_t persona;

    printf("\nIngrese el Nombre:");
    fgets(&persona.nombre, sizeof(persona.nombre), stdin);

    printf("\nIngrese el numero de cuenta:");
    fgets(&persona.nombre, sizeof(persona.nombre), stdin);

    printf("\n Es argentino (1=si 0=no):");
    fgets(&persona.esArg, sizeof(persona.esArg), stdin);

    if (persona.esArg) {
        printf("\nIngrese el DNI:");
        fgets(&persona.id.dni, sizeof(persona.id.dni), stdin);
    } else {
        printf("\nIngrese el pasaporte:");
        fgets(&persona.id.pasaporte, sizeof(persona.id.pasaporte), stdin);
    }

    return persona;
}
