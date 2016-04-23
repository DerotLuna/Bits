#include <stdio.h>
#include <stdlib.h>
/*
 * Proyecto 1
 *
 * Ruben Dario Luna Materan C.I.: 25.217437
 *  Brian Amaya C.I.:  25.213.842
 *
 */

#if 0
/*
 * Instrucciones:
 *
 * PASO 1: Lea las siguientes instrucciones detenidamente.


  Reglas para los rompecabezas de enteros:

  Remplace el "return" en cada funcion con una o mas lineas de
  codigo que implemente la funcion. Su codigo debe seguir el
  siguiente estilo:

  int Funct(arg1, arg2, ...) {
      /* breve descripcion de como funciona su implementacion */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Cada "Expr" debe ser definida usando solo lo siguiente:
  1. las constantes de enteros deben estar en el rango [0,255]
  o [0x00,0xFF].
  2. Argumentos de la funcion y variables locales.
  3. operadores unarios ! ~
  4. Operadores binarios & ^ | + << >>

  Algunos rompecabezas pueden restringir mas esta lista
  cada "Expr" puede ser conformada por mas de un operador

  Esta prohibido el uso de lo siguiente:
  1. el uso de estructuras de control como condicionales y ciclos.
  2. el uso de Define o algun macro.
  3. Definir o crear alguna funcion adicional en este archivo.
  4. Llamar a funciones.
  5. El uso de otros operadores como &&, ||, -, or ?:
  6. cualquier forma de "casting".
  7. El uso de cualquier otro tipo de dato distinto a int, asi   tambien el uso de arreglos, registros o uniones.

  Puede asumir lo siguiente:
  1. Se usa complemento a 2, y la representacion de los enteros es de 32 bits
  2. Los desplazamientos son aritmeticos

EJEMPLOS DE FUNCIONES ACEPTADAS:
  /*
   * pow2plus1 - retorna 2^x + 1, donde 0 <= x = 31
   */
  int pow2plus1(int x)
  {
     /* Explota la capacidadd de los desplazamientos para
        calcular las potencias de 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - retorna 2^x + 4, donde 0 <= x <= 31
   */
  int pow2plus4(int x)
  {
     /* Explota la capacidadd de los desplazamientos para
        calcular las potencias de 2 */
     int resultado = (1 << x);
     resultado += 4;
     return resultado;
  }


NOTAS: Cada funciï¿½n tiene una cantidad maxima de operandos que pueden utilizar para su implementaciï¿½n de la funcion.  Note que el operador de asignacion "=" no cuenta.

REGLAS PARA LOS ROMPECABEZAS DE PUNTO FLOTANTE
Para los problemas que requiera que implemente operaciones de punto flotantes
las reglas son menos extrictas. Esta permitido el uso de ciclos y condicionales, tambien puede usar enteros y unsigneds a voluntad.

Esta prohibido el uso de lo siguiente:
  1. El uso de Define o algun macro.
  2. Definir o crear algua funcion adicional en este archivo.
  3. Llamar a funciones.
  4. cualquier forma de "casting".
  5. El uso de cualquier otro tipo de dato distinto a int o unsigned, asi como tambien el uso de
     arreglos, registros o uniones.
  6. El uso de cualquier tipo de dato flotante (float y double) asi como tambien operaciones o constantes de estos.

/*
 * PASO 2: Modificar las siguientes funciones de acuerdo a las reglas.
 */


#endif

/*
 * bitAnd - x&y usando solo ~ and |
 *   Ejemplo: bitAnd(6, 5) = 4
 *   Operaciones permitidas: ~ |
 *   Cantidad maxima de operaciones: 8
 *   Dificultad: 1
 */
int bitAnd(int x, int y)
{
  return ~(~x | ~y);
}
/*
 * bitXor - x^y usando solo ~ and &
 *   Ejemplo: bitXor(6, 5) = 4
 *   Operaciones permitidas: ~ &
 *   Cantidad maxima de operaciones: 8
 *   Dificultad: 1
 */
int bitXor(int x, int y)
{
  return (~(x & y) & ~(~x & ~y));
}
/*
 * thirdBits - Retorna una palabra con cada tercer bit (empezando
 * desde el bit menos significativo) en 1 y el resto en 0.
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 8
 *   Dificultad: 1
 */
int thirdBits(void)
{
  int x = 1;

   x =  x | 8;
   x =  x | 64;
   x =  x | 512;
   x =  x | 4096;
   x =  x | 32768;
   x =  x | 262144;    //Sumo las potencias de dos, intercalando cada tres para obtener un 1 cada tercer bit.
   x =  x | 2097152;
   x =  x | 16777216;
   x =  x | 134217728;
   x =  x | 1073741824;

   return (x);
}
/*
 * fitsBits - retorna 1 si se puede representar x como un entero
 * de n bits en complemento a 2.
 *   1 <= n <= 32
 *   Ejemplos: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 15
 *   Dificultad: 2
 */
int fitsBits(int x, int n) {
    int sign = x>>31;
    x >>= (n-1);

  return !(x ^ sign); // Buscar la manera de no usar "!", aunque sea una operaciÃ³n permitida, no quiero usarla
}
/*
}
/*
 * sign - retorna 1 si es positivo, 0 si cero, y -1 si negativo
 *  Ejemplos: sign(130) = 1
 *            sign(-23) = -1
 *  Operaciones permitidas: ! ~ & ^ | + << >>
 *  Cantidad maxima de operaciones: 10
 *  Dificultad: 2
 */
int sign(int x) {
  return ((!!x)) | (x >> 31));
  /* Si el signo de x es negativo, significa que x a nivel de bits tiene el bit más significativo en 1
     por lo que si se hace el shifting a la derecha, generará 0xFFFFFFFF, que es -1, y al hacer el OR con !!x, dará -1
     
     Si el signo es positivo y distinto de 0, la doble negacion de x dará 1, y 1 OR cualquier cosa = 1
     
     Si el numero es 0, la doble negacion de 0 es 0, y el shifting de 0 a la derecha, generará 0 y 0|0 = 0
     */
}
/*
 * getByte - Extrae el byte n de la palabra x
 *   Los bytes estan numerados desde 0 (LSB) a 3 (MSB)
 *   Ejemplos: getByte(0x12345678,1) = 0x56
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 6
 *   Dificultad: 2
 */
