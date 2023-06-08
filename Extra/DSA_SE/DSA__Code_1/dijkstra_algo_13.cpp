/*
Title: Write a C++ program to implement Single Source Shortest Path problem by using 
Dijkstra’s Algorithm. 

Problem Statement: Tour operator organizes guided bus trips across the Maharashtra. 
Tourists may have different preferences. Tour operator offers a choice from many different 
routes. Every day the bus moves from starting city S to another city F as chosen by client. On 
this way, the tourists can see the sights alongside the route travelled from S to F. Client may 
have preference to choose route. There is a restriction on the routes that the tourists may choose 
from, the bus has to take a short route from S to F or a route having one distance unit longer 
than the minimal distance. Two routes from S to F are considered different if there is at least 
one road from a city A to a city B which is part of one route, but not of the other route. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Structure to represent a city and its distance from the source
struct City {
    int id;
    int distance;

    City(int id, int distance) {
        this->id = id;
        this->distance = distance;
    }
};

// Structure to represent a road between two cities
struct Road {
    int source;
    int destination;
    int distance;

    Road(int source, int destination, int distance) {
        this->source = source;
        this->destination = destination;
        this->distance = distance;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(const City& a, const City& b) {
        return a.distance > b.distance;
    }
};

// Dijkstra's algorithm to find the shortest path from the source city to all other cities
vector<int> dijkstra(const vector<vector<Road>>& graph, int source) {
    int numCities = graph.size();

    // Initialize distances to all cities as infinity except for the source city
    vector<int> distances(numCities, INT_MAX);
    distances[source] = 0;

    // Priority queue to store cities based on their distances
    priority_queue<City, vector<City>, Compare> pq;
    pq.push(City(source, 0));

    while (!pq.empty()) {
        int currentCity = pq.top().id;
        pq.pop();

        // Traverse the neighboring cities of the current city
        for (const Road& road : graph[currentCity]) {
            int neighborCity = road.destination;
            int distance = road.distance;

            // Relax the edge if a shorter path is found
            if (distances[currentCity] + distance < distances[neighborCity]) {
                distances[neighborCity] = distances[currentCity] + distance;
                pq.push(City(neighborCity, distances[neighborCity]));
            }
        }
    }

    return distances;
}

int main() {
    int numCities, numRoads;
    cout << "Enter the number of cities: ";
    cin >> numCities;
    cout << "Enter the number of roads: ";
    cin >> numRoads;

    // Create a graph representation using adjacency list
    vector<vector<Road>> graph(numCities);

    cout << "Enter the source, destination, and distance for each road:" << endl;
    for (int i = 0; i < numRoads; i++) {
        int source, destination, distance;
        cin >> source >> destination >> distance;
        graph[source].push_back(Road(source, destination, distance));
        graph[destination].push_back(Road(destination, source, distance));
    }

    int sourceCity;
    cout << "Enter the source city: ";
    cin >> sourceCity;

    // Find the shortest distances from the source city to all other cities
    vector<int> shortestDistances = dijkstra(graph, sourceCity);

    cout << "Shortest distances from city " << sourceCity << ":" << endl;
    for (int i = 0; i < numCities; i++) {
        cout << "City " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
