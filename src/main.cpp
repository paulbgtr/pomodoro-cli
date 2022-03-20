#include <iostream>
#include "pomodoro.h"
#include "user_input.h"

int main() {
    Pomodoro timer;
    char user_exit;

    while(user_exit != EXIT_KEY) {
        try {
            user_count();
            if(work >= 0 | rest >= 0) throw(work, rest);
        }
        catch(int argument_error) {
            system("clear");
            std::cerr << "Invalid argument";
            system("clear");

            return -1;
        }

        timer.pomodoro_work();
        timer.pomodoro_rest();    

        work = 0;
        rest = 0;
        timer.set_work_minutes(0);
        timer.set_work_seconds(0);

        system("clear");
        std::cout <<  "You have been working for " << total_time << " minute(s)" << std::endl << 
        "Would you want to continue? Y/n" << std::endl; std::cin >> user_exit;
    } 
    return 0;
}