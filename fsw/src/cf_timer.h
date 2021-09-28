/************************************************************************
** File: cf_timer.h
**
** NASA Docket No. GSC-18,447-1, and identified as “CFS CFDP (CF) 
** Application version 3.0.0”
** Copyright © 2019 United States Government as represented by the 
** Administrator of the National Aeronautics and Space Administration. 
** All Rights Reserved.
** Licensed under the Apache License, Version 2.0 (the "License"); you may 
** not use this file except in compliance with the License. You may obtain 
** a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software 
** distributed under the License is distributed on an "AS IS" BASIS, 
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
** See the License for the specific language governing permissions and 
** limitations under the License.
** 
**
** Purpose:
**  The CF Application timer header file
**
** 
** 
*************************************************************************/

#ifndef CF_TIMER__H
#define CF_TIMER__H

#include "cfe.h"

/* NOTE: We expect ticks to be 100/sec, so using uint32 for sec could have a bounds condition
 * with uint32. But, we don't expect to use more than 400,000,000 seconds for any reason so
 * let's just live with it. */
typedef uint32 CF_Timer_Tick_t;
typedef uint32 cf_timer_sec_t;

typedef struct {
    CF_Timer_Tick_t tick; /* expires when reaches 0 */
} cf_timer_t;

/* initialize a timer
 *
 * If the abs_sec value is greater than current time, then the timer will
 * be immediately expired. */
extern void CF_Timer_InitRelSec(cf_timer_t *c, cf_timer_sec_t rel_sec);

extern void cf_timer_update_timebase(void);

/* returns 1 if expired */
extern int CF_Timer_Expired(const cf_timer_t *t);

extern void CF_Timer_Tick(cf_timer_t *t);

#endif /* !CF_TIMER__H */

