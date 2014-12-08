#include "ch.h"
#include "hal.h"
#include "chprintf.h"


int main(void){
halInit(); // initialize Hardware Abstraction Layer
chSysInit(); // initialize ChibiOS kernel
/* sdInit(); should be used as we see in the SerialDriver state machine
, but it is already implicitely called in halInit();*/
//palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(7)); // used function : USART3_TX
//palSetPadMode(GPIOB, 11, PAL_MODE_ALTERNATE(7)); // used function : USART3_RX
sdStart(&SD1, NULL); // starts the serial driver with uartCfg as a config
//char data[] = "Hello World ! \n \r"; /* we create the string "Hello World!", \n means go to the next line
//\r sets it to the left of the screen */
char data[] = "Hello World ! \n \r";
while(1){
  chprintf((BaseSequentialStream *)&SD1, "**********************");
  chprintf((BaseSequentialStream *)&SD1, "* TM4C123x I2C Demo. *");
  chprintf((BaseSequentialStream *)&SD1, "**********************\n");
  chThdSleepMilliseconds(1000);
  sdWrite(&SD1, (uint8_t *) data, strlen(data)); // Writes "Hello World in the UART output

  }
}



