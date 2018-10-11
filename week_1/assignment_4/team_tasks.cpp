//
// Created by d.eroshenkov on 03.10.2018.
//

#include <map>
#include <string>
#include <iostream>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus
{
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const
    {
        return members.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person)
    {
        members[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count)
    {
        if (!members.count(person))
        {
            return {};
        }

        int undone_tasks = members.at(person)[TaskStatus::TESTING] + members.at(person)[TaskStatus::NEW] +
                           members.at(person)[TaskStatus::IN_PROGRESS];

        if (task_count > undone_tasks)
        {
            task_count = undone_tasks;
        }

        TasksInfo updated_tasks;
        TasksInfo untouched_tasks;
        TasksInfo tasks = GetPersonTasksInfo(person);

        int num_tasks = min(task_count, tasks.at(TaskStatus::NEW));

        if (num_tasks)
        {
            members.at(person)[TaskStatus::NEW] -= num_tasks;
            members.at(person)[TaskStatus::IN_PROGRESS] += num_tasks;
            updated_tasks[TaskStatus::IN_PROGRESS] += num_tasks;
            task_count -= num_tasks;
        }
        int num = tasks.at(TaskStatus::NEW) - num_tasks;

        if (num)
        {
            untouched_tasks[TaskStatus::NEW] += num;
        }

        num_tasks = min(task_count, tasks.at(TaskStatus::IN_PROGRESS));
        if (num_tasks)
        {
            members.at(person)[TaskStatus::IN_PROGRESS] -= num_tasks;
            members.at(person)[TaskStatus::TESTING] += num_tasks;
            updated_tasks[TaskStatus::TESTING] += num_tasks;
            task_count -= num_tasks;
        }
        num = tasks.at(TaskStatus::IN_PROGRESS) - num_tasks;

        if (num)
        {
            untouched_tasks[TaskStatus::IN_PROGRESS] += num;
        }

        num_tasks = min(task_count, tasks.at(TaskStatus::TESTING));
        if (num_tasks)
        {
            members.at(person)[TaskStatus::TESTING] -= num_tasks;
            members.at(person)[TaskStatus::DONE] += num_tasks;
            updated_tasks[TaskStatus::DONE] += num_tasks;
        }
        num = tasks.at(TaskStatus::TESTING) - num_tasks;

        if (num)
        {
            untouched_tasks[TaskStatus::TESTING] += num;
        }

        return tuple(updated_tasks, untouched_tasks);
    }

private:
    map<string, TasksInfo> members;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info)
{
    cout << tasks_info[TaskStatus::NEW] << " new tasks" << ", " << tasks_info[TaskStatus::IN_PROGRESS]
         << " tasks in progress" << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" << ", "
         << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
    TeamTasks tasks;

    for (int i = 0; i < 5; ++i)
    {
        tasks.AddNewTask("Alice");
    }


//    cout << "Ilia's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//    cout << "Ivan's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//


    TasksInfo updated_tasks, untouched_tasks;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    for (int i = 0; i < 5; ++i)
    {
        tasks.AddNewTask("Alice");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
    cout << "Alice's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);


//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 3);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 3);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 3);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);

    return 0;
}