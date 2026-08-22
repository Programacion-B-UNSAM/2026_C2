#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ARCHIVO "cuentas.bin"

#define CUENTA_MAX 99999999ULL /* 12 digitos */

#define BIT_ARG 31                    /* bit donde guardamos la bandera */
#define MASCARA_ARG (1ULL << BIT_ARG) /* 1000 0000 ... 0000 */
#define MASCARA_CUENTA (~MASCARA_ARG) /* 0111 1111 ... 1111 */

typedef struct
{
  char nombre[20];

  /* bits 0..62 -> numero de cuenta
     bit 63     -> 1 = argentino, 0 = extranjero          */
  uint32_t nroCuenta;

  union id
  {
    char pasaporte[13]; /* 12 alfanumericos + '\0' */
    uint32_t dni;       /* hasta 10 digitos        */
  } id;
} datos_bancarios_t;

void printBinario(uint64_t dato)
{
  printf("0b");
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (dato >> i) & 0b1);
    if ((i % 4 == 0))
      printf(" ");
  }
  printf("\n");
  return;
}

uint32_t hacerArg(datos_bancarios_t persona)
{
  return persona.nroCuenta | MASCARA_ARG; /* prende el bit 32 */
}

/* Devuelve solo el numero de cuenta (sin info de argentinidad) */
uint32_t obtenerCuenta(uint32_t campo)
{
  return campo & MASCARA_CUENTA;
}

/* Devuelve 1 o 0 segun el estado del bit 32 */
int esArgentino(uint32_t campo)
{
  return (campo >> BIT_ARG) & 1;
}

void mostrarPersona(datos_bancarios_t persona)
{
  printf("\nNombre:           %s\n", persona.nombre);
  printf("Numero de Cuenta: %llu\n", obtenerCuenta(persona.nroCuenta));

  if (esArgentino(persona.nroCuenta))
  {
    printf("Nacionalidad:     Argentina\n");
    printf("DNI:              %llu\n", persona.id.dni);
  }
  else
  {
    printf("Nacionalidad:     Extranjera\n");
    printf("Pasaporte:        %s\n", persona.id.pasaporte);
  }

  printf("Cuenta bin:       ");
  printBinario(persona.nroCuenta);
  printf("\n");
}

int main(void)
{
  /* Un arreglo garantiza que personas[1] esta pegado a personas[0].
     No es suerte del compilador: el estandar exige que sean contiguos. */
  datos_bancarios_t personas[2] = {
      [0] = {.nombre = "Juan", .nroCuenta = 1230, .id.dni = 40085741},
      [1] = {.nombre = "Maria", .nroCuenta = 4560, .id.pasaporte = "ABCDEF"},
  };

  personas[0].nroCuenta = hacerArg(personas[0]);

  mostrarPersona(personas[0]);
  mostrarPersona(personas[1]);

  return 0;
}
