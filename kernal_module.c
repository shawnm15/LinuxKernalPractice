#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{

    printk(KERN_INFO "Loading Module\n");
    struct task_struct *task;

	task=&init_task;
	printk(KERN_INFO "PID-%i,STATE-%lu,FLAGS-%i,PRIORITY-%i,PROCESS-%i,TGID-%i\n", task->pid,task->state,task->flags,task->rt_priority,task->policy,task->tgid);
	
	for (; (task=next_task(task))!= &init_task; ){
		printk(KERN_INFO "PID-%i,STATE-%lu,FLAGS-%i,PRIORITY-%i,PROCESS-%i,TGID-%i\n", task->pid,task->state,task->flags,task->rt_priority,task->policy,task->tgid);
		
		
	}

    return 0;
}


/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

