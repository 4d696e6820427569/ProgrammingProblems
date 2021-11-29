/**
 * EG problem 2
 *
 * Metro Land is a country located on a 2D plane. They are having a summer
 * festival for everyone in the country and would like to minimize the overall
 * cost of travel for their citizens. Cost of travel are calculated as follows:
 *
 * A city is located at coordinates (x, y).
 * The festival is located at coordinates (a, b).
 * Cost of travel from a city to the festival = |x-a| + |y-b| per person.
 *
 * The festival can be held at any location in Metro Land. Find the optimal
 * location for the festival, defined as the location with the minimal total
 * travel cost assuming all people attend. Dtermine the total cost of travel
 * for all citizens to go to the festival at that location.
 *
 * Example
 *
 * numPeople = [1, 2]
 * x = [1, 3]
 * y = [1, 3]
 *
 * There is 1 person in City 0 located at (x[0], y[0]) = (1, 1) and there are
 * 2 people in City 1 at (x[1], y[1]) = (3, 3).
 *
 * If the location for the festival is at (2, 2):
 *
 * The cost of travel from city 0 at (1, 1) to the festival 2 = |1 - 2| + |1 - 2|
 * The cost of travel from city 1 at (3, 3) to the festival 4 = 2 *|3-2| + |3-2|.
 * The total cost of travel for all citizens to go to the festival is 2 + 4 = 6.
 *
 * If the location for the festival is at (3, 3).
 * The cost of travel from city 0 at (1, 1) to the festival 4 = |1-3| + |1-3|.
 * The cost of travel from city 1 at (3, 3) to the festival 0. The total cost of
 * travel for all citizens to go to the festival is 0 + 4 = 4. So, the optimal
 * location for the festival is at (3, 3).
 *
 * Another way to analyze the problem follow.s These 2 matrices show the costs to
 * move one person from a city to any other position (a, b) on the map with an
 * origin at (x, y) = (1, 1) at the top left.
 *
 * City 0 = [[0, 1, 2], [1, 2, 3], [2, 3, 4]]
 * City 1 = [[4, 3, 2], [3, 2, 1], [2, 1, 0]]
 *
 * Since there are 2 people in City 1, multiply those values by 2, then sum the
 * two matrices, (City0 * 1 + City1 * 2):
 *
 * [[8, 7, 6], [7, 6, 5], [6, 5, 4]]
 *
 * The lowest total cost to travel is if the event is held at grid position (3, 3)
 * at a cost of 4.
 *
 * Constraints:
 * 1 <= n <= 10^3
 * 1 <= x[i], y[i] <= 10^4
 * 1 <= p[i] <= 50.
 */

#include <vector>

using std::vector;


int minimizeCost(vector<int> numPeople, vector<int> x, vector<int> y)
{
    int min_cost = 0;
    return min_cost;
}

int main()
{
    return 0;
}
