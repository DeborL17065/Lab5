/*
 * File:   main.c
 * Author: debor
 *
 * Created on February 22, 2020, 8:46 PM
 */
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//SLAVE CONTADOR

#define _XTAL_FREQ   8000000
#include <xc.h>
#include <pic16F887.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PULSADOR_I   RD0
#define PULSADOR_D   RD1

void init(void);
void Contador(void);

uint8_t Estado1 =0;
uint8_t Estado2 =0;

void main(void) {
    init();
    while(1){
    
    }
       

    return;
}

void Contador(void){
    
    if (PULSADOR_I ==1){   
        Estado1 =1;
    }
    if (Estado1 ==1 && PULSADOR_I ==0){ //boton con antirebote
        Estado1 =0;
        PORTD++ ;      //se incrementa el PORTD
    }  
    if (PULSADOR_D ==1){   
        Estado2 =1;
    }
    if (Estado2 ==1 && PULSADOR_D ==0){ //boton con antirebote
        Estado2 =0;
        PORTD-- ;   //se decrementa el PORTD 
    } 
    
   
}

void init(void) { 
    ///8MH
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1; 
    ///////////////////////////////////////////////////////////
    TRISDbits.TRISD0 =1; //PULSADOR DE INCREMENTO
    TRISDbits.TRISD1 =1; //PULSADOR DE DECREMENTO
    TRISD =0b11110000; //se definen los primero 4 bits puerto D como salidas
    //////////////////////////////////////////////////////////////
    PORTC =0;            //se limpia el puerto C
    PORTD =0;          //se limpia el puerto D
    //////////////////////////////////////////////////////////
    ANSELH =0;
 
}