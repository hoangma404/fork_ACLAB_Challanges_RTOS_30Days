/**
 * @file main.c
 * @brief Simple ESP-IDF example demonstrating a FreeRTOS task that prints a message periodically.
 *
 * This example creates one FreeRTOS task that prints "Hello from FreeRTOS!"
 * every second using vTaskDelay for timing control. It illustrates the basic
 * structure for creating and running tasks in an ESP32 application.
 */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
/**
 * @brief Task function that repeatedly prints a message to the console.
 *
 * This task runs indefinitely in a loop, printing "Hello from FreeRTOS!"
 * every second. The delay is implemented using vTaskDelay().
 *
 * @param pvParameters Pointer to optional parameters passed during task creation (unused here).
 */

#define LED_PIN 2

void hello_task(void *pvParameters) {
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(GPIO_NUM_2, 1); // bat 
        vTaskDelay(pdMS_TO_TICKS(500)); // delay for 500 ms

        gpio_set_level(GPIO_NUM_2, 0); // tat 
        vTaskDelay(pdMS_TO_TICKS(500)); // delay for 500 ms
    }
}

/**
 * @brief Application entry point for the ESP-IDF program.
 *
 * This function creates the hello_task with a stack size of 2048 bytes and
 * a priority level of 5. It does not return, as the FreeRTOS scheduler takes over.
 */
void app_main() {
    xTaskCreate(
        hello_task,       // Task function
        "HelloTask",      // Name
        2048,             // Stack size
        NULL,             // Parameters
        5,                // Priority
        NULL              // Task handle
    );
}