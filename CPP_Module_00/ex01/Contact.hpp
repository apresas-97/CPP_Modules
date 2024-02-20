#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{

public:

	Contact();
	~Contact();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickname(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecret(std::string str);

private:

	static int	_contactCount;

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string	_phoneNumber;
	std::string _darkestSecret;

};

#endif