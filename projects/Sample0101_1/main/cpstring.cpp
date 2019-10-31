
#include "cpstring.h"
namespace cp {

	ostream& operator <<(ostream& os, const String& s)
	{
		os << s.data();
		return os;
	};

}
//end namespace cp
