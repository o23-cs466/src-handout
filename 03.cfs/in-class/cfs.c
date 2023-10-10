#include "stdio.h"

enum state {EMBRYO, RUNNING, READY, BLOCKED, DONE};
static char *state_names[] = {"embryo", "running", "ready", "blocked", "done"};

static const int BASE_SCHEDULE_LATENCY = 48;
// static const int SEED = 42;    // same seed -> same IO pattern
static const int MIN_GRANULARITY = 6;

struct job
{
  char *name;
  int cpu_need;       // count down to zero
  int IO_chance;      // out of 100 ... 
  int arrive;         // time this job arrives
  int vruntime;       // my vruntime
  int blocked_until;  // while out doing and IO
  enum state state;   // process' state
} jobs[] = 
{
  {"P1", 75, 0,  0,   0, 0, EMBRYO},   // hard coded processes for simulation
  {"P2", 75, 0,  0,   0, 0, EMBRYO},
  {"P3", 50, 0, 50,   0, 0, EMBRYO},
  {NULL,  0, 0,  0,   0, 0, DONE}
};


/*
 * purpose: determine the number of runnable processes.
 *          note that in production we would maintain a count, but
 *          for simplicity we will just rip through the array.
 * input: the jobs array
 * result: the count!
 */
static int runnable(struct job *job)
{
  int count = 0;

  // for(int i=0; job[i]->name != NULL; i++)
  //   if (job[i]->state ....
  for(; job->name != NULL; job++)
    if (job->state == RUNNING || job->state == READY)
      count++;

  return count;
}


/*
 * purpose:  print the jobs table
 * input:  the jobs
 * result: table is (nicely) printed 
 */
static void print_jobs(char *msg, struct job *job)
{
  printf("%s", msg);
  for(; job->name != NULL; job++)
  {
    printf("  %s arrives at %3d,  ", job->name, job->arrive);
    printf("vruntime %3dms   cpu need %3dms  state %s  ", 
        job->vruntime, job->cpu_need, state_names[job->state]);
    if (job->state == BLOCKED)
      printf(" (blocked until %d3)", job->blocked_until);
    printf("\n");
  }
}


/*
 * purpose: find the runnable job with the smallest vruntime 
 * input: the jobs array
 * result: the selected job or NULL if no runnable job exists
 */
static struct job *min_vruntime(struct job *jobs)
{
  struct job *min = jobs;  

  for(jobs++; jobs->name != NULL; jobs++)
    if (jobs->state == READY && jobs->vruntime < min->vruntime)
      min = jobs;

  // YOUR CODE HERE

  return min->state == DONE ? NULL : min;
}


/*
 * purpose: assign the CPU to a new job
 * input: the jobs array
 * result: the chosen job or NULL if there is no runnable jobs
 */
static struct job *schedule(struct job *jobs)
{
  // YOUR CODE HERE ... hint see min_vruntime
  struct job *chosen = min_vruntime(jobs);

  if (chosen == NULL)
    return NULL;

  chosen->state = RUNNING;
  return chosen;
}


/*
 * purpose: wake up sleepyheads
 * input: the jobs array
 * result: jobs whose waiting time has passed get woken up! 
 */
static void wakeup_now(struct job *jobs, int current_time)
{
  struct job *min = min_vruntime(jobs);

  for(; jobs->name != NULL; jobs++)
  {
    if (jobs->state == EMBRYO && jobs->arrive <= current_time)
    {
      // YOUR CODE HERE ... 
      jobs->state = READY;
      jobs->vruntime = min == NULL ? 0 : min->vruntime;
    }

    if (jobs->state == BLOCKED && jobs->blocked_until <= current_time)
    {
      // YOUR CODE HERE ... only needed if I/O included
      jobs -> state = READY;
      jobs->vruntime = min == NULL ? 0 : min->vruntime;
    }
  }
}





int main()
{
  int current_time = 0;

  wakeup_now(jobs, current_time);
  struct job *current = schedule(jobs);

  while (current != NULL)
  {
    printf("\ncurrent time is %d\n", current_time);
    print_jobs("top of loop\n", jobs);

    int time;

    // YOUR CODE HERE  ...  determine the values of time
    time = BASE_SCHEDULE_LATENCY / runnable(jobs);
    if (time < MIN_GRANULARITY)
      time = MIN_GRANULARITY;

    if (time > current->cpu_need)  // i had this is the wrong place
      time = current->cpu_need;    // in class :)

    printf(" run %s for %d\n", current->name, time);

    current_time += time;
    current->vruntime += time;
    current->cpu_need -= time;

    // YOUR CODE HERE  ...  update jobs based on value of time


    if (current->cpu_need <= 0)
    {
      current->state = DONE;
      current->cpu_need = 0;
    }
    else
      current->state = READY;

    wakeup_now(jobs, current_time);
    current = schedule(jobs);
  }

  print_jobs("\nfinal\n", jobs);

  return 0;
}

