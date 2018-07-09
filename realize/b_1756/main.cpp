#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

map<int,int> min_map; //(min -> locate)
set<int> min_set;//The keys set

int up(int a)
{
    int h,new_val;
    map<int,int>::iterator it_map;
    set<int>::iterator it_set;
    if(a <= *(min_set.begin())) it_set = min_set.begin();
    else
    {
        for(it_set = min_set.end();it_set != min_set.begin();)
        {
            it_set--;
            int d_r = *(it_set);
            if(d_r == a) break;
            else if(d_r > a) continue;
            else
            {
                it_set++;
                break;
            }
        }
    }
    h = min_map[*(it_set)];
    //printf("In %d, pick height %d, radius %d\n",a,h,*(it_set));
    if(it_set != min_set.begin())
        min_set.erase(min_set.begin(),it_set);
    new_val = min_map[*(it_set)];
    min_map[*(it_set)] = --new_val;

    if(++it_set == min_set.end()) return -1;

    if(min_map[*it_set] == new_val)
    {
     //아래부터 쌓아 올려서 해당 폭을 가지는 애가 가득 찼을 때
        min_set.erase(--it_set);
    }
    return h;
}

int main()
{
    int d, n,i,max_h,min_val = 2000000000;
    scanf("%d %d",&d,&n);
    int *d_radius = (int *) malloc(sizeof(int)*d);
    int *d_min = (int *) malloc(sizeof(int)*d);
    int *n_radius = (int *) malloc(sizeof(int)*n);
    map<int,int>::iterator it_map;
    set<int>::iterator it_set;

    for(i=0;i<d;i++)
    {
        scanf("%d",d_radius + i);
        if(min_val > *(d_radius + i))
        {
            min_map.insert(pair<int,int>(min_val,i-1));
            min_set.insert(min_val);
            min_val = *(d_radius + i);

        }
        *(d_min + i) = min_val;
    }

    min_map.insert(pair<int,int>(min_val,i-1)); // insert the last min value
    min_set.insert(min_val);
    /*for(it_map=min_map.begin();it_map!=min_map.end();it_map++)
    {
        printf("%d:%d\n",it_map->first,it_map->second);
    }*/

    for(i=0;i<n;i++)
    {
        scanf("%d",n_radius + i);
        int n_val = *(n_radius + i);
        max_h = up(n_val);
        if(max_h == -1)
        {
            printf("0");
            return 0;
        }
        //printf("%d: r=%d h=%d\n",i,n_val,max_h);
    }
    printf("%d",max_h+1);

    return 0;
}
