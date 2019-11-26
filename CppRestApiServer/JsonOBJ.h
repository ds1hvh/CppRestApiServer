#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "game/Board.h"

class JsonOBJ {

public :
	JsonOBJ();
	JsonOBJ(const char* json);

	// Add key or key-value
	void add(std::string key);
	void add(std::string key, std::string value);
	void add(std::string key, Board board);
	void set(std::string key, std::string value);

	std::string getStr();

protected : 

private :
	rapidjson::Document document;
};