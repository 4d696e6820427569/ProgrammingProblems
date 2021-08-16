/**
 * Single source shortest path algorithms playground.
 */

#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <iostream>
#include <utility>

using std::vector;
using std::set;
using std::cout;
using std::numeric_limits;
using std::pair;

struct GraphVertex
{
    struct VertexWithDistance
    {
        GraphVertex& vertex;
        int dist;
    };

    vector<VertexWithDistance> edges;

    int dist = numeric_limits<int>::max();

    int id;

    GraphVertex(int nid) : id(nid) {};

    // The predecessor in the shortest path.
    const GraphVertex* pred = nullptr;
};

struct Comp
{
    bool operator()(const GraphVertex* lhs, const GraphVertex* rhs) const
    {
        return lhs->dist < rhs->dist;
    };
};

void OutputShortestPath(const GraphVertex* v)
{
    if (v) {
        OutputShortestPath(v->pred);
        std::cout << v->id << " ";
    }
}

void DijkstraShortestPath(GraphVertex* s, const GraphVertex* t)
{
    s->dist = 0;
    set<GraphVertex*, Comp> node_set;
    node_set.emplace(s);

    while (!node_set.empty()) {
        // Extracts the minimum distance vertex from the BST.
        GraphVertex* u = *node_set.cbegin();

        if (u->id == t->id) break;

        node_set.erase(node_set.cbegin());

        // Relax neighboring vertices of u.
        for (const GraphVertex::VertexWithDistance& v : u->edges) {
            // Distance to v = distance to u + the weight of the edge from
            // u to v.
            int dist_to_v = u->dist + v.dist;
            
            // If the total distance from u to v is less than the record
            // distance to v, update the recorded distance to v. Also
            // update the shortest path.
            if (dist_to_v < v.vertex.dist) {
                v.vertex.pred = u;
                v.vertex.dist = dist_to_v;
                node_set.emplace(&v.vertex);
            }
        }
    }

    OutputShortestPath(t);
    printf("\nDistance: %d\n", t->dist);
}

int main()
{
    vector<GraphVertex> tc;
    int tc_n = 9;
    for (int i = 0; i < tc_n; i++)
        tc.emplace_back(GraphVertex(i));

    tc[0].edges.emplace_back(GraphVertex::VertexWithDistance{tc[1], 4});
    tc[0].edges.emplace_back(GraphVertex::VertexWithDistance{tc[7], 8});

    tc[1].edges.emplace_back(GraphVertex::VertexWithDistance{tc[0], 4});
    tc[1].edges.emplace_back(GraphVertex::VertexWithDistance{tc[2], 8});
    tc[1].edges.emplace_back(GraphVertex::VertexWithDistance{tc[7], 11});

    tc[2].edges.emplace_back(GraphVertex::VertexWithDistance{tc[1], 8});
    tc[2].edges.emplace_back(GraphVertex::VertexWithDistance{tc[3], 7});
    tc[2].edges.emplace_back(GraphVertex::VertexWithDistance{tc[5], 4});
    tc[2].edges.emplace_back(GraphVertex::VertexWithDistance{tc[8], 2});

    tc[3].edges.emplace_back(GraphVertex::VertexWithDistance{tc[2], 7});
    tc[3].edges.emplace_back(GraphVertex::VertexWithDistance{tc[4], 9});
    tc[3].edges.emplace_back(GraphVertex::VertexWithDistance{tc[5], 14});

    tc[4].edges.emplace_back(GraphVertex::VertexWithDistance{tc[3], 9});
    tc[4].edges.emplace_back(GraphVertex::VertexWithDistance{tc[5], 10});

    tc[5].edges.emplace_back(GraphVertex::VertexWithDistance{tc[2], 4});
    tc[5].edges.emplace_back(GraphVertex::VertexWithDistance{tc[3], 14});
    tc[5].edges.emplace_back(GraphVertex::VertexWithDistance{tc[4], 10});
    tc[5].edges.emplace_back(GraphVertex::VertexWithDistance{tc[6], 2});

    tc[6].edges.emplace_back(GraphVertex::VertexWithDistance{tc[5], 2});
    tc[6].edges.emplace_back(GraphVertex::VertexWithDistance{tc[7], 1});
    tc[6].edges.emplace_back(GraphVertex::VertexWithDistance{tc[8], 6});

    tc[7].edges.emplace_back(GraphVertex::VertexWithDistance{tc[0], 8});
    tc[7].edges.emplace_back(GraphVertex::VertexWithDistance{tc[1], 11});
    tc[7].edges.emplace_back(GraphVertex::VertexWithDistance{tc[6], 1});
    tc[7].edges.emplace_back(GraphVertex::VertexWithDistance{tc[8], 7});

    tc[8].edges.emplace_back(GraphVertex::VertexWithDistance{tc[2], 2});
    tc[8].edges.emplace_back(GraphVertex::VertexWithDistance{tc[6], 6});
    tc[8].edges.emplace_back(GraphVertex::VertexWithDistance{tc[7], 1});

    printf("Shortest path between 0 and 4:\n");
    DijkstraShortestPath(&tc[0], &tc[4]);
    printf("\n");
    return 0;
}
