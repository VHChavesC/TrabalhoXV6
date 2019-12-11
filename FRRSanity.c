#include "types.h"
#include "stat.h"
#include "user.h"

int glob[10];
int count=0;

int main(){

	int PID=1;
	
	printf(1, "Child %d criada \n", getpid());

	PID=fork();


	if(PID==0)
		printf(1, "Child %d criada \n", getpid());

	for(int i=0; i<9;i++){
		if(PID==0){
			PID=fork();
			if(PID==0){
				printf(1, "Child %d criada \n", getpid());
			}
		}

	}

	for(int i=0;i<100;i++){
		printf(1, "Child %d prints for the %d \n", getpid(),i+1);

	}


	int endTime=uptime();


	int runtime=runt();

	wait();
	sleep(30);
	printf(1,"PID %d begin %d end time %d\n", getpid(), beginT(),endTime);
	printf(1, "Child %d ends at %d\n", getpid(),endTime-beginT());
	printf(1,"Process %d Runtime: %d , Waiting time: %d\n", getpid(), runtime,endTime-beginT()-runtime);
	//printf(1,"Process %d Waiting time: %d \n", getpid(), endTime-beginTime-runt());
	exit();
}