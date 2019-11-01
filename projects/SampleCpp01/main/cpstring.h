#pragma once

#include<iostream>
#include <sstream>
#include <exception>

using namespace std;

namespace cp {
	//--------------------------------------------------------------------------------------
	///	文字列型
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
		@brief	コンストラクタ
		*/
		String() {}
		/*!
		@brief	コンストラクタ
		@param[in]	data	初期化する文字列
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
		@brief	デストラクタ
		*/
		~String(){
			delete[] m_pdata;
		}
		/*!
		@brief	文字列の長さの取得
		@return	文字列の長さ
		*/
		size_t size() const{
			return m_size;
		}
		/*!
		@brief	文字列の長さの取得
		@return	文字列の長さ
		*/
		size_t length() const {
			return m_size;
		}
		/*!
		@brief	文字列の最大の長さの取得
		@return	文字列の最大の長さ
		*/
		size_t max_size() const {
			return m_maxsize;
		}
		/*!
		@brief	文字列の長さを変更する
		@param[in]	n	新しい長さ
		@return	なし
		*/
		void resize(size_t n){
			if (n >= (m_capacity - 1)) {
				capacity_update(n);
			}
			m_size = n;
		}
		/*!
		@brief	文字列を追加する
		@param[in]	s 追加する文字列
		@return	なし
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
		@brief	文字列をクリアする
		@return	なし
		*/
		void clear() {
			m_pdata[0] = '\0';
			m_size = 0;
		}
		/*!
		@brief	文字列か空かどうかをチェックする
		@return	空ならtrue
		*/
		bool empty() const {
			return (m_size == 0);
		}
		/*!
		@brief	文字列の先頭のポインタの取得
		@return	文字列の先頭のポインタ
		*/
		const char* data() const {
			return m_pdata;
		}
	};
	/*!
	@brief	Stringをcoutで使えるようにする
	@param[in]	os	ostreamの参照
	@param[in]	s	Stringの参照
	@return	ostreamの参照
	*/
	inline ostream& operator <<(ostream& os, const String& s)
	{
		os << s.data();
		return os;
	};

}
//end namespace cp
