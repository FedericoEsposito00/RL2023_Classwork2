#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(float p, float cmd) {
    _p = p;
    _cmd = cmd;
    _logged_data.open("logged_data.txt", ios::out);
    _t = 0;
}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {
    _cmd = x;
}


//Random initial value
void CONTROLLER::system_start() { //generate the loop thread
    cout<<"Controller started\n";
    boost::thread(&CONTROLLER::loop, this);
}

void CONTROLLER::system_stop() {
    _logged_data.close();
}

void CONTROLLER::loop() { 

    float e; // controller error
    float kp = 1; // proportional gain
    float ki = 1; // integral gain
    float kd = 1; // derivative gain
    float dt = 0.1; // time interval

    while (true) {
        e = _cmd - _p; 

        _p = _p + kp*e*dt + ki*e*dt*dt/2 + kd*e;
        _t = _t + dt;
        _logged_data<<_t<<", "<<_p<<", "<<_cmd<<",\n";
        usleep(dt*1e6);
    }

}


