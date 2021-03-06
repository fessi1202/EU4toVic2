#include "EU4RelationDetails.h"
#include "ParserHelpers.h"

EU4::EU4RelationDetails::EU4RelationDetails(std::istream& theStream)
{
	// the object holding the relationship value in old/new saves
	registerRegex("value|cached_sum", [this](const std::string& unused, std::istream& theStream)
		{
			const commonItems::singleInt valueInt(theStream);
			value = valueInt.getInt();
		});
	registerKeyword("military_access", [this](const std::string& unused, std::istream& theStream)
		{
			commonItems::ignoreItem(unused, theStream);
			military_access = true;
		});
	registerKeyword("last_send_diplomat", [this](const std::string& unused, std::istream& theStream)
		{
			const commonItems::singleString theDateStr(theStream);
			last_send_diplomat = date(theDateStr.getString());
		});
	registerKeyword("last_war", [this](const std::string& unused, std::istream& theStream)
		{
			const commonItems::singleString theDateStr(theStream);
			last_war = date(theDateStr.getString());
		});
	registerKeyword("attitude", [this](const std::string& unused, std::istream& theStream)
		{
			const commonItems::singleString attitudeStr(theStream);
			attitude = attitudeStr.getString();
		});
	registerRegex("[a-zA-Z0-9_\\.:]+", commonItems::ignoreItem);

	parseStream(theStream);
	clearRegisteredKeywords();
}
