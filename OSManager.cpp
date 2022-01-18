#include <iostream>
#include <thread>         
#include <chrono> 

 using namespace std;

class Process_OSManager 
{

private:
int *arr;
  
int *thread_Arr;
  
int front, rear;
  
int MAX;

public:
Process_OSManager (int maxsize = 10);
  
void addNewQueue ();
  
void showingTheProcess (string str);
  
void showingThreadList (string str);
  
int delq ();
  
int moveThread ();
  
void ready_queue (int data);
  
void anotherQueue (Process_OSManager obj);
  
void unwaitMethod (Process_OSManager obj, bool flag);
  
void createThread (int id);
  
void showQueueList ();

};


 
Process_OSManager::Process_OSManager (int maxsize) 
{
  
MAX = maxsize;
  
arr = new int[MAX];
  
thread_Arr = new int[MAX];
  
front = -1;
  
rear = -1;

} 
 
void

Process_OSManager::addNewQueue () 
{
  
int b;
  
while (b != -1)
    {
      
int pid;
      
cout << "Please enter a unique ID for the process: P_ID: \n";
      
cin >> pid;
      
 
if (rear == MAX - 1)
	
	{
	  
cout <<
	    "\nYou can't create a new process because the queue is full'";
	  
return;
	
}
      
rear++;
      
arr[rear] = pid;
      
if (front == -1)
	
front = 0;
      
 
cout << " A new process is created, process_id " << pid << endl;
      
cout << " Create a new thread by pressing any key, except -1 \n ";
      
cin >> b;
    
}

 
}


void
Process_OSManager::createThread (int id) 
{
  
int b;
  
while (b != -1)
    {
      
int thread_id;
      
cout << "Please enter a unique ID for Thread  \n";
      
cin >> thread_id;
      
 
if (rear == MAX - 1)
	
	{
	  
cout <<
	    "You can't create a new thread because the queue is full \n'";
	  
return;
	
}
      
rear++;
      
thread_Arr[rear] = thread_id;
      
if (front == -1)
	
front = 0;
      
 
cout << "A new thread is created, thread_id " << thread_id << endl;
      
cout << " Create a new thread by pressing any key, except -1 \n ";
      
cin >> b;
    
}

 
}


void
Process_OSManager::showingTheProcess (string str)
{
  
int i;
  
int len = 0;
  
for (int i = 0; i < 5; i++)
    {
      
if (arr[i] != 0 && arr[i] < 1000)
	{
	  
cout << "  reg" << arr[i] << " ";
	  
len++;
	
}
    
}
  
cout << endl;
  
cout << len << " process in the " << str << endl;

}


void
Process_OSManager::showingThreadList (string str)
{
  
int i;
  
int len = 0;
  
for (int i = 0; i < 5; i++)
    {
      
if (thread_Arr[i] != 0 && thread_Arr[i] < 1000)
	{
	  
cout << "  tid_" << thread_Arr[i] << "  ";
	  
len++;
	
}
    
 
 
}
  
cout << endl;
  
cout << len << " thread in the " << str << endl;

}


 
int
Process_OSManager::delq () 
{
  
int data;
  
if (front == -1)
    
    {
      
cout << "\nThere is no queue";
      
return 0;
    
}
  
 
data = arr[front];
  
arr[front] = 0;
  
if (front == rear)
    
front = rear = -1;
  
  else
    
front++;
  
 
return data;

}


int
Process_OSManager::moveThread () 
{
  
int data;
  
 
if (front == -1)
    
    {
      
cout << "\nThere is no queue";
      
return 0;
    
}
  
 
data = thread_Arr[front];
  
 
thread_Arr[front] = 0;
  
 
if (front == rear)
    
front = rear = -1;
  
  else
    
front++;
  
 
return data;

}


 
void
Process_OSManager::anotherQueue (Process_OSManager obj)
{
  
int data = obj.delq ();
  
 
if (rear == MAX - 1)
    
    {
      
cout << "\nQueue is full and you can not create new process'";
      
return;
    
}
  
rear++;
  
arr[rear] = data;
  
if (front == -1)
    
front = 0;
  
cout << "Processes are entered into a waiting queue \n";

 
}


