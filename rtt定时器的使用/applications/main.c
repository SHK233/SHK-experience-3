/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-08-16     armink       first implementation
 */

#include <rtthread.h>
#include <rtdevice.h>

//宏定义带创建定时器的控制块和所用到的变量
static rt_timer_t timer1;
static rt_timer_t timer2;
static int count = 0 ;

//创建定时器1的超时函数。
static void timeout1(void* parameter)
{
	rt_kprintf("periodic timer1 is timeout %d\n",count);
	count++;
	if(count>10)
	{
		rt_kprintf("periodic timer1 was stopped !\n");
		rt_timer_stop(timer1);
	}
}

//创建定时器2的超时函数
static void timeout2(void *parameter)
{
	rt_kprintf("one shot timer is timeout !\n");
}


int main(void)
{
	
    return 0;
}

int rtt_task3(void)
{
	//创建timer1为周期定时
	timer1 = rt_timer_create("timer1",timeout1,RT_NULL,10,RT_TIMER_FLAG_PERIODIC);
	if(timer1!=RT_NULL)
	{
		rt_timer_start(timer1);
	}
	timer2 = rt_timer_create("timer2",timeout2,RT_NULL,30,RT_TIMER_FLAG_ONE_SHOT);
	if(timer2!=RT_NULL)
	{
		rt_timer_start(timer2);
	}
	
	return 0;
	
}

MSH_CMD_EXPORT(rtt_task3, rtt task3);
