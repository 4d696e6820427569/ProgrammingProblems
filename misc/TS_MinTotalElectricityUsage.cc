/**
 * TuSimple Backend engineer HackerRank
 *
 * Description
 *
 * TuSimple has N machine to running models right now, and we know P greater
 * relationship between these machines (we assume greater at minimum 1).
 *
 * Besides, we know the minimum usage M of one machine currently, could you
 * estimate the total minimum usage of all the machines?
 *
 * If the relationship contradict with each other, output -1.
 *
 * The machine number is 1-N.
 *
 * Example:
 * N = 10, M = 1, P = 2
 *
 * and if we have the following P greater relationships
 *
 * usage[1] < usage[2]
 * usage[1] < usage[3]
 *
 * Final minimum usage = [1, 2, 2, 1, 1, 1, 1, 1, 1, 1]
 * sum: 12
 *
 * Function Description:
 * Complete the function minimum_total_usage in the editor below.
 *
 * minimum_total_usage has the following parameter(s):
 *  int N: the machine number
 *  int M: the minimum unit usage
 *  int[][] relationships: the greater relationship between machines.
 *
 * Returns
 * int: the total minimum usage.
 *
 * Constraints:
 * N <= 1000
 * M * N < 100000000
 */
