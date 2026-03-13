#include "flight_control.h"
#include "imu.h"
#include <stdint.h>

static imu_data_t imu_data;

void flight_control_init(void)
{
    imu_init();
}

void flight_control_loop(void)
{
    imu_read(&imu_data);

    // nanti:
    // filter_update()
    // pid_update()
    // mixer_update()
    // esc_write()
}