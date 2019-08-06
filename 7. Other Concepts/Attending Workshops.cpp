#include<bits/stdc++.h>
using namespace std;

///Editable
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

const unsigned int N = 100001;
///Structures
struct Workshop
{
    int start_time, duration, end_time;

};
struct Available_Workshops
{
    int no_wp;
    Workshop *type_wp = new Workshop[N];
};

///Functions
Available_Workshops* initialize (int start_times[], int durations[], int n)
{
    Available_Workshops* aw = new Available_Workshops();
    aw->no_wp = n;

    // Create array of workshops
    for (int i=0; i<n; i++)
    {
        Workshop wp;
        wp.start_time = start_times[i];
        wp.end_time = start_times[i] + durations[i];
        wp.duration = durations[i];

        aw->type_wp[i] = wp;
    }

    return aw;
}
bool operator<(Workshop const & a, Workshop const & b)
{
      return a.end_time < b.end_time;
}
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int max_ws = 1;
    int no_ws = ptr->no_wp;
    Workshop *wp = ptr->type_wp;
    sort(wp, wp+no_ws);
    Workshop prev = wp[0];
    for (int i=1 ; i<no_ws; i++)
    {
        Workshop current = wp[i];
        if (current.start_time >= prev.end_time)
        {
            max_ws++;
            prev = current;
        }
    }
    return max_ws;
}

///Ends

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

/**
Problem Tester's code:

#include<bits/stdc++.h>

using namespace std;
typedef struct Workshops
{
    int s,d,e;
}Workshops;

typedef struct Available_Workshops
{
    int n;
    Workshops *shops;
    Available_Workshops(int t)
    {
        n = t;
        shops = (Workshops*)malloc(t*sizeof(Workshops));
    }
}Available_Workshops;

bool comp(const Workshops &a, const Workshops &b)
{
    if(a.e < b.e)
        return true;
    return false;
}
Available_Workshops* initialize (int start_time[], int duration[] ,int N)
{
    Available_Workshops* node = new Available_Workshops(N);
    for(int i =0 ; i< node->n; i++)
    {
        (node->shops)[i].s = start_time[i];
        (node->shops)[i].d = duration[i];
        (node->shops)[i].e = start_time[i] + duration[i];
    }
    return node;
}

int CalculateMaxWorkshops (Available_Workshops* ptr)
{
    sort(ptr->shops, ptr->shops + ptr->n, comp);
    int ans = 1, t;
    for(int i = 0 ; i < ptr->n; i++)
    {
        if(i == 0)
        {
            t = (ptr->shops[i]).e;
            continue;
        }
        if((ptr->shops[i]).s>=t)
        {
            ans++;
            t = (ptr->shops[i]).e;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }

    Available_Workshops* ptr;
    ptr=initialize(start_time,duration,n);
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    return 0;
}
*/
