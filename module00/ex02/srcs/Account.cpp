#include <iostream>
#include <ctime>

#include "Account.hpp"

// Initialize the static variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor and destructor
Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout \
		<< "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "created\n";
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout \
		<< "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "closed\n";
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout \
		<< "accounts:" << Account::getNbAccounts() << ";" \
		<< "total:" << Account::getTotalAmount() << ";" \
		<< "deposits:" << Account::getNbDeposits() << ";" \
		<< "withdrawals:" << Account::getNbWithdrawals() << "\n";
	return ;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits ++;
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout \
		<< "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "deposit:" << deposit << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_deposits:" << this->_nbDeposits << "\n";
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	p_amount = this->_amount;
	if (this->_amount < withdrawal) {
		Account::_displayTimestamp();
		std::cout \
			<< "index:" << this->_accountIndex << ";" \
			<< "p_amount:" << p_amount << ";" \
			<< "withdrawal:refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	Account::_displayTimestamp();
	std::cout \
		<< "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "withdrawal:" << withdrawal << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout \
		<< "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "deposits:" << this->_nbDeposits << ";" \
		<< "withdrawals:" << this->_nbWithdrawals << "\n";
	return ;
}

void	Account::_displayTimestamp( void ) {
	std::time_t now = time(0);
	std::tm *ltm = localtime(&now);

	/* test for test.log
	std::cout << "[19920104_091532] ";
	*/
	std::cout << "[";
	std::cout << ltm->tm_year + 1900;
	if (ltm->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << ltm->tm_mon + 1;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday;
	std::cout << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec;
	std::cout << "] ";
}
