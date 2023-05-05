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
		else // after filling out the nopts and option array
		{
			// in printing the combination, we just only manipulate the nopts array since there is a pattern
			move--; // since in the if statement above prints the first combination therefore we must decrement the move
			while(move != 0) { // this loops terminates if the move reaches the value of 0, this move variable serves as the index of nopts  
				if(nopts[move+1] == 0){ // if the next element of the current element is equal to zero therefore the current element must be decrement
					nopts[move]--;                 
					
					// printing
					i = 1;
					while(nopts[i] != 0){
						printf("%2i",option[i][nopts[i]]);
						i++;
					}
					printf("\n");

					if(nopts[move] == 0){ // the current element reaches zero
						move--;			  // the current index will be moved
						nopts[move]--;    // after moving, the current element decrement
						
						// for this if-else statement is to check the difference between the current element and the next element to the right
						// the goal is to have the difference of at most 1 only
						if(nopts[move]-nopts[move+1] > 1){ // if the difference is 2 above there will be changes on the nopts array as well the move value
							// this records the previous imporatant value since this will be changed later on
							int prev_element = nopts[move]; 
							int prev_move = move;
							int temp = (nopts[move]-nopts[move+1]);

							// change the value of move
							move = move + ((nopts[move]-nopts[move+1])-1);
							for(int a = 1; a < temp; a++){ // this manipulates the nopts array
								nopts[a+prev_move] = prev_element - a;
							}

							// printing
							i = 1;
							while(nopts[i] != 0){
								printf("%2i",option[i][nopts[i]]);
								i++;
							}
							printf("\n");
						
						}else{ // if the difference is at most 1 
							// printing
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