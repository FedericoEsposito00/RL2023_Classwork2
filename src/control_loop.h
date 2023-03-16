#include <iostream>
#include <fstream>
#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(float p, float _cmd);
        
        void loop();               //Main loop function        
        void system_start();       //start the system
        void system_stop();        //stop the system (close the output file)
        void set_xdes(double x);   //member to set the desired value

    private:
        float _p; // System state
        float _cmd; // Desired value
        float _t; //time
        ofstream _logged_data; // Output file
};
