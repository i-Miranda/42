/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:43:51 by ivmirand          #+#    #+#             */
/*   Updated: 2025/10/02 01:01:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

static void print_msg_value(std::string msg, int value){
	std::cout << msg << value;
}

static void	print_index(Account& account) {
	print_msg_value(" index:", account._accountIndex);
}

static void	print_amount(Account& account) {
	print_msg_value(";amount:", account._amount);
}

static void	print_p_amount(Account& account) {
	print_msg_value(";p_amount:", account._amount);
}

static void	print_deposit(int deposit) {
	print_msg_value(";deposit:", deposit);
}

static void	print_nb_deposits(Account& account) {
	print_msg_value(";nb_deposits:", account._nbDeposits);
}

static bool	print_withdrawal(Account& account, int withdrawal) {
	if (withdrawal > account._amount) {
		std::cout << ";withdrawl:refused" << std::endl;
		return (false);
	}
	print_msg_value(";withdrawal:", withdrawal);
	return (true);
}

static void	print_nb_withdrawals(Account& account) {
	print_msg_value(";nb_withdrawals:", account._nbWithdrawals);
}

int Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit){
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	print_index(*this);
	this->_amount = initial_deposit;
	print_amount(*this);
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	print_index(*this);
	print_amount(*this);
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	print_index(*this);
	print_p_amount(*this);
	print_deposit(deposit);
	this->_amount += deposit;
	print_amount(*this);
	this->_nbDeposits++;
	print_nb_deposits(*this);
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	print_p_amount(*this);
	if (!print_withdrawal(*this, withdrawal))
		return (false);
	this->_amount -= withdrawal;
	print_amount(*this);
	this->_nbWithdrawals++;
	print_nb_withdrawals(*this);
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	print_index(*this);
	print_amount(*this);
	print_msg_value(";deposits:", this->_nbDeposits);
	print_msg_value(";withdrawals:", this->_nbWithdrawals);
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t rawtime = std::time(NULL);
	struct tm* timeinfo = std::localtime(&rawtime);
	char buffer[20];
	
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}

Account::Account( void ) {
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	print_index(*this);
	this->_amount = 0;
	print_amount(*this);
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;
	std::cout << ";created" << std::endl;
}
