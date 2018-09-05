#pragma once
#include "TimeController.h"
#include "DateController.h"
#include "Display.h"
class Display
{
public:
	Display(void);
	~Display(void);
	void render(DateController, TimeController);
};

