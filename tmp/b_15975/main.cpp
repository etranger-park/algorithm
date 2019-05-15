#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct Singer
{
  int num_songs;
  float score;
  int over_time;
  Singer():num_songs(1),score(0), over_time(-1){};
};

struct Song
{
  int id;
  int singer;
  int num_songs; // include my self
  map<int, int> sub_tree_singer; //singer id, num
  vector<int> child_songs; // id of songs
  bool check;
  Song():check(false){};
};

struct Data
{
  int t;
  int id_song;
  int score;
  Data(int t, int id_song, int score):t(t), id_song(id_song), score(score){};
};

struct cmp{
    bool operator()(Data left, Data right){
        return left.t > right.t; // 시간 오름차순
    };
};

vector<Song> vec_song;

void SearchSubTree()
{
  stack<int> st;
  st.push(1);
  while(!st.empty())
  {
    int song_id = st.top();
    st.pop();
    Song &song = vec_song[song_id - 1];
    song.check = true;
    vector<int>::iterator it;
    bool finish = true;
    for(it = song.child_songs.begin(); it != song.child_songs.end(); it++)
    {
      Song &child_song = vec_song[*it - 1];
      if(!child_song.check)
      {
        st.push(song.id);
        st.push(child_song.id);
        finish = false;
        break;
      }
    }
    if(finish)
    {
      song.sub_tree_singer.insert(make_pair(song.singer, 1));
      song.num_songs = 1;
      vector<int>::iterator it;
      for(it = song.child_songs.begin(); it != song.child_songs.end(); it++)
      {
        Song &child_song = vec_song[*it - 1];
        map<int, int>::iterator sub_tree_it;
        map<int, int>::iterator child_sub_tree_it;
        for(child_sub_tree_it = child_song.sub_tree_singer.begin();child_sub_tree_it!=child_song.sub_tree_singer.end(); child_sub_tree_it++)
        {
          int singer = child_sub_tree_it->first;
          int num = child_sub_tree_it->second;
          song.num_songs += num;
          sub_tree_it = song.sub_tree_singer.find(singer);
          if(sub_tree_it == song.sub_tree_singer.end())
          {
            song.sub_tree_singer.insert(make_pair(singer, num));
          }
          else
          {
            sub_tree_it->second +=num;
          }
        }
      }
    }
  }
}

int main()
{
  priority_queue< Data, vector<Data>, cmp> datas;
  map<int, Singer> map_singer; // id, singer

  int num_song, num_data, target_score;
  cin >> num_song >> num_data >> target_score;
  vec_song.assign(num_song,Song());
  vec_song[0].id = 1;
  for(int i = 1; i < num_song; i++)
  {
    // set parent
    int parent;
    cin >> parent;
    vec_song[i].id = i + 1;
    vec_song[parent - 1].child_songs.push_back(i+1);
  }
  map<int, Singer>::iterator singer_it;
  for(int i = 0; i < num_song; i++)
  {
    // set singer
    int singer;
    cin >> singer;
    vec_song[i].singer = singer;
    singer_it = map_singer.find(singer);
    if(singer_it != map_singer.end())
    {
      singer_it->second.num_songs++;
    }
    else
    {
      map_singer.insert(make_pair(singer,Singer()));
    }
  }

  SearchSubTree(); // Makes Tree
  for(int i = 0; i < num_data; i++)
  {
    int t, id, score;
    cin >> t >> id >> score;
    datas.push(Data(t,id,score));
  }
  while(!datas.empty())
  {
    Data data = datas.top();
    datas.pop();
    Song &song = vec_song[data.id_song - 1];
    map<int, int>::iterator sub_singer_it;
    // printf("Data time:%d, score:%d, root:%d\n",data.t, data.score,data.id_song);
    for(sub_singer_it = song.sub_tree_singer.begin(); sub_singer_it != song.sub_tree_singer.end(); sub_singer_it++)
    {
      singer_it = map_singer.find(sub_singer_it->first);
      if(singer_it != map_singer.end())
      {
        Singer &singer = singer_it->second;
        singer.score += ((data.score / song.num_songs) * sub_singer_it->second) / (float)(singer.num_songs);
        // printf("singer id: %d, singer score %f\n",singer.id, singer.score);
        if(singer.over_time < 0 && singer.score > (float)target_score)
        {
          singer.over_time = data.t;
        } 
      }
    }
  }
  for(int i = 0; i < num_song; i++)
  {
    Song &song = vec_song[i];
    singer_it = map_singer.find(song.singer);
    printf("%d\n",singer_it->second.over_time);
  }
  return 0;
}