#pragma once
#include "Slave_child_array.h"
	/*
	* @brief Klassen $name til styring af elektromagnetisk l�s
	* @relates
	*/


	class Slave_Child_1
	{
	public:
		Slave_Child_1();
		Slave_Child_1(Slave_Array_Read_cpp *ArrayPtr);
		bool activate();
		bool deactivate();
		void stop();

	private:
		bool state_;
		Slave_Array_Read_cpp *ArrayPtr_;

	};


