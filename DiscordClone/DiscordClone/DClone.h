#pragma once
#include <iostream>
#include "MyWindow.h"

class DClone
{
public:
    DClone() {
        myWindow = new MyWindow();  // Initialize the myWindow pointer
    }

    ~DClone() {
        delete myWindow;  // Clean up the allocated MyWindow object in the destructor
    }

    void Run() {
        myWindow->Show();  // Call the Show() function on the myWindow object
    }

private:
    MyWindow* myWindow;
};
