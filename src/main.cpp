#include <argp.h>
#include "../include/note.hpp"

std::unique_ptr<Note> note = std::make_unique<Note>();

bool show_completed = false;

static int parseOptions(int key, char *arg,
                        struct argp_state *state) {
    switch(key) {
        case 'x':
            show_completed = true;
            break;
        case 'l':
            note->list(show_completed);
            break;
        case 'a':
            note->add(arg);
            break;
        case 's':
            note->show(std::strtol(arg, nullptr, 0));
            break;
        case 'c':
            note->complete(std::strtol(arg, nullptr, 0));
            break;
        case 'd':
            std::vector<int> numbers;
            std::stringstream ss(arg);
            int i;
            while (ss >> i)
            {
                numbers.push_back(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            note->del(numbers);
            break;
    }
    return 0;
}

int main(int argc, char **argv) {
    if(argc == 1) {
        note->list(false);
    }
    else {
        struct argp_option options[] = {
        {"add", 'a', "string", 0, "Add an entry"},
        {"delete", 'd', "int", 0, "Delete [n]th entry"},
        {"delete", 'd', "list", 0, "Delete [n]th entries"},
        {"show-completed", 'x', 0, 0, "Show entries that are marked as completed while listing"},
        {"list", 'l', 0, 0, "List all entries"},
        {"show", 's', "int", 0, "Show [n]th entry"},
        {"complete", 'c', "int", 0, "Mark [n]th entry as completed"},
        { 0 }
        };
        struct argp argp = { options, parseOptions };
        return argp_parse(&argp, argc, argv, 0, 0, 0);
    }
}
