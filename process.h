#ifndef PROCESS_H
#define PROCESS_H
#include <string>
struct Process {
    int id;
    std::string name;
    int priority;
    int memory_size;
        // Определение оператора ==
    bool operator==(const Process& other) const {
        return id == other.id && name == other.name && priority == other.priority && memory_size == other.memory_size;
    }
};
    std::ostream& operator<<(std::ostream& os, const Process& p) {
    os << "ID: " << p.id << ", Name: " << p.name << ", Priority: " << p.priority << ", Memory size: " << p.memory_size;
    return os;
}

#endif // PROCESS_H
