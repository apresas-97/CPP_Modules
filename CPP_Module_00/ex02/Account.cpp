#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// Public:

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << " " << \
	"index:" << this->_accountIndex << ";" << \
	"amount:" << this->_amount << ";" << \
	"created" << std::endl;

	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " " << \
	"index:" << this->_accountIndex << ";" << \
	"amount:" << this->checkAmount() << ";" << \
	"closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " " << \
	"accounts:" << Account::getNbAccounts() << ";" << \
	"total:" << Account::getTotalAmount() << ";" << \
	"deposits:" << Account::getNbDeposits() << ";" << \
	"withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " " << \
	"index:" << this->_accountIndex << ";" << \
	"p_amount:" << this->checkAmount() << ";" << \
	"deposit:" << deposit << ";";

	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;

	std::cout << \
	"amount:" << this->checkAmount() << ";" << \
	"nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " " << \
	"index:" << this->_accountIndex << ";" << \
	"p_amount:" << this->checkAmount() << ";" << \
	"withdrawal:";

	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;

	std::cout << withdrawal << ";" << \
	"amount:" << this->checkAmount() << ";" << \
	"nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " " << \
	"index:" << this->_accountIndex << ";" << \
	"amount:" << this->checkAmount() << ";" << \
	"deposits:" << this->_nbDeposits << ";" << \
	"withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

// Private:

void	Account::_displayTimestamp( void )
{
	time_t time = std::time(NULL);
	std::tm	*timeInfo = std::localtime(&time);

	std::cout << \
	"[" << \
	(timeInfo->tm_year + 1900) << \
	std::setfill('0') << std::setw(2) << (timeInfo->tm_mon + 1) << \
	std::setfill('0') << std::setw(2) << (timeInfo->tm_mday) << \
	"_" << \
	std::setfill('0') << std::setw(2) << (timeInfo->tm_hour) << \
	std::setfill('0') << std::setw(2) << (timeInfo->tm_min) << \
	std::setfill('0') << std::setw(2) << (timeInfo->tm_sec) << \
	"]";
	return ;
}
