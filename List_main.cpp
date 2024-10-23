#include "list.h"
#include "process.h"
#include "dynamic_List.h"

int main() {
    Dynamic_List<Process> processList_d;
    List<Process> processList_s(5);


    Process p1 = {1, "Process 1", 0, 612};
    Process p2 = {2, "Process 2", 5, 456};
    Process p3 = {3, "Process 3", 3, 1048};
    Process p4 = {4, "Process 4", 4, 4155};
    Process p5 = {5, "Process 5", 1, 46565};

    processList_d.add(p1, 0);
    processList_d.add(p2, 1);
    processList_d.add(p3, 2);
    processList_d.add(p4, 3);
    processList_d.add(p5, 4);

    processList_s.add(p1, 0);
    processList_s.add(p2, 1);
    processList_s.add(p3, 2);
    processList_s.add(p4, 3);
    processList_s.add(p5, 4);

    std::cout << "Dynamic List:" << std::endl;
    processList_d.display();

    std::cout << "Static List:" << std::endl;
    processList_s.display();

    Process p6 = {6, "Process 6", 2, 56656};
    processList_d.add(p6, 5);

    std::cout << "Adding a new element in static List: " << std::endl;
    processList_s.add(p6, 5);

    std::cout << "Dynamic List after add a new process: " << std::endl;
    processList_d.display();

    std::cout << "Static List after add a new process: " << std::endl;
    processList_s.display();

    processList_d.remove(2);
    std::cout << "Dynamic List after remove a second process: " << std::endl;
    processList_d.display();

    processList_s.remove(2);
    std::cout << "Static List after remove a second process: " << std::endl;
    processList_s.display();

    return 0;
}