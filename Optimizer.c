#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"




	

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}
	/* YOUR CODE GOES HERE */
	Instruction *prevs;
	Instruction *curr;
	Instruction *after;
	curr = head; 
	int run =1;
	while(1==1)
	{
	
	  if(curr->next != NULL){ 
	 	curr = curr->next;
	 	prevs =  curr->prev;
	 	after = curr->next;

	 	}
	  else{	  
	  	if(run == 0){
	  	break;
	  }
	  curr = head;
	  	  if(curr->next != NULL){ 
	 	curr = curr->next;
	 	prevs =  curr->prev;
	 	after = curr->next;
	 	run =0;
	 	}




	  }
	  if(prevs->opcode == LOADI && curr->opcode == LOADI ){
	  		if(after->opcode == ADD){
	  			run = 1;
	  			int a = prevs->field2;
	  			int b = curr->field2;
	  			int c = a+b;
	  			curr->opcode = LOADI;
	  			curr->field1 = after->field1;
	  			curr->field2 = c;
	  			curr->next = after->next;
	  			curr->prev = prevs->prev;

	  				if(prevs == head){
	  					head = curr;
	  				}else
	  				{
	  					prevs->next = curr;
	  					prevs->prev->next =curr;
	  				}


	  		}
	  		if(after->opcode == MUL){
	  			int a = prevs->field2;
	  			int b = curr->field2;
	  			int c = a*b;
	  			run = 1;
	  			curr->opcode = LOADI;
	  			curr->field2 = c;
	  			curr->field1 = after->field1;

	  			curr->next = after->next;
	  			curr->prev = prevs->prev;
	  					if(prevs == head){
	  					head = curr;
	  				}else
	  				{
	  					prevs->next = curr;
	  					prevs->prev->next =curr;
	  				}
	  		}
	  		if(after->opcode == SUB){
					int a = 0; 
	  				int b = 0;
	  			if(after->field2 == prevs->field2){
	  					a = prevs->field2;
	  					b = curr->field2;
	  				}
	  				else
	  				{
	  					 b = prevs->field2;
	  					 a = curr->field2;
	  				}

	  			int c = a-b;
	  			run = 1;
	  			curr->opcode = LOADI;
	  			curr->field2 = c;
	  			curr->next = after->next;
	  			curr->prev = prevs->prev;
	  				if(prevs == head){
	  					head = curr;
	  				}else
	  				{
	  					prevs->next = curr;
	  					prevs->prev->next =curr;
	  				}
	  		
	  		}
	  }
	}



	if (head) {
		PrintInstructionList(stdout, head);	

		DestroyInstructionList(head);
	}
	return EXIT_SUCCESS;
}

