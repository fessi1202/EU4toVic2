#include "Configuration.h"
#include "Parsers/Parser.h"
#include "Parsers\Object.h"
#include "Log.h"
#include <vector>
using namespace std;



Configuration* Configuration::instance = NULL;

Configuration::Configuration()
{
	printf("Reading configuration file.\n");
	log("Reading configuration file.\n");

	vector<Object*> obj = doParseFile("configuration.txt")->getValue("configuration");
	if (obj.size() != 1)
	{
		printf("Configuration file must contain exactly one configuration section.");
		log("Configuration file must contain exactly one configuration section.");
		exit (-2);
	}


	CK2Path		= obj[0]->getLeaf("CK2directory");
	EU3Path		= obj[0]->getLeaf("EU3directory");
	HRETitle		= obj[0]->getLeaf("HRETitle");
	advisorsType= obj[0]->getLeaf("advisorsType");

	id				= 1;
}