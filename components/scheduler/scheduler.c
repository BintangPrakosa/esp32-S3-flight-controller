#include "scheduler.h"

#include <stdio.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gptimer.h"
#include "esp_attr.h"

static bool IRAM_ATTR timer_callback(
        gptimer_handle_t timer,
        const gptimer_alarm_event_data_t *edata,
        void *user_ctx)
{
    // Loop flight controller akan dipanggil di sini
    // nanti: gyro read + PID + motor update

    return pdFALSE;
}

void scheduler_init(void)
{
    gptimer_handle_t timer = NULL;

    gptimer_config_t config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000 // 1 tick = 1 µs
    };

    gptimer_new_timer(&config, &timer);

    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_callback,
    };

    gptimer_register_event_callbacks(timer, &cbs, NULL);

    gptimer_enable(timer);

    gptimer_alarm_config_t alarm_config = {
        .reload_count = 0,
        .alarm_count = 500, // 500 µs = 2kHz
        .flags.auto_reload_on_alarm = true,
    };

    gptimer_set_alarm_action(timer, &alarm_config);

    gptimer_start(timer);

    printf("Scheduler 2kHz started\n");
}