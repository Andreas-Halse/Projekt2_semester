#pragma once

class Motor
{
public:
    Motor();
    void checkOnOff();
    void checkDirecton();

private:
    bool on = false;
    bool direction = false; 
};