void
Process_OSManager::showQueueList ()
{
  
const char *arr_item[] =
    { "Running_queue", "Ready_queue", "Waiting_Queue", "New_Queue",
"Terminated_queue" };
  
for (int i = 0; i < 5; i++)
    {
      
cout << i + 1 << " . " << arr_item[i] << endl;

} 
 
} 
void

Process_OSManager::unwaitMethod (Process_OSManager obj, bool flag)
{
  
if (flag)
    {
      
 
cout << "Please wait for 5 seconds \n";
      
for (int j = 0; j < 5; j++)
	{
	  
this_thread::sleep_for (chrono::seconds (1));
	  
cout << "  second " << j << " \n";
    
} 
}
  
 
int data = obj.moveThread ();
  
 
if (rear == MAX - 1)
    
    {
      
cout << "\nA new process cannot be created because the queue is full'";
      
return;
    
}
  
rear++;
  
thread_Arr[rear] = data;
  
if (front == -1)
    
front = 0;
  
cout << " A process enters the ready queue \n";

 
}


 
int
main () 
{
  
Process_OSManager running_queue (5);
  
Process_OSManager ready_queue (5);
  
Process_OSManager wait_queue (5);
  
Process_OSManager terminated_queue (5);
  
Process_OSManager new_queue (5);
  
 
int selectSwitchCases;
  
cout << "   \n\n";
  
cout << "   OS Lab Assignment :-- by: Kanwal Jeet Singh\n";
  
cout << "   Process and Thread Management \n\n";
  
cout << " ................................................ \n";
  
cout << "  Choose the option for executing the command \n";
  
cout << " ................................................ \n\n\n";
  
 
cout << "  Select: 1 Displays the queue list when you press. :- 1 \n";
  
cout << "  Select: 2 Process creation in a queue. \n";
  
cout << "  Select: 3 Displaying the process in a queue. \n";
  
 
cout << "  Select: 4 Thread creation in a queue \n";
  
cout << "  Select: 5 Displaying the thread in a queue \n";
  
 
cout << "  Select: 6 Unwait_command to manipulate queue \n";
  
cout << "  Select: 7 Check the manipulated waiting queue \n";
  
cout << "  Select: 8 Check the manipulated ready queue \n";
  
cout << "  Select: 9 In order to perform EOQUANTUM command \n";
  
cout << "  Select: 10 In order to perform EOLIFE command \n";
  
cout << "  Select: 11 In order to perform WAIT command \n";
  
cout << "  Select: 12 for  displaying thread in a running queue \n";
  
cout << "  Select: 13 for  displaying thread in a running queue \n";
  
cout << "  Select: 14 Exiting \n";
  
 
cout << " ................................................ \n";
  
 
while (1)
    {
      
 
cout << " You can choose any option : ";
      
cin >> selectSwitchCases;
      
switch (selectSwitchCases)
	{
	
case 1:
	  
new_queue.showQueueList ();
	  
break;
	
case 2:
	  
ready_queue.addNewQueue ();
	  
break;
	
case 3:
	  
ready_queue.showingTheProcess ("READY_QUEUE");
	  
break;
	
case 4:
	  
ready_queue.createThread (10);
	  
break;
	
case 5:
	  
ready_queue.showingThreadList ("READY_QUEUE");
	  
break;
	
case 6:
	  
ready_queue.unwaitMethod (wait_queue, false);
	  
break;
	
case 7:
	  
wait_queue.showingThreadList ("WAIT_QUEUE");
	  
break;
	
case 8:
	  
ready_queue.showingThreadList ("MANIPULATED_READY_QUEUE ");
	  
break;
	
case 9:
	  
ready_queue.unwaitMethod (running_queue, true);
	  
break;
	
case 10:
	  
terminated_queue.unwaitMethod (running_queue, false);
	  
break;
	
case 11:
	  
wait_queue.unwaitMethod (running_queue, false);
	  
break;
	
case 12:
	  
running_queue.createThread (10);
	  
break;
	
case 13:
	  
terminated_queue.showingThreadList ("terminated_queue");
	  
break;
	
case 14:
	  
exit (1);
	
default:
	  
break;
	
}
    
}
  
return 0;

}
