#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <locale>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed\n";
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:"<< getNbWithdrawals() << ";\n";
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal < 0 || withdrawal > _amount)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";\n";
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t time = std::time(NULL);
    char timeString[sizeof("yyyy-mm-ddThh:mm:ssZ")];
    std::strftime(timeString, sizeof(timeString), "%Y%m%d_%H%M%S", std::gmtime(&time));
	std::cout << "[";
    std::cout << timeString;
	std::cout << "] ";
}