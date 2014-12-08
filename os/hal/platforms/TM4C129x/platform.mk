# List of all the MSP430 platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/platforms/TM4C129x/hal_lld.c \
              ${CHIBIOS}/os/hal/platforms/TM4C129x/pal_lld.c \
              ${CHIBIOS}/os/hal/platforms/MSP430/serial_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/platforms/TM4C129x
