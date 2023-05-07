#include "mbed.h"

AnalogIn red(p20);      // Potentiometer for red color
AnalogIn green(p19);    // Potentiometer for green color
PwmOut led(p21);        // LED output pin

int main() {
    led.period_ms(1);   // Set the PWM period to 1ms

    while(1) {
        float red_value = red.read();     // Read the analog value of red potentiometer
        float green_value = green.read(); // Read the analog value of green potentiometer
        float sum = red_value + green_value;
        
        // Calculate the mixed color values
        float red_pwm_value = red_value / sum;
        float green_pwm_value = green_value / sum;
        
        led.write(green_pwm_value);       // Set the green LED brightness
        led.write(red_pwm_value);      // Set the red LED brightness

        // Check the analog values to determine the color of the LED
        if(red_value == 0 && green_value == 0) {
            printf("LED off\n");
        }
        else if(red_value >= 0.8 && green_value <= 0.2) {
            printf("LED red\n");
        }
        else if(red_value >= 0.8 && green_value >= 0.8) {
            printf("LED yellow\n");
        }
        
        wait(0.05);     // Wait for 0.05 seconds before reading the analog values again
    }
}
