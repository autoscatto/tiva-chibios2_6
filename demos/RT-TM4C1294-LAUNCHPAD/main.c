#include "ch.h"
#include "hal.h"


int main(void) {


  halInit();
  chSysInit();
  //palTogglePad(GPIOF, GPIOF_LED0);
  palSetPad(GPIOF, GPIOF_LED1); 
  while(TRUE) {}
}





