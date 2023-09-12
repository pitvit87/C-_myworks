#pragma once

class Menu
{
	int choice;
	char allow;
public:
	void display() const;
	int defineChoice();
	bool allowContinue();
};

