#ifndef H_CONTACT_H
#define H_CONTACT_H


// TODO: add namespace here
namespace communication
{
	const int areaCodeLength = 3;
	const int numberLength = 7;
	const int numberCode1Length = 3;
	const int numberCode2Length = 4;

	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		// TODO: add the default constructor here
		Contact();
		// TODO: add the constructor with parameters here
		Contact(const char*, const long long*, const int);
		// TODO: add the destructor here
		~Contact();

		// TODO: add the display function here
		void display() const;
		// TODO: add the isEmpty function here
		bool isEmpty() const;

	public:
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;

	private:
		bool isValidPhoneNumber(const long long);

	};
}
#endif
