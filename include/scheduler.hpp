#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <functional>
#include <vector>
#include <chrono>

// Represents a single scheduled task
struct Task {
    std::function<void()> func;                     // Function to execute
    std::chrono::milliseconds period;               // Execution period
    std::chrono::steady_clock::time_point next_run; // Next scheduled time
};

// Simple cooperative scheduler (embedded)
class Scheduler {
public:

    Scheduler() = default;
    ~Scheduler() = default;

    // Prevent copying
    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;

    // Allow move movement if needed
    Scheduler(Scheduler&&) = default;
    Scheduler& operator=(Scheduler&&) = default;
    
    // Add a task that runs every period
    void add_task(const std::function<void()>& task,
                  std::chrono::milliseconds period);

    // Call this regularly from the main loop
    void tick();

private:
    std::vector<Task> tasks_;
};

#endif // SCHEDULER_HPP