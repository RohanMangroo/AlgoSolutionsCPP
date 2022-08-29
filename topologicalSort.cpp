#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
using nestedVector = vector<vector<int>>;
using intVect = vector<int>;
using boolMap = unordered_map<int, bool>;
using intVectMap = unordered_map<int, intVect>;

void print(intVectMap completed)
{
    for (auto item : completed)
    {
        cout << item.first << ": ";

        for (int i = 0; i < item.second.size(); i++)
        {
            cout << item.second[i] << " ";
        }
        cout << endl;
    }
}

intVectMap createAdjList(intVect jobs, nestedVector dep)
{
    intVectMap adjList;

    for (int i = 0; i < jobs.size(); i++)
    {
        int currJob = jobs[i];
        intVect vec;
        adjList[currJob] = vec;
    };

    for (int i = 0; i < dep.size(); i++)
    {
        intVect currDep = dep[i];

        int job = currDep[1];
        int dep = currDep[0];
        adjList[job].push_back(dep);
    }
    return adjList;
}

void traverseJobs(intVectMap &adjList, int currJob, boolMap &completed, boolMap &inProgress, intVect &result)
{
    if (completed.find(currJob) != completed.end())
        return;
    if (completed.find(-1) != completed.end())
        return;

    if (inProgress.find(currJob) == inProgress.end())
        inProgress[currJob] = true;
    else
    {
        completed[-1] = true;
        return;
    };

    intVect depsOfCurrJob = adjList[currJob];

    for (int i = 0; i < depsOfCurrJob.size(); i++)
    {
        int currDep = depsOfCurrJob[i];
        traverseJobs(adjList, currDep, completed, inProgress, result);
    }

    inProgress.erase(currJob);
    completed[currJob] = true;
    result.push_back(currJob);
}

intVect topologicalSort(intVect jobs, nestedVector deps)
{
    cout << boolalpha << endl;

    intVectMap adjList = createAdjList(jobs, deps);
    boolMap completed;
    boolMap inProgress;
    intVect result;

    for (int i = 0; i < jobs.size(); i++)
    {
        int currJob = jobs[i];
        cout << currJob << endl;
        traverseJobs(adjList, currJob, completed, inProgress, result);
    }

    // print(adjList);

    vector<int> vect;

    if (completed.find(-1) != completed.end())
        return vect;
    else
        return result;
}

// unordered_map <int, bool> completed;
// completed[1] = false;

// for(auto item: completed){
//     cout << item.first << " " << item.second endl;
//   }