/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI_X.C
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/

#include <cstdlib>
#include <unistd.h>
#include <time.h>

#include <pthread.h>

#include "GUI.h"
#include "GUI_X.h"

/*********************************************************************
*
*       Global data
*/
//volatile int OS_TimeMS=0;

/*********************************************************************
*
*      Timing:
*                 GUI_X_GetTime()
*                 GUI_X_Delay(int)

  Some timing dependent routines of emWin require a GetTime
  and delay function. Default time unit (tick), normally is
  1 ms.
*/

int GUI_X_GetTime(void)
{
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC, &time);
	return time.tv_nsec/1000000;
}

void GUI_X_Delay(int ms)
{
	usleep(ms*500);
}

/*********************************************************************
*
*       GUI_X_Init()
*
* Note:
*     GUI_X_Init() is called from GUI_Init is a possibility to init
*     some hardware which needs to be up and running before the GUI.
*     If not required, leave this routine blank.
*/

//pthread_mutex_t lock;

void GUI_X_Init(void)
{
	//pthread_mutex_init(&lock,NULL);
}

void GUI_X_Exit(void)
{
	//pthread_mutex_destroy(&lock);
}

/*********************************************************************
*
*       GUI_X_ExecIdle
*
* Note:
*  Called if WM is in idle state
*/

void GUI_X_ExecIdle(void)
{
}

/*********************************************************************
*
*      Logging: Publics referenced by upper layers
*
Note:
  These routines are needed only in higher debug levels.
*/

void GUI_X_Log(const char *s)
{
}

void GUI_X_InitOS(void)
{
}

void GUI_X_Unlock(void)
{
	//pthread_mutex_unlock(&lock);
}

void GUI_X_Lock(void)
{
	//pthread_mutex_lock(&lock);
}

U32  GUI_X_GetTaskId(void)
{
	return 0;
}

void GUI_X_Warn(const char *s)
{
}

void GUI_X_ErrorOut(const char *s)
{
}


