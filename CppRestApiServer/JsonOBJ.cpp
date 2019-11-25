#include "JsonOBJ.h"
#include<string>

JsonOBJ::JsonOBJ()
{
	document.SetObject();
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

	for (bool card : board.getClearList()) {
		v.PushBack(card, allocator);
	}

	document.AddMember(k, v, allocator);
}


void JsonOBJ::set(std::string key, std::string value)
{
	auto& allocator = document.GetAllocator();
	rapidjson::Value& v = document[key.c_str()];
	v.SetString(value.c_str(), value.length(), allocator);
}

std::string JsonOBJ::getDoc()
{
	rapidjson::StringBuffer buffer;

	buffer.Clear();

	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	document.Accept(writer);

	return std::string(buffer.GetString());
}
