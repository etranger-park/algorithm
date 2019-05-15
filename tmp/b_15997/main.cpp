#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

enum
{
  AB = 3, // 0011
  AC = 5, // 0101
  AD = 9, // 1001
  BC = 6, // 0110
  BD = 10,// 1010
  CD = 12 // 1100
};

typedef struct
{
  double left_win;
  double draw;
  double right_win;
} Prob;

map<int, Prob> probs_map;

double get_prob(int leageu, int each_case)
{
  double result = 1.0f;
  Prob prob = probs_map.find(leageu)->second;
  switch (each_case)
  {
    case 0:
      return prob.left_win;
      break;
    case 1:
      return prob.draw;
      break;
    case 2:
      return prob.right_win;
      break;
  }
  printf("Wrong Case leageu: %d case %d\n",leageu,each_case);
  return result;
}

int main()
{
  map<string, int> name_map;
  for(int i = 0; i < 4; i++)
  {
    string name;
    cin >> name;
    name_map.insert(make_pair(name, i));
  }
  for(int i = 0; i<6; i++) // 4개 팀 총 리그 수 6
  {
    string t1, t2;
    double a,d,l;
    cin >> t1 >> t2 >> a >> d >> l;
    int t1_index = name_map.find(t1)->second;
    int t2_index = name_map.find(t2)->second;
    Prob prob;
    bool left_small = t1_index < t2_index;
    prob.left_win = left_small ? a : l;
    prob.draw = d;
    prob.right_win = left_small ? l : a;
    int key = (1 << t1_index) + (1 << t2_index);
    probs_map.insert(make_pair(key, prob));
  }
  double total_prob[] = {0, 0, 0, 0};
  int total_case = 729; // 3 ^ 6
  for(int i=0; i<total_case; i++)
  {
    // 0 left win, 1 draw, 2 right win
    int test_cd = i / 243;
    int test_bd = (i / 81) % 3;
    int test_bc = (i / 27) % 3;
    int test_ad = (i / 9) % 3;
    int test_ac = (i / 3) % 3;
    int test_ab = i % 3;
    // printf("%d %d %d %d %d %d\n",test_ab, test_ac, test_ad, test_bc, test_bd, test_cd);
    int score[] = {0, 0, 0, 0}; //score of a,b,c,d
    double prob = 1.0f;
    if(test_cd == 0)
      score[2] += 3; // C win
    else if(test_cd == 1)
    {
      score[2] += 1;
      score[3] += 1;
    }
    else
      score[3] += 3;

    if(test_bd == 0)
      score[1] += 3;
    else if(test_bd == 1)
    {
      score[1] += 1;
      score[3] += 1;
    }
    else
      score[3] += 3;
    
    if(test_bc == 0)
      score[1] += 3;
    else if(test_bc == 1)
    {
      score[1] += 1;
      score[2] += 1;
    }
    else
      score[2] += 3;
    
    if(test_ad == 0)
      score[0] += 3;
    else if(test_ad == 1)
    {
      score[0] += 1;
      score[3] += 1;
    }
    else
      score[3] += 3;
    
    if(test_ac == 0)
      score[0] += 3;
    else if(test_ac == 1)
    {
      score[0] += 1;
      score[2] += 1;
    }
    else
      score[2] += 3;
    
    if(test_ab == 0)
      score[0] += 3;
    else if(test_ab == 1)
    {
      score[0] += 1;
      score[1] += 1;
    }
    else
      score[1] += 3;
  
    prob *= get_prob(AB,test_ab);
    prob *= get_prob(AC,test_ac);
    prob *= get_prob(AD,test_ad);
    prob *= get_prob(BC,test_bc);
    prob *= get_prob(BD,test_bd);
    prob *= get_prob(CD,test_cd);

    // 상위 두 명 찾기
    int first_num = 0, second_num = 0;
    int first_score = -1, second_score = -2;
    // cout << "score: ";
    for(int j=0; j<4; j++)
    {
      if(score[j] == first_score)
        first_num ++;
      else if(score[j] > first_score)
      {
        second_num = first_num;
        second_score = first_score;
        first_num = 1;
        first_score = score[j];
      }
      else if(score[j] == second_score)
        second_num++;
      else if(score[j] > second_score)
      {
        second_num = 1;
        second_score = score[j];
      }
      // cout << score[j]<<" ";
    }
    // cout << endl;
    // printf("first num:%d score:%d  second num:%d, score:%d \n",first_num, first_score, second_num, second_score);
    // printf("prob %f\n",prob);
    
    for(int j = 0; j<4; j++)
    {
      if(score[j]==first_score)
      {
        if(first_num > 1)
          total_prob[j] += (prob * 2.0 / (double)first_num);
        else if(first_num == 1)
          total_prob[j] += prob;
      }
      else if(first_num == 1 && score[j] == second_score)
      {
        total_prob[j] += (prob / (double) second_num);
      }
      // cout << total_prob[j] <<' ';
    }
    // cout << endl;
  }
  for(int i = 0; i < 4;i++)
  {
    printf("%.9f\n",total_prob[i]);
  }
  return 0;
}