int getByte(int x, int n)
{
  n <<= 3; //dezplazo por 3 por la definicion de la numeracion de bytes
  return (x >> (n) & 0xFF); //desplazo entre el resultado de n y lo que me quede lo "separo" con el 256(0xFF)
}
/*
 * logicalShift - desplaza x a la derecha n bits, usando
 * desplazamiento logico
 *   Puede asumir que 0 <= n <= 31
 *   Ejemplos: logicalShift(0x87654321,4) = 0x08765432
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 20
 *   Dificultad: 3
 */
int logicalShift(int x, int n)
{
      int muestra = 1; //

     muestra = muestra << 31; // muestra estarÃ­a de la forma 10000...

     muestra = muestra >> (n+(~1 ^ 1)); //Como el digito mÃ¡s significativo de muestra es 1, entonces se repetirÃ¡ por el desplazamiento a la derecha
                                        //Dejando el digito menos significativo en 0
                                        
     x = x >> n; //Se desplaza normalmente x

     return (x & ~muestra); //Esto aplicarÃ¡ bit a bit un "and", que por el negado de "muestra" y la estructura que tiene,
                           //podrÃ¡ deshacerse de los "1's" si x fuese negativa
}
/*
 * addOK - Determina si se puede calcular x+y sin overflow
 *   Ejemplo: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 20
 *   Dificultad: 3
 */
int addOK(int x, int y) {
  int capsule = 0;
  capsule = (x+y) >> 31; //guardo el signo de la suma de x + y
  x = x >> 31;
  y = y >> 31;
  //Obtuve el signo de x pero tambien el de y.
  return !!((x ^ y) | capsule);
  /*Lo que retornamos sera con respecto al siguiente concepto:
    si al sumar valores con igual signo, cambia su signo es que ocurrio un overflow. */
}
/*
 * bang - Calcula !x sin usar !
 *   Ejemplos: bang(3) = 0, bang(0) = 1
 *   Operaciones permitidas: ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 12
 *   Dificultad: 4
 */
