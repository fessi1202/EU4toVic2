/*Copyright(c) 2019 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */


#ifndef EU4_GOVERNMENTSECTION_H_
#define EU4_GOVERNMENTSECTION_H_

#include "EU4ReformStackSection.h"
#include <memory>
#include <optional>
#include <set>


namespace EU4
{
	class governmentSection : commonItems::parser
	{
	public:
		governmentSection(std::istream& theStream);
		std::string getGovernment() const { return government; }
		std::set<std::string> getGovernmentReforms() const { return reformStack; }

		static std::string readGovernment(std::istream& theStream)
		{
			commonItems::singleString governmentString(theStream);
			std::string governmentStr = governmentString.getString();
			return governmentStr;
		}

	private:

		static std::set<std::string> readGovernmentReforms(std::istream& theStream)
		{
			EU4::reformStackSection refStack(theStream);
			return refStack.getReforms();
		}

		std::string government;
		std::set<std::string> reformStack;
	};
}

#endif // EU4_GOVERNMENTSECTION_H_