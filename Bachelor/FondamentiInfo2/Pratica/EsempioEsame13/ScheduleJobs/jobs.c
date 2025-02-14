#include<stdlib.h>
#include<stdio.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;



int ScheduleJobs(const job* jobs, size_t j_size) {
    int tcurr = 0;
    int index = 0;
    int profit = 0;
    int* used = calloc(1, sizeof(int));
    int k = 0;
    for (size_t j = 0; j < j_size; j++) {
        int max = 0;
        int trovato = 0;
        for (size_t i = 0; i < j_size; i++) {
            if ((jobs[i].profit / jobs[i].duration) > max) {
                for (int l = 0; l < k; l++) {
                    if (used[l] == (int)i) {
                        trovato = 1;
                        break;
                    }
                }
                if (trovato == 0) {
                    if (tcurr + jobs[i].duration <= jobs[i].deadline) {
                        max = jobs[i].profit / jobs[i].duration;
                        index = i;
                    }
                   
                }
                trovato = 0;
            }
            else if ((jobs[i].profit / jobs[i].duration) == max) {
                if (jobs[i].duration < jobs[index].duration) {
                    max = jobs[i].profit / jobs[i].duration;
                    index = i;
                }
            }
        }
        if (index >= 0) {
            tcurr += jobs[index].duration;
            profit += jobs[index].profit;
            fprintf(stdout, "%d ", index);
            k += 1;
            used = realloc(used, k * sizeof(int));
            used[k - 1] = index;
            index = -1;
       }
        
        
    }

    return profit;
    
}

