#include "headers.h"

/* arg for semctl system calls. */
union Semun
{
    int val;               /* value for SETVAL */
    struct semid_ds *buf;  /* buffer for IPC_STAT & IPC_SET */
    ushort *array;         /* array for GETALL & SETALL */
    struct seminfo *__buf; /* buffer for IPC_INFO */
    void *__pad;
};

int attachShm(int key);
void createSem(int key, union Semun *sem);
void up();
void down();
void clearResources(int signum);

int remaining_time, shm_id, sem_id;
int *sched_shmaddr;
union Semun semun;
int prevClk, nxtClk;
int main(int agrc, char *argv[])
{
    initClk();
    signal(SIGINT, clearResources);
    attachShm(SCHEDULER_SHM_KEY);

    createSem(SCHED_SEM_KEY, &semun);
    //TODO it needs to get the remaining time from somewhere
    remaining_time = atoi(argv[0]);
    prevClk = getClk();
    while (remaining_time > 0)
    {
        
        nxtClk = getClk();
        if (nxtClk == prevClk + 1)
        {
            remaining_time--;
            *sched_shmaddr = remaining_time;

            if (remaining_time != 0)
            {
                up();
            }
        }
        prevClk = nxtClk;  
    }

    clearResources(0);
}

int attachShm(int key)
{
    int shmid = shmget(key, 4, IPC_CREAT | 0644);

    if (shmid == -1)
    {
        perror("Error in creating the shared memory @ Process:(\n");
        exit(-1);
    }

    sched_shmaddr = (int *)shmat(shmid, (void *)0, 0);
    if (*sched_shmaddr == -1)
    {
        perror("Error in attach in Process:(\n");
        exit(-1);
    }

    return shm_id;
}

void createSem(int key, union Semun *sem)
{
    //1. Create Sems:
    sem_id = semget(key, 1, 0666 | IPC_CREAT);

    if (sem_id == -1)
    {
        perror("Error in create the semaphor at scheduler:(\n");
        exit(-1);
    }
}

void down()
{
    struct sembuf p_op;

    p_op.sem_num = 0;
    p_op.sem_op = -1;
    p_op.sem_flg = !IPC_NOWAIT;

    if (semop(sem_id, &p_op, 1) == -1)
    {
        perror("Error in down() at Process:(\n");
        exit(-1);
    }
}

void up()
{
    struct sembuf v_op;

    v_op.sem_num = 0;
    v_op.sem_op = 1;
    v_op.sem_flg = !IPC_NOWAIT;

    if (semop(sem_id, &v_op, 1) == -1)
    {
        perror("Error in up() at Process:(\n");
        exit(-1);
    }
}

/*
 * Detach the shared memory.
 * Send notification to the schedular Via SIGUSR2 signal.
 * Release the clock.
 * Exit.
*/
void clearResources(int signum)
{
    printf("Current process is exiting\n");
    shmdt(sched_shmaddr);
    destroyClk(false);
    kill(getppid(), SIGUSR2);
    exit(0);
}
