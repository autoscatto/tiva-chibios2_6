#include "ch.h"
#include "hal.h"


int main(void) {


  halInit();
  chSysInit();

  while(TRUE) {
    palTogglePad(GPIOF, GPIOF_LED0);
    chThdSleepMilliseconds(1000);
  }
}





