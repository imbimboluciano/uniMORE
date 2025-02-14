#include<stdlib.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

extern int ScheduleJobs(const job* jobs, size_t j_size); 

int main(void) {

    int dur[] = {2,4,1,8,4,20};
    int prof[] = { 50,130,35,50,300,145 };
    int deadline[] = {4,25,3,30,7,30};
    job* jobs = calloc(6, sizeof(job));
    for (int i = 0; i < 6; i++) {
        jobs[i].duration = dur[i];
        jobs[i].profit = prof[i];
        jobs[i].deadline = deadline[i];
    }

    int res = ScheduleJobs(jobs, 6);
    
    return 0;
}