int bang(int x)
{
  int comp2 = ~x + 1; //Calculamos el complemento a 2

    //El bit de signo al operar 0|~0 es 0
    //El bit de signo al operar x|~x, siendo x un numero distinto de 0, es 1

    int shift = (x | comp2) >> 31;

    //Despues de operar x con su complemento a 2, dependiendo del bit de signo, se realizarÃ¡ un shifting a la derecha de 31 bits
    //que si el bit de signo es 0, todo el shifting generarÃ¡ 0.
    //Mientras que  si el bit de signo generado es 1, el shifting generarÃ¡ 0xFFFFFFFF que es equivalente al complemento a 2 de 0x0000001
    //y es -1 en decimal.

  return (shift+1); //Solo faltarÃ­a sumarle 1 a lo obtenido para obtener 1 o 0.
}
/*
 * divpwr2 - Calcula x/(2^n), para 0 <= n <= 30
 *  Redondear hacia cero
 *   Ejemplos: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Operaciones permitidas: ! ~ & ^ | + << >>
 *   Cantidad maxima de operaciones: 15
 *   Dificultad: 2
 */
int divpwr2(int x, int n)
{
    x = (x >> n ); //al correr x a la derecha, n bits, es equivalente a dividir entre las potencias de 2
    return x;
}
/*
 * floatNeg - Retorna el equivalente a nivel de bits de la
 *  expresion -f .
 *   Ambos, el parametro y el resultado deben pasar como enteros
 *   sin signo, pero deben interpretarse como la representacion a
 *  nivel de bits de un valor punto flotante de precisiï¿½n simple.
 *   Cuando el parametro es NaN, retorna el parametro.
 *   Operaciones permitidas: Cualquier operacion de int y unsigned
 *   incluyendo
 *   ||, &&. Tambien if, while
 *   Cantidad maxima de operaciones: 10
 *   Dificultad: 2
 */
unsigned floatNeg(unsigned uf)
{
    int NaN = 0xFF << 23; // Para que queden los 8 bits de signo en ocho 1's
    int aux_Mantisa = 0x7FFFFF;// 23 bits de solo 1´s y el resto en 0
    int mantisa = uf & aux_Mantisa; //multiplicamos bit a bit para solo obtener 23 bits del numero original
    if (((uf & NaN) == NaN) && (mantisa != 0)) return uf; 
    /* Si los 8 bits de exponente que se obtiene al multplicar uf con NaN son 1's, entonces
       se retorna el parametro porque no seria numero y nos aseguramos que la mantisa no sea 0*/
    return uf ^ (1 << 31); 
    /*
      Se le asigna el signo corriendo 0x01 31 bits a la izquierda para obtener 0x80000000 que sería 
      para luego hacer Xor que le asignará el bit de signo.
    */
 
}
/*
 * floatTwice - Retorna el equivalente a nivel de bits de la
 * expresion 2*f del parametro f.
 *   Tanto el parï¿½metro como el resultado pasan como enteros sin
 *  signo, pero se interpretan como representaciones de valores
 *  punto flotante de precision simple.
 *  Cuando el parametro es NaN, retorna NaN.
 *   Operaciones permitidas: Cualquier operacion de enteros o
 *  enteros sin signo, incluyendo  ||, &&. Tambien if, while
 *   Cantidad maxima de operaciones: 30
 *   Dificultad: 4
 */
unsigned floatTwice(unsigned f)
{
    int NaN = 0xFF << 23; // Para que queden los 8 bits de signo en ocho 1's
    int NegF = ~f + 1;
    int aux_Mantisa = 0x7FFFFF;// 23 bits de solo 1´s y el resto en 0
    int mantisa = f & aux_Mantisa; //multiplicamos bit a bit para solo obtener 23 bits del numero original

    if (f >> 31 &&  1){
      int comp2 = ~((~f + 1) << 1) + 1;
        if (!(comp2 >> 31) && 1)
            return f;
        else
        return comp2;
    }
    else if (((f & NaN) == NaN) && (mantisa != 0)) return f;
    /* Si los 8 bits de exponente que se obtiene al multplicar f con NaN son 1's, entonces
       se retorna el parametro porque no seria numero y nos aseguramos que la mantisa no sea 0*/
    return f << 1;
}

int main(int argc, char *argv[])
{
  /*rintf("%i\n", bitAnd(6, 5));
  printf("%i\n", bitXor(6, 5));
  printf("%d\n", thirdBits());
  */
  printf("%i\n", sign(0));
  printf("%i\n", floatTwice(-23));
  //addOK(0x80000000,0x80000000) = 0
  //addOK(0x80000000,0x70000000) = 1
  system("PAUSE");
  return 0;
}

