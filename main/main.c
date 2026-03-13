#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "scheduler.h"

void app_main(void)
{
    printf("Flight controller boot\n");

    scheduler_init();

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}