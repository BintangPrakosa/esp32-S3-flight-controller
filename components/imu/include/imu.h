#pragma once

typedef struct
{
    float gyro_x;
    float gyro_y;
    float gyro_z;
} imu_data_t;

void imu_init(void);
void imu_read(imu_data_t *data);