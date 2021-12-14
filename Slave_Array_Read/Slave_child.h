#pragma once
#include "Slave_child_array.h"
	/*
	* @brief Klassen $name til styring af elektromagnetisk lås
	* @relates
	*/


	class Slave_Child
	{
	public:
		Slave_Child(Slave_Array_Read_cpp *ArrayPtr);
		bool activate();
		bool deactivate();
		void stop();

	private:
		bool state_;
		Slave_Array_Read_cpp *ArrayPtr_;

	};


