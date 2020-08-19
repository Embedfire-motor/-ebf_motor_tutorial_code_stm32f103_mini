#ifndef __BSP_MOTOR_TIM_H
#define	__BSP_MOTOR_TIM_H

#include "stm32f1xx.h"

/*�궨��*/
#define PWM_TIM                        	TIM4

#define PWM_TIM_GPIO_AF_ENALBE()        //{__HAL_AFIO_REMAP_TIM3_PARTIAL();\
																				__HAL_AFIO_REMAP_SWJ_NONJTRST();}

#define PWM_TIM_CLK_ENABLE()  					__HAL_RCC_TIM4_CLK_ENABLE()

#define PWM_CHANNEL_1                   TIM_CHANNEL_1
#define PWM_CHANNEL_2                   TIM_CHANNEL_2

/* �ۼ� TIM_Period�������һ�����»����ж�*/		
/* ����ʱ����0������PWM_PERIOD_COUNT����ΪPWM_PERIOD_COUNT+1�Σ�Ϊһ����ʱ���� */
#define PWM_PERIOD_COUNT     (3600)

/* ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK=72MHz */
/* �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(PWM_PRESCALER_COUNT+1) */
#define PWM_PRESCALER_COUNT     (2)

/* ���Ƚ�ֵ */
#define PWM_MAX_PERIOD_COUNT              (PWM_PERIOD_COUNT - 100)

/*PWM����*/
#define PWM_TIM_CH1_GPIO_CLK()             __HAL_RCC_GPIOB_CLK_ENABLE();
#define PWM_TIM_CH1_GPIO_PORT              GPIOB
#define PWM_TIM_CH1_PIN                    GPIO_PIN_6

#define PWM_TIM_CH2_GPIO_CLK()             __HAL_RCC_GPIOB_CLK_ENABLE();
#define PWM_TIM_CH2_GPIO_PORT              GPIOB
#define PWM_TIM_CH2_PIN                    GPIO_PIN_7

extern TIM_HandleTypeDef  DCM_TimeBaseStructure;

extern void Motor_TIMx_Configuration(void);
extern void TIM1_SetPWM_pulse(uint32_t channel,int compare);

#endif   /* __BSP_MOTOR_TIM_H */
