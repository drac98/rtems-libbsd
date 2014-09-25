/**
 * @file
 *
 * @ingroup rtems_bsd_machine
 *
 * @brief TODO.
 */

/*
 * Copyright (c) 2009-2013 embedded brains GmbH.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Dornierstr. 4
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _RTEMS_BSD_MACHINE_RTEMS_BSD_THREAD_H_
#define _RTEMS_BSD_MACHINE_RTEMS_BSD_THREAD_H_

#include <rtems/bsd/sys/param.h>
#include <rtems/bsd/sys/types.h>
#include <sys/proc.h>
#include <sys/queue.h>

#include <rtems/score/threadq.h>
#include <rtems.h>

#define BSD_TASK_NAME rtems_build_name('_', 'B', 'S', 'D')

#define BSD_TASK_PRIORITY_NORMAL 120

#define BSD_TASK_PRIORITY_TIMER 110

#define BSD_TASK_PRIORITY_INTERRUPT 100

#define BSD_TASK_PRIORITY_RESOURCE_OWNER 100

/* FIXME */
#define BSD_MINIMUM_TASK_STACK_SIZE ((size_t) 32 * 1024)

struct sleepqueue {
	Thread_queue_Control sq_blocked;
	LIST_ENTRY(sleepqueue) sq_hash;
	LIST_HEAD(, sleepqueue) sq_free;
	void *sq_wchan;
};

struct thread *
rtems_bsd_get_thread(const Thread_Control *thread);

static inline rtems_id
rtems_bsd_get_task_id(const struct thread *td)
{
	return td->td_thread->Object.id;
}

#endif /* _RTEMS_BSD_MACHINE_RTEMS_BSD_THREAD_H_ */
