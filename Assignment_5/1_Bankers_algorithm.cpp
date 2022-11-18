#include <bits/stdc++.h>
using namespace std;

struct banker
{
    int id;
    int max_need;
    int current_need;
    int allocation;
    bool is_complete = false;
};

void banker_algorithm(struct banker b[] , int total_process , int total_resource)
{
    // 1 step calculate the current need of the all process
    for(int i = 0; i < total_process ; i++)
    {
        b[i].current_need = b[i].max_need - b[i].allocation;
    }

    // 2nd step calculate the available resource
    int total_allocation = 0;
    for(int i = 0; i < total_process ; i++)
    {
        total_allocation += b[i].allocation;
    }

    // 3rd step will be calculate the remaining resource
    int remaining_resource = total_resource - total_allocation;

    bool flag = true;

    while(flag)
    {
        bool process_found = false;
        for(int i = 0; i < total_process ; i++)
        {
            if(b[i].current_need <= remaining_resource  && b[i].is_complete == false)
            {
                process_found = true;
                b[i].is_complete = true;
                remaining_resource += b[i].allocation;
                cout << " P " << b[i].id << "->";
                break;
            }
        }

        if(process_found == false)
            flag = false;
    }

    bool is_safe_sequence;
    for(int i = 0 ; i < total_process ; i++)
    {
        if(b[i].is_complete == false)
        {
            is_safe_sequence = false;
        }
    }

    if(is_safe_sequence)
    {
        cout << "Safe Sequence " << endl;
    }

    else
    {
        cout << "Unsafe sequence " << endl;
    }
}

int main()
{
    int total_resource;
    cout << "Enter the total resource : ";
    cin >> total_resource;

    int total_process;
    cout << "Enter the total process : ";
    cin >> total_process;

    struct banker b[total_process];

    for(int i = 0; i < total_process ; i++)
    {
        int p;
        cout << "Enter for Process " + to_string(i+1) + " Max Allocation : ";
        cin >> p;

        int a;
        cout << "Enter for Process " + to_string(i+1) + " Allocation : ";
        cin >> a;

        b[i].id = i+1;
        b[i].max_need = p;
        b[i].allocation= a;
    }

    banker_algorithm(b , total_process , total_resource);
}


