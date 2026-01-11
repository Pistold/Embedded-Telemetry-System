#include "scheduler.hpp"

void Scheduler::add_task(const std::function<void()>& task,
                         std::chrono::milliseconds period)
{
    Task t;
    t.func = task;
    t.period = period;
    t.next_run = std::chrono::steady_clock::now() + period;

    tasks_.push_back(t);
}

void Scheduler::tick()
{
    auto now = std::chrono::steady_clock::now();

    for (auto& task : tasks_) {
        if (now >= task.next_run) {
            task.func();
            task.next_run = now + task.period;
        }
    }
}