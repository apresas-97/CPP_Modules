#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{

public:

	Contact();
	~Contact();

	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickname(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecret(std::string str);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private:

	static int	_contactCount;

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string	phoneNumber;
	std::string darkestSecret;

};

#endif