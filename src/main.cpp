#include <argp.h>
#include "../include/note.hpp"

Note *note = new Note();
static int parseOptions(int key, char *arg,
		struct argp_state *state) {
	switch(key) {
		case 'a':
			note->add(arg);
			break;
		case 'd':
			note->del(std::strtol(arg, nullptr, 0));
			break;
	}
	return 0;
}

int main(int argc, char **argv) {
	if(argc == 1) {
		note->list();
	}
	else {
		struct argp_option options[] = {
		{"add", 'a', "string", 0, "Add an entry"},
		{"delete", 'd', "int", 0, "Delete [n]th entry"},
		{ 0 }
		};
		struct argp argp = { options, parseOptions };
		return argp_parse(&argp, argc, argv, 0, 0, 0);
	}
}
