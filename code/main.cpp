//
// Created by Kunming Yang on 2020-02-02.
//

#include <iostream>
#include <boost/version.hpp>
#include <boost/graph/adjacency_list.hpp>


using namespace std;
using namespace boost;
int main()
{
    adjacency_list<> g;

    adjacency_list<>::vertex_descriptor v1 = add_vertex(g);
    adjacency_list<>::vertex_descriptor v2 = add_vertex(g);
    adjacency_list<>::vertex_descriptor v3 = add_vertex(g);
    adjacency_list<>::vertex_descriptor v4 = add_vertex(g);

    cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << '\n';
}