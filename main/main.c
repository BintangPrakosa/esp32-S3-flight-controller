#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "flight_control.h"
#include "scheduler.h"

void app_main(void)
{
    printf("FC boot\n");

    flight_control_init();
    scheduler_init();

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}