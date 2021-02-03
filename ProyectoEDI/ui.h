/*
 * ui.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef UI_H_
#define UI_H_

#include "Opendata.h"
#include "Calles.h"
#include "timer.h"


class UI {


private:


    Opendata *O;
	int  menu     ();
	void ejecutar ();


public:

	 UI();
	~UI();
};

#endif /* UI_H_ */
