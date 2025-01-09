#ifndef __LSM6DSM_H
#define __LSM6DSM_H

#include "Arduino.h"

#define LSM6DSM_I2C_ADDRESS 0x6A // 输出Z轴低位在前数据

class LSM6DSM
{
public:
    LSM6DSM() {}
    ~LSM6DSM() {}

    bool Init(uint8_t addr = LSM6DSM_I2C_ADDRESS);

    bool IsConnected();
    void ConfigAcc(uint8_t acc_odr, uint8_t acc_scale);
    void ConfigGyr(uint8_t gyr_odr, uint8_t gyr_scale);
    void GetMotion6(
        int16_t *acc_x,
        int16_t *acc_y,
        int16_t *acc_z,
        int16_t *gyr_x,
        int16_t *gyr_y,
        int16_t *gyr_z);
    int16_t GetTemperature();
    void SoftReset();// 向0x12发0x01重置内存
    void EnableEMbeddedFunc();
    void DisableEMbeddedFunc();
    void EnableAWT(int16_t angle, int16_t Delay);
    void DisableAWT();
    void EnableTapDetection();
    void DisableTapDetection();
    void EnablePedometer(uint16_t debounce_time, uint8_t debounce_step);
    uint16_t GetCurrentStep();
    void ResetStepCounter();
    void DisablePedometer();

private:
    uint8_t Address; // 等于6A
    void WriteReg(uint8_t reg, uint8_t dat);
    uint8_t ReadReg(uint8_t reg);
    void ReadRegs(uint8_t reg, uint8_t *buf, uint16_t len);
    void SetRegisterBits(uint8_t reg, uint8_t data, bool setBits);
};

#endif
