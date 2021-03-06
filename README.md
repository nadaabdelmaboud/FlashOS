

<p >
<a><img  src="https://i.ibb.co/zGfHG79/kisspng-flash-wally-west-logo-the-cw-television-network-su-5b39a5e2d06500-8939138315305046748536.png" align="center" alt="FlashOs Logo" Width="300px" height="300px"/></a>

[![GitHub forks](https://img.shields.io/github/forks/MohmedMonsef/FlashOS?label=fork&style=plastic)](https://github.com/MohmedMonsef/FlashOS/network) [![GitHub Repo stars](https://img.shields.io/github/stars/MohmedMonsef/FlashOS?style=plastic)](https://github.com/MohmedMonsef/FlashOS/stargazers) [![GitHub contributors](https://img.shields.io/github/contributors/MohmedMonsef/FlashOS?style=plastic)](https://github.com/MohmedMonsef/FlashOS/graphs/contributors) [
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/MohmedMonsef/FlashOS?style=plastic)]()
<h1 align="center">FlashOs</h1>
</p>

## Description
This project consists of 3 phases : 
1. Scheduler
	*	HPF (Highest Priority First)
	*	SRTN (Shortest Remaining Time Next)
	*	RR (Round Robin)
2. Memory Management
	*	Buddy Algorithm
4. Producer-Consumer 

## System Design
![Files Arch](https://i.ibb.co/HH13hrJ/Screenshot-from-2021-01-22-05-36-10.png)

## Data-structures
1. 2-Level Priority Queue:
	- First level: each node represents a linked list that’s is sorted with the priority.
	- Second level: each linked list in the first level is a list of all processes have the same priority sorted by the arrival time.
2. Circular Queue:
	*	The name “Circular” demonstrates the way we are dealing with it. We pop a process, then give it its quantum then push it at the end of the queue.
	* Optimizes the round robin algorithm as each insert – select – delete is O(1).
3. Array of linked lists for memory 
	*	each list represents the memory blocks with the size of this list - sizes of lists are multiples of 2 till 2 power 10 (1024 -memory size ).

## IPCS
1. Semaphores
2. Message Queues
3. Shared Memory
4. Signals

* #### Refer to [OS-Report](OS-Report.pdf) for more details about the used methodologies and input/output samples.
- ## Scheduler

     * ####  Run
     
	      ```bash
	       - Add your custom testcase in processes.txt
	       - For random testcases run:
	       $ gcc test_generator.c -o test_generator.out
	       $ ./test_generator.out
      	```
      
     	```bash
		   $ cd Scheduler
      	   $ make
      	   $ make run
      	```
     *	Log Files
		 * Refer to [Scheduler Performance](Scheduler/performance.log)
		 *  Refer to [Scheduler Log](Scheduler/scheduler.log)




		
  

## Memory Management
   ```bash
  $ cd Memory/Scheduler
  $ make
   $ make run
   ```
    
  * Log Files
	* Refer to [Memory Log](Memory/Scheduler/memory.log)
		
## Producer-Consumer
   ```bash
  $ cd Phase3
  $ make
  $ ./producer.out
  $ ./concumer.out
   ```

## Contributors
* Ahmed Magdy
* Mohamed Monsef
* Menna Mahmoud
* Nada Abdelmaboud


