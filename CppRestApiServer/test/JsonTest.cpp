
#include "../Test.h"
#include "../JsonOBJ.h"
#include "../game/Board.h"
#include <iostream>

int JsonTest() {

	JsonOBJ* json_tester = new JsonOBJ();
	Board board(4);

	json_tester->add("abc");
	json_tester->add("aaa", "bbb");
	json_tester->set("abc", "bbb");

	json_tester->add("data", board);

	std::cout << json_tester->getDoc().c_str();

	return 0;
}