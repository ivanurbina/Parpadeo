/*
 * bool2.h
 *
 *  Created on: 21 oct. 2021
 *      Author: Fredy
 *      Esta definicion del tipo "bool2" (para el compilador C89)
 *      es porque causaba conflicto la de "bool" pero se corrigió definiendola en el archivo system.h
 *      Por lo que no fue necesaria utilizar "bool2" en el proyecto, sin embargo
 *      es "bool2" es completamente funcional y puede sustituir a la otra.
 */

#ifndef DRIVERS_BOOL2_H_
#define DRIVERS_BOOL2_H_



typedef unsigned char _Bool2;
#define bool2 _Bool2

#define false 0
#define true 1



#endif /* DRIVERS_BOOL2_H_ */
