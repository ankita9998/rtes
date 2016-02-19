/*   */

#include<stdio.h>

int N_TASKS = 4;                         //Enter number of tasks and modify
float T[4] = {2.0,5.0,7.0,13.0};                   //length of arrays.
                                         //Enter relative Deadlines and
float C[4] = {1.0,1.0,1.0,2.0};                    //Completion times along with
int rdl[4] = {2,5,7,13};                 //LCM.
int ret[4] = {1,1,1,2};

int LCM = 910;

void processor_utilization(){
int i;
float temp = 0;
  for(i = 0; i < N_TASKS; i ++){
  temp = temp + (C[i]/T[i]);
  }
  printf("EX:8 Processor Utilization Factor is:%f\n",temp);
}

int updateParams(int tid_current){
ret[tid_current]--;
int i;
	 for(i=0;i<N_TASKS;i++){
	 rdl[i]--;
      if(rdl[i] == 0 && ret[i] != 0){
        printf("Deadline of task %d missed,Task set is not schedulable by EDF\n",i);
        return(1);
      }
     else {
       continue;
     }
		  if(rdl[i] == 0){
			  rdl[i] = T[i];
			  ret[i] = C[i];
		    }
	  }

  return(0);
}

int findBestTask(){

	int j;
	int min_val = 100;
  int min_rdl_id = -1;

	for(j=0;j<N_TASKS;j++){

		if(min_val > rdl[j] && ret[j] > 0){
			min_val = rdl[j];
			min_rdl_id = j;
		}
	}

	return min_rdl_id;
}

void EDF_feasibility(){
int count = 1;
int ddl_missed;

  while(count <= LCM){
    int i = findBestTask();
    ddl_missed = updateParams(i);
    count++;
  }
  if (ddl_missed != 1){
    printf("Tasks are feasibile by EDF\n");
  }
}

void main(){

processor_utilization();
EDF_feasibility();


}
