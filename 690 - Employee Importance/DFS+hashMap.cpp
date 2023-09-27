/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        auto IDToPointer = std::unordered_map<int, Employee*>{};
        for (const auto& employee : employees)
        {
            IDToPointer[employee->id] = employee;
        }

        auto totalImportance{ 0 };
        auto DFS = std::stack<int>();
        DFS.push(id);

        while (!DFS.empty())
        {
            auto employee = IDToPointer[DFS.top()];
            DFS.pop();
            totalImportance += employee->importance;

            for (const auto& subordinate : employee->subordinates)
            {
                DFS.push(subordinate);
            }
        }

        return totalImportance;
    }
};