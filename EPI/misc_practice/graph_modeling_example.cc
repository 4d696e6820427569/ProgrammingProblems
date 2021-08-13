/**
 * EPI Chapter 19 Graphs
 *
 * Suppose you were given a list of the outcomes of matches between pairs of
 * teams, with each outcome being a win or loss.
 *
 * Given teams A and B, is there a sequence of teams starting with A and ending
 * with B such that each team in the sequence has beaten the next team in the
 * sequence?
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::make_unique;
using std::unique_ptr;

struct MatchResult
{
    string winning_team, losing_team;
};

unordered_map<string, unordered_set<string>> BuildGraph(const vector<MatchResult>&);
bool IsReachableDFS(const unordered_map<string, unordered_set<string>>&, 
        const string&, const string&, unordered_set<string>*);

bool CanTeamABeatTeamB(const vector<MatchResult>& matches,
        const string& team_a, const string& team_b)
{
    return IsReachableDFS(BuildGraph(matches), team_a, team_b,
            make_unique<unordered_set<string>>().get());
}



unordered_map<string, unordered_set<string>> BuildGraph(
        const vector<MatchResult>& matches) 
{
    unordered_map<string, unordered_set<string>> graph;
    for (const MatchResult& match : matches) {
        graph[match.winning_team].emplace(match.losing_team);
    }
    return graph;
}

bool IsReachableDFS(const unordered_map<string, unordered_set<string>>& graph,
        const string& curr, const string& dest,
        unordered_set<string>* visited_ptr)
{
    unordered_set<string>& visited = *visited_ptr;
    if (curr == dest) {
        return true;
    } else if (visited.find(curr) != visited.end() ||
            graph.find(curr) == graph.end()) {
        return false;
    }

    visited.emplace(curr);
    const auto& team_list = graph.at(curr);
    return any_of(begin(team_list), end(team_list), [&](const string& team) {
            return IsReachableDFS(graph, team, dest, visited_ptr);
            });
}

int main()
{
    return 0;
}


