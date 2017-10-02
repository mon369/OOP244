#define _CRT_SECURE_NO_WARNINGS 
#include "Error.h"
#include <string.h>
#include <iostream>

namespace ict{
	Error::Error() {
		m_message = nullptr;
	}
	Error::Error(const char* errorMessage) {
		m_message = nullptr;
		message(errorMessage);
	}

	void Error::message(const char* errorMessage) {
		delete[] m_message;
		m_message = new char[strlen(errorMessage) + 1];
		strncpy(m_message, errorMessage, strlen(errorMessage));
		m_message[strlen(errorMessage)] = '\0';
	}
  

	void Error::clear() {

			delete[] m_message;
			m_message = nullptr;

	}

	bool Error::isClear()const{
		return (m_message == nullptr) ? true : false;
	}

	
	Error::operator bool() const {
		return isClear();
	}


	Error::operator const char *() const {
		return m_message;
	}

	void Error::operator=(const char* errorMessage) {
		clear();
		message(errorMessage);
	}

	Error::~Error() {
		clear();
	}
	
	std::ostream& operator<<(std::ostream& os, const Error& e) {
		if (!e.isClear()) {
			os << (const char*)e;
		}
			return os;
		
	}
}
