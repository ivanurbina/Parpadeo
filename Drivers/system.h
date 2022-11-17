 // FileName:        system.h
 // Dependencies:    None
 // Processor:       MSP432
 // Board:           MSP43P401R
 // Program Version: CCS V8.3 TI
 // Company:         Texas Instruments
 // Description:     Incluye librer�as, define ciertas macros y significados as� como llevar un control de versiones.
 // Authors:         Jos� Luis Chac�n M. y Jes�s Alejandro Navarro Acosta.
 // Updated:         10/2021 by Alfredo Chac�n A.

#ifndef _system_h_
#define _system_h_

#pragma once                //Esto es redundante

//#define __MSP432P401R__
#define  __SYSTEM_CLOCK    48000000 // Frecuencias funcionales recomendadas: 12, 24 y 48 Mhz.

/* Librerias a usar (paquete predeterminado). */
#include <sys/types.h>
//#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/************** Incluye Board Support Package. **************/
#include "Drivers/BSP1.h"

/* Archivos fuente POSIX. */
//#include <pthread.h>
//#include <semaphore.h>
//#include <ti/posix/tirtos/_pthread.h>
//#include <ti/sysbios/knl/Task.h>

/* Archivos fuente RTOS. */
//#include <ti/sysbios/BIOS.h>
//#include <ti/sysbios/knl/Event.h>



/* Definiciones para el thread principal. */
#define THREADSTACKSIZE1            1500

/* Definiciones del estado 'normal' de los botones externos a la tarjeta (solo hay dos botones). */
#define GND 0
#define VCC 1
/***********************************************************************************
 * Estas se agregaron de stdbool.h  para definir el tipo bool ya que no es C++
 ***********************************************************************************/
#define false   0
#define true    1
#define bool    _Bool
/************************************************************************************/

/* Definici�n del estado 'normal' de los botones que ya existen en la tarjeta y de los que son externos. */
#define BOARD_BUTTON_NORMAL_STATE  VCC  // Esto no se cambia.
#define NORMAL_STATE_EXTRA_BUTTONS GND  // Aqui se coloca GND o VCC (var�a dependiendo de la implementaci�n deseada).

/* Funciones de inicializaci�n. */
extern void System_InicialiceIO    (void);
extern void System_InicialiceUART  (void);

/* Funci�n inicial. */
extern void funcion_inicial (void);

/* M�quina de estados. */
extern void process_events (void);

/* Funcion especial que imprime el mensaje asegurando que no habr� interrupciones y por ende,
 * asegure funcionamiento �ptimo.                                                           */
extern void print(char* message);

#endif
