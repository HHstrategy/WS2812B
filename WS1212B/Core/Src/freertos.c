/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId MainTaskHandle;
osThreadId CircularRingHandle;
osThreadId HeartBeatHandle;
osThreadId AllColorsHandle;
osThreadId ColorWheelHandle;
osThreadId PatternMoveHandle;
osThreadId FullEmptyHandle;
osThreadId AlternateColorsHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Main_Task(void const * argument);
void CircularRing_Task(void const * argument);
void HeartBeat_Task(void const * argument);
void AllColors_Task(void const * argument);
void ColorWheel_Task(void const * argument);
void PatternMove_Task(void const * argument);
void FullEmpty_Task(void const * argument);
void AlternateColors_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of MainTask */
  osThreadDef(MainTask, Main_Task, osPriorityNormal, 0, 128);
  MainTaskHandle = osThreadCreate(osThread(MainTask), NULL);

  /* definition and creation of CircularRing */
  osThreadDef(CircularRing, CircularRing_Task, osPriorityIdle, 0, 128);
  CircularRingHandle = osThreadCreate(osThread(CircularRing), NULL);

  /* definition and creation of HeartBeat */
  osThreadDef(HeartBeat, HeartBeat_Task, osPriorityIdle, 0, 128);
  HeartBeatHandle = osThreadCreate(osThread(HeartBeat), NULL);

  /* definition and creation of AllColors */
  osThreadDef(AllColors, AllColors_Task, osPriorityIdle, 0, 128);
  AllColorsHandle = osThreadCreate(osThread(AllColors), NULL);

  /* definition and creation of ColorWheel */
  osThreadDef(ColorWheel, ColorWheel_Task, osPriorityIdle, 0, 128);
  ColorWheelHandle = osThreadCreate(osThread(ColorWheel), NULL);

  /* definition and creation of PatternMove */
  osThreadDef(PatternMove, PatternMove_Task, osPriorityIdle, 0, 128);
  PatternMoveHandle = osThreadCreate(osThread(PatternMove), NULL);

  /* definition and creation of FullEmpty */
  osThreadDef(FullEmpty, FullEmpty_Task, osPriorityIdle, 0, 128);
  FullEmptyHandle = osThreadCreate(osThread(FullEmpty), NULL);

  /* definition and creation of AlternateColors */
  osThreadDef(AlternateColors, AlternateColors_Task, osPriorityIdle, 0, 128);
  AlternateColorsHandle = osThreadCreate(osThread(AlternateColors), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	vTaskSuspend(CircularRingHandle);			//首先先挂起所有任务
	vTaskSuspend(HeartBeatHandle);
	vTaskSuspend(AllColorsHandle);
	vTaskSuspend(ColorWheelHandle);
	vTaskSuspend(PatternMoveHandle);
	vTaskSuspend(FullEmptyHandle);
	vTaskSuspend(AlternateColorsHandle);
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Main_Task */
/**
  * @brief  Function implementing the MainTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Main_Task */
void Main_Task(void const * argument)
{
  /* USER CODE BEGIN Main_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(5000);
  }
  /* USER CODE END Main_Task */
}

/* USER CODE BEGIN Header_CircularRing_Task */
/**
* @brief Function implementing the CircularRing thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CircularRing_Task */
void CircularRing_Task(void const * argument)
{
  /* USER CODE BEGIN CircularRing_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(CircularRingHandle);
	vTaskDelay(10000);
	vTaskSuspend(CircularRingHandle);
  }
  /* USER CODE END CircularRing_Task */
}

/* USER CODE BEGIN Header_HeartBeat_Task */
/**
* @brief Function implementing the HeartBeat thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_HeartBeat_Task */
void HeartBeat_Task(void const * argument)
{
  /* USER CODE BEGIN HeartBeat_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(HeartBeatHandle);
	vTaskDelay(10000);
	vTaskSuspend(HeartBeatHandle);
  }
  /* USER CODE END HeartBeat_Task */
}

/* USER CODE BEGIN Header_AllColors_Task */
/**
* @brief Function implementing the AllColors thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_AllColors_Task */
void AllColors_Task(void const * argument)
{
  /* USER CODE BEGIN AllColors_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(AllColorsHandle);
	vTaskDelay(10000);
	vTaskSuspend(AllColorsHandle);
  }
  /* USER CODE END AllColors_Task */
}

/* USER CODE BEGIN Header_ColorWheel_Task */
/**
* @brief Function implementing the ColorWheel thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ColorWheel_Task */
void ColorWheel_Task(void const * argument)
{
  /* USER CODE BEGIN ColorWheel_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(ColorWheelHandle);
	vTaskDelay(10000);
	vTaskSuspend(ColorWheelHandle);
  }
  /* USER CODE END ColorWheel_Task */
}

/* USER CODE BEGIN Header_PatternMove_Task */
/**
* @brief Function implementing the PatternMove thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_PatternMove_Task */
void PatternMove_Task(void const * argument)
{
  /* USER CODE BEGIN PatternMove_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(PatternMoveHandle);
	vTaskDelay(10000);
	vTaskSuspend(PatternMoveHandle);
  }
  /* USER CODE END PatternMove_Task */
}

/* USER CODE BEGIN Header_FullEmpty_Task */
/**
* @brief Function implementing the FullEmpty thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_FullEmpty_Task */
void FullEmpty_Task(void const * argument)
{
  /* USER CODE BEGIN FullEmpty_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(FullEmptyHandle);
	vTaskDelay(10000);
	vTaskSuspend(FullEmptyHandle);
  }
  /* USER CODE END FullEmpty_Task */
}

/* USER CODE BEGIN Header_AlternateColors_Task */
/**
* @brief Function implementing the AlternateColors thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_AlternateColors_Task */
void AlternateColors_Task(void const * argument)
{
  /* USER CODE BEGIN AlternateColors_Task */
  /* Infinite loop */
  for(;;)
  {
    vTaskResume(AlternateColorsHandle);
	vTaskDelay(10000);
	vTaskSuspend(AlternateColorsHandle);
  }
  /* USER CODE END AlternateColors_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

