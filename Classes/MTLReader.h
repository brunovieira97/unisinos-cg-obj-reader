#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class MTLReader {
	enum MTLTypes {
		INVALID,
		NEW_MATERIAL,
		MAP_KD,
		KA,
		KS,
		KD,
		NS
	};

	typedef std::map<std::string, MTLTypes> MTLTypeMap;

	MTLTypeMap mtlTypeMap = {
		{"newmtl", MTLTypes::NEW_MATERIAL},
		{"map_Kd", MTLTypes::MAP_KD},
		{"Ka", MTLTypes::KA},
		{"Ks", MTLTypes::KS},
		{"Kd", MTLTypes::KD},
		{"Ns", MTLTypes::NS}
	};

	private:
		int lineCount;
		void Read(std::string filename);
	
	public:
		MTLReader(std::string filename);
};