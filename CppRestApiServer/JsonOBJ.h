#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "game/Board.h"
class JsonOBJ {

public :
	JsonOBJ();
	
	// Add key or key-value
	void add(std::string key);
	void add(std::string key, std::string value);
	void add(std::string key, Board board);
	void set(std::string key, std::string value);

	std::string getDoc();

protected : 

private :
	rapidjson::Document document;
};