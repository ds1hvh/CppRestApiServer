
#include "JsonOBJ.h"
#include<string>
#include<iostream>

JsonOBJ::JsonOBJ()
{
	document.SetObject();
}

JsonOBJ::JsonOBJ(const char* json) {
	document.Parse(json);
}

void JsonOBJ::add(std::string key)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k;
	k.SetString(key.c_str(), key.length(), allocator);
	document.AddMember(k, "", allocator);

}

void JsonOBJ::add(std::string key, std::string value)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k, v;

	k.SetString(key.c_str(), key.length(), allocator);
	v.SetString(value.c_str(), value.length(), allocator);
	document.AddMember(k, v, allocator);

}

void JsonOBJ::add(std::string key, Board board)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value k, v;

	k.SetString(key.c_str(), key.length(), allocator);
	v.SetArray();
	
	int size = board.getSize();
	bool* clearList = board.getClearList();
	for (int i = 0; i < size; i++) 
	{
		rapidjson::Value v_pair;
		v_pair.SetObject();

		v_pair.AddMember("cleared", clearList[i], allocator);
		v.PushBack(v_pair, allocator);
	}

	document.AddMember(k, v, allocator);
}


void JsonOBJ::set(std::string key, std::string value)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value& v = document[key.c_str()];
	v.SetString(value.c_str(), value.length(), allocator);
	document.AddMember("data", v, allocator);
}

std::string JsonOBJ::getStr()
{
	rapidjson::StringBuffer buffer;

	buffer.Clear();

	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	document.Accept(writer);

	return std::string(buffer.GetString());
}
