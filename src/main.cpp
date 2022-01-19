#include <iostream>
#include <unistd.h>
#include <iomanip>

const int minute = 60;

bool time_correct;  // sets to true, when the user enters the correct value of time (>=0)

int rest_seconds;
int work_seconds;
int work_minutes;
int rest_minutes;

int work;
int rest;
int total_time;  

char user_exit;
char exit_key;

// creates the choice for a user of how many minutes would they want to work and rest.
void user_count(){ 
  std::cout << "enter how many minutes would you want to work: ";
  std::cin >> work;
  
  total_time += work;

  std::cout << "enter how many minutes would you want to rest: ";
  std::cin >> rest;
}

void display_timer(){
  system("clear");
  std::cout << std::endl;

  std::cout << std::setw(25);
  std::cout << "POMODORO" << std::endl;
}

// timer for the work.
void pomodoro_work(){
  while(true){
    sleep(1);
    display_timer();
    
    std::cout << std::setw(27);
    std::cout << "TIME TO WORK" << std::endl;
    std::cout << std::setw(20);
    std::cout << "" << work_minutes << work_seconds << std::endl;

    work_seconds++;
    
    if(work_seconds == minute){
      work_minutes++;
      work_seconds = 0;
    }

    if(work_minutes == work) break;
  }
}

// timer for the rest.
void pomodoro_rest(){
  while(true){
    sleep(1);
    display_timer();
    
    std::cout << std::setw(27);
    std::cout << "TIME TO REST" << std::endl;
    std::cout << std::setw(20);
    std::cout << "" << rest_minutes << rest_seconds << std::endl;
    
    rest_seconds++;

    if(rest_seconds == minute){
      rest_minutes++;
      rest_seconds = 0;
    }
    
    if(rest_minutes == rest) break;; 
  }
}

int main(){
  while(user_exit != 'n'){
    while(time_correct != true){
      try{
        user_count();
      if(work <= 0 | rest <= 0){
          throw(work);
          throw(rest);
        }
      else time_correct = true;
      }
      catch(int time_check){
        std::cerr << "you have entered the wrong amount of time" << std::endl;
      }
  }    

    pomodoro_work();
    pomodoro_rest();
   
    work = 0;
    rest = 0;
    work_minutes = 0;
    work_seconds = 0;

    system("clear"); 
  
    std::cout << "you have been working for " << total_time << " minute(s)" << std::endl;
    std::cout << "would you want to continue? Y/n" << std::endl;
    std::cin >> user_exit;
  }
  return 0;
}
