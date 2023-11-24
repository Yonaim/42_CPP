#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>

enum token_types
{
	TOKEN_OPERATOR = 0,
	TOKEN_NUMBER,
	TOKEN_NONE,
};

typedef struct s_token
{
	int type;
	int value;
} t_token;

class RPN
{
private:
	// pair 쓸까 했지만 문제가 더 복잡해지는 것 같으므로 그냥 구조체 사용.
	std::stack<t_token> _stack;

	// for OCF (not use)
	RPN();
	RPN(const RPN &orig);
	RPN &operator=(const RPN &orig);

	void push(const std::string &token);
	int pop_number(void);
	int operate_basic4(int op, int opd_1, int opd_2);

public:
	RPN(const std::string &exp);
	~RPN();

	int result(void);

	// exception
	class UnexpectedTokenException;
	class InvalidExpressionException;
	class UnclosedExpressionException;
};

class RPN::UnexpectedTokenException : public std::exception
{
	const char *what(void) const throw();
};

class RPN::InvalidExpressionException : public std::exception
{
	const char *what(void) const throw();
};

class RPN::UnclosedExpressionException : public std::exception
{
	const char *what(void) const throw();
};

#endif