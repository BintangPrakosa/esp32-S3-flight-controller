#include "imu.h"

static float t = 0;

void imu_init(void)
{
}

void imu_read(imu_data_t *data)
{
    t += 0.01f;

    data->gyro_x = t;
    data->gyro_y = t * 0.5f;
    data->gyro_z = t * 0.25f;
}