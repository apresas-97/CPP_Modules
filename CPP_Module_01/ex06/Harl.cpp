#include "Harl.hpp"

Harl::Harl( void )
{
	this->debug();
	this->info();
	this->warning();
	this->error();
}

Harl::~Harl( void )
{

}

void Harl::complain( std::string level )
{
	void	(Harl::*functionPTR[]) ( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	int	filter = 0;
	while (filter < 4)
	{
		if (level == this->functionNames[filter])
			break;
		filter++;
	}

	switch (filter)
	{
		case 0:
			(this->*functionPTR[0]) ();
			__attribute__ ((fallthrough));// Esto no hace falta en 42, creo
		case 1:
			(this->*functionPTR[1]) ();
			__attribute__ ((fallthrough));// Esto no hace falta en 42, creo
		case 2:
			(this->*functionPTR[2]) ();
			__attribute__ ((fallthrough));// Esto no hace falta en 42, creo
		case 3:
			(this->*functionPTR[3]) ();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return ;
}

void Harl::debug( void )
{
	if (this->functionNames[0].empty())
	{
		this->functionNames[0] = __func__;
		for (size_t i = 0; i < this->functionNames[0].length(); i++)
			this->functionNames[0][i] -= 32;
		return ;
	}
	std::cout << "[ " << this->functionNames[0] << " ] " << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
	if (this->functionNames[1].empty())
	{
		this->functionNames[1] = __func__;
		for (size_t i = 0; i < this->functionNames[1].length(); i++)
			this->functionNames[1][i] -= 32;
		return ;
	}
	std::cout << "[ " << this->functionNames[1] << " ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	if (this->functionNames[2].empty())
	{
		this->functionNames[2] = __func__;
		for (size_t i = 0; i < this->functionNames[2].length(); i++)
			this->functionNames[2][i] -= 32;
		return ;
	}
	std::cout << "[ " << this->functionNames[2] << " ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	if (this->functionNames[3].empty())
	{
		this->functionNames[3] = __func__;
		for (size_t i = 0; i < this->functionNames[3].length(); i++)
			this->functionNames[3][i] -= 32;
		return ;
	}
	std::cout << "[ " << this->functionNames[3] << " ] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
