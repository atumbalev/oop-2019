#include <iostream>

using Procedure = void(*)();

struct final_action {
    Procedure proc;
    explicit final_action(Procedure _proc) : proc{_proc} {}
    ~final_action() { proc(); }
};

final_action finally(Procedure proc)
{
    return final_action(proc);
}

int main()
{
    final_action act = finally([](){std::cout << "Bye" << std::endl; });
    std::cout << "Hi" << std::endl;
    return 0;
}
