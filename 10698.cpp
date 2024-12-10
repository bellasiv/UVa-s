//
//Isabella Erazo Fernández - 10/13/2024
// wrong answer :<
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

struct Scores{
    string teams;
    int points; 
    int gamesPlayed;
    int goals;
    int sufferedGoals;
    int goalDifference;
    double percentageEarned;

    bool operator<(const Scores &other) const {
        bool ans;

        if(points != other.goals){
            ans = points > other.points;
        }else if(goalDifference != other.goalDifference){
            ans = goalDifference > other.goalDifference;
        }else if(goals != other.goals){
            ans = goals > other.goals;
        }else if(teams != other.teams){
            ans = teams < other.teams;
        }
        return ans;
    };  
};


int main(){
    int goals, num1, num2, total_points;
    map<string,Scores>::iterator it, ti;
    map<string,Scores> stats;
    char equi[15], equi2[15];
    vector<Scores> scores;
    int T, G; 

    while(scanf("%d %d", &T, &G) == 2 && T != 0 && G != 0){
        Scores s;

        s.gamesPlayed = 0;
        s.goalDifference = 0;
        s.goals = 0;
        s.percentageEarned = 0;
        s.points = 0;
        s.sufferedGoals = 0;

        stats.clear();
        
        for(int i= 0; i<T; i++){
            scanf("%s",&equi);
            string s1(equi);
            s.teams = s1;
            stats[s1] = s;
        }

        for(int i=0; i<G; i++){
            scanf("%s %d - %d %s", &equi, &num1, &num2, &equi2);
            string s1(equi), s2(equi2);

            it = stats.find(s1);
            ti = stats.find(s2);

            (it->second).gamesPlayed++;
            (ti->second).gamesPlayed++;

            if(num1 == num2){
                (it->second).points++;
                (ti->second).points++;
            }
            if(num1 > num2){
                (it->second).points += 3;
            }
            if(num2 > num1){
                (ti->second).points += 3;        
            }

            (it->second).goals += num1;
            (ti->second).goals += num2;

            (it->second).sufferedGoals += num2;
            (ti->second).sufferedGoals += num1;

            (it->second).goalDifference = (it->second).goals - (it->second).sufferedGoals;
            (ti->second).goalDifference = (ti->second).goals - (ti->second).sufferedGoals;

            (it->second).percentageEarned = (double)((it->second).points *100.0)/(double)((it->second).gamesPlayed*3);
            (ti->second).percentageEarned = (double)((ti->second).points *100.0)/(double)((ti->second).gamesPlayed*3);
        }

        for(it=stats.begin(); it != stats.end(); it++){
            scores.push_back(it->second);
        }

        sort(scores.begin(), scores.end());

        int num;
        for(int i=0; i<scores.size(); i++){ 
            if( i > 0 && (scores[i].points == scores[i-1].points) && (scores[i].gamesPlayed == scores[i-1].gamesPlayed)
            &&(scores[i].goals == scores[i-1].goals) && (scores[i].sufferedGoals == scores[i-1].sufferedGoals)
            &&(scores[i].goalDifference == scores[i-1].goalDifference) && (scores[i].percentageEarned == scores[i-1].percentageEarned)){
                printf("   ");
            } else {  
                num = i+1;
                printf("%2d.",num);
            }
            printf("%16s %3d %3d %3d %3d %3d", scores[i].teams.c_str(),scores[i].points, scores[i].gamesPlayed, scores[i].goals, 
            scores[i].sufferedGoals, scores[i].goalDifference);

            if(scores[i].gamesPlayed == 0){
                printf(" %6s\n","N/A");
            } else {
                printf(" %6.2lf\n",scores[i].percentageEarned);
            }
        }
    }
    return 0; 
}
