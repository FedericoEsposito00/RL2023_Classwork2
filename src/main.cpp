#include "control_loop.h"

using namespace std;

//the goal is to implement a simple PID controller, 
//running on input value to reach the desired one

// Sense: read a value from keyboard
// Plan:  generate the correct input
// Act:   set the input

int main(int argc, char** argv) {  

    float initial_controller_value = 0;

    if (argc > 1) {
        initial_controller_value = atof(argv[1]);
    } 

    CONTROLLER c(0, initial_controller_value);

    c.system_start();

    bool going = true;
    string input;

    while (going) {
        cout<<"Give me the reference value (Insert any non-numerical value to stop the controller)\n";
        cin>>input;

        int i = 0;
        while (input[i] != '\0' && going) {
            if (input[i] != '.' && input[0] != '-' && !isdigit(input[i])) {
                going = false;
            }
            i++;
        } 

        if (going) {
            c.set_xdes(stof(input));
        } else {
            cout<<"Shutting off\n";
            c.system_stop();
        }

        sleep(1); // remember to add a sleep function at the end of the while loop
    }

    return 0;
}
