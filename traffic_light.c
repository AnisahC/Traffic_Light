#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

//define GPIO pin number
#define ECHO 18
#define TRIG 24

#define LED_RED 8
#define LED_YELLOW 7
#define LED_GREEN 12

//measure distance
double distance() {
    //send a pulse, lasting for 10uS
    gpioWrite(TRIG, 1);
    usleep(10);
    gpioWrite(TRIG, 0);

    while(gpioRead(ECHO) == 0) {
        //wait for the echo signal
    }

    uint32_t start = gpioTick(); //record the start time

    while(gpioRead(ECHO) == 1) {
        //wait for the echo signal
    }

    uint32_t end = gpioTick(); //record the end time

    //calculate the distance
    double distance = (end - start) * 0.0343 / 2;

    return distance;

}

int main() {
    //initialize the GPIO
    if(gpioInitialise() < 0) {
        return -1;
    }

    //set the GPIO pin mode
    gpioSetMode(TRIG, PI_OUTPUT);
    gpioSetMode(ECHO, PI_INPUT);

    //initialize the GPIO pin
    gpioWrite(TRIG, 0);
    int i = 0;

    while(i<100) {
        //measure the distance
        double dist = distance();
        printf("Distance: %.2f cm\n", dist);

        if(dist > 15) {
            //red light
            gpioWrite(LED_RED, 1);
            gpioWrite(LED_YELLOW, 0);
            gpioWrite(LED_GREEN, 0);
        }
        if(dist > 8 && dist <= 15) {
            //yellow light
            gpioWrite(LED_YELLOW, 1);
            gpioWrite(LED_RED, 0);
            gpioWrite(LED_GREEN, 0);
        }
        if(dist <= 8) {
            //green light
            gpioWrite(LED_GREEN, 1);
            gpioWrite(LED_RED, 0);
            gpioWrite(LED_YELLOW, 0);
        }

        usleep(500000); //delay for 0.5s
        i++;
    }

    gpioWrite(LED_GREEN, 0);
    gpioWrite(LED_RED, 0);
    gpioWrite(LED_YELLOW, 0);

    //release the GPIO
    gpioTerminate();

    return 0;
}
