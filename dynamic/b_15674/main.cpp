#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200001
#define MAX_D 200001
#define MAX_G 1000000001
#define MAX_P 1000000001

using namespace std;

int N,D,Q;//constant
int cost_g[MAX_N];
int cost_p[MAX_N];
vector<int> request_same[MAX_N];
vector<int> request_diff[MAX_N];

char result_arr[MAX_N] = {0};
char g_arr[MAX_N] = {0};
char p_arr[MAX_N] = {0};
int root_Node[MAX_N] = {0};
uint64_t min_arr[MAX_N] = {0};
uint64_t max_arr[MAX_N] = {0};

uint64_t get_cost(int src,int src_value,char *arr)
{
    uint64_t result = (uint64_t) (src_value == 1 ? cost_g[src] : cost_p[src]);
    int min_node = src;
    *(arr + src) = src_value;
    vector<int>::iterator it;
    for(it=request_diff[src].begin();it!=request_diff[src].end();it++)
    {
        if(*it < min_node) min_node = *it;
        if(*(arr+ *(it)) != 0) continue;
        result+=get_cost(*(it),(src_value == 1 ? 2:1) ,arr);
    }
    for(it=request_same[src].begin();it!=request_same[src].end();it++)
    {
        if(*it < min_node) min_node = *it;
        if(*(arr+ *(it)) != 0) continue;
        result+=get_cost(*(it),(src_value == 1 ? 1:2) ,arr);
    }
    root_Node[src] = min_node;
    return result;
}

uint64_t find_init()
{
    int i,j;
    uint64_t result = 0;
    for(i=1;i<=N;i++)
    {
        if(result_arr[i]!=0) continue;
        if(request_diff[i].empty() && request_same[i].empty())
        {
            int tree = min(cost_g[i],cost_p[i]);
            if(tree==cost_g[i])
            {
                result_arr[i]=1;
                max_arr[i] = cost_p[i];
            }
            else
            {
                result_arr[i]=2;
                max_arr[i] = cost_g[i];
            }
            min_arr[i] = tree;
            root_Node[i] = i;
            result += (uint64_t) tree;
            //cout << i<<"th "<<"cost:"<<tree<<endl;
        }
        else
        {
            uint64_t result_g = get_cost(i,1,g_arr);
            uint64_t result_p = get_cost(i,2,p_arr);
            if(result_g < result_p)
            {
                //cout << src << ": g is more small " << result_g << endl;
                result+=result_g;
                for(j=1;j<=N;j++)
                {
                    if(g_arr[j]!=-1)
                        result_arr[j] = g_arr[j];
                    g_arr[j] = -1; p_arr[j] = -1;
                }
                min_arr[i] = result_g;
                max_arr[i] = result_p;
            }
            else
            {
                //cout << src << ": p is more small " << result_p << endl;
                result +=result_p;
                for(j=1;j<=N;j++)
                {
                    if(p_arr[j]!=0)
                        result_arr[j] = p_arr[j];
                    g_arr[j] = 0; p_arr[j] = 0;
                }
                min_arr[i] = result_p;
                max_arr[i] = result_g;
            }
        }
    }

    return result;
}

uint64_t init()
{
    cin >> N >>D;
    int i;
    uint64_t result;
    for(i=1;i<=N;i++)
    {
        int G,P;
        cin >> G >>P;
        cost_g[i] = G;
        cost_p[i] = P;
    }
    for(i=0;i<D;i++)
    {
        int C,A,B;
        cin >> C >> A >> B;
        if(C == 0)
        {
            request_same[A].push_back(B);
            request_same[B].push_back(A);
        }
        else if(C == 1)
        {
           request_diff[A].push_back(B);
           request_diff[B].push_back(A);
        }
    }
    result = find_init();
    cout << result << endl;
    return result;
}

int get_root_node(int src)
{
    int a = src;
    while(root_Node[a] < a)
        a = root_Node[a];
    return a;
}

void handling_require(uint64_t _result)
{
    int i;
    uint64_t result = _result;
    cin >> Q;
    for(i=0;i<Q;i++)
    {
        int C,A,B;
        cin >> C >> A >> B;
        switch(C)
        {
        case 0:
            request_same[A].push_back(B);
            request_same[B].push_back(A);
            int root_a, root_b;
            root_a = get_root_node(A);
            root_b = get_root_node(B);
            if(result_arr[A] == result_arr[B])
            {
                cout << result << endl;
                if(root_a < root_b)
                {
                    root_Node[root_b] = root_a;
                    min_arr[root_a] += min_arr[root_b];
                    max_arr[root_a] += max_arr[root_b];
                }
                else
                {
                    root_Node[root_a] = root_b;
                    min_arr[root_b] += min_arr[root_a];
                    max_arr[root_b] += max_arr[root_a];
                }
                continue;
            }
            else
            {
                const uint64_t case1 = min_arr[root_a] + max_arr[root_b];
                const uint64_t case2 = min_arr[root_b] + max_arr[root_a];
                if(case1 < case2)
                {
                    result = result - min_arr[root_b] + max_arr[root_b];
                    if(root_a < root_b)
                    {
                        root_Node[root_b] = root_a;
                        min_arr[root_a] = case1;
                        max_arr[root_a] = case2;
                    }
                    else
                    {
                        root_Node[root_a] = root_b;
                        min_arr[root_b] = case1;
                        max_arr[root_b] = case2;
                    }
                }
                else
                {
                    result = result - min_arr[root_a] + max_arr[root_a];
                    if(root_a < root_b)
                    {
                        root_Node[root_b] = root_a;
                        min_arr[root_a] = case2;
                        max_arr[root_a] = case1;
                    }
                    else
                    {
                        root_Node[root_a] = root_b;
                        min_arr[root_b] = case2;
                        max_arr[root_b] = case1;
                    }
                }
                cout << result << endl;
            }
            break;
        case 1:
            request_diff[A].push_back(B);
            request_diff[B].push_back(A);
            if(result_arr[A] != result_arr[B])
            {
                cout << result << endl;
                continue;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }
}

int main()
{
    int i;
    uint64_t result = init();
    handling_require(result);
    return 0;
}
