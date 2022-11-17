/**********************************************************
 * FileName:        main.c  / Proyect: PARPADEO
 * Dependencies:    msp.h,
 * Processor:       MSP432
 * Board:           MSP432P401R
 * Program version: CCS V10 TI
 * Company:         Texas Instruments
 * Description:     "EJERCICIO_1_U2 (básico)" DE CONFIGURACION DE GPIO (CON ESTRUCTURAS del BSP)
 * Authors:         ALFREDO CHACON
 * Created on: 6 mar. 2021
 * Updated:         06/2021
 * Nota:    el proyecto PARPADEO es un ejemplo basico sobre el uso de GPIO
 *
 ******************************************************************/
/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribución, modificación o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahuano son responsables del mal uso de este material.
 *************************************************************************************************/
#include "msp.h"
#include "Drivers/system.h"

/*****************************************************************************
 * Function: MAIN
 * Preconditions: NINGUNA.
 * Overview:
 * Input: NINGUNA.
 * Output: NINGUNA
 *
 *****************************************************************************/

//Branch "con_Drivers"


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

	GPIO_init_board();      // Configuracion del GPIO
	bool toggle = true;

	GPIO_setOutput(BSP_LED1_PORT, BSP_LED1, toggle);
	GPIO_setOutput(BSP_LED2_PORT, BSP_LED2, LOW);   // RGB Rojo
	GPIO_setOutput(BSP_LED3_PORT, BSP_LED3, LOW);   // RGB verde
	GPIO_setOutput(BSP_LED4_PORT, BSP_LED4, HIGH);   // RGB azul


	while(1){

	    GPIO_setOutput(BSP_LED1_PORT, BSP_LED1, toggle = (toggle == true ? false : true));
	    GPIO_setOutput(BSP_LED4_PORT, BSP_LED4, !toggle );
	    _delay_cyc les(500000);
	}
}
