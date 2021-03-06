#ifndef _BOARD_INCLUDED_
#define _BOARD_INCLUDED_

#include "stdint.h"

#define MAX_RPM 13100 // Maxon max rpm
#define REDUCTION 26 // Gearbox reduction
#define MAX_MAXON_PWM 0.9
#define MIN_MAXON_PWM 0.1

char setVoltage(char ch, float duty); // установить напряжение на выходе управления двигателем -1,0 .. 1,0
char setPWM(char ch, float duty);

char setVoltageMaxon (char ch, int8_t pwm_dir , float duty);
char setSpeedMaxon(char ch, float targetSpeed);

extern uint32_t * PWM_CCR[10];  //регистры сравнения каналов ШИМ
extern uint32_t  PWM_DIR[10];
extern uint32_t  GENERAL_PIN[10];
extern uint32_t  EXTI_PIN[10];
extern uint32_t  V12_PIN[6];

extern uint16_t adcData[10];
extern uint8_t pinType[10];
extern uint8_t extiType[10];
extern uint16_t extiFlag;

void initAll(void); // That's all!
void clear_ext_interrupt(unsigned char pin);
void add_ext_interrupt(unsigned char pin, char edge);
#endif
