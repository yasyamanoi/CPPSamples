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
		size_t m_maxsize{ UINT_MAX };
		void capacity_update(size_t n) {
			if (n >= (m_maxsize - 1)) {
				throw runtime_error("error: memory cannot be reserve.");
			}
			size_t cap = m_capacity;
			while (cap <= n) {
				cap *= 2;
			}
			auto pdata = new char[cap];
			if (m_pdata) {
				strcpy_s(pdata, cap - 1, m_pdata);
				delete[] m_pdata;
			}
			m_pdata = pdata;
			m_capacity = cap;
		}
	public:
		/*!
		@brief	�R���X�g���N�^
		*/
		String() {}
		/*!
		@brief	�R���X�g���N�^
		@param[in]	data	���������镶����
		*/
		String(const char* data) {
			m_size = strlen(data);
			if (m_size >= (m_maxsize - 1)) {
				throw runtime_error("error: memory cannot be secured.");
			}
			while (m_capacity <= (m_size - 1)) {
				m_capacity *= 2;
			}
			m_pdata = new char[m_capacity];
			strcpy_s(m_pdata, m_capacity - 1, data);
		}
		/*!
		@brief	�f�X�g���N�^
		*/
		~String(){
			delete[] m_pdata;
		}
		/*!
		@brief	������̒����̎擾
		@return	������̒���
		*/
		size_t size() const{
			return m_size;
		}
		/*!
		@brief	������̒����̎擾
		@return	������̒���
		*/
		size_t length() const {
			return m_size;
		}
		/*!
		@brief	������̍ő�̒����̎擾
		@return	������̍ő�̒���
		*/
		size_t max_size() const {
			return m_maxsize;
		}
		/*!
		@brief	������̒�����ύX����
		@param[in]	n	�V��������
		@return	�Ȃ�
		*/
		void resize(size_t n){
			if (n >= (m_capacity - 1)) {
				capacity_update(n);
			}
			m_size = n;
		}
		/*!
		@brief	�������ǉ�����
		@param[in]	s �ǉ����镶����
		@return	�Ȃ�
		*/
		String& append(const String& s) {
			auto total = size() + s.size();
			if (total >= (m_capacity - 1)) {
				capacity_update(total);
			}
			strcat_s(m_pdata, m_capacity, s.data());
			m_size = total;
			return *this;
		}
		String& append(const char* s) {
			auto total = size() + strlen(s);
			if (total >= (m_capacity - 1)) {
				capacity_update(total);
			}
			strcat_s(m_pdata, m_capacity, s);
			m_size = total;
			return *this;
		}
		String& append(char s) {
			char arr[2] = {};
			arr[0] = s;
			auto total = size() + 1;
			if (total >= (m_capacity - 1)) {
				capacity_update(total);
			}
			strcat_s(m_pdata, m_capacity, arr);
			m_size = total;
			return *this;
		}
		String& operator+=(const String& s) {
			return append(s);
		}
		String& operator+=(const char* s) {
			return append(s);
		}
		String& operator+=(char s) {
			return append(s);
		}
		/*!
		@brief	��������N���A����
		@return	�Ȃ�
		*/
		void clear() {
			m_pdata[0] = '\0';
			m_size = 0;
		}
		/*!
		@brief	�����񂩋󂩂ǂ������`�F�b�N����
		@return	��Ȃ�true
		*/
		bool empty() const {
			return (m_size == 0);
		}
		/*!
		@brief	������̐擪�̃|�C���^�̎擾
		@return	������̐擪�̃|�C���^
		*/
		const char* data() const {
			return m_pdata;
		}
	};
	/*!
	@brief	String��cout�Ŏg����悤�ɂ���
	@param[in]	os	ostream�̎Q��
	@param[in]	s	String�̎Q��
	@return	ostream�̎Q��
	*/
	inline ostream& operator <<(ostream& os, const String& s)
	{
		os << s.data();
		return os;
	};

}
//end namespace cp
