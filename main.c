#include "MKL25Z4.h"
int led_r = 18;
int led_v = 19;
int led_az = 1;
int t;
int main (void){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
    PORTB -> PCR[18]|=(1<<8);
    PORTB -> PCR[19]|=(1<<8);
    PORTD -> PCR[1]|=(1<<8);
    PTB->PDDR|=(1<<18);
    PTB->PDDR|=(1<<19);
    PTD->PDDR|=(1<<1);
    PTB->PSOR|=(1<<18);
    PTB->PSOR|=(1<<19);
    PTD->PSOR|=(1<<1);
    while (1){
        PTB->PTOR|=(1<<18);
        for(t=7000000; t>0; t--);
        PTB->PTOR|=(1<<18);
        PTB->PTOR|=(1<<19);
        for(t=7000000; t>0; t--);
        PTB->PTOR|=(1<<19);
        PTD->PTOR|=(1<<1);
        for(t=7000000; t>0; t--);
        PTD->PTOR|=(1<<1);
   }
    return 0;
}
