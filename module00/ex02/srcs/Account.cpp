#include <iostream>

#include "Account.hpp"

using namespace std;

// Initialize the static variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	cout << "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "created\n";
}

Account::~Account( void )
{
	cout << "Account closed\n";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	cout << "accounts:" << _nbAccounts << ";" \
		<< "total:" << _totalAmount << ";" \
		<< "deposits:" << _totalNbDeposits << ";" \
		<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits ++;
	this->_nbDeposits++;

	cout << "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "deposit:" << deposit << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_deposits:" << this->_nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = this->_amount;
	if (this->_amount < withdrawal)
	{
		cout << "index:" << this->_accountIndex << ";" \
			<< "p_amount:" << p_amount << ";" \
			<< "withdrawal:refused\n";
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	cout << "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "withdrawal:" << withdrawal << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_deposits:" << this->_nbWithdrawals << "\n";
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	cout << "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "deposits:" << this->_nbDeposits << ";" \
		<< "withdrawals:" << this->_nbWithdrawals << "\n";
	return ;
}
