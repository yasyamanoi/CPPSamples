#pragma once

#include<iostream>
#include <sstream>
#include <exception>

using namespace std;

namespace cp {
	//--------------------------------------------------------------------------------------
	///	������^
	//--------------------------------------------------------------------------------------
	class String {
		char* m_pdata{ nullptr };
		size_t m_capacity{16};
		size_t m_size{};
		size_t m_maxsize{sizeof(size_t)};
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		String() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	data	���������镶����
		*/
		//--------------------------------------------------------------------------------------
		String(const char* data) {
			size_t i = 0;
			while (data[i] != '\0') {
				if (i >= (m_maxsize - 1)) {
					throw runtime_error("error: memory cannot be secured.");
				}
				i++;
			}
			m_size = i;
			while (m_capacity < m_size) {
				m_capacity *= 2;
			}
			m_pdata = new char[m_capacity];
			strcpy_s(m_pdata, m_capacity - 1, data);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		~String(){
			delete[] m_pdata;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������̐擪�̃|�C���^�̎擾
		@return	������̐擪�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		const char* data() const {
			return m_pdata;
		}
	};
	//--------------------------------------------------------------------------------------
	/*!
	@brief	String��cout�Ŏg����悤�ɂ���
	@param[in]	os	ostream�̎Q��
	@param[in]	s	String�̎Q��
	@return	ostream�̎Q��
	*/
	//--------------------------------------------------------------------------------------
	inline ostream& operator <<(ostream& os, const String& s)
	{
		os << s.data();
		return os;
	};

}
//end namespace cp