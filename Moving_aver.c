#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "xbasic_types.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "ARM_interface.h"
#include "UART.h"

volatile u8 moving_aver_cnt_X =  0;
volatile double moving_aver_sum_X = 0.0;
volatile double moving_aver_result_X = 0.0;
volatile u8 moving_aver_cnt_Y =  0;
volatile double moving_aver_sum_Y = 0.0;
volatile double moving_aver_result_Y = 0.0;

void Balanced_initialized(u8 cnt);

void Moving_Aver_X(double data, u8 moving_aver_number)
{
	if(moving_aver_cnt_X == 0)
	{
		moving_aver_sum_X = 0.0;
		moving_aver_result_X = 0.0;
		moving_aver_cnt_X ++;
		moving_aver_data_X_1st = data;
		moving_aver_sum_X += data;
	}
	else if(moving_aver_cnt_X != moving_aver_number)
	{
		moving_aver_cnt_X ++;
		moving_aver_sum_X += data;
	}
	else
	{
		moving_aver_result_X = moving_aver_sum_X / (double)moving_aver_number;
		moving_aver_sum_X = moving_aver_sum_X -  moving_aver_data_X_1st + data;
		moving_aver_data_X_1st = data;
		if(freq_mixed_flag)
		{
			Balanced_initialized(0);
		}
	}
}

void Moving_Aver_Y(double data, u8 moving_aver_number)
{
	if(moving_aver_cnt_Y == 0)
	{
		moving_aver_sum_Y = 0.0;
		moving_aver_result_Y = 0.0;
		moving_aver_cnt_Y ++;
		moving_aver_data_Y_1st = data;
		moving_aver_sum_Y += data;
	}
	else if(moving_aver_cnt_Y != moving_aver_number)
	{
		moving_aver_cnt_Y ++;
		moving_aver_sum_Y += data;
	}
	else
	{
		moving_aver_result_Y = moving_aver_sum_Y / (double)moving_aver_number;
		moving_aver_sum_Y = moving_aver_sum_Y -  moving_aver_data_Y_1st + data;
		moving_aver_data_Y_1st = data;
		if(freq_mixed_flag)
		{
			Balanced_initialized(0);
		}
	}
}
