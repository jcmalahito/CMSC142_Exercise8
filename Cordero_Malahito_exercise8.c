#include <stdio.h>
#include <stdlib.h>
#define N 4

int main(){
	int start, move;
	int nopts[N+2]; //array of top of stacks
	int option[N+2][N+2]; //array of stacks of options
	int i, candidate;

	move = start = 0; 
	nopts[start]= 1;
	
	while (nopts[start] >0) //while dummy stack is not empty
	{
		if(nopts[move]>0) 
		{
			move++;
			nopts[move]=0; //initialize new move

			if(move==N+1) //solution found!
			{
				for(i=1;i<move;i++)
					printf("%2i",option[i][nopts[i]]);
				printf("\n");
			}
			else if(move == 1){
				for(candidate = N; candidate >=1; candidate --) 
				{
					nopts[move]++;
					option[move][nopts[move]] = candidate;
					printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
				}
			}
			else{
				for(candidate=N;candidate > 0 ;candidate--)
				{ // candidate = 2
					for(i=move-1;i>=1;i--)
						if(candidate==option[i][nopts[i]]) break;
					if(i <= 0)
						option[move][++nopts[move]] = candidate;
				}
			}
		}
		else 
		{
			move--;
			while(move != 0) {
				if(nopts[move+1] == 0){
					nopts[move]--;                 
					i = 1;
					while(nopts[i] != 0){
						printf("%2i",option[i][nopts[i]]);
						i++;
					}
					printf("\n");       
					if(nopts[move] == 0){
						move--;
						nopts[move]--;
						if(nopts[move]-nopts[move+1] > 1){
							int prev_element = nopts[move];
							int prev_move = move;
							int temp = (nopts[move]-nopts[move+1]);
							
							move = move + ((nopts[move]-nopts[move+1])-1);
							for(int a = 1; a < temp; a++){
								nopts[a+prev_move] = prev_element - a;
							}
							i = 1;
							while(nopts[i] != 0){
								printf("%2i",option[i][nopts[i]]);
								i++;
							}
							printf("\n");
						}else{
							i = 1;
							while(nopts[i] != 0){
								printf("%2i",option[i][nopts[i]]);
								i++;
							}
							printf("\n");
						}
					}
				}
		}
			break;
		}
	}
}