#pragma once

#include<iostream>
#include <sstream>
#include <exception>

using namespace std;

namespace cp {
	template<typename T>
	class Vector {
		T* m_pdata{ nullptr };
		size_t m_capacity{ 16 };
		size_t m_size{};
		size_t m_maxsize{ UINT_MAX };
		Vector() {

		}
		Vector(size_t sz) {

		}
		Vector(const T[] arr) {

		}
	};
}
//end namespace cp
