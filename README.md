#Push Swap
The Push_swap project calculates and displays on the standard output the least amount of instructions that will need to sort in ascending order any given set of random numbers.  
#How to run the program:
1) make   
2) ARG="random numbers"; /.push_swap $ARG                      // prints all the instructions   
3) ARG="random numbers"; ./push_swap $ARG | wc -l              // prints the count of all the intructions    
4) ARG="random numbers"; ./push_swap $ARG | ./checker $ARG 	 // prints [OK] if all the numbers are proprely sorted and [KO] if it fails    
5) ARG="random numbers"; ./push_swap $ARG | ./checker $ARG -c  // prints the last instruction with colors   
6) ARG="random numbers"; ./checker $ARG -v 					 // debugger that executes any given instruction    